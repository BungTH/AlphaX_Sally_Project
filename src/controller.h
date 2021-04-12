








/**************************************************************************/
void handleAddNewPhoto(PHOTO_T** pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);

void handleSearchByTag(HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[]);

void handleSearchCondition(HASHITEM_T* hashtag[],HASHITEM_T* hashphoto[]);
/**************************************************************************/
void handleDisplayInBroswer(HASHITEM_T* hashphoto[]);

void handlefindSimilar();
/**************************************************************************/
void handlemainmenu(PHOTO_T* pHead, HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);

void handleSubMenu(HASHITEM_T* hashphoto[], HASHITEM_T* hashtag[]);
