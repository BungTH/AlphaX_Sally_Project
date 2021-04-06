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
PHOTO_T* findPhoto(char* namephoto,HASHITEM_T* hashphoto[]);  

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
int checktag(PHOTO_T* photo,char* tag[],int sizetag);

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
PHOTO_T* searchByTag(char* tag[],int sizetag,HASHITEM_T* hashtag[]); 

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
void checkexcept(PHOTO_T* photo,char* except[],int sizeexcept);
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
						HASHITEM_T* hashtag[]); 

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
			,char* tag[],int sizetag);
/************************************************************
 *This function delete the tag to the photo
 *
 *	Arguement : char* namephoto (name of the photo to add tag)
 *				char* tag[] (array of the tag to delete)
 *				
 *	return    : NO
 ************************************************************/
void deleteTag(char* namephoto,HASHITEM_T* hashphoto[],HASHITEM_T* hashtag[],char* tag[]);