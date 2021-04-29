/**************************************************
 *
 *dtype.h
 *
 *	This function include all abstract data type 
 *	including hash and sorting algorithm
 *  that use in the program
 *
 *	Created By Napas 
 *		Mar 26 2021
 *************************************************/



/**************** HASH ADT ********************/



/**********************************************
 *This function use create the array of linklist 
 *or in other word hash table
 *
 * Arugement : NO
 * Return : array of linklist
 **********************************************/
HASHITEM_T** intialHash();

/****************************************************
 *This function convert key to the index of the array
 *use as a hash function both
 *dictionray tag and photo
 *
 * Arugement : char* key (name key)
 * Return    : unsigned long (index of the array)
 ****************************************************/
unsigned long hashfunction(char* key);

/***************************************************
 *This Function insert the hash item to hashtable
 *
 * Arugement : char* key (name key)
 *	     : PHOTO_T* item (information of the photo)
 *	     : HASHITEM_T* hash[] (hash table)
 *
 * Return    : (int) success for 1 and 0 for fail
 ******************************************************/
int insertitem(char* key,PHOTO_T* item,HASHITEM_T* hash[]);

/******************************************************
 *This Function return the linklist of the hash in
 *the given key
 *
 * Arugement : char* key (name of the key)
 *	     : HASHITEM_T* hash[] (hashtable)
 *
 * Return    : HASHITEM_T* (linklist of HASHITEM_T)
 ******************************************************/
HASHITEM_T* getlist(char* key,HASHITEM_T* hash[]);

/******************************************************
 *This Function free all the data in the hash
 *
 * Arugement : HASHITEM_T* hash[] (hashtable)
 *
 * Return    : NO
 *****************************************************/
void freeHash(HASHITEM_T* hash[]);

 


/*****************sort algorithm*********************/


int insertArray(PHOTO_T* data,PHOTO_T* photoarray[],int arrsize,int currentCount);



