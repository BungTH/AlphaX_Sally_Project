

/*
 *This Function check is the string input is all alphabhetic or not
 *this function 
 *	Arugment : (char* stringTocheck[])
 *
 *	Return : (int) 1 => the string is all alphabhetic or spacebar
 *					 0 => for the string is not all alphabhetic or spacebar
 */
int checkStr(char stringToCheck[]);

int isEnter(char str[]);

int checkStr(char stringToCheck[]);

void getCharater(char* prompt, char* character);

void getOption(char* choice);

void getstring(char* prompt, char* string);

void getNamePhoto(char* namephoto);

void getAllNameTag(char* tag[],int* sizetag);

void freestring(char* ArrStr[], int ArrSize);