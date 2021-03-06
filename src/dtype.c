/**************************************************
 *
 *  dtype.h
 *
 *	This function include all astract data type 
 *	that use in the program
 *
 *	Created By Napas 
 *		Mar 26 2021
 *************************************************/
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastruct.h"
#include "dtype.h"

/**************** HASH ADT ********************/



/*
 *  This function use create the array of linklist 
 *  or in other word hash table
 *
 *  Arugement : NO
 * 
 *  Return : array of linklist
 */
HASHITEM_T** intialHash()
	{
	return (HASHITEM_T**)calloc(BUCKET_COUNT,sizeof(HASHITEM_T*));
	}
/*
 *  This function convert key to the index of the array
 *  use as a hash function both
 *  dictionray tag and photo
 *
 *  Arugement : char* key (name key)
 * 
 *  Return    : unsigned long (index of the array)
 */
unsigned long hashfunction(char* key)
	{
	unsigned int result = 0;
	unsigned int tmp = 0;
	int size = BUCKET_COUNT;
	int i = 0;
	for (i = 0; i < strlen(key); i++)
		{
		/* shift up four bits then add in next char */ 
		result = (result << 4) + key[i];
		if (tmp = (result & 0xf0000000))  /* if high bit is set */
		    {
		    /* XOR result with down shifted tmp */
		    result = result ^ (tmp >> 24);
		    /* then XOR with tmp itself */
		    result = result ^ tmp;
		    }
		}
	 result = result % size;   /* make it fit in the table size */ 
	 return result;
	}

/*
 *  This Function insert the hash item to hashtable
 *
 *  Arugement : char* key (name key)
 *	     : PHOTO_T* item (information of the photo)
 *	     : HASHITEM_T* hash[] (hash table that going insert)
 *
 *  Return    : (int) success for 1 and 0 for fail
 */
int insertitem(char* key,PHOTO_T* item,HASHITEM_T* hash[])
	{
	unsigned int index = 0;
	HASHITEM_T* pHead = NULL;/*head linklist of*/
	HASHITEM_T* tmp = NULL;
	int bOk = 1;
	index = hashfunction(key); /*get the index of the hash*/
	pHead = hash[index]; 
	
	/*allocate the data to add to hash*/
	tmp = (HASHITEM_T*) calloc(1,sizeof(HASHITEM_T));
	if(tmp == NULL)
		bOk = 0;
	tmp->photo = item;
	tmp->next = pHead;
	
	/*set new head*/
	hash[index] = tmp;
	
	return bOk;
	}

/*
 *  This Function return the linklist of the hash in
 *  the given key
 *
 *  Arugement : char* key (name of the key)
 *	     : HASHITEM_T* hash[] (hashtable)
 *
 *  Return    : HASHITEM_T* (linklist of HASHITEM_T)
 */
HASHITEM_T* getlist(char* key,HASHITEM_T* hash[])
	{
	return hash[hashfunction(key)];
	}




/*****************sort algorithm*********************/
/*
 *  This Function insert the photo to the array and
 *  resize when the array is going to fully
 *
 * 
 *  Arugement : PHOTO_T* data       => data going to add to photo
 * 				PHOTO_T* photoarray => array of the photo we 
 * 										want to insert
 * 				int arrsize         => size of the array right now 
 *				int currentCount    => the current number of the 
 *									   item that going to have in array
 *
 *  Return    : NO
 */
int insertArray(PHOTO_T* data,PHOTO_T* photoarray[],int arrsize,int currentCount)
     {
     if(currentCount >= arrsize)
         {
         arrsize += DEFAULTSIZE;
         photoarray = realloc(photoarray,(arrsize)*sizeof(PHOTO_T*));
         }
      photoarray[currentCount] = data;
	return arrsize;
     }








