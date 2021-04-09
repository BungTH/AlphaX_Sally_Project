

/*
 *This Function check is the string input is all alphabhetic or not
 *this function 
 *	Arugment : (char* stringTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or spacebar
 *					 0 => for the string is not all alphabhetic or spacebar
 */
int checkStr(char stringToCheck[]);

int isunique(char* namephoto,HASHITEM_T* hashphoto[]);

int isEnter(char str[]);

int checkStr(char stringToCheck[]);

int checkPathAndNamePhoto(char pathToCheck[]);

void getCharater(char* prompt, char* character);

void getOption(char* choice);

void getString(char* prompt, char* string);

void getNamePhoto(char* namephoto);

void getAllNameTag(char* tag[],int* sizetag);

void getPath(char* path);

void freestring(char* ArrStr[], int ArrSize);