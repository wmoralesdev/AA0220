#include <iostream>
using namespace std;

struct node{
    string data;
    node* next;
};

void push(string, node**);
void traverseStack(node*);

int main(void) {
    string aux = "";
    node* stk = NULL;
    
    cout << "Enter a phrase (Press enter to add, Ctrl + D to stop input): ";

    while(cin >> aux) {
        push(aux, &stk);
    }

    traverseStack(stk);

    return 0;
}

void push(string data, node** stk) {
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