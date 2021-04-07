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
	char * tag[256];
	int sizetag = 0;

	//searchByTagPage(tag,&sizetag); <-- Today Goal
	PHOTO_T* result = searchByTag(tag,sizetag,hashtag);
	PHOTO_T* tmp = result;
	printf("the Result is ");
	while(tmp != NULL)
		{
		displayphoto(tmp);
		tmp = tmp->nextResult;
		}
	//handlesubmenu();
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
