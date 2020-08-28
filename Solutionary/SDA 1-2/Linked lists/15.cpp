#include <time.h>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std;

void traverseList(node*);

int main(void) {
    node* list = NULL, *oddsList = NULL;

    // Filling with random
    for(int i = 0; i < 400; i++)
        pushBack(T(rand() % 300), &list);

    auto transfer = [](node* origin, node** destiny) {
        while(origin) {
            if(origin->info.data % 2 != 0)
                pushBack(origin->info, destiny);
            origin = origin->next;
        }
    };

    transfer(list, &oddsList);
    traverseList(oddsList);

    return 0;
}


void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}