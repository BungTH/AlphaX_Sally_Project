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
 #include "controller.h"
 #include "dtype.h"
 #include "readwrite.h"
 #include "model.h"
 #include "view.h"




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
	char* tag[20];
	int sizetag = 0;
	int count = 0;
	PHOTO_T* result = NULL;
	PHOTO_T* tmp = NULL;
	int i = 0;
	searchByTagPage(tag,&sizetag);
	/*
	for (i= 0 ;i<sizetag;i++)
		printf("%s\n",tag[i]);
	*/
	result = searchByTag(tag,sizetag,hashtag);
	freestring(tag,sizetag);
	
	if(result == NULL)
		{
		printf("\nFound %d photo(s) \n",count);
		}
	else
		{
		printf("\nThe Result is \n");
		tmp = result;
		while(tmp != NULL)
			{
			displayphoto(tmp,count);
			tmp = tmp->nextResult;
			count++;
			}
		printf("Found %d photo(s) \n",count);
		}

	//handleSubMenu();
	
	}

void handleSearchCondition()
	{
	//handlesubmenu()
	}
/**************************************/



void handlemainmenu(PHOTO_T * pHead,HASHITEM_T ** hashphoto,HASHITEM_T ** hashtag)
	{
	char whichcheck = '0'; /*collect which validation option user want*/
	char input[128];/*get data from user*/

	while(whichcheck != '4')
		{
		menuPage(&whichcheck);
		switch(whichcheck)/*check which subprogram user selected*/
			{
			case '1':
				 handleAddNewPhoto(pHead,hashphoto,hashtag);/**/
				 clearscreen();
				 break;
			case '2':
				 handleSearchByTag(hashtag);/**/
				 clearscreen();
				 break;
			case '3':
				 handleSearchCondition(hashphoto,hashtag);/**/
				 clearscreen();
				 break;
			case '4':
				 printf("\nGoodbye\n");
				 break;
			default: 
				 printf("invalid input( enter only 1-5)\n"); 
                 break;   
            }
        }
	}
void handleSubMenu(HASHITEM_T** hashphoto,HASHITEM_T** hashtag)
	{
	char whichcheck = '0'; /*collect which validation option user want*/
	char input[128];/*get data from user*/

	while(whichcheck != '4')
		{
		subMenuPage(&whichcheck);
		switch(whichcheck)/*check which subprogram user selected*/
			{
			case '1':
				 handleAddDeleteTag(hashphoto);
				 break;
			case '2':
				 handlefindSimilar(hashphoto,hashtag);
				 break;
			case '3':
				 handleDisplayBroswer(hashphoto);
				 break;
			case '4':
				 clearscreen();
				 break;
			default: 
				 printf("invalid input( enter only 1-4)\n"); 
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
