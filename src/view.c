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
	printf("\t Which option do you want to choose?");
	printf("--------------------------------------------\n");
    
    while(isalpha(option) != 0)
        {
		printf("\n\tEnter your option :");
        fgets(inputline,sizeof(inputline),stdin);
	    sscanf(inputline,"%c",&option);
        if(allAlpha(option) == 1)
            {
            *choice = option;/*set choice*/
            }
		else
			{
			printf("\tInvalid Option Please input again!\n");
            printf("\nEnter your option :");
			fgets(inputline, sizeof(inputline), stdin);
	    	sscanf(inputline, "%c", &option);
			}
        }
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
	while (isalpha(option) != 0)
        {
        printf("\n\tEnter your option :");
        fgets(inputline, sizeof(inputline), stdin);
	    sscanf(inputline, "%c", &option);
		sscanf(inputline, "%s", &alt);

        if (allAlpha(option) == 1)
            {
            *choice = option;/*set choice*/	
            }
		else
			{
			printf("\tInvalid Option Please input again!\n");
            printf("\nEnter your option :");
			fgets(inputline, sizeof(inputline), stdin);
	    	sscanf(inputline, "%c", &option);
			}
        }
	}

void searchByTagPage(char * tag[], int * sizetag)
	{
    char inputline[64];
	int count = 0;
	char tags[TAGBUFFER];
	printf("--------------------------------------------\n");
	printf("\tPlease insert Tags (Type \"DONE\" to stop)\n");
	printf("--------------------------------------------\n");
    printf("Enter the name tag: ");
	fgets(inputline, sizeof(inputline), stdin);
	sscanf(inputline, "%s", tags);
	while (strcasecmp(tags,"DONE") != 0)
		{
		if (allAlpha(tags) == 1)
			{
			strcpy(tag[count],tags);
			count++;
			}
		else
			{
			printf("\tInvalid tags Must be all alphabetic(Please insert again)\n");
			}
        printf("Enter the name tag: ");
		fgets(inputline, sizeof(inputline), stdin);
		sscanf(inputline, "%s", tags);			
		}
	*sizetag = count;		
	}
	
void searchConPage(char * tag[], int * sizetag, char * except[], int * sizeexcept)
{
	char inputline[64];
	char tags[TAGBUFFER];
	char excepts[TAGBUFFER];
    int count = 0;
	
	printf("--------------------------------------------\n");
	printf("\t Search photo dy condition\n");
	printf("--------------------------------------------\n");

	printf(" Enter tag (Type \"DONE\" to stop): ");
	fgets(inputline, sizeof(inputline), stdin);
	sscanf(inputline, "%s", tags);
	while (strcasecmp(tags,"DONE") != 0)
		{
		if (allAlpha(tags) == 1)
			{
			strcpy(tag[count],tags);
			count++;
			}
		else 
			{
			printf(" Invalid tag! Tag must be all alphabetic.");	
			}
        printf(" Enter tag (Type \"DONE\" to stop): ");
		fgets(inputline, sizeof(inputline), stdin);
		sscanf(inputline, "%s", tags);			
		}
	*sizetag = count;

    count = 0; /*reset count  to zero*/
	printf(" Enter condition (Type \"DONE\" to stop): ");
	fgets(inputline, sizeof(inputline), stdin);
	sscanf(inputline, "%s", excepts);
	while (strcasecmp(tags,"DONE") != 0)
		{
		if (allAlpha(excepts) == 1)
			{
			strcpy(excepts[count],excepts);
			count++;
			}
		else 
			{
			printf(" Invalid condition! Condition must be all alphabetic.");	
			}
        printf(" Enter condition (Type \"DONE\" to stop): ");
		fgets(inputline, sizeof(inputline), stdin);
		sscanf(inputline, "%s", excepts);			
		}
	*sizeexcept = count;		
}

void similarPage(char  namephoto[])
{
	char inputline[PHOTOSIZE];
	char photoname[PHOTOSIZE];

	printf("--------------------------------------------\n");
	printf("\t Find 3 similar photos\n");
	printf("--------------------------------------------\n");

	printf("\nEnter name of a photo: ");
	fgets(inputline,sizeof(inputline),stdin);
	sscanf(inputline,"%s", photoname);
	while (1)
		{
		if (allAlpha(photoname) == 1)
			{
            /*assign to namephoto*/
			strcpy(namephoto,photoname);
            break;
			}
		else
			{
			printf(" Invalid name of a photo! Name of a photo must be all alphabetic.");	
			}	
        printf("\nEnter name of a photo: ");    
        fgets(inputline,sizeof(inputline),stdin);
	    sscanf(inputline,"%s", photoname);
		}
}

void addDeleteTagPage(char* namephoto, char* tag[], int sizetag)
{
	char inputline[512];
	char tags[TAGBUFFER];
	char photoname[PHOTOSIZE];

	printf("--------------------------------------------\n");
	printf("\t Add/Delete tag\n");
	printf("--------------------------------------------\n");

	printf("\nEnter name of a photo: ");
	fgets(inputline,sizeof(inputline),stdin);
	sscanf(inputline,"%s", photoname);
	while (1)
		{
		if (allAlpha(photoname) == 1)
			{
            /*assign to namephoto*/
			strcpy(namephoto,photoname);
            break;
			}
		else
			{
			printf(" Invalid name of a photo! Name of a photo must be all alphabetic.");	
			}	
        printf("\nEnter name of a photo: ");    
        fgets(inputline,sizeof(inputline),stdin);
	    sscanf(inputline,"%s", photoname);
		}
	printf("\nEnter tag to add: ");
	fgets(inputline,sizeof(inputline),stdin);
	sscanf(inputline,"%s",tags);
	while (1)
		{
		fgets(inputline, sizeof(inputline), stdin);
		sscanf(inputline, "%s", tags);
		while (strcasecmp(tags,"DONE") != 0)
			{
			if (allAlpha(tags) == 1)
				{
            	/*assign to tags*/
				strcpy(tag,tags);
            	break;
				}
			else 				
				{
				printf(" Invalid tag! Tag must be all alphabetic.");	
				}
        	printf(" Enter tag (Type \"DONE\" to stop): ");
			fgets(inputline, sizeof(inputline), stdin);
			sscanf(inputline, "%s", tags);					
			}
		}
}