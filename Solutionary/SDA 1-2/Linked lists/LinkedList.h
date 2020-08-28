/*
    Used to avoid code repetition between excercises that need a simple insertion in a list and use the same
    structure
*/

#pragma once

// Contains node information, currently is just an int value named Data
// Constructed with and without parameter
struct nodeData {
    int data;

    nodeData() {}
    nodeData(int _data): data(_data) {}

    bool operator==(const nodeData& r) {
        return this->data == r.data;
    }

    bool operator<(const nodeData& r) {
        return this->data < r.data;
    }

    bool operator>(const nodeData& r) {
        return this->data > r.data;
    }

    bool operator<=(const nodeData& r) {
        return this->data <= r.data;
    }

    bool operator>=(const nodeData& r) {
        return this->data >= r.data;
    }
};
typedef nodeData T;

// Node definition, a T type information field and a pointer to next element
struct node {
    T info;
    node* next;
};

// Function that inserts a T element in a list, insertions is like a queue
void pushBack(T info, node** list) {
    node* n = new node;
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