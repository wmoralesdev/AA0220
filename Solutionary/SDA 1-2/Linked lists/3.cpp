#include <iostream>
#include "LinkedList.h"
using namespace std;

char empty(node* list);

int main(void) {
    node* list = NULL;

    pushBack(T(3), &list);
    pushBack(T(5), &list);
    pushBack(T(7), &list);
    pushBack(T(8), &list);

    auto empty = [](node* list) {
    // 0 implies emptyness
        return list == NULL ? '0' : '*';
    };

    cout << "Empty: " << empty(list) << endl;

    return 0;
}