#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void push(int, node**);
void traverseStack(node*);
void replace(int, int, node**);

int main(void) {
    node* stk = NULL;

    for(int i = 0; i < 10; i++) {
        push(rand() % 5, &stk);
    }

    traverseStack(stk);
    replace(9, 2, &stk);
    traverseStack(stk);

    return 0;
}

void push(int data, node** stk) {
    node*n = new node;
    n->data = data;

    n->next = *stk;
    *stk = n;
}

// Recursive
void replace(int n, int o, node** stk) {
    if(*stk) {
        if((*stk)->data == o)
            (*stk)->data = n;
        replace(n, o, &(*stk)->next);
    }
}

// TraverseStack used only to verify mod content
void traverseStack(node* stk) {
    if(stk) {
        cout << stk->data << "  ";
        traverseStack(stk->next);
    }
    else {
        cout << endl;
    }
}