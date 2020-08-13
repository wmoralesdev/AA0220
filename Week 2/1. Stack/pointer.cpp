#include <iostream>
using namespace std;

// Using struct to define node unit
// Nodes consists of info and pointer to next element
struct node {
    int info;
    node* next;
};

// Using typedef for easy management
typedef node* st;

bool empty(node*);
bool emptySt(st);

int size(node*);
int sizeSt(node*);

void push(node**, int);
void pushSt(st*, int);

node* top(node*);
st topSt(st);

void swap(node**, node**);
void swapSt(st*, st*);

int main(void) {
    // Native node type
    node* s = NULL;

    // Typedef stack - not initialized to demonstrate garbage values error
    st ss;

    // Checking if empty
    cout << "Empty s: " << (empty(s) ? "true" : "false") << endl;
    cout << "Empty ss: " << (empty(ss) ? "true" : "false") << endl << endl;

    // Init ss to fix error
    ss = NULL;

    // Rechecking emptyness
    cout << "Empty ss: " << (empty(ss) ? "true" : "false") << endl << endl;

    // To push elements at node* type, double pointer should be sent
    // or mem allocation of pointer
    push(&s, 1);
    push(&s, 3);
    push(&s, 5);

    // To push elements at typedef, double pointer is expected
    // st is already pointer so mem alloc is sent
    push(&ss, 2);
    push(&ss, 4);
    push(&ss, 6);

    // Checking size of each
    cout << "Size of s: " << size(s) << endl;
    cout << "Size of ss: " << size(ss) << endl << endl  ;

    // Using top to access at element
    cout << "Top of s with node*: " << top(s)->info << endl;
    cout << "Top of ss with typedef: " << top(ss)->info << endl << endl;

    // Instantiating stacks to swap
    node* swap1 = NULL, *swap2 = NULL;
    push(&swap1, 5);
    push(&swap1, 7);

    push(&swap2, 4);
    push(&swap2, 6);

    cout << "Top before swap at swap1: " << top(swap1)->info << endl;
    cout << "Top before swap at swap2: " << top(swap2)->info << endl << endl;

    swap(&swap1, &swap2);

    cout << "Top after swap at swap1: " << top(swap1)->info << endl;
    cout << "Top after swap at swap2: " << top(swap2)->info << endl << endl;

    st st1 = NULL, st2 = NULL;

    push(&st1, 11);
    push(&st2, 13);

    push(&st1, 12);
    push(&st2, 14);

    cout << "Top before swap at st1: " << top(st1)->info << endl;
    cout << "Top before swap at st2: " << top(st2)->info << endl << endl;

    swap(&st1, &st2);

    cout << "Top after swap at st1: " << top(st1)->info << endl;
    cout << "Top after swap at st2: " << top(st2)->info << endl << endl;

    return 0;
}

// Empty function should return boolean
bool empty(node* s) {
    return s == NULL;
}

bool emptySt(st s) {
    return s == NULL;
}

// Size should peek every element and return a integer indicating how many were found
// implements recursion with stack - 1 element
int size(node* s) {
    return s ? 1 + size(s->next) : 0;
}

int sizeSt(st s) {
    return s ? 1 + size(s->next) : 0;
}

// To alter pointer type, a double pointer reference needs to be sent
void push(node** s, int info) {
    node* n = new node;

    // Info asigned to new element
    n->info = info;

    // New element nexus should point towards stack top
    n->next = *s;

    // Stack should correspond to new element
    *s = n;
}

// Using typedef as pointer, equals to double pointer for definition
void pushSt(st* s, int info) {
    st n = new node;

    // Same as previous overload
    n->info = info;
    n->next = *s;
    *s = n;
}

// Top returns reference to node at top position, existing nexus should be ignored
// therefore a new node with next as NULL should be returned
node* top(node* s) {
    node* n = new node;
    n->info = s->info;
    n->next = NULL;

    return n;
}

// Same as previous function
st topSt(st s) {
    st n = new node;
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

void swapSt(st* s, st* ss) {
    st aux = *s;

    // Uses * notation because mem allocation contained should be changed, not direct mem address
    s = ss;
    *ss = aux;
}