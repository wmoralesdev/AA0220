#include <iostream>
#include "LinkedList.h"
using namespace std;

int multiply (node*);

int main(void) {
    node* list = NULL;

    pushBack(T(3), &list);
    pushBack(T(5), &list);
    pushBack(T(7), &list);
    pushBack(T(8), &list);

    cout << "Calculated: " << multiply(list) << endl;

    return 0;
}

int multiply (node* l) {
    return l != NULL ? l->info.data * multiply(l->next) : 1;
}