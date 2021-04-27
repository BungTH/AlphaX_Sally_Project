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
 *   		   int index =>  index number of photo
 *
 *	Return : NO
 *
 */
void displayphoto(PHOTO_T* photo,int index)
	{
	LIST_TAG_T* alltag = photo->alltag; /*get all tag of the photo(as a head of linklist)*/
	LIST_TAG_T* tmp = NULL;
	printf("\n-----------------------\n");
	printf("No. %d",index+1);
	printf("\n-----------------------\n");
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
	printf("\n-----------------------\n");
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
void menuPage(char* choice)
	{
    printf("\n--------------------------------------------\n");
	printf("\t MAINMENU\n");
    printf("\t 1 - ADD NEW PHOTO WITH NEW TAGS\n");
	printf("\t 2 - SEARCH PHOTO BY TAG\n");
	printf("\t 3 - SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf("\t 4 - EXIT\n");
	printf("\t Which option do you want to choose?\n");
	printf("--------------------------------------------\n");
    
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
void subMenuPage(char * choice)
	{
	printf("\n--------------------------------------------\n");
	printf("\t What do you want to do?\n");
	printf("\t 1 - SEARCH SIMILAR PHOTO(S)\n");
	printf("\t 2 - DISPLAY ON BROWSER\n");
	printf("\t 3 - GO TO MAIN MENU\n");
	printf("--------------------------------------------\n");

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
void addNewPhotoPage(HASHITEM_T* hashphoto[],char* namephoto, int * sizetag
					,char* path,char* tag[])
	{
	printf("--------------------------------------------\n");
	printf("\tAdd new photo\n");
	printf("--------------------------------------------\n");
	
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
void searchByTagPage(char* tag[], int * sizetag)
	{
	printf("--------------------------------------------\n");
	printf("\tSearch by tag\n");
	printf("--------------------------------------------\n");
	printf("\nPlease input the include tag");
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
void searchConPage(char * tag[], int * sizetag, char * except[], int * sizeexcept)
{
	printf("--------------------------------------------\n");
	printf("\t SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf("--------------------------------------------\n");
	printf("\nPlease input the include tag");
	getAllNameTag(tag,sizetag);
	printf("\n--------------------------------------------\n");
	printf("\nPlease input the exclude tag");
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
void similarPage(char  namephoto[])
{
	printf("--------------------------------------------\n");
	printf("\t Find 3 similar photos\n");
	printf("--------------------------------------------\n");
	printf("\nPlease name of photo to find the similar photo");
	getNamePhoto(namephoto);
}



/*
 * This function display user interface of display 
 * on the browser
 * 
 *  Argument : char namephoto => store photoname
 *
 *  Return : NO
 *
 */
void displayInBrowserPage(char namephoto[])
	{
	printf("--------------------------------------------\n");
	printf("\t DISPLAY ON BROWSER\n");
	printf("--------------------------------------------\n");
	getNamePhoto(namephoto);
	}

