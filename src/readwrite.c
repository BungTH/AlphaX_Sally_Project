/*
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
 *                    - Bug [SOLVED] :  segmentation fault when try to access
 *                                      data from masterlist in main
 *                                      see add_photo_2_masterlist
 *                    - Added comment for each function
 *       April 8 2021 - Added code and comment to addPhoto function
 *                    - Module finished
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "datastruct.h"
#include "dtype.h"
#include "readwrite.h"



/*---------------------------------------PRIVATE FUNCTION---------------------------------------*/

/*
 * 
 *  This function will add the information of data structure 
 *  for each photo into the hash table
 *
 *	Arugement : PHOTO_T * photo (data structure of photo)
 *				HASHITEM_T * hashphoto[] (hash table of photo)
 *
 *	return	  : BOOL result (result of insertion)
 *              - TRUE for succeeded insertion
 *              - FALSE for failed insertion
 * 
 */
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



/*
 * 
 *  This function will add the information of linked list
 *  for tag(s) in photo into the hash table
 *
 *	Arugement : PHOTO_T * photo (data structure of photo)
 *				HASHITEM_T * hashtag[] (hash table of tag)
 *
 *	return	  : BOOL result (result of insertion)
 *              - TRUE for succeeded insertion
 *              - FALSE for failed insertion
 *
 */
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
		if(result == FALSE)
		{
			printf("ERROR - Failed to insert item to the hashtable\n");
			break;
		}
		pTmp = pTmp->next;
	}
	return result;
}



/*
 * 
 *  This function will copy the information from one data
 *  structure to the master list which will be used to compare
 *  and search in other function
 *
 *	Arugement : PHOTO_T * photo (data structure of photo)
 *				PHOTO_T ** pHead (data structure of master list)
 *
 *	return	  : None
 *
 */
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



/*
 * 
 *  This function will create the data base file if the program
 *  failed to open the file or the file doesn't existed
 *
 *	Arugement : None
 *
 *	return	  : None
 *
 */
void createFile()
{
    FILE * pTmp = NULL;                     //variable to hold position of temporary file

    pTmp = fopen("tag.txt","w");
    if(pTmp == NULL)
    {
        printf("\tERROR - Failed to create database file\n");
    }
    else
    {
        printf("\tNotice - File had been created\n");
        fclose(pTmp);
    }
}



/*---------------------------------------PUBLIC FUNCTION---------------------------------------*/

/*
 * 
 *  This function will check calloc operation, is it successful or not,
 *  it will display error if calloc is not successful
 *
 *	Arugement : void * pointer (input data to validate calloc operation)
 *
 *	return	  : result (result of operation)
 *
 */
BOOL checkNULL(void * pointer)
{
    BOOL result = TRUE;                     //variable to hold result of operation

    if(pointer == NULL)
    {
        printf("\tERROR - Failed to calloc \n");
        result  = FALSE;
    }
    return result;
}



/*
 * 
 *  This function will read the data from the data base file
 *  then initialized the data structure required in the program
 *  and other necessary elements
 *
 *	Arugement : PHOTO_T ** pHead (data structure of master list)
 *              HASHITEM_T * hashphoto[] (hash table of photo)
 *              HASHITEM_T * hashtag[] (hash table of tag)
 *
 *	return	  : BOOL result (result of calloc and insertion)
 *              - TRUE for succeeded calloc and insertion
 *              - FALSE for failed calloc or insertion
 *
 */
STATUS readData(PHOTO_T ** pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
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

    BOOL result = TRUE;                     //variable to hold result of operation

    char inputline[BUFFER];                 //variable to hold data from input file as buffer

    pIn = fopen("tag.txt","r");
    if(pIn == NULL)
    {
        printf("\tERROR - Failed to open input file\n");
        createFile();
    }
    else
    {
        while(fgets(inputline,sizeof(inputline),pIn) != NULL)
        {
            inputData = calloc(1,sizeof(PHOTO_T));
            result = (result && checkNULL(inputData));
            //adding data to data structure
            sscanf(inputline,"%[^;];%d;%s",pic_name,&pic_tagNum,pic_path);
            fgets(inputline,sizeof(inputline),pIn);
            sscanf(inputline,"%[^\n]s",pic_tagAll);
            strcpy(inputData->namephoto,pic_name);
            inputData->numtag = pic_tagNum;
            strcpy(inputData->path,pic_path);
            

            /*setup all tag to inputData*/
            pHeadTag = (LIST_TAG_T *)calloc(1,sizeof(LIST_TAG_T));
            result = (result && checkNULL(pHeadTag));
            pCurrentTag = pHeadTag;
            ptr = strtok(pic_tagAll,delim);
            while(ptr != NULL)
            {
                strcpy(pCurrentTag->nametag,ptr);
                ptr = strtok(NULL,delim);
                if(ptr != NULL)
                {
                    pCurrentTag->next = (LIST_TAG_T *)calloc(1,sizeof(LIST_TAG_T));
                    result = (result && checkNULL(pCurrentTag->next));
                    pCurrentTag = pCurrentTag->next;
                }
            }
            inputData->alltag = pHeadTag;


            /*set for calculate*/
            inputData->count = 0;
            inputData->state = 0;
            if(!(add_photo_2_hashphoto(inputData, hashphoto) && add_photo_2_hashtag(inputData, hashtag)))
            {
                result = FALSE;
            }
            add_photo_2_masterlist(inputData, pHead);
        }
        return result;
    }
    fclose(pIn);
}



/*
 * 
 *  This function will read the data from the argument given
 *  then initialized the data structure required in the program
 *  and other necessary elements
 *
 *	Arugement : char * namephoto (name of photo)
 *              int * tag_amouth (amouth of tag)
 *              char * path (path of photo)
 *              char * tag_all[] (all tag in photo)
 *              PHOTO_T ** pHead (data structure of master list)
 *              HASHITEM_T * hashphoto[] (hash table of photo)
 *              HASHITEM_T * hashtag[] (hash table of tag)
 *
 *	return	  : BOOL result (result of calloc and insertion)
 *              - TRUE for succeeded calloc and insertion
 *              - FALSE for failed calloc or insertion
 *
 */
STATUS addPhotoToStruct(char * namephoto, int tag_amount, char * path, char * tag_all[],
                PHOTO_T ** pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
{
    PHOTO_T * inputData;                    //variable to hold pointer to data structure

    LIST_TAG_T * pHeadTag = NULL;           //variable to hold pointer to head of linkedlist
    LIST_TAG_T * pCurrentTag = NULL;        //variable to hold pointer to current node in linkedlist

    BOOL result = TRUE;                     //variable to hold result of operation

    int i;                                  //variable for loop

    inputData = calloc(1,sizeof(PHOTO_T));
    result = (result && checkNULL(inputData));
    //adding data to data structure
    strcpy(inputData->namephoto,namephoto);
    inputData->numtag = tag_amount;
    strcpy(inputData->path,path);
    for(i = 0;i < tag_amount;i++)
    {   
        pCurrentTag = (LIST_TAG_T *)calloc(1,sizeof(LIST_TAG_T));
        result = (result && checkNULL(pCurrentTag));
        strcpy(pCurrentTag->nametag,tag_all[i]);
        if(pHeadTag == NULL)     
        {
            pHeadTag = pCurrentTag;
        }
        else
        {
            pCurrentTag->next = pHeadTag;
            pHeadTag = pCurrentTag;
        }
    }
    inputData->alltag = pHeadTag;
    
    inputData->count = 0;
    inputData->state = 0;
    if(!(add_photo_2_hashphoto(inputData, hashphoto) && add_photo_2_hashtag(inputData, hashtag)))
        {
        return FALSE;
        }
    add_photo_2_masterlist(inputData, pHead);
    return TRUE;
}



/*
 * 
 *  This function will write the data into the output file
 *  that will be used in the other module or function in
 *  the program
 *
 *	Arugement : PHOTO_T * pHead (data structure of master list)
 *
 *	return	  : None
 *
 */
void writeData(PHOTO_T * pHead)
{
    FILE * pOut = NULL;                     //variable to hold position of output file
    PHOTO_T * pTmp = NULL;                  //variable to hold position of temporary data structure
    LIST_TAG_T * pTmpTag = NULL;            //variable to hold position of temporary linkedlist
    
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
            pTmpTag = pTmp->alltag;
            fprintf(pOut,"%s;%d;%s\n",pTmp->namephoto,pTmp->numtag,pTmp->path);
            while(pTmpTag != NULL)
            {
                fprintf(pOut,"%s",pTmpTag->nametag);
                //check if there is next element or not
                if(pTmpTag->next != NULL)
                {
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



/*
 * 
 *  This function will free all the used memory allocated to
 *  the data structure and linked list
 *
 *	Arugement : PHOTO_T * pHead (data structure of master list)
 *				HASHITEM_T * hashphoto[] (hash table of photo)
 *              HASHITEM_T * hashtag[] (hash table of tag)
 *
 *	return	  : None
 *
 */
void freeAll(PHOTO_T * pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
{
    LIST_TAG_T * pTmp = NULL;               //variable to hold pointer to temporary linkedlist
    
    while(pHead != NULL)
    {
        pTmp = pHead->alltag;
        pHead = pHead->next;
        free(pTmp);
    }
    //freeHash bug : double free error
    /*freeHash(hashphoto);
    freeHash(hashtag);*/
}
