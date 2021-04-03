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

#define ALLTAG 512
#define BUFFER 512



//use dtype.c
void add_photo_2_hashphoto(PHOTO_T * photo, HASHITEM_T * hashphoto[])
{

}



//use dtype.c
void add_photo_2_hashtag(PHOTO_T * photo, HASHITEM_T * hashtag[])
{

}



//use "next" and hand build link list
void add_photo_2_masterlist(PHOTO_T * photo, PHOTO_T * pHead)
{

}



//set data to NULL
void freeAll(PHOTO_T * pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[])
{

}



//write data to
void writeData(PHOTO_T * pHead)
{

}



void createFile()
{

}



void readData(PHOTO_T * pHead, HASHITEM_T * hashphoto[], HASHTAG_T * hashtag[])
{
    FILE * pIn = NULL;

    PHOTO_T * inputData;

    LIST_TAG_T * pListHead = NULL;
    LIST_TAG_T * pListTemp = NULL;

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
                //printf("%s - %d - %s - %s",pic_name,pic_tagNum,pic_path,pic_tagAll);
                strcpy(inputData->namephoto,pic_name);
                inputData->numtag = pic_tagNum;
                strcpy(inputData->path,pic_path);
                //1st strtok
                pListHead = calloc(1,sizeof(LIST_TAG_T));
                pListTemp = calloc(1,sizeof(LIST_TAG_T));
                ptr = strtok(pic_tagAll,delim);
                //other strtok 
                while(ptr != NULL)
                {
                    printf("ptr = %s\n",ptr);
                    /*strcpy(pListTemp->nametag,ptr); //core dump
                    if(pListHead == NULL)
                    {
                        pListHead = pListTemp;
                    }
                    else
                    {
                        pListTemp->next = pListHead;
                        pListHead = pListTemp;
                    }*/
                    ptr = strtok(NULL,delim);
                }
                //strtok then assign tag
                /*add_photo_2_hashphoto(inputData, hashphoto);
                add_photo_2_hashtag(inputData, hashtag);
                add_photo_2_masterlist(inputData, pHead);*/
            }
        }
        fclose(pIn);
    }
}



int main()
{
    PHOTO_T* dummyHead;
    HASHITEM_T** dummyhashphoto;
    HASHTAG_T** dummyhashtag;

    readData(dummyHead,dummyhashphoto,dummyhashtag);
}