#include <iostream>
using namespace std;

struct nodeData {
    int _int;
    char _char;

    nodeData() {}
    nodeData(int _i, char _c) : _int(_i), _char(_c) {}
};
typedef nodeData T;

// Using struct to define node unit
// Nodes consist of info and pointer to next element
struct node {
    T info;
    node* next;
};

// queue consists of front and back pointers to reference elements
struct queue {
    node* front,* back;
};

void pop(queue*);
bool empty(queue);
void push(queue*, T);
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
    push(&q, T(1, 'a'));
    push(&q, T(3, 'c'));
    push(&q, T(5, 'e'));

    // Checking size iterative and recursively
    cout << "Iterative size of q: " << iterativeSize(q) << endl;
    cout << "Recursive size of q: " << recursiveSize(q.front) << endl << endl;

    // Checking front and back
    cout << "Front: " << q.front->info._int << ", " << q.front->info._char << endl;
    cout << "Back: " << q.back->info._int << ", " << q.back->info._char << endl << endl;

    // Popping last element
    pop(&q);

    // Checking new back
    cout << "Back after popping: " << q.back->info._int << ", " << q.back->info._char << endl << endl;

    // Swap - exchanges contents fron queue1 to queue2
    queue r;
    r.front = r.back = NULL;

    push(&r, T(2, 'b'));
    push(&r, T(4, 'd'));
    push(&r, T(6, 'f'));

    cout << "q front info before swap: " << q.front->info._int << ", " << q.front->info._char << endl;
    cout << "r front info before swap: " << r.front->info._int << ", " << r.front->info._char << endl << endl;

    swap(&q, &r);

    cout << "q front info after swap: " << q.front->info._int << ", " << q.front->info._char << endl;
    cout << "r front info after swap: " << r.front->info._int << ", " << r.front->info._char << endl << endl;

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
void push(queue* q, T info) {
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

void pop(queue* q) {
    node* aux = q->front;
    q->front = q->front->next;

    delete aux;
}

// Swap interchanges queue1 with queue2
void swap(queue* q, queue* r) {
    node* auxFront = q->front, *auxBack = q->back;

    q->front = r->front;
    q->back = r->back;
    
    r->front = auxFront;
    r->back = auxBack;
}