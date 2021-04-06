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

void handleSearchByTag()
	{
	//searchByTagPage();
	}

void handleSearchCondition()
	{

	}
/**************************************/



void handlemainmenu()
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
				 handleAddNewPhoto();/**/
				 break;
			case '2':
				 handleSearchByTag();/**/
				 break;
			case '3':
				 handleSearchCondition();/**/
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

    handlemainmenu();

    writeData(pHead);
    freeAll(pHead,hashphoto,hashtag);
	}
