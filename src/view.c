/*************************************
 *  
 * 
 * 
 * 
 ************************************/

#include "datastruct.h"
#include "view.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>



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

void getNametag()
{
	char inputline[256];
	int count = 0;
	int numberTag[15];		/* number of tag (Maximum:15) */

	printf("---------------------------\n");
	printf(" \n");
	printf(" WELCOME TO PHOTO SEARCH ENGINE PROGRAM!");
	printf(" \n");
	printf("...........................\n");
	while (1)
		{
		while (numberTag < 1)
			{
			printf(" Enter number of tag to search: ");
			fgets(inputline,sizeof(inputline),stdin);
			sscanf(inputline,"%d",numberTag);	
			}
		while (count > 0)
			{
			printf(" Enter tag to search: ");
			fgets(inputline,sizeof(inputline),stdin);
			sscanf(inputline,"%s",nametag);
			for (i = 0 ; i < numberTag ; i++)
				{
				if (strcmp(nametag,"\0" == 0))
					{
					printf(" ERROR! Please Enter tag.\n");
					}		
				}		
			}
		}	
}

void menuPage(char* which)
{
	char inputline[32];

    char option = 'A';
    printf("--------------------------------------------\n");
	printf(" MENU\n");
	printf(" 1 - SEARCH PHOTO BY TAG\n");
	printf(" 2 - SEARCH PHOTO BY TAG AND EXCLUDED TAG\n");
	printf(" 3 - ADD TAG AND PHOTO\n");
	printf(" Which option do you want to choose?");
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

void searchByTagPage()

