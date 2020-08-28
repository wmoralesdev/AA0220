#include <time.h>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h" // Push back is not used for the purpose of the excercise
using namespace std;

int getRandom(void);
void traverseList(node*);

template <class e>
void insertElement(e, node**);
void transferElements(node*, node**);

int main(void) {
    srand(time(NULL));

    node* pList = NULL, *pList2 = NULL;

    for(int i = 0; i < 1500; i++)
        insertElement(T(getRandom()), &pList);

    cout << "Every element: " << endl;
    traverseList(pList);

    transferElements(pList, &pList2);

    cout << "Less than 100: " << endl;
    traverseList(pList2);

    return 0;
}

int getRandom(void) {
    return rand() % 1500 + 1;
}

template <class e>
void insertElement(e data, node** pList) {
    node* n = new node;
    n->info = data;

    if(!*pList || (*pList)->info >= n->info) {
        n->next = *pList;
        *pList = n;
    }
    else {
        node* current = *pList;

        while(current->next && current->next->info < n->info)
            current = current->next;

        n->next = current->next;
        current->next = n;
    }
}

void transferElements(node* origin, node** dest) {
    if(origin) {
        if(origin->info.data < 100) {
            node* n = new node;
            n->info = origin->info;
            n->next = NULL;

            if(!*dest)
                *dest = n;
            else {
                node* aux = *dest;
                while(aux->next)
                    aux = aux->next;

                aux->next = n;
            }
        }
        transferElements(origin->next, dest);
    }
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.data <<  endl;
        traverseList(list->next);
    }
}