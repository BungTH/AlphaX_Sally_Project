/**********************************************
*
*   readwrite.c
*
*   This file handle reading and writing
*   the information of the photos to the
*   file and also setup the data structure
*   for further usage
*
*   Created by Bung
*       2 April 2021
*
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastruct.h"
#include "readwrite.h"
#include "dtype.h"

#define ALLTAG 512
#define BUFFER 512



//use dtype.c
int add_photo_2_hashphoto(PHOTO_T * photo, HASHITEM_T * hashphoto[])
{
	int result = 1;
	if(!insertitem(photo->namephoto,photo,hashphoto))
		{
		result = 0;	
		}
	return result;
}



//use dtype.c
int add_photo_2_hashtag(PHOTO_T * photo, HASHITEM_T * hashtag[])
{
	int result = 1;
	LIST_TAG_T* headAlltag = photo->alltag;
	
	LIST_TAG_T* tmp = headAlltag;
	while(tmp != NULL)	
		{
		if(!insertitem(tmp->nametag,photo,hashtag))
			{
			result = 0;
			break;	
			}
		tmp = tmp->next;
		}
	return result;
}



//use "next" and hand build link list
void add_photo_2_masterlist(PHOTO_T * photo, PHOTO_T** pHead)
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

}



//write data to
void writeData(PHOTO_T* pHead)
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



void readData(PHOTO_T** pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
{
    FILE * pIn = NULL;

    PHOTO_T * inputData;

    LIST_TAG_T * pHeadTag = NULL;
    LIST_TAG_T * pCurrentTag = NULL;

    char pic_name[PHOTOSIZE];
    int pic_tagNum;
    char pic_path[PATHSIZE];
    char pic_tagAll[ALLTAG];

    const char delim[] = ";";
    char * ptr = NULL;

    char inputline[BUFFER];

    pIn = fopen("tag.txt","r");
    if(pIn == NULL)
    {
        printf("\tERROR - can't open file\n");
    }
    else
    {
        while(fgets(inputline,sizeof(inputline),pIn) != NULL)
        {
            inputData = calloc(1,sizeof(PHOTO_T));
            if(inputData == NULL)
            {
                printf("\tERROR - Calloc failed for inputData\n");
            }
            else
            {
                sscanf(inputline,"%[^;];%d;%s",pic_name,&pic_tagNum,pic_path);
                fgets(inputline,sizeof(inputline),pIn);
                sscanf(inputline,"%s",pic_tagAll);
                //adding data to structure
                strcpy(inputData->namephoto,pic_name);
                inputData->numtag = pic_tagNum;
                strcpy(inputData->path,pic_path);                
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
                add_photo_2_hashphoto(inputData, hashphoto);
                add_photo_2_hashtag(inputData, hashtag);
                add_photo_2_masterlist(inputData, pHead);
            }
        }
        fclose(pIn);
    }
}



int main()
{
    PHOTO_T * pHead = NULL;
    
    HASHITEM_T ** hashphoto = intialHash();
    HASHITEM_T ** hashtag = intialHash();

    readData(&pHead,hashphoto,hashtag);
    writeData(pHead);
}





