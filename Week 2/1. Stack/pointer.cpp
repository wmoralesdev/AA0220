#include <iostream>
using namespace std;

struct nodeData{
    int _int;
    char _char;

    nodeData() {}
    nodeData(int _i, char _c) : _int(_i), _char(_c) {}
};
typedef nodeData T;

// Using struct to define node unit
// Nodes consists of info and pointer to next element
struct node {
    T info;
    node* next;
};

int size(node*);
node* top(node*);
void pop(node**);
bool empty(node*);
void push(node**, T);
void swap(node**, node**);

int main(void) {
    // Native node type
    node* s = NULL;

    // Checking if empty
    cout << "Empty s: " << (empty(s) ? "true" : "false") << endl << endl;

    // To push elements at node* type, double pointer should be sent
    // or mem allocation of pointer
    push(&s, T(1, 'a'));
    push(&s, T(3, 'c'));
    push(&s, T(5, 'e'));

    // Checking size of stack
    cout << "Size of s: " << size(s) << endl << endl;

    // Using top to access at element - saving reference
    node* topInfo = top(s);
    cout << "Top of s: " << topInfo->info._int << ", " << topInfo->info._char << endl << endl;

    // Deleting with pop
    pop(&s);

    // Checking new top
    topInfo = top(s);
    cout << "Top of s after deletion: " << topInfo->info._int << ", " << topInfo->info._char << endl << endl;

    // Instantiating stacks to swap
    node* swap1 = NULL, *swap2 = NULL;
    push(&swap1, T(5, 'e'));
    push(&swap1, T(7, 'g'));

    push(&swap2, T(4, 'd'));
    push(&swap2, T(6, 'f'));

    topInfo = top(swap1);
    cout << "Top before swap at swap1: " << topInfo->info._int << ", " << topInfo->info._char << endl;
    
    topInfo = top(swap2);
    cout << "Top before swap at swap2: " << topInfo->info._int << ", " << topInfo->info._char << endl << endl;

    swap(&swap1, &swap2);

    topInfo = top(swap1);
    cout << "Top after swap at swap1: " << topInfo->info._int << ", " << topInfo->info._char << endl;
    
    topInfo = top(swap2);
    cout << "Top after swap at swap2: " << topInfo->info._int << ", " << topInfo->info._char << endl << endl;

    return 0;
}

// Empty function should return boolean
bool empty(node* s) {
    return s == NULL;
}

// Size should peek every element and return a integer indicating how many were found
// implements recursion with stack - 1 element
int size(node* s) {
    return s ? 1 + size(s->next) : 0;
}

// To alter pointer type, a double pointer reference needs to be sent
void push(node** s, T info) {
    node* n = new node;

    // Info asigned to new element
    n->info = info;

    // New element nexus should point towards stack top
    n->next = *s;

    // Stack should correspond to new element
    *s = n;
}

// Pop deletes top node
void pop(node** s) {
    node* aux = *s;
    *s = (*s)->next;

    delete aux;
}

// Top returns reference to node at top position, existing nexus should be ignored
// therefore a new node with next as NULL should be returned
node* top(node* s) {
    node* n = new node;
    n->info = s->info;
    n->next = NULL;

    return n;
}

// Swap interchanges stack1 with stack2
void swap(node** s, node** ss) {
    node* aux = *s;

    // Uses * notation because mem allocation contained should be changed, not direct mem address
    *s = *ss;
    *ss = aux;
}