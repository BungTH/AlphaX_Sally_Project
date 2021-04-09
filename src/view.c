/*************************************
 *  
 * view.c 
 * 
 *      
 * 
 * 
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
 *This Function clear the screen
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



void menuPage(char* choice)
	{
    printf("--------------------------------------------\n");
	printf("\t MAINMENU\n");
    printf("\t 1 - ADD TAG AND PHOTO\n");
	printf("\t 2 - SEARCH PHOTO BY TAG\n");
	printf("\t 3 - SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf("\t 4 - EXIT\n");
	printf("\t Which option do you want to choose?\n");
	printf("--------------------------------------------\n");
    
    getOption(choice);
    printf("%s",CLEAR_ESCAPE);
	}

void subMenuPage(char * choice)
	{
	char option;
	printf("--------------------------------------------\n");
	printf("\t What do you want to do?\n");
    printf("\t 1 - DISPLAY ADD/DELETE TAGS\n");
	printf("\t 2 - SEARCH SIMILAR PHOTO(S)\n");
	printf("\t 3 - DISPLAY ON BROWSER\n");
	printf("\t 4 - GO TO MAIN MENU\n");
	printf("--------------------------------------------\n");

	getOption(choice);
	printf("%s",CLEAR_ESCAPE);
	}

void addNewPhotoPage(HASHITEM_T* hashphoto[])
	{
	printf("");
	}

void searchByTagPage(char* tag[], int * sizetag)
	{
	int count = 0;
	char nametag[TAGBUFFER] = "\0";
	BOOL flag = FALSE;
	printf("--------------------------------------------\n");
	printf("\tSearch by tag\n");
	printf("--------------------------------------------\n");
	printf("\nPlease input the include tag");
    getAllNameTag(tag,sizetag);
	}
	
void searchConPage(char * tag[], int * sizetag, char * except[], int * sizeexcept)
{
	char inputline[512];
	char nametag[TAGBUFFER];
	char excepts[TAGBUFFER];
    int count = 0;
	BOOL flag = FALSE;
	
	printf("--------------------------------------------\n");
	printf("\t Search photo dy condition\n");
	printf("--------------------------------------------\n");
	
	printf("\nPlease input the include tag");
	getAllNameTag(tag,sizetag);
	printf("\nPlease input the exclude tag");
	getAllNameTag(except,sizeexcept);
}		

void similarPage(char  namephoto[])
{
	char inputline[PHOTOSIZE];
	char photoname[PHOTOSIZE];
	BOOL flag = FALSE;

	printf("--------------------------------------------\n");
	printf("\t Find 3 similar photos\n");
	printf("--------------------------------------------\n");
	printf("\nPlease name of photo to find the similar photo");
	getNamePhoto(namephoto);
}
	
void addDeleteTagPage(char* namephoto, char* tag[], int* sizetag,int* options)
{
	char inputline[512];
	char tags[TAGBUFFER];
	char photoname[PHOTOSIZE];
	int count = 0;
	BOOL flag = FALSE;

	printf("--------------------------------------------\n");
	printf("\t Add/Delete tag\n");
	printf("--------------------------------------------\n");

	getNamePhoto(namephoto);
	getAllNameTag(tag,sizetag);	
}

