
/*
 *
 *
 * 
 * 
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "datastruct.h"
#include "getinput.h"
#include "model.h"




/*
 *This Function check is the string input is all alphabhetic or not
 *this function 
 *	Arugment : (char* stringTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or spacebar
 *					 0 => for the string is not all alphabhetic or spacebar
 */
int checkStr(char stringToCheck[])
	{
	  int i = 0;   /* loop counter for looking at characters */
	  int bOk = 1; /* return value. Assume all okay until we find
			          a non-digit character */

	  /* loop through all the characters, or until we find a non-digit */
	  while(bOk && stringToCheck[i] != '\0')
	    {
	    if (!isalpha(stringToCheck[i]) && stringToCheck[i] != ' ')
	    	bOk = 0;
	    i++;
	    }
	  return bOk;
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

BOOL isunique(char* namephoto,HASHITEM_T* hashphoto[])
    {
    BOOL result  = FALSE;
    if(findPhoto(namephoto,hashphoto) == NULL)
        result  = TRUE;
    return result;
    }


void getCharater(char* prompt, char* character)
	{
	char input[512];
	printf("\n%s", prompt);
	fgets(input,sizeof(input),stdin);
	*character = input[0];
	}



void getOption(char* choice)
	{
	char option = 'A';
	while (isalpha(option))
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

	
void getstring(char* prompt,char* string)
	{
	char input[512];
	printf("\n%s",prompt);
	fgets(input,sizeof(input),stdin);
	input[strlen(input)-1] = '\0';
	strcpy(string,input);
	}

void getNamePhoto(char* namephoto)
	{
	BOOL flag = FALSE;
	while(flag == FALSE)
		{
		getstring("Enter name photo :",namephoto);
		flag = checkStr(namephoto);
		if(flag == TRUE)
			break;
		else
			printf("Invalid tag! Tag must be all alphabetic or space.\n");
		strcpy(namephoto,"\0");
		}
	}

void getAllNameTag(char* tag[],int* sizetag)
	{
	int count = 0;
	char nametag[TAGBUFFER] = "\0";
	BOOL flag = FALSE;
    
	while(flag == FALSE)
		{
		getstring("Enter name tag <enter to exit with no spacebar>: ",nametag);
		flag = isEnter(nametag);
		if(flag == TRUE)
			break;
		else if(checkStr(nametag))
			{
			tag[count] = strdup(nametag);
			count++;
			}
		else
			printf("Invalid tag! Tag must be all alphabetic or space.\n");	
		strcpy(nametag,"\0");
		}
	*sizetag = count;
	}	

void freestring(char* ArrStr[],int ArrSize)
	{
	int i = 0;
	for(i=0;i<ArrSize;i++)
		free(ArrStr[i]);
	}