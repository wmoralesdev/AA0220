#include <iostream>
using namespace std;

struct nodeP {
    int info;
    nodeP* next;

    nodeP() { next = NULL; }
    nodeP(int _info) : info(_info) { next = NULL; }
};

struct node {
    int info;
    nodeP* stk;
    node* next;

    node() { next = NULL; stk = NULL; }
    node(int _info) : info(_info) { next = NULL; stk = NULL; }
    node(int _info, nodeP* _stk) : info(_info), stk(_stk) 
    { next = NULL; }
};

void printList(node*);
void printStack(nodeP*);
void pushFront(nodeP**, int);
void pushBack(node**, int, nodeP*);
void pushBack(nodeP** de, int info);

int main(void) {
    node* list = NULL;
    nodeP* stk = NULL;

    pushBack(&stk, 4);
    pushBack(&stk, 8);
    pushBack(&stk, 7);

    pushBack(&list, 3, stk);

    pushBack(&stk, 8);
    pushBack(&list, 6, stk);
    
    pushBack(&stk, 15);
    pushBack(&list, 9, stk);

    // lista nodo 1 --> 
    // lista nodo 2 --> 
    // lista nodo 3 --> 

    printList(list);

    return 0;
}

void pushFront(nodeP** de, int info) {
    nodeP* n = new nodeP(info);

    n->next = *de;
    *de = n;
}

void pushBack(node** de, int info, nodeP* stk) {
    node* n = new node(info, stk);

    node* aux = *de;

    if(!*de) {
        *de = n;
    }
    else {
        while (aux->next)
        aux = aux->next;
    
        aux->next = n;
    }
}

void pushBack(nodeP** de, int info) {
    nodeP* n = new nodeP(info);

    nodeP* aux = *de;

    if(!*de) {
        *de = n;
    }
    else {
        while (aux->next)
        aux = aux->next;
    
        aux->next = n;
    }
}

void printList(node* list) {
    if(list) {
        printStack(list->stk);
        cout << endl;
        printList(list->next);
    }
}

void printStack(nodeP* stack) {
    if(stack) {
        cout << stack->info << "\t";
        printStack(stack->next);
    }
}