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





/************************************************************
 *This Function check is the string input is all alphabhetic or not
 *
 *	@Arugment => (char* stringTocheck[])
 *
 *	@Return => (int) 1 => the string is all alphabhetic 
 *					 0 => for the string is not all alphabhetic
 ************************************************************/
int allAlpha(char stringToCheck[])
	{
	  int i = 0;   /* loop counter for looking at characters */
	  int bOk = 1; /* return value. Assume all okay until we find
			          a non-digit character */

	  /* loop through all the characters, or until we find a non-digit */
	  while(bOk && stringToCheck[i] != '\0')
	    {
	    if (!isalpha(stringToCheck[i]))
	    	bOk = 0;
	    i++;
	    }
	  return bOk;
	}

void getCharater(char* prompt, char* character)
	{
	char input[512];
	printf("\n%s", prompt);
	fgets(input,sizeof(input),stdin);
	*character = input[0];
	}

	
void getstring(char* prompt,char* string)
	{
	char input[512];
	printf("\n%s",prompt);
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%s",string);
	}


void freestring(char* ArrStr[],int ArrSize)
	{
	int i = 0;
	for(i=0;i<ArrSize;i++)
		free(ArrStr[i]);
	}

/*
 *This Function clear the screen
 *and ask of enter to go the main menu
 *	@Arugment => NO
 *
 *	@Return => NO
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
	char inputline[32];
    char option = 'A';
    printf("--------------------------------------------\n");
	printf("\t MAINMENU\n");
    printf("\t 1 - ADD TAG AND PHOTO\n");
	printf("\t 2 - SEARCH PHOTO BY TAG\n");
	printf("\t 3 - SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf("\t 4 - EXIT\n");
	printf("\t Which option do you want to choose?\n");
	printf("--------------------------------------------\n");
    
    while(isalpha(option))
        {
		getCharater("\n\tEnter your option:",&option);
        if(!isalpha(option))
            {
            *choice = option;/*set choice*/
            }
		else
			{
			printf("\tInvalid Option Please input again!");
			}
        }
    printf("%s",CLEAR_ESCAPE);
	}

void subMenuPage(char * choice)
	{
	char inputline[512];
	char option = 'A';
	char alt[512];
	printf("--------------------------------------------\n");
	printf("\t What do you want to do?\n");
    printf("\t 1 - DISPLAY ADD/DELETE TAGS\n");
	printf("\t 2 - SEARCH SIMILAR PHOTO(S)\n");
	printf("\t 3 - DISPLAY ON BROWSER\n");
	printf("\t 4 - GO TO MAIN MENU\n");
	printf("--------------------------------------------\n");
	while (!isalpha(option))
        {
        getCharater("\n\tEnter your option: ",&option);
        if (!isalpha(option))
            {
            *choice = option;/*set choice*/	
            }
		else
			{
			printf("\tInvalid Option Please input again!");
			}
        }
	}

BOOL isEnter(char str[])
	{
	BOOL flag = FALSE;

	if(strlen(str) == 0)
		{
		flag = TRUE;
		}
	return flag;
	}


void searchByTagPage(char* tag[], int * sizetag)
{
    char inputline[512];
	int count = 0;
	char nametag[TAGBUFFER] = "\0";
	BOOL flag = FALSE;
	printf("--------------------------------------------\n");
	printf("\tSearch by tag\n");
	printf("--------------------------------------------\n");
    
	while(flag == FALSE)
		{
		getstring("Enter name tag <enter to exit with no spacebar>: ",nametag);
		flag = isEnter(nametag);
		if(flag == TRUE)
			{
			break;
			}
		else
			{
			if(allAlpha(nametag))
				{
				tag[count] = strdup(nametag);
				count++;
				}
			else
				{
				printf("Invalid tag! Tag must be all alphabetic.\n");
				}
			}	
		strcpy(nametag,"\0");
		}
	*sizetag = count;	
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
	while(flag == FALSE)
		{
		getstring("Enter name tag <enter to exit with no spacebar>: ",nametag);
		flag = isEnter(nametag);
		if(flag == TRUE)
			{
			break;
			}
		else
			{
			if(allAlpha(nametag))
				{
				tag[count] = strdup(nametag);
				count++;
				}
			else
				{
				printf("Invalid tag! Tag must be all alphabetic.\n");
				}
			}	
		strcpy(nametag,"\0");
		}
	*sizetag = count;	

    count = 0; /*reset count  to zero*/
	while (flag == FALSE)
		{
		getstring("Enter exclude tag <enter to exit with no spacebar>: ",excepts);
		flag = isEnter(excepts);
		if(flag == TRUE)
			{
			break;
			}
		else
			{
			if(allAlpha(excepts))
				{
				tag[count] = strdup(excepts);
				count++;
				}
			else
				{
				printf("Invalid exclude tag! Exclude tag must be all alphabetic.\n");
				}
			}	
		strcpy(excepts,"\0");
		}
	*sizeexcept = count;		
}		

void similarPage(char  namephoto[])
{
	char inputline[PHOTOSIZE];
	char photoname[PHOTOSIZE];
	BOOL flag = FALSE;

	printf("--------------------------------------------\n");
	printf("\t Find 3 similar photos\n");
	printf("--------------------------------------------\n");
	while(flag == FALSE)
		{
		getstring("Enter name of photo <enter to exit with no spacebar>: ",photoname);
		flag = isEnter(photoname);
		if(flag == TRUE)
			{
			break;
			}
		}	
}
	
void addDeleteTagPage(char* namephoto, char* tag[], int* sizetag)
{
	char inputline[512];
	char tags[TAGBUFFER];
	char photoname[PHOTOSIZE];
	int count = 0;
	BOOL flag = FALSE;

	printf("--------------------------------------------\n");
	printf("\t Add/Delete tag\n");
	printf("--------------------------------------------\n");
	while(flag == FALSE)
		{
		getstring("Enter name of photo <enter to exit with no spacebar>: ",photoname);
		flag = isEnter(photoname);
		if(flag == TRUE)
			{
			break;
			}
		else
			{
			if(allAlpha(photoname))
				{
				tag[count] = strdup(photoname);
				count++;
				}
			else
				{
				printf("Invalid name of photo! Name of photo must be all alphabetic.\n");
				}
			}	
		strcpy(photoname,"\0");
		}
	while(flag == FALSE)
		{
		getstring("Enter tag to add <enter to finish>: ",tags);	
		flag = isEnter(tags);
		if(flag == TRUE)
			{
			break;
			}
		else
			{
			if(allAlpha(tags))
				{
				tag[count] = strdup(tags);
				count++;
				}
			else
				{
				printf("Invalid tag! Tag must be all alphabetic.\n");
				}
			}
		strcpy(tags,"\0");		
		}
	*sizetag = count;			
}

