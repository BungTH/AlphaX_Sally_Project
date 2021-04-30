/*************************************
 *  
 * view.c
 *  
 * 		This file contain all function that display 
 *      the user interface and receive the data as 
 * 		a output argument.   
 * 
 * 		Created by Thitirat[Phukan][63070503413]
 * 
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "datastruct.h"
#include "view.h"
#include "getinput.h"

/*
 *This function clear the screen
 *and ask of enter to go the main menu
 *
 *	Arugment : NO
 *
 *	Return : NO
 *
 */
void clearscreen()
	{
	char input[16]; 
	printf("\nHit RETURN to go to main Menu: ");
    fgets(input,sizeof(input),stdin);
    printf("%s",CLEAR_ESCAPE);	
	}

/*
 * This function display photo and information
 * of photo on the screen.
 *
 *	Arugment : PHOTO_T* photo => all data of photo 
 *   		   
 *
 *	Return : NO
 *
 */
void displayphoto(PHOTO_T* photo)
	{
	LIST_TAG_T* alltag = photo->alltag; /*get all tag of the photo(as a head of linklist)*/
	LIST_TAG_T* tmp = NULL;

	printf("\n------------------------------------------------\n\n");
	printf("Name : %s\n",photo->namephoto);
	printf("Path : %s\n",photo->path);
	printf("Number of tag : %d\n",photo->numtag);
	printf("All of the tags:\n");
	tmp = alltag;
	while(tmp != NULL)
		{
		printf("%s,",tmp->nametag);
		tmp = tmp->next;	
		}
	printf("\n------------------------------------------------\n");
	}

/*
 * This function will display main menu on the screen
 * and ask for option that user want to choose. 
 * Moreover, set value of choice.
 * 
 *  Argument : char* choice => store option
 *
 *  Return : NO
 *
 */
void menuUI(char* choice)
	{
    printf("\n------------------------------------------------\n");
	printf("\t ||MAINMENU||\n");
	printf("\n------------------------------------------------\n");
    printf("\t 1 - ADD NEW PHOTO WITH NEW TAGS\n");
	printf("\t 2 - SEARCH PHOTO BY TAG\n");
	printf("\t 3 - SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf("\t 4 - EXIT\n");
	printf("\t Which option do you want to choose?\n");
	printf("\n------------------------------------------------\n");
    
    getOption(choice);
    printf("%s",CLEAR_ESCAPE);
	}

/*
 * This function display submenu on the screen
 * and ask for option that user want to choose.
 * Moreover, set value of choice.
 * 
 *  Argument : char* choice => store option
 *	
 *  Return : NO
 *
 */
void subMenuUI(char * choice)
	{
	printf("\n------------------------------------------------\n");
	printf("\t ||What do you want to do?||\n");
	printf("\n------------------------------------------------\n");
	printf("\t 1 - SEARCH SIMILAR PHOTO(S)\n");
	printf("\t 2 - DISPLAY ON BROWSER\n");
	printf("\t 3 - GO TO MAIN MENU\n");
	printf("\n------------------------------------------------\n");

	getOption(choice);
	}

/*
 * This function display user interface of add new photo 
 * and ask for name of photo,path and tag.
 * Moreover, set value of namephoto,sizetag,path and tag.
 * 
 *  Argument : HASHITEM_T* hashphoto[] => hashphoto (use for check unique of the photo)
 *			   char* namephoto => store and set value of photoname
 *			   int* sizetag => store and set value of amount 
 * 							   of nametags that user typed
 *			   char* path => store and set value of path
 *	  	       char* tag => store and set value of nametag
 *
 *  Return : NO
 *
 */
void addNewPhotoUI(HASHITEM_T* hashphoto[],char* namephoto, int * sizetag
					,char* path,char* tag[])
	{
	int i =0; 
	char confirm = 'Y';
	do
		{
		printf("------------------------------------------------\n");
		printf("\t ||Add new photo||\n");
		printf("------------------------------------------------\n");
		printf("\nPlease input the photo name");
		getNamePhoto(namephoto);
		
		while(!isunique(namephoto, hashphoto))
			{
			printf("'%s' have been already use\n",namephoto);
			getNamePhoto(namephoto);
			}
			
		printf("\nPlease input the photo path");
		getPath(path);
		printf("\nPlease input the all photo tag");
		getAllNameTag(tag,sizetag);

		printf("------------------------------------------------\n");
		printf("\tconfirm to add the photo\n");
		printf("------------------------------------------------\n");
		//display data 
		printf("\nPhoto name: %s",namephoto);
		printf("\nPhoto path: %s\n",path);
		printf("\nPhoto all of the tag: ");
		for (i = 0 ; i < *sizetag ; i++)
			printf("%s,",tag[i]);
		printf("\n");
		getCharater("Enter Y to confirm and N for no: ",&confirm);
		if(confirm != 'y' && confirm !='Y')
			printf("%s",CLEAR_ESCAPE);
		else
			printf("\nData have been added\n");
		}
	while(confirm != 'y' && confirm !='Y');

	}

/*
 * This function display user interface of search by tag 
 * and ask for tag and  ask for enter to stop.
 * Moreover, set value of tag and sizetag in output argument.
 *
 *  Argument : char* tag[] => store and set value of nametag
 * 			   int * sizetag => store and set value of amount 
 * 								of nametags that user typed 
 *
 *  Return : NO
 *
 */
void searchByTagUI(char* tag[], int * sizetag)
	{
	printf("------------------------------------------------\n");
	printf("\t ||Search by tag||\n");
	printf("------------------------------------------------\n");
	printf("\n||Please input the include tag||");
	printf("\n------------------------------------------------\n");
    getAllNameTag(tag,sizetag);
	}

/*
 * This function display user interface of 
 * search by include tag and exclude tag 
 * and ask for include tag and exclude tag 
 * and also ask for enter to stop.
 * Moreover set value of tag,sizetag,except 
 * and sizeexcept in output argument.
 * 
 *  Argument : char* tag[] => store and set value of nametag
 * 			   int * sizetag => store and set value of amount of 
 * 								nametags that user typed 
 *             char * except[] => store and set value of exclude tag
 *             int * sizeexcept => store and set value of amount of 
 * 								exclude tags that user typed
 *			
 *  Return : NO
 *
 */	
void searchConUI(char * tag[], int * sizetag, char * except[], int * sizeexcept)
{
	printf("------------------------------------------------\n");
	printf("\t ||SEARCH PHOTO BY TAG AND EXCLUDED TAG||\n");
	printf("------------------------------------------------\n");
	printf("\n||Please input the include tag||");
	getAllNameTag(tag,sizetag);
	printf("\n------------------------------------------------\n");
	printf("\n||Please input the exclude tag||");
	getAllNameTag(except,sizeexcept);
}		




/*
 * This function display user interface of find 3 similar photos
 * and ask for name of photo after that display 3 similar photos.
 * Moreover this function also store photoname.
 *
 *  Argument : char namephoto => store photoname
 *
 *  Return : NO
 *
 */
void similarUI(char  namephoto[])
{
	printf("------------------------------------------------\n");
	printf("\t||Find 3 similar photos||\n");
	printf("------------------------------------------------\n");
	printf("\n||Please name of photo to find the similar photo||");
	getNamePhoto(namephoto);
}



/*
 * This function display user interface of display 
 * on the browser
 * 
 *  Argument : char namephoto => store photoname
 *			   char* option => option browser to display
 *  Return : NO
 *
 */
void displayInBrowserUI(char namephoto[],char* option)
	{
	printf("------------------------------------------------\n");
	printf("\t||DISPLAY ON BROWSER||\n");
	printf("------------------------------------------------\n");
	printf("||Please select your browser||\n");
	printf("1 - Google Chrome\n");
	printf("2 - Microsoft Edge\n");
	printf("3 - Safari\n");
	printf("4 - Firefox\n");
	printf("5 - eog\n");
	printf("------------------------------------------------\n");
	getOption(option);
	getNamePhoto(namephoto);
	}

