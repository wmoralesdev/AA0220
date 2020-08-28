#include <iostream>
using namespace std;

enum operation{RETIRE, DEPOSIT, QUERY, UPDATE, PAYMENT};

struct transaction {
    operation op;
    double duration;

    transaction() {}
    transaction(operation _op, double _duration) : op(_op), duration(_duration) {}
    transaction(const transaction& t) : op(t.op), duration(t.duration) {}
};

struct person{
    string name;
    transaction trans;
    int quantity;

    person() {}
    person(string _name, transaction _trans, int _quantity) 
    : name(_name), trans(_trans), quantity(_quantity) {}
};
typedef person T;

struct node{
    T info;
    node* next;
};

struct queue {
    node* front,* back;
};

int size(node*);
void push(queue*, T);
double average(queue);

const transaction ret(RETIRE, 4);
const transaction dep(RETIRE, 2);
const transaction que(QUERY, 3.5);
const transaction up(UPDATE, 5);
const transaction pay(PAYMENT, 2);

int main(void) {
    queue q;
    q.front = q.back = NULL;

    push(&q, T("Walter", ret, 2));
    push(&q, T("Enmanuel", dep, 3));
    push(&q, T("Daniela", dep, 2));
    push(&q, T("Miguel", pay, 4));
    push(&q, T("Andrea", up, 1));
    push(&q, T("Xiomara", que, 1));
    push(&q, T("Rafael", ret, 1));

    cout << "Average waiting time: " << average(q) << endl;

    return 0;
}

int size(node* q) {
    return q ? 1 + size(q->next) : 0;
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

double average(queue q) {
    double aux = 0;
    node* auxPtr = q.front;

    while(auxPtr) {
        aux += (auxPtr->info.trans.duration * auxPtr->info.quantity);
        auxPtr = auxPtr->next;
    }

    return aux / size(q.front);
}