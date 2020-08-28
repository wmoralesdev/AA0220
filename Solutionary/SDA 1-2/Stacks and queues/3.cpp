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
    int n = 0;

    cout << "Number: "; cin >> n;

    while(n > 0) {
        push(n % 10, &stk);
        n /= 10;
    }
    
    traverseStack(stk);

    return 0;
}

void push(int data, node** stk) {
    node*n = new node;
    n->data = data;

    n->next = *stk;
    *stk = n;
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