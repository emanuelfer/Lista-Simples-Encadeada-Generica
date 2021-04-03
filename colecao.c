#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

SLList *create(){
    SLList *l;
    l = (SLList*)malloc(sizeof(SLList));
    if(l != NULL){
        l->first = NULL;
        l->cur = l->first;
        return l;
    }

    return NULL;
}

int destroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return 1;
        }
    }
    return 0;
}

int colInsertFirst(SLList *l, void *item){
    SLNode *node;
    if(l != NULL){
        node = (SLNode*)malloc(sizeof(SLNode));
        node->data = item;
        if(l->first == NULL){
            node->next = NULL;
        }else{
            node->next = l->first;
        }
        l->first = node;
        return 1;
    }
    return 0;
}

void *query(SLList *l, void *key, int(*cmp)(void *,void *)){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *aux = l->first;
            while(aux->next != NULL && cmp(key,aux->data) != 1){
                aux = aux->next;
            }
            if(cmp(key, aux->data) == 1){
                return aux->data;
            }
        }
    }
    return NULL;
}

void *colRemove(SLList *l, void *key, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l->first != NULL){
            void *data;
            SLNode *cur = l->first, *prev = NULL;
            while(cur->next != NULL && cmp(key, cur->data)!= 1){
                prev = cur;
                cur = cur->next;
            }
            if(cmp(key, cur->data) == 1){
                data = cur->data;
                if(prev == NULL){
                    l->first = cur->next;
                }else{
                    prev->next = cur->next;
                }
                free(cur);
                return data;
            }
        }
    }

    return NULL;
}

void *getFirst(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            l->cur = l->first;
            return l->first->data;
        }
    }
    return NULL;
}

void *getNext(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *node = l->cur->next;
            if(node != NULL){
                l->cur = l->cur->next;
                return node->data;
            }
        }
    }
    return NULL;
}










