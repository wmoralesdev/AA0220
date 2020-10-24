#include <string>
#include <iostream>
using namespace std;

struct node {
    string info;
    node* next,* prev;

    node() { next = prev = NULL; }
    node(string _info) : info(_info) { next = prev = NULL; }
};

struct dl {
    node* front,* back;

    dl() { front = back = NULL; }
};

void memorize(dl toMemorize, dl* memorized);
void pushBack(string info, dl* d);

int main(void) {
    dl words, memorizedWords;
    string aux = "";

    cout << "Word (Ctrl + D to end input): ";
    while(cin >> aux) {
        pushBack(aux, &words);
        cout << "Word (Ctrl + D to end input): ";
    }

    memorize(words, &memorizedWords);

    while(memorizedWords.front) {
        cout << memorizedWords.front->info << endl;
        memorizedWords.front = memorizedWords.front->next;
    }
}

void memorize(dl toMemorize, dl* memorized) {
    int aux = 0;

    while(toMemorize.front) {
        if(aux++ % 2 == 0) {
            pushBack(toMemorize.front->info, memorized);
        }
        pushBack(toMemorize.front->info, memorized);
        toMemorize.front = toMemorize.front->next;
    }
}

void pushBack(string info, dl* d) {
    node* n = new node(info);

    if(!d->front)
        d->front = d->back = n;
    else {
        d->back->next = n;
        n->prev = d->back;
        d->back = n;
    }
}