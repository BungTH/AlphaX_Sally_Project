/****************************************
 *
 *
 *
 *
 *
 ****************************************/
 
 #include <stdio.h>
 #include <stdlib.h>

 #include "datastruct.h"
 #include "dtype.h"
 #include "readwrite.h"
 #include "model.h"
 //#include "view.h"


/*should be in view.c*/
void displayphoto(PHOTO_T* photo)
	{
	LIST_TAG_T* alltag = photo->alltag; /*get all tag of the photo(as a head of linklist)*/
	LIST_TAG_T* tmp = NULL;
	printf("\n\n-----------------------\n\n");
	printf("name : %s\n",photo->namephoto);
	printf("path : %s\n",photo->path);
	printf("number of tag : %d\n",photo->numtag);
	printf("All of the tags:\n");
	printf("************************\n");
	tmp = alltag;
	while(tmp != NULL)
		{
		printf("\t%s\n",tmp->nametag);
		tmp = tmp->next;	
		}
	printf("************************\n");
	printf("\n\n-----------------------\n\n");
	}

void handleAddDeleteTag()
	{

	}

void handleDisplayBroswer()
	{

	}

void handlefindSimilar()
	{

	} 
/**************************************/
void handleAddNewPhoto()
	{

	} 

void handleSearchByTag(HASHITEM_T ** hashtag)
	{
	char* tag[256];
	int sizetag = 0;
	int i = 0;
	//searchByTagPage(tag,sizetag);
	PHOTO_T* result = searchByTag(tag,sizetag,hashtag);
	PHOTO_T* tmp = result;
	printf("the Result is ");
	while(tmp != NULL)
		{
		displayphoto(tmp);
		tmp = tmp->nextResult;
		}
	}

void handleSearchCondition()
	{

	}
/**************************************/



void handlemainmenu(PHOTO_T * pHead,HASHITEM_T ** hashphoto,HASHITEM_T ** hashtag)
	{
	char whichcheck = '0'; /*collect which validation option user want*/
	char input[128];/*get data from user*/

	while(whichcheck != '4')
		{

		/*****change to menuPage()*****/
		/*********************************************
		printmainmenu();/*shortcut to print mainmenu	

		fgets(input,sizeof(input),stdin);
		sscanf(input,"%c",&whichcheck);
		************************************************/

		switch(whichcheck)/*check which subprogram user selected*/
			{
			case '1':
				 handleAddNewPhoto(pHead,hashphoto,hashtag);/**/
				 break;
			case '2':
				 handleSearchByTag(hashtag);/**/
				 break;
			case '3':
				 handleSearchCondition(hashphoto,hashtag);/**/
				 break;
			case '4':
				 printf("\nGoodbye\n");
				 exit(0);
				 break;
			default: 
				 printf("invalid input( enter only 1-5)\n"); 
                 break;   
            }
        }
	}

int main()
	{
    PHOTO_T * pHead;
    HASHITEM_T ** hashphoto = intialHash();
    HASHITEM_T ** hashtag = intialHash();
    readData(&pHead,hashphoto,hashtag);

    handlemainmenu(pHead,hashphoto,hashtag);

    writeData(pHead);
    freeAll(pHead,hashphoto,hashtag);
	}
