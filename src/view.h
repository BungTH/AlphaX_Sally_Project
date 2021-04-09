/***********************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 ***********************************************/



#define CLEAR_ESCAPE "\033[2J" /*use for clear the screen*/
#define CHARMAX 32 /*use in getLimitedint()*/



void displayphoto(PHOTO_T* photo,int index);

void clearscreen();

void menuPage(char* choice);

void subMenuPage(char* choice);

/**************************************************/

void addNewPhotoPage();

void searchByTagPage(char* tag[], int* sizetag);

void searchConPage(char* tag[], int* sizetag, char* except[], int* sizeexcept);

/**************************************************/

void addDeleteTagPage(char* namephoto, char* tag[], int* sizetag,int* options);

void similarPage(char  namephoto[]);

void displayBrowserPage();


/**************************************************/
