/*******************************************
 *
 *
 *model.h
 *
 *	This file contain function handling s
 *	search for photo(s) that user want 
 *	,list three most similar photos 
 *	and Add a new photo with new tags
 *
 *	Created by Fang
 *		Mar 28 2020
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastruct.h"
#include "dtype.h"
#include "model.h"



/************************************************************
 *This function find the photo with the 
 *given name and return the information 
 *about the photo 
 *
 *	Arugement : char* namephoto (name of the photo) 
 *				HASHITEM_T* hashphoto[] (hash table of photo)
 *
 *	return	  : PHOTO_T* (information about the photo)
 				NULL for not found
 ************************************************************/
PHOTO_T* findPhoto(char* namephoto,HASHITEM_T* hashphoto[])
	{
	HASHITEM_T* tmp = NULL;
	PHOTO_T* result = NULL; /*result of solution*/

	tmp = getlist(namephoto,hashphoto);

	while(tmp != NULL)
		{
		if(strcmp(tmp->photo->namephoto,namephoto) == 0)
			{
			result = tmp->photo;
			break;
			}
		tmp = tmp->next;
		}
	return result;
	} 

/************************************************************
 *This function check the photo have all of the tag[] or
 *not if not return false and true for  the photo include 
 *with tag[]
 *
 *	Arguement : PHOTO_T* photo (information of the photo)
 *			    char* tag[]	   (array tag)
 *
 *  return	  : 1 for photo have all tag[] 0 for else
 ************************************************************/
int checktag(PHOTO_T* photo,char* tag[],int sizetag)
	{
	int count = 0; 
	int i = 0;/*use for loop*/

	LIST_TAG_T* tmp = photo->alltag;/*linklist of all tag*/

	while(tmp != NULL)
		{ 
		for(i = 0;i<sizetag;i++)
			if(strcmp(tmp->nametag,tag[i]) == 0)
				count++;
		tmp = tmp->next;
		}
	/*if sizetag == count mean photo include all tag[]*/
	return  sizetag == count;
	}

/************************************************************
 *This function find the photo with the 
 *given tag[] that user given and return 
 *linklist photo result that have a all tag in tag[]
 *
 *	Arugement : char* tag[] (photo tag included) 
 *			  : HASHITEM_T* hashtag[] (hash table of tag)
 *
 *	return	  : linklist of photo that have tag[] in it
 ************************************************************/
PHOTO_T* searchByTag(char* tag[],int sizetag,HASHITEM_T* hashtag[])
	{
	HASHITEM_T* tmp = NULL;
	PHOTO_T* listresult = NULL;
	PHOTO_T* tmpstate = NULL;
	int i = 0;
	//int sizetag = sizeof(tag)/sizeof(char*);

	
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
/************************************************************
 *This function delete the photo from the linklist that  
 *have tag in except[] !!!!! this function look forward check
 *photo->nextResult and delete the next item not the photo
 *
 *	Arguement : PHOTO_T* photo (linklist of result)
 *			    char* except[]	   (except tag)
 *
 *  return	  : NO
 ************************************************************/
void checkexcept(PHOTO_T* photo,char* except[],int sizeexcept)
	{
	/*get head linklist of alltag next photo*/
	LIST_TAG_T* nextphototag = photo->nextResult->alltag;

	LIST_TAG_T* tmptag = nextphototag;

	PHOTO_T* tmpphoto = NULL;

	//int sizetag = sizeof(except)/sizeof(char*);

	int i = 0;

	while(tmptag != NULL)
		{ 
		for(i = 0;i<sizeexcept;i++)
			{
			if(strcmp(tmptag->nametag,except[i]) == 0)
				{
				/*delete photo->nextResult and connect new photo*/
				tmpphoto = photo->nextResult;
				photo->nextResult = photo->nextResult->nextResult;
				tmpphoto->nextResult = NULL;
				}
			}
		tmptag = tmptag->next;
		}
	}
/************************************************************
 *This function find the photo with the 
 *given tag[] that user given and return 
 *linklist photo result that have a all tag in tag[]
 *but not exclude all except[]
 *
 *	Arugement : char* tag[] (photo tag included) 
 *			    char* except[] (photo not include)	
 *			    HASHITEM_T* hashtag[] (hash table of tag)
 *
 *	return	  : linklist of photo that have tag[] and excluded 
 *				except[] in it
 ************************************************************/
PHOTO_T* searchCondition(char* tag[],char* except[],
						int sizetag,int sizeexcpet,
						HASHITEM_T* hashtag[])
	{
	int i = 0;
	PHOTO_T* listresult = NULL;
	PHOTO_T* tmp = NULL;	
	LIST_TAG_T* alltag = NULL;
	listresult = searchByTag(tag,sizetag,hashtag);

	//int sizeexcept = sizeof(except)/sizeof(char*);
	/*loop the list*/
	tmp  = listresult;
	while(tmp != NULL)
		{
		if(tmp  == listresult)/*if tmp is head*/
			{
				printf("Hello");
				/*checktag*/
				LIST_TAG_T* alltag =  tmp->alltag;/*get all tag*/
				//if()

			}
		else/*if not head*/
			{
			checkexcept(tmp,except,sizeexcpet);
			}	
		tmp = tmp->nextResult;
		}
	return listresult;
	}

/************************************************************
 *This function find the similar photo 
 *with the given namephoto and return 
 *the linklist of the top 3 similar
 *
 *	Arugement : char* namephoto (name of the photo)
 *			    HASHITEM_T* hashtag[] (hash table of tag[])
 *	
 *	return 	  : linklist of the result (top 3 similar photo)
 ************************************************************/
PHOTO_T* findSimilar(char* namephoto,HASHITEM_T* hashtag[]);

/************************************************************
 *This function add the tag to the photo
 *
 *	Arguement : char* namephoto (name of the photo to add tag)
 *				char* tag[] (array of the tag to add)
 *				
 *	return    : NO
 ************************************************************/
void addTag(char* namephoto,
			HASHITEM_T* hashphoto[],HASHITEM_T* hashtag[]
			,char* tag[],int sizetag)
	{
	PHOTO_T* photo = findPhoto(namephoto,hashphoto);/*get the photo*/
	LIST_TAG_T* alltag = NULL;/*alltag of the photo*/
	LIST_TAG_T* addtag = NULL;/*tag that going to add*/

	alltag = photo->alltag;/*get head linklist of all tag*/
	int i=0;

	photo->numtag += sizetag;

	for(i=0;i<sizetag;i++)
		{

		addtag = (LIST_TAG_T*)calloc(1,sizeof(LIST_TAG_T));
		strcpy(addtag->nametag,tag[i]);

		/*add to photo*/
		addtag->next = alltag;
		alltag = addtag;

		/*add to hashtag*/
		insertitem(tag[i],photo,hashtag);

		}
	}
/************************************************************
 *This function delete the tag to the photo
 *
 *	Arguement : char* namephoto (name of the photo to add tag)
 *				char* tag[] (array of the tag to delete)
 *				
 *	return    : NO
 ************************************************************/
void deleteTag(char* namephoto,HASHITEM_T* hashphoto[],HASHITEM_T* hashtag[],char* tag[])
	{
	PHOTO_T* photo = findPhoto(namephoto,hashphoto);/*get the photo*/
	LIST_TAG_T* alltag = NULL;/*alltag of the photo*/
	LIST_TAG_T* tmp = NULL;
	//int sizetag = sizeof(tag)/sizeof(char*);

	alltag = photo->alltag;/*get head linklist of all tag*/

	tmp = alltag;
	while(tmp != NULL)
		{
		//if()
		printf("Hello");	
		}
	

	/*delete out of hashtag*/

	}