#include <iostream>
using namespace std;

struct nodeData {
    int data;

    nodeData() {}
    nodeData(int _data): data(_data) {}
};
typedef nodeData T;

struct node {
    T info;
    node* next;
};

int multiply (node*);
void pushBack(T, node**);

int main(void) {
    node* list = NULL;

    pushBack(T(3), &list);
    pushBack(T(5), &list);
    pushBack(T(7), &list);
    pushBack(T(8), &list);

    cout << multiply(list) << endl;

    return 0;
}

int multiply (node* l) {
    return l != NULL ? l->info.data * multiply(l->next) : 1;
}

void pushBack(T info, node** list) {
    node* n = (node*)malloc(sizeof(node));
    n->info = info;
    n->next = NULL;

    if(!*list){
        *list = n;
    }
    else {
        node* aux = *list;

        while(aux->next)
            aux = aux->next;
        
        aux->next = n;
    }
}