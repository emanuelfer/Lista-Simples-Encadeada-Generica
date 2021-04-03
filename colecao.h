#ifndef COLECAO_H_INCLUDED
#define COLECAO_H_INCLUDED


typedef struct _collection_{
    void *data;
    struct _colecao_ *next;
}SLNode;



typedef struct _SLList_{
    SLNode *first;
    SLNode *cur;
}SLList;


SLList *create();
int destroy(SLList *l);
int colInsertFirst(SLList *l, void *item);
void *query(SLList *l, void *key, int(*cmp)(void *,void *));
void *colRemove(SLList *l, void *key, int(*cmp)(void*, void*));
void *getFirst(SLList *l);
void *getNext(SLList *l);


#endif // COLECAO_H_INCLUDED
