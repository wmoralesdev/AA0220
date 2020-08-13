#include <iostream>
using namespace std;

// Using struct to define node unit
// Nodes consist of info and pointer to next element
struct node {
    int info;
    node* next;
};

// queue consists of front and back pointers to reference elements
struct queue {
    node* front,* back;
};

bool empty(queue);
void push(queue*, int);
int iterativeSize(queue);
int recursiveSize(node*);
void swap(queue*, queue*);

int main(void) {
    // Native node type
    queue q;
    q.front = q.back = NULL;

    // Checking if empty
    cout << "Empty q: " << (empty(q) ? "true" : "false") << endl;

    // To push elements complete queue mem alloc should be sent, not front, neither back
    push(&q, 1);
    push(&q, 3);
    push(&q, 5);

    // Checking size iterative and recursively
    cout << "Iterative size of q: " << iterativeSize(q) << endl;
    cout << "Recursive size of q: " << recursiveSize(q.front) << endl << endl;

    // Checking front and back
    cout << "Front: " << q.front->info << endl;
    cout << "Back: " << q.back->info << endl << endl;

    // Swap - exchanges contents fron queue1 to queue2
    queue r;
    r.front = r.back = NULL;

    push(&r, 2);
    push(&r, 4);
    push(&r, 6);

    cout << "q front before swap: " << q.front->info << endl;
    cout << "r front before swap: " << r.front->info << endl;

    swap(&q, &r);

    cout << "q front after swap: " << q.front->info << endl;
    cout << "r front after swap: " << r.front->info << endl;

    return 0;
}

// Empty function should return boolean
bool empty(queue q) {
    return q.front == NULL;
}

/*  Size can be made in two ways
        1. Receive full queue (with back and front) and iteratively count elements
        2. Receive front and recursively count elements
*/
int iterativeSize(queue q) {
    int counter = 0;
    while(q.front) {
        q.front = q.front->next;
        counter++;
    }

    return counter;
}

int recursiveSize(node* nxt) {
    return nxt ? 1 + recursiveSize(nxt->next) : 0;
}

// To alter non pointer, mem alloc needs to be sent
void push(queue* q, int info) {
    node* n = new node;

    // Info asigned to new element
    n->info = info;

    // New element nexus should point to NULL
    n->next = NULL;

    // If queue is empty, first element is front and back at the same time
    if(!q->front) {
        q->front = n;
        q->back = n;
    }
    else {
        // Queue back is new element created, after inserted it becomes back reference
        q->back->next = n;
        q->back = n;
    }
}

// Swap interchanges queue1 with queue2
void swap(queue* q, queue* r) {
    node* auxFront = q->front, *auxBack = q->back;

    q->front = r->front;
    q->back = r->back;
    
    r->front = auxFront;
    r->back = auxBack;
}