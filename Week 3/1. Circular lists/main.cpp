#include <iostream>
using namespace std;

struct nodeinfo {
    int i;
    char c;

    nodeinfo() {}
    nodeinfo(int _i, char _c) : i(_i), c(_c) {}

    bool operator==(const nodeinfo& r) {
        return this->i == r.i && this->c == r.c;
    }

    bool operator!=(const nodeinfo& r) {
        return this->i != r.i && this->c != r.c;
    }
};
typedef nodeinfo T;

struct node {
    T info;
    node* next;
};

int size(node*);
bool empty(node*);
void traverseList(node*);
node* pushBack(T, node*);
node* pushFront(T, node*);
bool removeAt(int, node**);
void pushAt(int, T, node**);

int main(void) {
    // Reference to last node is stored
    node *last = NULL;
    cout << "Back pushing: " << endl;

    // Every push function returns modified pointer
    last = pushBack(T(5, 'e'), last);
    last = pushBack(T(6, 'f'), last);
    last = pushBack(T(7, 'g'), last);

    traverseList(last);

    cout << "Front pushing: " << endl;
    last = pushFront(T(3, 'c'), last);
    last = pushFront(T(2, 'b'), last);
    last = pushFront(T(1, 'a'), last);
    traverseList(last);

    cout << "Pushing at position: " << endl;
    pushAt(4, T(4, 'd'), &last);
    traverseList(last);

    cout << "Removed at pos 1: " << removeAt(1, &(*last).next) << endl;
    traverseList(last);

    cout << "Removed at pos 0: " << removeAt(0, &(*last).next) << endl;
    traverseList(last);

    return 0;
}

bool empty(node *last) {
    return last == NULL;
}

int size(node* last) {
    node* aux = last;
    int current = 0;

    do {
        aux = aux->next;
        current++;
    } while(aux != last);

    return current;
}

void traverseList(node* last) {
    node* aux = last;

    // Do while structure used to iterate through every element of the list, saving reference to head
    do {
        aux = aux->next;
        cout << aux->info.i << "," << aux->info.c << "  ";
    } while(aux != last);
    cout << endl << endl;
}

// Returs modified pointer
// Receives T to insert and pointer to modify
node* pushBack(T info, node* last) {    
    node* n = new node;
    n->info = info;

    // If list is empty, then make new node point to itself to keep circular reference
    if(!last) {
        n->next = n;
        last = n;
    }
    // If not, push element at last position, making it next pointer point towards head
    // then move last to new
    else {
        n->next = last->next;
        last->next = n;
        last = n;
    }

    return last;
}

node* pushFront(T info, node* last) {
    node* n = new node;
    n->info = info;

    // Same as push front
    if(!last) {
        n->next = n;
        last = n;
    }
    // Make new.next be last.next (head) then, change last.next to newly created
    else {
        n->next = last->next;
        last->next = n;
    }

    return last;
}

// Push element at given position
// Receives position, T to insert and last node ref as double pointer
void pushAt(int pos, T info, node** last) {
    node* n = new node;
    n->info = info;
    n->next = NULL;
    
    // If position is 0, then insertion is head-like
    if(pos == 0) {
        n->next = (*last)->next;
        (*last)->next = n;
    }
    // Create an auxiliar reference to cycle through list until insert position is found
    // then modify the next pointers
    else{
        node* aux = *last;
        while(pos != 1) {
            pos--;
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;
    }
}

// Returns true if element can be deleted
// Receives pos to delete, and head reference as double pointer
bool removeAt(int pos, node** head) {
    // If head needs to be deleted
    if(pos == 0) {
        (*head) = (*head)->next;
        return true;
    }

    // Create two references, one to a current node, and aux is at prev
    node* move = *head, *aux = NULL;
    int counter = 0;

    // Iterate until desired position
    while(counter != pos) {
        aux = move;
        move = move->next;
        counter++;
    }

    // Jump node to be deleted
    aux->next = move->next;
    
    // Free mem
    delete(move);
    
    return true;
}