#include <iostream>
using namespace std;

typedef struct nodeData {
    int i;
    char c;

    nodeData() {}
    nodeData(int _i, char _c) : i(_i), c(_c) {}

    bool operator==(const nodeData& rhs) {
        return this->i == rhs.i && this->c == rhs.c;
    }
} T;

struct node {
    T info;
    node* next;
};

int size(node*);
bool empty(node*);
int remove(T, node**);
void travelList(node*);
void pushBack(T, node**);
void pushFront(T, node**);
void pushAt(int, T, node**);
bool removeFirst(T, node**);
bool removeAt(int, int, node**);

template <class Predicative>
int removeIf(Predicative pr, node** list);

int main(void) {
    // List containing pointer
    node* pStart = NULL;

    // Checking list emptyness
    cout << "List is empty: " << (empty(pStart) ? "true" : "false") << endl << endl;

    // Pushing elements at list end
    pushBack(T(5, 'e'), &pStart);
    pushBack(T(6, 'f'), &pStart);
    pushBack(T(7, 'g'), &pStart);
    cout << "List after pushing elements to back" << endl;
    travelList(pStart);
    
    // Pushing element at list front
    pushFront(T(3, 'c'), &pStart);
    pushFront(T(2, 'b'), &pStart);
    pushFront(T(1, 'a'), &pStart);
    cout << "List after pushing elements to front" << endl;
    travelList(pStart);

    // Checking list size
    cout << "Size of list: " << size(pStart) << endl << endl;

    // Pushing elements at given position
    pushAt(0, T(0, '*'), &pStart);
    pushAt(4, T(4, 'd'), &pStart);
    pushAt(8, T(8, 'h'), &pStart);
    cout << "List after pushing elements to given pos" << endl;
    travelList(pStart);
    
    // Deleting elements
    cout << "Deleting 4 with removeFirst: " << (removeFirst(T(4, 'd'), &pStart) ? "true" : "false") << endl;
    cout << "New list:\t";
    travelList(pStart);

    cout << "Deleting 0 with remove: " << remove(T(0, '*'), &pStart) << endl;
    cout << "New list:\t";
    travelList(pStart);

    cout << "Deleting odds with removeIf: " << removeIf([](T e) -> bool {
        return e.i % 2 != 0;
    }, &pStart) << endl;
    cout << "New list:\t";
    travelList(pStart);

    cout << "Deleting at pos 3 with removeAt: " << removeAt(0, 1, &pStart) << endl;
    cout << "New list:\t";
    travelList(pStart);

    return 0;
}

bool empty(node* list) {
    return list == NULL;
}

int size(node* list) {
    return list == NULL ? 0 : 1 + size(list->next);
}

// Base case: list is not null
// Recursive call: repeat with next node connected
void travelList(node* list) {
    if(list){
        cout << list->info.i << "," << list->info.c << "  ";
        travelList(list->next);
    }
    else{
        cout << endl << endl;
    }
}

// Same as queue insertion
void pushBack(T info, node** list) {
    node* n = (node*)malloc(sizeof(node));
    n->info = info;
    n->next = NULL;

    if(!*list){
        *list = n;
    }
    else {
        node* aux = *list;

        while(aux->next)
            aux = aux->next;
        
        aux->next = n;
    }
}

// Same as stack insertion
void pushFront(T info, node** list) {
    node* n = (node*)malloc(sizeof(node));
    n->info = info;

    n->next = *list;
    *list = n;
}

/* 
    Inserts at given position
    Needs to iterate through list with aux node to keep intact the starting pointer
    Type of insertion: as queue
*/
void pushAt(int pos, T info, node** list) {
    node* n = (node*)malloc(sizeof(node));
    n->info = info;
    n->next = NULL;
    
    if(pos == 0) {
        n->next = *list;
        *list = n;
    }
    else{
        node* aux = *list;
        while(pos != 1) {
            pos--;
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;
    }
}

/*
    Base case: mem alloc contained mem address is not null
    Delete condition: node info must be equal to delete element
    Recursive call: two calls, one in case an element is deleted, the other
    in case no element is found at current node
*/
int remove(T e, node** list) {
    if(*list) {
        if((*list)->info == e){
            *list = (*list)->next;
            return 1 + remove(e, list);
        }
        else
            return 0 + remove(e, &(*list)->next);
    }
    else
        return 0;
}

// Same as remove, but when an element is deleted recursion stops
bool removeFirst(T e, node** list) {
    if(*list) {
        if((*list)->info == e){
            *list = (*list)->next;
            return true;
        }
        else
            return false + removeFirst(e, &(*list)->next);
    }
    else
        return false;
}

// Same as remove, but delete condition is a lambda predicative
template <class Predicative>
int removeIf(Predicative pr, node** list) {
    if(*list) {
        if(pr((*list)->info)) {
            *list = (*list)->next;
            return 1 + removeIf(pr, list);
        }
        else
            return 0 + removeIf(pr, &(*list)->next);
    }
    else
        return 0;
}

// Same as remove, but position deleting
bool removeAt(int current, int pos, node** list) {
    if(*list) {
        if(current == pos){
            *list = (*list)->next;
            return true;
        }
        else
            return false + removeAt(current + 1, pos, &(*list)->next);
    }
    else {
        return false;
    }
}