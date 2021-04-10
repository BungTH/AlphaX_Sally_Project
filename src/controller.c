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
 #include "getinput.h"


/************************************************************************************/

void handleAddDeleteTag()
	{

	}

void handleDisplayBroswer()
	{

	}

void handlefindSimilar()
	{

	} 
/************************************************************************************/
void handleAddNewPhoto(PHOTO_T** pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[])
	{
	int sizetag = 0;
	char path[PATHSIZE];
	char* tag[TAGBUFFER];
	char namephoto[PHOTOSIZE];
	addNewPhotoPage(hashphoto,namephoto,&sizetag,path,tag);
	addPhotoToStruct(namephoto, sizetag, path, tag, pHead, hashphoto, hashtag);
	//printf("\nhandleAddNewPhoto phead %s\n",(*pHead)->namephoto);
	} 
/*
 * 
 *   This function get all the user input, validate the input
 *   then search for tags that match what user had input and print out the result.
 * 
 * 	 Argument: HASHITEM_T* hashtag[]
 * 
 *   return:   Non
 * 
 */
void handleSearchByTag(HASHITEM_T* hashtag[])
	{
	char* tag[TAGBUFFER];
	int sizetag = 0;
	int count = 0;
	PHOTO_T* result = NULL;
	PHOTO_T* tmp = NULL;
	int i = 0;
	searchByTagPage(tag,&sizetag); /*get all the data and display UI*/
	result = searchByTag(tag,sizetag,hashtag);/*get the result*/
	
	if(result == NULL)
		printf("\nFound %d photo(s) \n",count);
	else
		{
		tmp = result;
		while(tmp != NULL)
			{
			displayphoto(tmp,count);
			tmp = tmp->nextResult;
			count++;
			}
		printf("Found %d photo(s) \n",count);
		}
	freestring(tag,sizetag);/*free tag and sizetag use*/
	//handleSubMenu();
	}
/* 
 *
 *   This function get the input from user, validate the input
 *   Then search with the conditions and print out the result.
 * 
 *   Argument: HASHITEM_T* hashtag[]
 * 
 *   return:   Non
 * 
 */
void handleSearchCondition(HASHITEM_T* hashtag[])
	{
	char* tag[TAGBUFFER];
	int sizetag = 0;
	char* except[TAGBUFFER];
	int sizeexcept = 0;
	int count = 0;
	PHOTO_T* result = NULL;
	PHOTO_T* tmp = NULL;
	int i = 0;
	
	searchConPage(tag,&sizetag,except,&sizeexcept);/*get all the data that user input and display UI*/
	result = searchCondition(tag,sizetag,except,sizeexcept,hashtag);/*get the result of search with condition*/
	
	if(result == NULL)
		printf("\nFound %d photo(s) \n",count);
	else
		{
		tmp = result;
		while(tmp != NULL)
			{
			displayphoto(tmp,count);
			tmp = tmp->nextResult;
			count++;
			}
		printf("Found %d photo(s) \n",count);
		}
	freestring(tag,sizetag);/*free tag and sizetag use*/
	}
/* 
 *
 *  This function print out the menu page, and option from user input(from UI), validate the option
 *  and show the selected option what user want to do.
 * 
 *  Argument: PHOTO_T* pHead
 *            HASHITEM_T* hashphoto[]
 *            HASHITEM_T* hashtag[]
 * 
 *  return:   Non
 * 
 */
void handlemainmenu(PHOTO_T* pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[])
	{
	char whichcheck = 'A'; /*collect which validation option user want*/
	char input[128];/*get data from user*/

	while(whichcheck != '4')
		{
		menuPage(&whichcheck);
		switch(whichcheck)/*check which subprogram user selected*/
			{
			case '1':
				 handleAddNewPhoto(&pHead,hashphoto,hashtag);/**/
				 //printf("handlemainmenu phead %s",pHead->namephoto);
				 clearscreen();
				 break;
			case '2':
				 handleSearchByTag(hashtag);/**/
				 clearscreen();
				 break;
			case '3':
				 handleSearchCondition(hashtag);/**/
				 clearscreen();
				 break;
			case '4':
				 writeData(pHead);
				 printf("\nGoodbye\n");
				 break;
			default: 
				 printf("invalid input( enter only 1-5)\n"); 
                 break;   
            }
        }
	}
/*
 *
 *  This function print out the sub-menu for extra option
 *  add or delete tags, find similar and display photo in browser.
 *  Validate the option and show the function that option selected.
 * 
 *  Argument: HASHITEM_T* hashphoto[]
 * 			 HASHITEM_T* hashtag[]
 * 
 *  Return:   Non
 * 
 */
void handleSubMenu(HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[])
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
    readData(&pHead, hashphoto, hashtag);

    handlemainmenu(pHead, hashphoto, hashtag);

    freeAll(pHead, hashphoto, hashtag);
	}
