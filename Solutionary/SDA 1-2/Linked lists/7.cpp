#include <iostream>
#include "LinkedList.h"
using namespace std;

T getAt(int, node*);

int main(void) {
    int pos = 0;
    node* list = NULL;

    pushBack(T(3), &list);
    pushBack(T(5), &list);
    pushBack(T(7), &list);
    pushBack(T(8), &list);

    cout << "Pos: "; cin >> pos;

    try {
        T e = getAt(pos, list);
        cout << e.data << endl;
    }
    catch(...) {
        cout << "Invalid position" << endl;
    }

    return 0;
}

T getAt(int pos, node* list) {
    if(list) {
        if(pos == 0) {
            return list->info;
        }
        else
            return getAt(pos - 1, list->next);
    }
    else {
        throw exception();
    }
}