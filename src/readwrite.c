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



void readData(PHOTO_T* pHead, HASHITEM_T* hashphoto[], HASHTAG_T* hashtag[])
{
    FILE* pIn = NULL;

    PHOTO_T* inputData;
    
    char pic_name[PHOTOSIZE];
    int pic_tagNum;
    char pic_path[PATHSIZE];
    char pic_tagAll[ALLTAG];

    char inputline[320];

    pIn = fopen("tag.txt","r");
    while(fgets(inputline,sizeof(inputline),pIn) != NULL)
    {
        inputData = calloc(1,sizeof(PHOTO_T));
        if(inputData == NULL)
        {
            printf("\tError - Calloc failed for inputData\n");
        }
        else
        {
            sscanf(inputline,"%s:%d:%s",pic_name,pic_tagNum,pic_path);
            fgets(inputline,sizeof(inputline),pIn);
            sscanf(inputline,"%s",pic_tagAll);
            printf("%s - %d - %s\n%s",pic_name,pic_tagNum,pic_path,pic_tagAll);
        }
    }
}



//use dtype.c
void add_photo_2_hashphoto(PHOTO_T* photo, HASHITEM_T* hashphoto[])
{

}



//use dtype.c
void add_photo_2_hashtag(PHOTO_T* photo, HASHITEM_T* hashtag[])
{

}



//use "next" and hand build link list
void add_photo_2_masterlist(PHOTO_T* photo, PHOTO_T* pHead)
{

}



//set data to NULL
void freeAll(PHOTO_T* pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[])
{

}



//write data to
void writeData(PHOTO_T* pHead)
{

}



void createFile()
{

}



int main()
{

}