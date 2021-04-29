/****************************************
 *controller.h
 *  
 * This file contain all handle option
 * to controll all system in This project.
 *
 * Created by Manutsawin (Sern) ID: 63070503442
 * 	   Mar 30 2021
 ****************************************/

/* 
 * 
 *  This function get all the user input, validate the input
 *  Then add new photo with new tag and path in the structure file.
 * 
 *  Argument:  PHOTO_T** pHead => head of the photo linked list. To pass argument to function addPhotoToStruct.
 * 
 * 			   HASHITEM_T* hashphoto[] => hash table of photo. Pass argument to addNewPhotoUI and addPhotoToStruct.
 * 
 * 			   HASHITEM_T* hashtag[] => hash table of tag. To pass argument to function addPhotoToStruct.
 * 
 *  return:    Non
 * 								
 */
void handleAddNewPhoto(PHOTO_T** pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);

/*
 * 
 *   This function get all the user input, validate the input
 *   then search for tags that match what user had input and print out the result.
 * 
 * 	 Argument:  HASHITEM_T* hashtag[] => hash table of tag. For pass argument to other functions.
 * 										 to find result of search.
 * 
 * 			    HASHITEM_T* hashphoto[] => hash table of photo. Pass argument to go sub-menu.
 * 
 *              int option => handle the option from the menu to choose what to do
 *                            1 - to search by tag.
 *                            2 - to search by condition.
 * 
 *   return:    Non
 * 
 */
void handleSearchOption(HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[],int option);

/* 
 * 
 *   This function get the input from user, validate the input
 * 	 Then find the similar photo.
 * 
 * 	 Argument:  HASHITEM_T* hashphoto[] => hash table of photo.
 * 										   Pass argument to other functions to find similar photo.
 * 				HASHITEM_T* hashtag[] => hash table of tag.
 * 										 Pass argument to other functions to find similar photo.
 * 
 * 	 return:    Non
 * 
 */
void handlefindSimilar(HASHITEM_T* hashphoto[],HASHITEM_T* hashtag[]);

/* 
 * 
 *   This function get the input from user, validate the input
 *   Then display photo in browser
 *	 
 *   Argument:  HASHITEM_T* hashphoto[] => hash table of photo.
 * 
 * 	 return:    Non
 * 
 */
void handleDisplayInBrowser(HASHITEM_T* hashphoto[]);

/*
 *
 *  This function print out the sub-menu for extra option
 *  add or delete tags, find similar and display photo in browser.
 *  Validate the option and show the function that option selected.
 * 
 *  Argument: HASHITEM_T* hashphoto[] => hash table of photo. Pass argument to other functions.
 * 										 For each switch case.
 * 			  HASHITEM_T* hashtag[] => hash table of tag. Pass argument to other functions.
 * 									   For each switch case.
 * 
 *  Return:   Non
 * 
 */
void handleSubMenu(HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);
