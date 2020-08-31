#include <iostream>
using namespace std;

struct nodeData {
    int _int;
    

    nodeData() {}
    nodeData(int _i) : _int(_i) {}
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
void printStk(node *);
void Invert(queue * );

int main(void) {
    // Native node type
    queue q;
    q.front = q.back = NULL;

    // Checking if empty
    cout << "Empty q: " << (empty(q) ? "true" : "false") << endl;

    // To push elements complete queue mem alloc should be sent, not front, neither back
    push(&q, T(4));
    push(&q, T(3));
    push(&q, T(2));

    printStk(q.front);
    cout << endl;

    cout << "Cola invertida: " <<endl ;
    Invert(&q);

    return 0;
}

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
void Invert(queue * cola){
    node* actual = cola->front;
    node * anterior = NULL;
    node* sig = actual ? actual->next : NULL;
    cola->back = cola->front;
    node * aux = NULL;
    while(actual){
        actual->next = anterior;
        anterior = actual;
        actual = sig;
        sig = actual ? actual->next: NULL;
    }
    cola->front = anterior;
    aux= cola->front;
    printStk(aux);
}


void printStk(node *q){
    if(q){
        cout << q->info._int << " ";
        printStk(q->next);
        
    }
}
bool empty(queue q) {
    return q.front == NULL;
}