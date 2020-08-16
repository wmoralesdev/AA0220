#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
};

int size(node*);
bool empty(node*);
void travelList(node*);
void pushBack(int, node**);
void pushFront(int, node**);
int remove(int, node** list);
void pushAt(int, int, node**);
bool removeFirst(int, node**);

template <class Predicative>
int removeIf(Predicative pr, node** list);

int main(void) {
    // List containing pointer
    node* pStart = NULL;

    // Checking list emptyness
    cout << "List is empty: " << (empty(pStart) ? "true" : "false") << endl << endl;

    // Pushing elements at list end
    pushBack(5, &pStart);
    pushBack(6, &pStart);
    pushBack(7, &pStart);
    cout << "List after pushing elements to back" << endl;
    travelList(pStart);
    
    // Pushing element at list front
    pushFront(3, &pStart);
    pushFront(2, &pStart);
    pushFront(1, &pStart);
    cout << "List after pushing elements to front" << endl;
    travelList(pStart);

    // Checking list size
    cout << "Size of list: " << size(pStart) << endl << endl;

    // Pushing elements at given position
    pushAt(0, 0, &pStart);
    pushAt(4, 4, &pStart);
    pushAt(8, 8, &pStart);
    cout << "List after pushing elements to given pos" << endl;
    travelList(pStart);
    
    // Deleting elements
    cout << "Deleting 4 with removeFirst: " << (removeFirst(4, &pStart) ? "true" : "false") << endl << endl;
    cout << "Deleting 0 with remove: " << remove(0, &pStart) << endl << endl;

    cout << "Deleting odds with removeIf: " << removeIf([](int e) -> bool {
        return e % 2 != 0;
    }, &pStart) << endl << endl;
    
    cout << "List after deleting elements" << endl;
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
        cout << list->info << "  ";
        travelList(list->next);
    }
    else{
        cout << endl << endl;
    }
}

// Same as queue insertion
void pushBack(int info, node** list) {
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
void pushFront(int info, node** list) {
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
void pushAt(int pos, int info, node** list) {
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
int remove(int e, node** list) {
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
bool removeFirst(int e, node** list) {
    if(*list) {
        if((*list)->info == e){
            *list = (*list)->next;
            return true;
        }
        else
            return false + remove(e, &(*list)->next);
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