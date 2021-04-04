/******************************************************************
 *
 *   readwrite.c
 *
 *   This file handle reading and writing
 *   the information of the photos to the
 *   file and also setup the data structure
 *   for further usage
 *
 *   Created By Bung
 *       April 2 2021 - Initially create readwrite.c
 * 
 *   Modified By Bung
 *       April 4 2021 - Added comment for each function
 *                    - Added code to freeAll, writeData function
 *                    - Bug : segmentation fault when try to access
 *                            data from masterlist in main
 *                      see add_photo_2_masterlist
 * 
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastruct.h"
#include "readwrite.h"
#include "dtype.h"

#define ALLTAG 512
#define BUFFER 512



//use dtype.c
STATUS add_photo_2_hashphoto(PHOTO_T * photo, HASHITEM_T * hashphoto[])
{
	BOOL result = FALSE;                    //variable to hold result of insertitem function

    result = insertitem(photo->namephoto,photo,hashphoto);
	if(result == FALSE)
    {
        printf("\tERROR - Failed to insert item to the hashtable\n");
    }
    return result;
}



//use dtype.c
STATUS add_photo_2_hashtag(PHOTO_T * photo, HASHITEM_T * hashtag[])
{
	LIST_TAG_T * pHeadAlltag = NULL;        //variable to hold pointer to head of linkedlist
	LIST_TAG_T * pTmp = NULL;               //variable to hold pointer to temporary linkedlist for tag

    BOOL result = FALSE;                    //variable to hold result of insertitem function

    pHeadAlltag = photo->alltag;
    pTmp = pHeadAlltag;
	while(pTmp != NULL)
	{
        result = insertitem(pTmp->nametag,photo,hashtag);
		if(result == 0)
		{
			printf("ERROR - Failed to insert item to the hashtable\n");
			break;
		}
		pTmp = pTmp->next;
	}
	return result;
}



//use "next" and hand build link list
void add_photo_2_masterlist(PHOTO_T * photo, PHOTO_T ** pHead)
{
	if(*pHead == NULL)
    {
        *pHead = photo;
    }
    else
    {
        photo->next = *pHead;
        *pHead = photo;
    }
}



//set data to NULL
void freeAll(PHOTO_T * pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
{
    LIST_TAG_T * pTmp = NULL;               //variable to hold pointer to temporary linkedlist

    while(pHead != NULL)
    {
        pTmp = pHead->alltag;
        pHead = pHead->next;
        free(pTmp);
    }
    /*freeHash(hashphoto);
    freeHash(hashtag);*/
}



//write data to
void writeData(PHOTO_T * pHead)
{
    FILE * pOut = NULL;                     //variable to hold position of output file

    PHOTO_T * pTmp = NULL;

    LIST_TAG_T * pTmpTag = NULL;

    pOut = fopen("tag_copy.txt","w");
    if(pOut == NULL)
    {
        printf("\tERROR - Failed to open output file\n");
    }
    else
    {
        pTmp = pHead;
        while(pTmp != NULL)
        {
            pTmpTag = pHead->alltag;
            fprintf(pOut,"%s;%d;%s\n",pTmp->namephoto,pTmp->numtag,pTmp->path);
            while(pTmpTag != NULL)
            {
                fprintf(pOut,"%s",pTmpTag->nametag);
                //check if there is next element or not
                if(pTmpTag->next != NULL)
                {
                    printf(";");
                    fprintf(pOut,";");
                }
                pTmpTag = pTmpTag->next;
            }
            fprintf(pOut,"\n");
            pTmp = pTmp->next;
        }
        fclose(pOut);
    }
}



void createFile()
{

}



void readData(PHOTO_T ** pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
{
    FILE * pIn = NULL;                      //variable to hold position of input file

    PHOTO_T * inputData;                    //variable to hold pointer to data structure

    LIST_TAG_T * pHeadTag = NULL;           //variable to hold pointer to head of linkedlist
    LIST_TAG_T * pCurrentTag = NULL;        //variable to hold pointer to current node in linkedlist

    char pic_name[PHOTOSIZE];               //variable to hold name of picture
    int pic_tagNum;                         //variable to hold number of tag in picture
    char pic_path[PATHSIZE];                //variable to hold path of picture
    char pic_tagAll[ALLTAG];                //variable to hold all tag in picture

    const char delim[] = ";";               //variable to hold delimiter that want to seperate
    char * ptr = NULL;                      //variable to hold seperated tag

    BOOL result_name = FALSE;               //variable to hold result from add_photo_2_hashphoto function
    BOOL result_tag = FALSE;                //variable to hold result from add_photo_2_hashtag function

    char inputline[BUFFER];                 //variable to hold data from input file as buffer

    pIn = fopen("tag.txt","r");
    if(pIn == NULL)
    {
        printf("\tERROR - Failed to open input file\n");
    }
    else
    {
        while(fgets(inputline,sizeof(inputline),pIn) != NULL)
        {
            inputData = calloc(1,sizeof(PHOTO_T));
            if(inputData == NULL)
            {
                printf("\tERROR - Failed to calloc for inputData\n");
            }
            else
            {
                //adding data to data structure
                sscanf(inputline,"%[^;];%d;%s",pic_name,&pic_tagNum,pic_path);
                fgets(inputline,sizeof(inputline),pIn);
                sscanf(inputline,"%s",pic_tagAll);
                strcpy(inputData->namephoto,pic_name);
                inputData->numtag = pic_tagNum;
                strcpy(inputData->path,pic_path);
                //seperating alltag to small one
                pHeadTag = (LIST_TAG_T *)calloc(1,sizeof(LIST_TAG_T));
                pCurrentTag = pHeadTag;
                ptr = strtok(pic_tagAll,delim);
                while(ptr != NULL)
                {
                    strcpy(pCurrentTag->nametag,ptr);
                    ptr = strtok(NULL,delim);
                    if(ptr != NULL)
                    {
                        pCurrentTag->next = (LIST_TAG_T *)calloc(1,sizeof(LIST_TAG_T));
                        pCurrentTag = pCurrentTag->next;
                    }
                }
                inputData->alltag = pHeadTag;
                inputData->count = 0;
                inputData->state = 0;
                /*
                *   test printing tag from linkedlist
                *   printf("-Printing linkedlist data : seperated tags\n");
                *   pCurrentTag = pHeadTag;
                *   while(pCurrentTag != NULL)
                *   {
                *       printf("\ttag = %s\n",pCurrentTag->nametag);
                *       pCurrentTag = pCurrentTag->next;
                *   }
                * 
                */
                result_name = add_photo_2_hashphoto(inputData, hashphoto);
                result_tag = add_photo_2_hashtag(inputData, hashtag);
                pHead = add_photo_2_masterlist(inputData);
            }
        }
        fclose(pIn);
    }
}



int main()
{
    PHOTO_T * pHead;

    HASHITEM_T ** hashphoto = intialHash();

    HASHITEM_T ** hashtag = intialHash();

    readData(&pHead,hashphoto,hashtag);
    writeData(pHead);
    freeAll(pHead,hashphoto,hashtag);
}