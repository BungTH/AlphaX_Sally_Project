/***********************************************
 *
 * getinput.h
 * 
 * 		This file contain all function 
 *		that get the input from the user
 *		and validate the input from user
 * 
 * 		Created by Thitirat[Phukan][63070503413]
 ***********************************************/

/*
 *This Function check is the string input is all alphabhetic or not
 *this function 
 *	Arugment : (char* stringTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or spacebar
 *					 0 => for the string is not all alphabhetic or spacebar
 */
int checkStr(char stringToCheck[]);

/*
 *This Function check if the path input is alphabhetic or \\
 *	Argument : (char* pathTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or \\
 *				   0 => for the string is not all alphabhetic or \\
 */
int checkPathAndNamePhoto(char pathToCheck[]);

/*
 *This Function check if the photo is unique or not
 * 
 *	Argument : char* namephoto => set and store value of namephoto
 *			   HASHITEM_T* hashphoto[] => hashphoto (use for check unique of the photo)
 *
 *	Return : NO
 *
 */
int isunique(char* namephoto,HASHITEM_T* hashphoto[]);

/*
 *This Function check that user press enter or not
 * 
 *	Argument : char str[] => string
 *
 *	Return : NO
 *
 */
int isEnter(char str[]);

/*
 *This Function get input of character 
 * 
 *	Argument : char* prompt => text to display
 *             char* character =>store and set value of character
 *
 *	Return : NO
 *
 */
void getCharater(char* prompt, char* character);

/*
 *This Function get input of option with validation
 * 
 *	Argument : char* choice => store and set value of choice
 *
 *	Return : NO
 *
 */
void getOption(char* choice);

/*
 *This Function get input of string 
 * 
 *	Argument : char* prompt => text to display
 *             char* string =>store and set value of string
 *
 *	Return : NO
 *
 */	
void getString(char* prompt, char* string);

/*
 *This Function get input of name of photo 
 *and check if it is all alphabhetic or spacebar or . or /
 *and asking the name photo until it valid
 * 
 *	Argument : char* namephoto => set and store value of namephoto
 *
 *	Return : NO
 *
 */	
void getNamePhoto(char* namephoto);

/*
 *This Function get input of nametag
 *until user press enter with validation.
 * 
 *	Argument : char* tag[] => set and store value of tag
 *             int* sizetag => store and set value of amount 
 * 							   of nametags that user typed
 *
 *	Return : NO
 *
 */	
void getAllNameTag(char* tag[],int* sizetag);

/*
 *This Function get input of path
 *with path validation
 * 
 *	Argument : char* path => set and store value of path
 *
 *	Return : NO
 *
 */	
void getPath(char* path);

/*
 *This Function free string in array of string
 * 
 *	Argument : char* ArrStr[] => array of string to free data 
 *			   int ArrSize => size of Arrsize[]
 *
 *	Return : NO
 *
 */
void freestring(char* ArrStr[], int ArrSize);