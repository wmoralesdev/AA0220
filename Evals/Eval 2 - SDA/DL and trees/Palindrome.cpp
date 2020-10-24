#include <iostream>
using namespace std;

struct node {
    char info;
    node* next,* prev;

    node() { next = prev = NULL; }
    node(int _info) : info(_info) { next = prev = NULL; }
};

struct dl {
    node* front,* back;

    dl() { front = back = NULL; }
};

void createBeginToEnd(dl* create, dl source);
void createEndToBegin(dl* create, dl source);
void pushBack(char info, dl* d);

int main(void) {
    dl list, dl1, dl2;
    string aux = "";
    
    cout << "Phrase: ";
    getline(cin, aux);

    // Insert every char of string in list unless it is a space
    for(auto it = aux.begin(); it != aux.end(); it++)
        if(*it != ' ')
            pushBack(*it, &list);

    // Create two lists and check them
    createBeginToEnd(&dl1, list);
    createEndToBegin(&dl2, list);

    bool arePalindrome = true;

    // Iterates through both lists checking positions
    while(dl1.front && dl2.front) {
        if(dl1.front->info != dl2.front->info)
            arePalindrome = false;

        dl1.front = dl1.front->next;
        dl2.front = dl2.front->next;
    }

    // If flag is true and both lists are empty the word is palindrome
    if(arePalindrome && !dl1.front && !dl2.front)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

void createBeginToEnd(dl* create, dl source) {
    // Creates list from front to back
    while(source.front) {
        pushBack(source.back->info, create);
        source.front = source.front->next;
    }
}

void createEndToBegin(dl* create, dl source) {
    // Creates list from back to front
    while(source.back) {
        pushBack(source.front->info, create);
        source.back = source.back->prev;
    }
}

void pushBack(char info, dl* d) {
    node* n = new node(info);

    if(!d->front)
        d->front = d->back = n;
    else {
        d->back->next = n;
        n->prev = d->back;
        d->back = n;
    }
}