#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
};

void alterInfo(node* list);
void push(int info, node** list);

int main(void) {
    node* list = NULL;
    push(4, &list);

    cout << list->info << endl;
    alterInfo(list);

    cout << list->info << endl;

    return 0;
}

void push(int info, node** list) {
    node* n = new node;
    n->info = info;
    n->next = NULL;

    n->next = *list;
    *list = n;
}

void alterInfo(node* list) {
    list->info = 20;
}