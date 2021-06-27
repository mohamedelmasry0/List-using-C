#include "List.h"
#include <stdlib.h>
/*---------------------------------*/
/*void cmp (int e1,int e2)
{
    strcmp (int e1,int e2)
    return;
}

compFun c = &cmp;
void (*c)(int) = &cmp;
/*---------------------------------


List*	newList	(compFun comp,prFun pr){

if ( strcmp( e1, e2 ) == 0 ) {
        printf( "You are connected\n" );
    } else {
        printf( "Login failed. Retry later.\n" );
    }


return ;
}
*/

int compFun(void* e1, void* e2) {
    int val1 = *(int*) e1;
    int val2 = *(int*) e2;

    return val1 - val2;
}
/**************************/
void prFun(void* List){
    if (List==NULL){
        printf("The list is empty \n");
        return;
    }
    while(List !=NULL) {
        printf("[%d]", List->val);
        List = List->next;
    }
}

List* newList(compFun comp, prFun pr) {
    List *newList = malloc(sizeof(List));

    if (newList == NULL) return 0;

    newList->comp = comp;
    newList->pr = pr;
    newList->nelts = 0;

    return newList;
}

void delList(List* l) {
    if (l == NULL) return;

    free(l);

    return;
}

status 	addListAt(List* l, int n, void* e) {
    Node* nthNode = l->head;

    for(int i=0; i < n; i++) {

        if (nthNode == NULL)
            return message(ERRINDEX);

        nthNode = nthNode->next;
    }

    if (nthNode == NULL)
        return message(ERRINDEX);

    e = nthNode->val;

    return message(OK);
}
