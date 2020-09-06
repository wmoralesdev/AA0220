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

    string toString() {
        return to_string(this->i) + "," + this->c;
    }
};
typedef nodeinfo T;

// Struct with ref to next and prev nodes
struct node {
    T info;
    node* prev, *next;
};

// Struct with front and back elements
struct doubleLinked {
    node* front,* back;

    doubleLinked () {
        front = back = NULL;
    }
};

void traverseEnd(node* back);
int remove(T e, node** front);
void traverseBegin(node* front);
bool removeFirst(T e, node** front);
void pushBack(T info, doubleLinked* dl);
void pushFront(T info, doubleLinked* dl);
void pushAt(int pos, T info, node** front);
bool removeAt(int current, int pos, node** front);

template <class Predicative>
int removeIf(Predicative removeCondition, node** front);

int main(void) {
    doubleLinked dl;

    pushBack(T(5, 'e'), &dl);
    pushBack(T(6, 'f'), &dl);
    pushBack(T(7, 'g'), &dl);
    cout << "List after pushing elements to back" << endl;
    traverseBegin(dl.front);
    
    pushFront(T(3, 'c'), &dl);
    pushFront(T(2, 'b'), &dl);
    pushFront(T(1, 'a'), &dl);
    cout << "List after pushing elements to front" << endl;
    traverseBegin(dl.front);

    pushAt(0, T(0, '*'), &dl.front);
    cout << "List after pushing at 0" << endl;
    traverseBegin(dl.front);

    pushAt(4, T(4, 'd'), &dl.front);
    cout << "List after pushing at 4" << endl;
    traverseBegin(dl.front);

    cout << "Deleting 0 with remove: " << remove(T(0, '*'), &dl.front) << endl;
    traverseBegin(dl.front);

    cout << "Deleting 4 with removeFirst: " << removeFirst(T(4, 'd'), &dl.front) << endl;
    traverseBegin(dl.front);

    cout << "Deleting at pos 1: " << removeAt(0, 1, &dl.front) << endl;
    traverseBegin(dl.front);

    cout << "Deleting odds with removeIf: " << removeIf([](T e) -> bool {
        return e.i % 2 != 0;
    }, &dl.front) << endl;
    traverseBegin(dl.front);

    return 0;
}

void pushFront(T info, doubleLinked* dl) {
    node* n = new node;
    n->info = info;
    n->prev = NULL;

    // If list is empty, then front and back are the same
    // and new prev and next are empty
    if(!dl->front) {
        dl->front = dl->back = n;
        n->prev = n->next = NULL;

        return;
    }

    // Make new next equals front of current list, 
    // make current list front.prev point at new node
    // and alter front pointer
    n->next = dl->front;
    dl->front->prev = n;
    dl->front = n;
}

void pushBack(T info, doubleLinked* dl) {
    node* n = new node;
    n->info = info;
    n->next = NULL;

    // Same as push front
    if(!dl->front) {
        dl->front = dl->back = n;
        n->prev = n->next = NULL;

        return;
    }

    // Make new.prev point at back of complete list,
    // then make back.next point to new node
    // and change back pointer ref
    n->prev = dl->back;
    dl->back->next = n;
    dl->back = n;
}

void pushAt(int pos, T info, node** front) {
    node* n = new node;
    n->info = info;
    n->prev = n->next = NULL;
    
    // If node is going to be inserted at first pos make it as pushFront
    if(pos == 0) {
        (*front)->prev = n;
        n->next = *front;

        *front = n;

        return;
    }

    int counter = 0;

    // Change to pushing position
    node* aux = *front;
    while(counter < pos - 1) {
        aux = aux->next;
        counter++;
    }

    // Alter references
    n->prev = aux;
    n->next = aux->next;
    aux->next->prev = n;
    aux->next = n;
}

void traverseBegin(node* front) {
    if(front) {
        cout << front->info.toString() << "  ";
        traverseBegin(front->next);
    }
    else
        cout << endl;
}

void traverseEnd(node* back) {
    if(back) {
        cout << back->info.toString() << "  ";
        traverseBegin(back->prev);
    }
    else
        cout << endl;
}

int remove(T e, node** front) {
    if(*front) {
        if((*front)->info == e) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }

            return 1 + remove(e, front);
        }
        else
            return 0 + remove(e, &(*front)->next);
    }
    else
        return 0;
}

bool removeFirst(T e, node** front) {
    if(*front) {
        if((*front)->info == e) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }
            return true;
        }
        else
            return false + removeFirst(e, &(*front)->next);
    }
    else
        return false;
}

bool removeAt(int current, int pos, node** front) {
    if(*front) {
        if(current == pos) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }

            return true;
        }
        else
            return false + removeAt(current + 1, pos, &(*front)->next);
    }
    else
        return false;
}

template <class Predicative>
int removeIf(Predicative removeCondition, node** front) {
    if(*front) {
        if(removeCondition((*front)->info)) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                node* prev = (*front)->prev;
                *front = (*front)->next;
                
                if(*front)
                    (*front)->prev = prev;

                prev->next = *front;
            }

            return 1 + removeIf(removeCondition, front);
        }
        else
            return 0 + removeIf(removeCondition, &(*front)->next);
    }
    else
        return 0;
}