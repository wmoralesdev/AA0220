/*
    Bobby is a garderner hamster. He has a big garden with n meters of space.
    One day, he decides that he doesn't like anymore the way his garden looks so he will move the trees so it looks 
    a little better, but he's a perfectionist so he wants them to alternate between the smalles and the biggest tree 
    still unplanted.
    Every tree occupies different amount of space (based on the quantity of nodes that it has) and the total size 
    of the arrangement of trees needs to be less than the total garden space.

    Input
    A value n where n < 10^5
    A value m that represents the quantity of trees that Bobby has
    For every tree, you'll get their inOrder and preOrder traversals

    Output
    Print the sequence that represents the tree arrangement
*/

#include <iostream>
using namespace std;

struct trav {
    string in, pre;

    trav() {}
    trav(string _in, string _pre) : in(_in), pre(_pre) {}

    bool operator<=(const trav& r) {
        return this->in.length() <= r.in.length();
    }
};
typedef trav T;

struct node {
    T info;
    node* next,* prev;

    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};

void swap(T* a, T* b);
void quickSort(node* head);
node* lastNode(node* head);
int getAndDeleteLast(node** list);
void pushBack(T info, node** list);
void _quickSort(node* low, node* high);
node* partition(node* low, node* high);

int main(void) {
    string auxIn, auxPre;
    node* list = NULL;
    int n = 0, m = 0;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> auxIn >> auxPre;
        pushBack(T(auxIn, auxPre), &list);
    }

    quickSort(list);

    int total = 0, aux = 0, prev = 0;
    
    while(list && total <= n) {
        if(aux % 2 == 0) {
            prev = list->info.in.length();
            list = list->next;
        }
        else {
            prev = getAndDeleteLast(&list);
        }

        cout << prev << "\t";
        total += prev;
        aux++;
    }

    return 0;
}

int getAndDeleteLast(node** list) {
    int dataToSend = 0;
    
    if(!(*list)->next) {
        dataToSend = (*list)->info.in.length();
        *list = NULL;

        delete *list;
        return dataToSend;
    }

    node* aux = *list;

    while(aux->next)
        aux = aux->next;

    dataToSend = aux->info.in.length();

    aux->prev->next = NULL;
    aux = NULL;

    delete aux;
    return dataToSend;
}

void pushBack(T info, node** list) {
    node* n = new node(info);

    if(!*list)
        *list = n;
    else {
        node* aux = *list;

        while(aux->next)
            aux = aux->next;

        n->prev = aux;
        aux->next = n;
    }
}

void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

void _quickSort(node* low, node* high) {
    if(high && low != high && low != high->next) {
        node* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

void quickSort(node* head) {
    node* last = lastNode(head);

    _quickSort(head, last);
}

node* lastNode(node* head) {
    while(head && head->next)
        head = head->next;

    return head;
}

node* partition(node* low, node* high) {
    T pivot = high->info;
    node* i = low->prev;

    for(node* j = low; j != high; j = j->next) {
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