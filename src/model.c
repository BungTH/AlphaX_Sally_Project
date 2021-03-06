/*****************************************
 *
 *  model.h
 *
 *	This file contain function handling s
 *	search for photo(s) that user want 
 *	,list three most similar photos 
 *	and Add a new photo with new tags
 *
 *	Created by Fang
 *		Mar 28 2020
 *****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastruct.h"
#include "dtype.h"
#include "model.h"


/*
 *  This function find the photo with the 
 *  given name and return the information 
 *  about the photo
 *
 *	Arugement : char* namephoto (name of the photo) 
 *				HASHITEM_T* hashphoto[] data structure for 
 *				searching photo with the input namephoto
 *
 *	Return	  : PHOTO_T* (information about the photo)
 *				NULL for not found
 */
PHOTO_T* findPhoto(char* namephoto,HASHITEM_T* hashphoto[])
	{
	HASHITEM_T* tmp = NULL;
	PHOTO_T* result = NULL; /*result of solution*/

	tmp = getlist(namephoto,hashphoto);

	while(tmp != NULL)
		{
		if(strcasecmp(tmp->photo->namephoto,namephoto) == 0)
			{
			result = tmp->photo;
			break;
			}
		tmp = tmp->next;
		}
	return result;
	} 

/*
 *  This function check the photo have all of the tag[] or
 *  not if not return false and true for  the photo include 
 *  with tag[]
 *
 *	Arguement : PHOTO_T* photo (information of the photo)
 *			    char* tag[]	   (array tag)
 *				int sizetag    (size of the array tag[])
 *
 *  Return	  : 1 for photo have all tag[] 0 for else
 */
int checktag(PHOTO_T* photo,char* tag[],int sizetag)
	{
	int count = 0; 
	int i = 0;/*use for loop*/

	LIST_TAG_T* tmp = photo->alltag;/*linklist of all tag*/

	while(tmp != NULL)
		{ 
		for(i = 0;i<sizetag;i++)
			if(strcasecmp(tmp->nametag,tag[i]) == 0)
				count++;
		tmp = tmp->next;
		}
	
	/*if sizetag == count mean photo include all tag[]*/
	return  sizetag == count;
	}

/*
 *  This function find the photo with the 
 *  given tag[] that user given and return 
 *  linklist photo result that have a all tag in tag[]
 *
 *	Arugement : char* tag[] (photo tag included) 
 *			  : int sizetag (size of array tag[])
 *			  : HASHITEM_T* hashtag[] (hash table of tag)
 *
 *	Return	  : linklist of photo that have tag[] in it
 */
PHOTO_T* searchByTag(char* tag[],int sizetag,HASHITEM_T* hashtag[])
	{
	HASHITEM_T* tmp = NULL;
	PHOTO_T* listresult = NULL;
	PHOTO_T* tmpstate = NULL;/*use to reset the state value of the listresult*/
	int i = 0;
	
	for(i = 0;i<sizetag;i++)
		{
		/*go to each tag*/
		tmp = getlist(tag[i],hashtag);
		while(tmp != NULL)
			{
			/*check if the photo haven't been in listresult*/
			if(!(tmp->photo->state))
				{
				/*if the photo include all of the tag */
				if(checktag(tmp->photo,tag,sizetag))
					{
					/*add the photo to the head of listresult*/
					tmp->photo->state = 1;/*set state to already in listresult*/
					if(listresult == NULL)
						tmp->photo->nextResult = NULL;/*set tail to NULL*/
					else 
						tmp->photo->nextResult = listresult;
					listresult = tmp->photo;
					}
				}
			tmp = tmp->next;
			}
		}
	/*loop listresult set all state to 0 (for next search use)*/
	tmpstate = listresult;
	while(tmpstate != NULL)
		{
		tmpstate->state = 0;
		tmpstate = tmpstate->nextResult;	
		}

	return listresult;
	}
/*
 *  This Function check the photo have a tag in tag[]
 *  but not in except[] tag or not
 * 
 * 
 *  Arguement : PHOTO_T* photo (information of the photo) 
 * 				char* tag[] (array of tag include)
 * 				int sizetag (array sizeof tag[])
 * 				char* except[] (array of tag exclude)
 * 				int sizeexcept (array sizeof except[]) 
 * 
 *  Return :  TRUE if the photo have all tag in tag[] and
 * 			  not have any tag in except[]
 * 
 * 			  otherwise FALSE				
 * 
 */
int checkexcept(PHOTO_T* photo,char* tag[],int sizetag,char* except[],int sizeexcept)
	{
	int countexcept = 0; 
	int i = 0;/*use for loop*/

	LIST_TAG_T* tmp = photo->alltag;/*linklist of all tag*/

	while(tmp != NULL)
		{ 
		for(i = 0;i<sizeexcept;i++)
			if(strcasecmp(tmp->nametag,except[i]) == 0)
				countexcept++;
		tmp = tmp->next;
		}
	return checktag(photo,tag,sizetag) && (countexcept == 0) ;
	}
/*
 *  This function find the photo with the 
 *  given tag[] that user given and return 
 *  linklist photo result that have a all tag in tag[]
 *
 *	Arugement : char* tag[]  ( array of tag included) 
 *			    int sizetag (size of array tag)
 *				char* except[] (array of tag excluded)
 * 				int sizeexcept (sizeof array except[])
 *			    HASHITEM_T* hashtag[] (hash table of tag)
 *
 *	Return	  : linklist of photo that have tag[] in it
 */
PHOTO_T* searchCondition(char* tag[],int sizetag,
						 char* except[],int sizeexcept,
						HASHITEM_T* hashtag[])
	{
	HASHITEM_T* tmp = NULL;
	PHOTO_T* listresult = NULL;
	PHOTO_T* tmpstate = NULL;/*use to reset the state value of the listresult*/
	int i = 0;
	
	for(i = 0;i<sizetag;i++)
		{
		/*go to each tag*/
		tmp = getlist(tag[i],hashtag);
		while(tmp != NULL)
			{
			/*check if the photo haven't been in listresult*/
			if(!(tmp->photo->state))
				{
				/*if the photo include all of the tag but not in except*/
				if(checkexcept(tmp->photo,tag,sizetag,except,sizeexcept))
					{
					/*add the photo to the head of listresult*/
					tmp->photo->state = 1;/*set state to already in listresult*/
					if(listresult == NULL)
						tmp->photo->nextResult = NULL;/*set tail to NULL*/
					else 
						tmp->photo->nextResult = listresult;
					listresult = tmp->photo;
					}
				}
			tmp = tmp->next;
			}
		}
	/*loop listresult set all state to 0 (for next search use)*/
	tmpstate = listresult;
	while(tmpstate != NULL)
		{
		tmpstate->state = 0;
		tmpstate = tmpstate->nextResult;	
		}

	return listresult;
	}

/*
 *  This function calculate the each photo
 *  similiar with the given alltag
 * 
 * 
 * 	Arguement : LIST_TAG_T* alltag (linklist of alltag of photo 
 * 				we want to find similiar)
 * 
 * 				PHOTO_T* photo photo we want to calculate the similiar
 *   
 * 	Return 	  : NO
 */
void calculateSimiliar(LIST_TAG_T* alltag,PHOTO_T* photo)
	{
	LIST_TAG_T* tmp = alltag;
	LIST_TAG_T* alltagphoto = photo->alltag;
	LIST_TAG_T* tmpphototag = alltagphoto;
	while(tmpphototag != NULL)
		{
		while(tmp != NULL)
			{
			if(strcasecmp(tmp->nametag,tmpphototag->nametag) == 0)
				photo->count++;
			tmp = tmp->next;
			}
		tmp = alltag;
		tmpphototag = tmpphototag->next;
		}
	}
/*
 *  This Function is use in function qsort 
 *  use to compare the priority of two item
 * 
 *  Arguement : const void *p => first photo for compare priority 
 * 			    const void *q => second photo for compare priority
 * 
 * 	Return    : the different of two priority
 */
int comparator(const void *p, const void *q)
	{
	PHOTO_T* l = *(PHOTO_T**)p;
    PHOTO_T* r = *(PHOTO_T**)q;
    return (l->count - r->count);
	}

/*
 *  This function find the similar photo 
 *  with the given namephoto and return 
 *  Array of the sorted photo
 *
 *	Arugement : char* namephoto (name of the photo that user want to find similar)
 *				int*  numresult (output argument of the number of result)
 *			    HASHITEM_T* hashtag[] (hash table of tag[])
 *				=>use for get linklist of photo that have that 
 *				tag
 *				HASHITEM_T* hashphoto[](hash photo)
 *				use for find all tag of the photo
 *	
 *	Return 	  : Array of sorted photo
 */
PHOTO_T** findSimilar(char* namephoto,int *numresult,HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[])
	{
	PHOTO_T* photo =  findPhoto(namephoto,hashphoto);
	/*get alltag of the photo*/
	LIST_TAG_T* alltag = photo->alltag;
	LIST_TAG_T* tmptag = alltag;
	HASHITEM_T* tmphash = NULL; 
	PHOTO_T* tmpstate = NULL;/*use to reset the state value of the listresult*/

	PHOTO_T** arraysort = calloc(DEFAULTSIZE,sizeof(PHOTO_T*));
	int count = 0;
	int arraysize = DEFAULTSIZE;
	int i = 0;

	if(photo != NULL)
		{/*go to all tag that photo have*/
		while(tmptag != NULL)
			{/*get the linklist of the hash[nametag]*/
			tmphash = getlist(tmptag->nametag,hashtag);
			while(tmphash != NULL)
				{/*if the photo is not already in arraysort and not photo that user input*/

				if(!(tmphash->photo->state)&& tmphash->photo != photo)
					{/*calculate the similiar and add to arraysort*/
					calculateSimiliar(alltag,tmphash->photo);
					arraysize = insertArray(tmphash->photo,arraysort,arraysize,count);
					tmphash->photo->state = 1;/*already in array*/
					count++; 
					}
				tmphash = tmphash->next;/*go to next photo linklist*/
				}
			tmptag = tmptag->next;/*go to next hash key*/
			}
		}
	
	qsort(arraysort,count,sizeof(PHOTO_T*),comparator);
	/*set the numberresult */
	*numresult = count; 
	return arraysort;
	}

