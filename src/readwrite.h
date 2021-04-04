/******************************************************************
 *
 *   readwrite.h
 *
 *   This file include all function
 *   that used in readwrite.c
 *
 *   Created By Bung
 *       3 April 2021 - Initially create readwrite.h
 * 
 *   Modified By Bung
 *       4 April 2021 - Added necessary comment and function
 * 
 ******************************************************************/

#define ALLTAG 512
#define BUFFER 512

/******************************************************************
 * 
 *  This function will read the data from the data base file
 *  then initialized the data structure required in the program
 *  and other necessary elements
 *
 *	Arugement : PHOTO_T ** pHead (data structure of master list)
 *              HASHITEM_T * hashphoto[] (hash table of photo)
 *              HASHITEM_T * hashtag[] (hash table of tag)
 *
 *	return	  : None
 *
 ******************************************************************/
void readData(PHOTO_T ** pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[]);

/******************************************************************
 * 
 *  This function will write the data into the output file
 *  that will be used in the other module or function in
 *  the program
 *
 *	Arugement : PHOTO_T * pHead (data structure of master list)
 *
 *	return	  : None
 *
 ******************************************************************/
void writeData(PHOTO_T * pHead);

/******************************************************************
 * 
 *  This function will free all the used memory allocated to
 *  the data structure and linked list
 *
 *	Arugement : PHOTO_T * pHead (data structure of master list)
 *				HASHITEM_T * hashphoto[] (hash table of photo)
 *              HASHITEM_T * hashtag[] (hash table of tag)
 *
 *	return	  : None
 *
 ******************************************************************/
void freeAll(PHOTO_T * pHead, HASHITEM_T * hashphoto[], HASHITEM_T * hashtag[]);