#include <iostream>
using namespace std;

struct node {
    int info;
    node* next,* prev;

    node() { next = prev = NULL; }
    node(int _info) : info(_info) { next = prev = NULL; }
};

struct dl {
    node* front,* back;

    dl() { front = back = NULL; }
};

void pushFront(int info, dl* d);
void createBeginToEnd(dl* create, dl source);
void createEndToBegin(dl* create, dl source);

int main(void) {
    // Creates double linked with front insertion (there's no restriction about it)
    dl d;
    int aux = 0;

    cout << "N (Ctrl + D to end input): ";
    while(cin >> aux) {
        pushFront(aux, &d);
        cout << "N (Ctrl + D to end input): ";
    }

    dl beginToEnd, endToBegin;

    createBeginToEnd(&beginToEnd, d);
    createEndToBegin(&endToBegin, d);

    return 0;
}

void pushFront(int info, dl* d) {
    node* n = new node(info);

    if(!d->front)
        d->front = d->back = n;
    else {
        d->front->prev = n;
        n->next = d->front;
        d->front = n;
    }
}

void createBeginToEnd(dl* create, dl source) {
    // Creates list traveling back as front insertion is considered
    while(source.back) {
        pushFront(source.back->info, create);
        source.back = source.back->prev;
    }
}

void createEndToBegin(dl* create, dl source) {
    // Creates list traveling front as front insertion is considered
    while(source.front) {
        pushFront(source.front->info, create);
        source.front = source.front->next;
    }
}