#include <iostream>
#include "LinkedList.h"
using namespace std;

void traverseList(node*);
node* insertionSort(node*);

int main(void) {
    srand(time(NULL));
    node* list = NULL;

    // Assuming 50 elements per list
    for(int i = 0; i < 50; i++)
        pushBack(T(rand() % 1000), &list);

    list = insertionSort(list);
    traverseList(list);

    return 0;
}

node* insertionSort(node* list) {
    if (!list || !list->next)
        return list;

    node* aux = NULL;

    while (list != NULL) {
        node* current = list;
        list = list->next;

        if (aux == NULL || current->info < aux->info) {
            current->next = aux;
            aux = current;
        } 
        else {
            node* aux2 = aux;

            while (aux2 != NULL) {
                if (aux2->next == NULL || current->info < aux2->next->info) {
                    current->next = aux2->next;
                    aux2->next = current;
                    break;
                }
                aux2 = aux2->next;
            }
        }
    }

    return aux;
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}