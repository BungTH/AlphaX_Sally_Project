/*************************************
 *  
 * view.c
 *  
 * 		This file contain all function that display 
 *      the user interface and receive the data as 
 * 		a output arguement.   
 * 
 * 		Created by Thitirat[Phukan][63070503413]
 * 
 ************************************/



#define CLEAR_ESCAPE "\033[2J" /*use for clear the screen*/





/*
 *  This Function clear the screen
 *  and ask of enter to go the main menu
 *
 *	Arugment : NO
 *
 *	Return : NO
 *
 */
void clearscreen();

/*
 *  This function display photo and information
 *  of photo on the screen.
 *
 *	Arugment : PHOTO_T* photo => all data of photo 
 *   		   
 *
 *	Return : NO
 *
 */
void displayphoto(PHOTO_T* photo);

/*
 *  This function will display main menu on the screen
 *  and ask for option that user want to choose. 
 *  Moreover, set value of choice.
 * 
 *  Argument : char* choice => store option
 
 *  Return : NO
 *
 */
void menuUI(char* choice);

/*
 *  This function display submenu on the screen
 *  and ask for option that user want to choose.
 *  Moreover, set value of choice.
 * 
 *  Argument : char* choice => store option
 *
 *  Return : NO
 *
 */
void subMenuUI(char* choice);

/**************************************************/
/*
 *  This function display user interface of add new photo 
 *  and ask for name of photo,path and tag.
 *  Moreover, set value of namephoto,sizetag,path and tag.
 * 
 *  Argument : HASHITEM_T* hashphoto[] => hashphoto (use for check unique of the photo)
 *			   char* namephoto => store and set value of photoname
 *			   int* sizetag => store and set value of amount 
 * 							   of nametags that user typed
 *			   char* path => store and set value of path
 *	  	       char* tag => store and set value of nametag
 *
 *  Return : NO
 *
 */
void addNewPhotoUI(HASHITEM_T* hashphoto[],char* namephoto, int * sizetag
					,char* path,char* tag[]);

/*
 *  This function display user interface of search by tag 
 *  and ask for tag and  ask for enter to stop.
 *  Moreover, set value of tag and sizetag in output argument.
 *
 *  Argument : char* tag[] => store and set value of nametag
 * 			   int * sizetag => store and set value of amount 
 * 								of nametags that user typed 
 *
 *  Return : NO
 *
 */
void searchByTagUI(char* tag[], int* sizetag);

/*
 *  This function display user interface of 
 *  search by include tag and exclude tag 
 *  and ask for include tag and exclude tag 
 *  and also ask for enter to stop.
 *  Moreover set value of tag,sizetag,except 
 *  and sizeexcept in output argument.
 * 
 *  Argument : char* tag[] => store and set value of nametag
 * 			   int * sizetag => store and set value of amount of 
 * 								nametags that user typed 
 *             char * except[] => store and set value of exclude tag
 *             int * sizeexcept => store and set value of amount of 
 * 								exclude tags that user typed
 *			
 *  Return : NO
 *
 */	
void searchConUI(char* tag[], int* sizetag, char* except[], int* sizeexcept);

/**************************************************/





/*
 *  This function display user interface of find 3 similar photos
 *  and ask for name of photo after that display 3 similar photos.
 *  Moreover this function also store photoname.
 *
 *  Argument : char namephoto => store photoname
 *
 *  Return : NO
 *
 */
 void similarUI(char  namephoto[]);


/*
 *  This function display user interface of display 
 *  on the browser
 * 
 *  Argument : char namephoto => store photoname
 *			   char* option => option browser to display
 *  Return : NO
 *
 */
void displayInBrowserUI(char namephoto[],char* option);


/**************************************************/
