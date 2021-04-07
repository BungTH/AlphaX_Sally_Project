/*************************************
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



void menuPage(char* which)
{
	char inputline[32];

    char option = 'A';
    printf("--------------------------------------------\n");
	printf("\t MENU\n");
    printf("\t 1 - ADD TAG AND PHOTO\n");
	printf("\t 2 - SEARCH PHOTO BY TAG\n");
	printf("\t 3 - SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf("\t 4 - EXIT\n");
	printf("\t Which option do you want to choose?\n");
	printf("--------------------------------------------\n");
    
    while(isalpha(option))
        {
        fgets(inputline,sizeof(inputline),stdin);
	    sscanf(inputline,"%c",&option);
        if(isalpha(option))
            {
            printf("Invalid - ..."); 
            }
        }
    *which = option;/*set which*/
	
}

void searchByTagPage(char * tag[], int * sizetag)
	{
    char inputline[32];
	int count = 0;
	char tags[TAGBUFFER];
	
	while(1)
		{
		printf("--------------------------------------------\n");
		printf("\tPlease insert Tags (Type \"DONE\" to stop)\n");
    	printf("--------------------------------------------\n");
		fget(inputline, sizeof(inputline), stdin);
		sscanf(inputline, "%s", tags);
    	while (strcasecmp(tags,"DONE") != 0)
			{
			len = strlen(tags);
			for (int i = 0; i < len; i++)
				{
				if (isalpha(tags[i]) == 0)
				}
			}
		}
	}
void search