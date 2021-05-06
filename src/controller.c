/****************************************
 *controller.c
 *  
 * This file contain all handle option
 * to controll all system in This project.
 *
 * Created by Manutsawin (Sern) ID: 63070503442
 * 	   Mar 30 2021
 ****************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include "datastruct.h"
 #include "controller.h"
 #include "dtype.h"
 #include "readwrite.h"
 #include "model.h"
 #include "view.h"
 #include "getinput.h"


/* 
 * 
 *  This function get all the user input, validate the input
 *  Then add new photo with new tag and path in the structure file.
 * 
 *  Argument:  PHOTO_T** pHead => head of the photo linked list. To pass argument to function addPhotoToStruct.
 * 
 * 			   HASHITEM_T* hashphoto[] => hash table of photo. Pass argument to addNewPhotoUI and addPhotoToStruct.
 * 
 * 			   HASHITEM_T* hashtag[] => hash table of tag. To pass argument to function addPhotoToStruct.
 * 
 *  return:    Non
 * 								
 */
void handleAddNewPhoto(PHOTO_T** pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[])
	{
	int sizetag = 0;
	char path[PATHSIZE];
	char* tag[TAGBUFFER];
	char namephoto[PHOTOSIZE];
	addNewPhotoUI(hashphoto,namephoto,&sizetag,path,tag);
	addPhotoToStruct(namephoto, sizetag, path, tag, pHead, hashphoto, hashtag);
	} 

/*
 * 
 *   This function get all the user input, validate the input
 *   then search for tags that match what user had input and print out the result.
 * 
 * 	 Argument:  HASHITEM_T* hashtag[] => hash table of tag. For pass argument to other functions.
 * 										 to find result of search.
 * 
 * 			    HASHITEM_T* hashphoto[] => hash table of photo. Pass argument to go sub-menu.
 * 
 *              int option => handle the option from the menu to choose what to do
 *                            1 - to search by tag.
 *                            2 - to search by condition.
 * 
 *   return:    Non
 * 
 */
void handleSearchOption(HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[],int option)
	{
	char* tag[TAGBUFFER];
	int sizetag = 0;
	char* except[TAGBUFFER];
	int sizeexcept = 0;
	int count = 0;
	PHOTO_T* result = NULL;
	PHOTO_T* tmp = NULL;
	int i = 0;
	
	if (option == 1)
		{
		/*get all the data and display UI*/
		searchByTagUI(tag,&sizetag); 
		/*get the result*/
		result = searchByTag(tag,sizetag,hashtag);
		}
	else if (option == 2)
		{
		/*get all the data that user input and display UI*/
		searchConUI(tag,&sizetag,except,&sizeexcept);
		/*get the result of search with conditsion*/
		result = searchCondition(tag,sizetag,except,sizeexcept,hashtag);	
		}
		
	if(result == NULL)
		printf("\nFound %d photo(s) \n",count);
	else
		{
		tmp = result;
		while(tmp != NULL)
			{
			printf("\n-----------------------\n");
			printf("No. %d",count+1);
			displayphoto(tmp);
			tmp = tmp->nextResult;
			count++;
			}
		printf("Found %d photo(s) \n",count);
		}
	freestring(tag,sizetag);/*free tag and sizetag use*/
	handleSubMenu(hashphoto,hashtag);
	}

/* 
 * 
 *   This function get the input from user, validate the input
 * 	 Then find the similar photo.
 * 
 * 	 Argument:  HASHITEM_T* hashphoto[] => hash table of photo.
 * 										   Pass argument to other functions to find similar photo.
 * 				HASHITEM_T* hashtag[] => hash table of tag.
 * 										 Pass argument to other functions to find similar photo.
 * 
 * 	 return:    Non
 * 
 */
void handlefindSimilar(HASHITEM_T* hashphoto[],HASHITEM_T* hashtag[])
	{
	char namephoto[PHOTOSIZE];
	int i = 0;
	int numresult = 0;
	int index = 1;
	similarUI(namephoto);

	PHOTO_T** result = findSimilar(namephoto,&numresult,hashtag,hashphoto);
	
    printf("\n------------------------------------------------\n");
	printf("Photo %s Information\n",namephoto);
	displayphoto(findPhoto(namephoto,hashphoto));
	printf("\nTop 3 similiar photo\n");
	for(i = numresult-1;i != numresult-4;i--)
		{
		printf("\n%d.This photo has %d similiar tag(s)",index,result[i]->count);
		displayphoto(result[i]);
		index++;
		}
	free(result);
	
	} 

/* 
 * 
 *   This function get the input from user, validate the input
 *   Then display photo in browser
 *	 
 *   Argument:  HASHITEM_T* hashphoto[] => hash table of photo.
 *                                         Pass argument to other functions to find photo.
 * 
 * 	 return:    Non
 * 
 */
void handleDisplayInBrowser(HASHITEM_T* hashphoto[])
	{
	char option = 'A';
	char path[PATHSIZE]="";
	char namephoto[PHOTOSIZE]= "";
	char command[PHOTOSIZE +5] = "";
	displayInBrowserUI(namephoto,&option);
	strcpy(path,findPhoto(namephoto,hashphoto)->path);
	if(option == '1')
		strcat(command,"google-chrome");
	if(option == '2')
		strcat(command,"firefox");
	if(option == '3')
		strcat(command,"eog");
	strcat(command," ");
	if(access(path, F_OK) == 0)
		{
		strcat(command,path);
		system(command);
		}
	else 
		{
		printf("\n%s is not exist\n",namephoto);
		}
	}


/*
 *
 *  This function print out the sub-menu for extra option
 *  add or delete tags, find similar and display photo in browser.
 *  Validate the option and show the function that option selected.
 * 
 *  Argument: HASHITEM_T* hashphoto[] => hash table of photo. Pass argument to other functions.
 * 										 For each switch case.
 * 			  HASHITEM_T* hashtag[] => hash table of tag. Pass argument to other functions.
 * 									   For each switch case.
 * 
 *  Return:   Non
 * 
 */
void handleSubMenu(HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[])
	{
	char whichcheck = '0'; /*collect which validation option user want*/
	char input[128];/*get data from user*/

	subMenuUI(&whichcheck);
	switch(whichcheck)/*check which subprogram user selected*/
		{
		case '1':
			handlefindSimilar(hashphoto,hashtag);
			break;
		case '2':
			handleDisplayInBrowser(hashphoto);
			break;
		case '3':
			clearscreen();	 
			break;
		default: 
			printf("invalid input( enter only 1-3)\n"); 
            break;   
        }
	}
	
int main()
	{
    PHOTO_T * pHead = NULL;
    HASHITEM_T ** hashphoto = intialHash();
    HASHITEM_T ** hashtag = intialHash();
   	char whichcheck = 'A'; /*collect which validation option user want*/
	char input[128];/*get data from user*/

	readData(&pHead, hashphoto, hashtag);

	while(whichcheck != '4')
		{
		menuUI(&whichcheck);
		switch(whichcheck)/*check which subprogram user selected*/
			{
			case '1':
				 handleAddNewPhoto(&pHead,hashphoto,hashtag);/**/
				 //printf("handlemainmenu phead %s",pHead->namephoto);
				 clearscreen();
				 break;
			case '2':
				 handleSearchOption(hashtag,hashphoto,1);/**/
				 break;
			case '3':
				 handleSearchOption(hashtag,hashphoto,2);/**/
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

    freeAll(pHead, hashphoto, hashtag);
	}
