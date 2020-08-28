// Inserting in asc order is same as 1.cpp, this examples contemplates desc inserting
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h" // Push back is not used for the purpose of the excercise
using namespace std;

void traverseList(node*);
void insertElement(T, node**);

int main(void) {
    srand(time(NULL));

    node* pList = NULL;

    for(int i = 0; i < 1500; i++)
        insertElement(T(rand() % 500), &pList);

    traverseList(pList);

    return 0;
}

int getRandom(void) {
    return rand() % 1500 + 1;
}

void insertElement(T data, node** pList) {
    node* n = new node;
    n->info = data;

    if(!*pList || (*pList)->info < n->info) {
        n->next = *pList;
        *pList = n;
    }
    else {
        node* current = *pList;

        while(current->next && current->next->info > n->info)
            current = current->next;

        n->next = current->next;
        current->next = n;
    }
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.data <<  endl;
        traverseList(list->next);
    }
}