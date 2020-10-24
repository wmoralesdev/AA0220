#include <iostream>
using namespace std;

template<class T>
struct node {
    T info;
    node<T>* next,* prev;

    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};

template<class T>
void swap(T* a, T* b);

template<class T>
void pushBack(node<T>** dl, T info);

int main(void) {
    node<int>* list = NULL;
}

template<class T>
void swap(T* a, T* b) {
    T temp = a;
    *a = *b;
    *b = temp;
}

template<class T>
void pushBack(node<T>** dl, T info) {
    node<T>* n = new node(info);
    
    if(!*dl)
        *dl = n;
    else {
        node<T>* aux = *dl;

        while(aux->next)
            aux = aux->next;

        n->prev = aux;
        aux->next = n;
    }
}

template<class T>
void _quickSort(node<T>* low, node<T>* high) {
    if(high && low != high && low != high->next) {
        node<T>* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

template<class T>
void quickSort(node<T>* head) {
    node<T>* last = lastNode(head);

    _quickSort(head, last);
}

template<class T>
node<T>* lastNode(node<T>* head) {
    while(head && head->next)
        head = head->next;

    return head;
}

// NULL 8 9 5 7 12 NULL
template<class T>
node<T>* partition(node<T>* low, node<T>* high) {
    T pivot = high->info;
    node<T>* i = low->prev;

    for(node<T>* j = low; j != high; j = j->next) {
        if(j->info <= pivot) {
            // equivalent to i++
            i = (!i) ? low : i->next;

            swap(&(i->info), &(j->info));
        }
    }
    
    // swap arr i + 1, arr high
    // return i + 1
    i = (!i) ? low : i->next;
    swap(&(i->info), &(high->info));
    return i;
}