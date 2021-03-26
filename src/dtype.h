/********************************** 
 *
 *dtype.h
 *
 *	This function include all
 *	astract data type that use 
 *	in the program
 *********************************/


/**************** Linklist ADT *****************/

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
