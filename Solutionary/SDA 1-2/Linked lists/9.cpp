#include <time.h>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std;

void traverseList(node*);
void traverseWithLimit(node*, int);

int main(void) {
    srand(time(NULL));
    // List creation is contempled in custom header file
    int quantity = 0, moreThan = 0;
    node* list = NULL;

    cout << "Quantity: "; cin >> quantity;

    // Assuming a limit of 1000 for rand generated number
    for(int i = 0; i < quantity; i++)
        pushBack(T(rand() % 1000), &list);

    cout << "List contents" << endl;
    traverseList(list);

    cout << endl << "Value to exceed: "; cin >> moreThan;

    cout << endl << "More than " << moreThan << endl;
    traverseWithLimit(list, moreThan);

    return 0;
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

void traverseWithLimit(node* list, int moreThan) {
    if(list) {
        if(list->info.data > moreThan) {
            cout << list->info.data << endl;
        }
        traverseWithLimit(list->next, moreThan);
    }
}