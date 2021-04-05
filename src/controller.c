/****************************************
 *
 *
 *
 *
 *
 ****************************************/
 
 #include "datastruct.h"
 #include "dtype.h"
 #include "readwrite.h"
 #include "model.h"


 
 
 

int main()
{
    PHOTO_T * pHead;
    HASHITEM_T ** hashphoto = intialHash();
    HASHITEM_T ** hashtag = intialHash();
    readData(&pHead,hashphoto,hashtag);
    writeData(pHead);
    freeAll(pHead,hashphoto,hashtag);
}
