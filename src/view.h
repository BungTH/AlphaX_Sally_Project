








#define CLEAR_ESCAPE "\033[2J" /*use for clear the screen*/
#define CHARMAX 32 /*use in getLimitedint()*/


int allAlpha(char stringToCheck[]);

void getstring(char* prompt,char* string);



void clearscreen();

void menuPage(char* choice);

void subMenuPage(char * choice);

void searchByTagPage(char * tag[], int * sizetag);

void searchConPage(char * tag[], int * sizetag, char * except[], int * sizeexcept);

void similarPage(char  namephoto[]);

void displayphoto(PHOTO_T* photo,int index);
