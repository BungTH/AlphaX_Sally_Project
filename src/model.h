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



/*
 *This function find the photo with the 
 *given name and return the information 
 *about the photo 
 *
 *	Arugement : char* namephoto (name of the photo) 
 *				HASHITEM_T* hashphoto[] (hash table of photo)
 *
 *	return	  : PHOTO_T* (information about the photo)
 *			    NULL for not found
 */
PHOTO_T* findPhoto(char* namephoto,HASHITEM_T* hashphoto[]);  

/*
 *This function check the photo have all of the tag[] or
 *not if not return false and true for  the photo include 
 *with tag[]
 *
 *	Arguement : PHOTO_T* photo (information of the photo)
 *			    char* tag[]	   (array tag)
 *				int sizetag    (size of the array tag[])
 *
 *  return	  : 1 for photo have all tag[] 0 for else
 */
int checktag(PHOTO_T* photo,char* tag[],int sizetag);

/*
 *This function find the photo with the 
 *given tag[] that user given and return 
 *linklist photo result that have a all tag in tag[]
 *
 *	Arugement : char* tag[] (photo tag included) 
 *			  : int sizetag (size of array tag[])
 *			  : HASHITEM_T* hashtag[] (hash table of tag)
 *
 *	return	  : linklist of photo that have tag[] in it
 */
PHOTO_T* searchByTag(char* tag[],int sizetag,HASHITEM_T* hashtag[]); 


/*
 *This Function check the photo have a tag in tag[]
 *but not in except[] tag or not
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
int checkexcept(PHOTO_T* photo,char* tag[],int sizetag,char* except[],int sizeexcept);

/*
 *This function find the photo with the 
 *given tag[] that user given and return 
 *linklist photo result that have a all tag in tag[]
 *
 *	Arugement : char* tag[]  ( array of tag included) 
 *			    int sizetag (size of array tag)
 *				char* except[] (array of tag excluded)
 * 				int sizeexcept (sizeof array except[])
 *			    HASHITEM_T* hashtag[] (hash table of tag)
 *
 *	return	  : linklist of photo that have tag[] in it
 */
PHOTO_T* searchCondition(char* tag[],int sizetag,
						 char* except[],int sizeexcept,
						HASHITEM_T* hashtag[]);

/*
 *This function find the similar photo 
 *with the given namephoto and return 
 *the linklist of the top 3 similar
 *
 *	Arugement : char* namephoto (name of the photo)
 *			    HASHITEM_T* hashtag[] (hash table of tag[])
 *	
 *	return 	  : linklist of the result (top 3 similar photo)
 */
PHOTO_T* findSimilar(char* namephoto,HASHITEM_T* hashtag[]);

