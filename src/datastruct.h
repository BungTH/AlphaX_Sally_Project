/**************************************
 *
 *datastruct.h
 *
 *	this file contain the data structure 
 *	All use in the program
 *
 *	Created By Fang
 *		Mar 26 2021
 *
 *  Modified by Bung (to prevent HASHTAG error)
 * 		April 3 2021
 **************************************/
#define BUCKET_COUNT 997
#define PHOTOSIZE 256
#define PATHSIZE 512
#define TAGBUFFER 32

typedef struct _listtag
	{
	/*linklist of tags*/
	char nametag[TAGBUFFER]; /*name of the tag*/
	struct _listtag *next;
	}LIST_TAG_T;

typedef struct _photo
	{
	char namephoto[PHOTOSIZE];/*name of the photo*/
	char path[PATHSIZE];/*path of photo*/
	int numtag; /*number of the tag*/
	int count; /*use for calculate the similar*/
	int state; /*use as a flag of calculation
	,use in search tag and find similar
	Block duplicate in list result
	true => already be the result of the search
	False => not already the result of the search*/
	LIST_TAG_T *alltag; /*list of all tag*/
	struct _photo *nextResult;/*use for search return as a list*/
	struct _photo *next;/*next photo (use in masterlist)*/
	}PHOTO_T;
	
typedef struct _hashitem
	{
	PHOTO_T* photo;
	struct _hashitem *next;
	}HASHITEM_T;




