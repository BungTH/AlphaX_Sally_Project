
/***********************************************
 *
 *getinput.c
 * 
 * 		This file contain all function 
 *		that get the input from the user
 *		and validate the input from user
 * 
 * 		Created by Thitirat[Phukan][63070503413]
 ***********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "datastruct.h"
#include "getinput.h"
#include "model.h"




/*
 *This Function check if the string input is all alphabhetic,spacebar 
 *or not 
 *
 *	Argument : (char* stringTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or spacebar
 *				   0 => for the string is not all alphabhetic or spacebar
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

/*
 *This Function check if the path input is alphabhetic or \\
 *	Argument : (char* pathTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or \\
 *				   0 => for the string is not all alphabhetic or \\
 */
int checkPathAndNamePhoto(char pathToCheck[])
	{
	int i = 0;
	int bOk = 1;

	while(bOk && pathToCheck[i] != '\0')
		{
	    if (!isalpha(pathToCheck[i]) && (pathToCheck[i] != '/') 
		&& (pathToCheck[i] != '.') && (pathToCheck[i] != '_')
		&& !(isdigit(pathToCheck[i])))
			bOk = 0;
		i++;
		}
	return bOk;
	}

/*
 *This Function check if the photo is unique or not
 * 
 *	Argument : char* namephoto => set and store value of namephoto
 *			   HASHITEM_T* hashphoto[] => hashphoto (use for check unique of the photo)
 *
 *	Return : NO
 *
 */
BOOL isunique(char* namephoto,HASHITEM_T* hashphoto[])
    {
    BOOL result  = FALSE;
    if(findPhoto(namephoto,hashphoto) == NULL)
        result  = TRUE;
    return result;
    }

/*
 *This Function check that user press enter or not
 * 
 *	Argument : char str[] => string
 *
 *	Return : NO
 *
 */
BOOL isEnter(char str[])
	{
	BOOL flag = FALSE;

	if(strlen(str) == 0)
		{
		flag = TRUE;
		}
	return flag;
	}

/*
 *This Function get input of character 
 * 
 *	Argument : char* prompt => text to display
 *             char* character =>store and set value of character
 *
 *	Return : NO
 *
 */
void getCharater(char* prompt, char* character)
	{
	char input[512];
	printf("\n%s", prompt);
	fgets(input,sizeof(input),stdin);
	*character = input[0];
	}

/*
 *This Function get input of option with validation
 * 
 *	Argument : char* choice => store and set value of choice
 *
 *	Return : NO
 *
 */
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

/*
 *This Function get input of string 
 * 
 *	Argument : char* prompt => text to display
 *             char* string =>store and set value of string
 *
 *	Return : NO
 *
 */	
void getString(char* prompt,char* string)
	{
	char input[512];
	printf("\n%s",prompt);
	fgets(input,sizeof(input),stdin);
	input[strlen(input)-1] = '\0';
	strcpy(string,input);
	}

/*
 *This Function get input of name of photo 
 *and check if it is all alphabhetic or spacebar or . or /
 *and asking the name photo until it valid
 * 
 *	Argument : char* namephoto => set and store value of namephoto
 *
 *	Return : NO
 *
 */	
void getNamePhoto(char* namephoto)
	{
	BOOL flag = FALSE;
	while(flag == FALSE)
		{
		getString("Enter name photo :",namephoto);
		flag = checkPathAndNamePhoto(namephoto);
		if(flag == TRUE)
			break;
		else
			printf("Invalid Path! Path must be only A-Z,'.','/',0-9\n");
		strcpy(namephoto,"\0");
		}
	}

/*
 *This Function get input of nametag
 *until user press enter with validation.
 * 
 *	Argument : char* tag[] => set and store value of tag
 *             int* sizetag => store and set value of amount 
 * 							   of nametags that user typed
 *
 *	Return : NO
 *
 */	
void getAllNameTag(char* tag[],int* sizetag)
	{
	int count = 0;
	char nametag[TAGBUFFER] = "\0";
	BOOL flag = FALSE;
    
	while(flag == FALSE)
		{
		getString("Enter name tag one by one <press ENTER to exit> : ",nametag);
		flag = isEnter(nametag);
		if(flag == TRUE)
			break;
		else if(count == 20)
			{
			printf("The max 20 tag for each photo");
			break;
			}
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

/*
 *This Function get input of path
 *with path validation
 * 
 *	Argument : char* path => set and store value of path
 *
 *	Return : NO
 *
 */	
void getPath(char* path)
	{
	BOOL flag = FALSE;
	while(flag == FALSE)
		{
		getString("Enter path :",path);
		flag = checkPathAndNamePhoto(path) && (access(path, F_OK) == 0);
		if(flag == TRUE)
			break;
		else
			printf("Invalid Path! Path must be only A-Z,'.',_,'/'.\n");
		strcpy(path,"\0");
		}
	}

/*
 *This Function free string in array of string
 * 
 *	Argument : char* ArrStr[] => array of string to free data 
 *			   int ArrSize => size of Arrsize[]
 *
 *	Return : NO
 *
 */
void freestring(char* ArrStr[],int ArrSize)
	{
	int i = 0;
	for(i=0;i<ArrSize;i++)
		free(ArrStr[i]);
	}