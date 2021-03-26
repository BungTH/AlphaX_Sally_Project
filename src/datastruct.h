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
 **************************************/
#define BUCKET_COUNT 997

typedef struct _listtag
	{
	/*linklist of tags*/
	char* nametag; /*name of the tag*/
	struct _listtag *next;
	}LIST_TAG_T;

typedef struct _photo
	{
	char namephoto[256];/*name of the photo*/
	char path[512];/*path of photo*/
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
