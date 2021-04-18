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
 *  Argument:  PHOTO_T** pHead => head of the photo linked list.
 * 			   HASHITEM_T* hashphoto[] => hash photo.
 * 			   HASHITEM_T* hashtag[] => hash tag.
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
 * 	 Argument:  HASHITEM_T* hashtag[]
 * 			    HASHITEM_T* hashphoto[]	
 * 
 *   return:    Non
 * 
 */
void handleSearchByTag(HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[]);

/* 
 *
 *   This function get the input from user, validate the input
 *   Then search with the conditions and print out the result.
 * 
 *   Argument: HASHITEM_T* hashtag[]
 * 			   HASHITEM_T* hashphoto[]
 * 				
 *   return:   Non
 * 
 */
void handleSearchCondition(HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[]);

/* 
 * 
 *   This function get the input from user, validate the input
 * 	 Then find the similar photo.
 * 
 * 	 Argument:  HASHITEM_T* hashphoto[] => hash photo.
 * 				HASHITEM_T* hashtag[] => hash tag.
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
 *   Argument:  HASHITEM_T* hashphoto[] => hash photo.
 * 
 * 	 return:    Non
 * 
 */
void handleDisplayInBrowser(HASHITEM_T* hashphoto[]);

/* 
 *
 *  This function print out the menu page, and option from user input(from UI), validate the option
 *  and show the selected option what user want to do.
 * 
 *  Argument: PHOTO_T* pHead
 *            HASHITEM_T* hashphoto[]
 *            HASHITEM_T* hashtag[]
 * 
 *  return:   Non
 * 
 */
void handlemainmenu(PHOTO_T* pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);

/*
 *
 *  This function print out the sub-menu for extra option
 *  add or delete tags, find similar and display photo in browser.
 *  Validate the option and show the function that option selected.
 * 
 *  Argument: HASHITEM_T* hashphoto[]
 * 			 HASHITEM_T* hashtag[]
 * 
 *  Return:   Non
 * 
 */
void handleSubMenu(HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);
