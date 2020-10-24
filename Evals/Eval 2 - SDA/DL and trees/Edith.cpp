#include <string>
#include <iostream>

#define DL_OUT_OF_RANGE "XXX"

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

bool isVowel(char c);
void pushBack(string info, dl* d);
void findEdithCrush(dl names, int pos);
node* findElementAtPos(dl names, int pos);

int main(void) {
    dl names;
    string aux = "";
    int auxInt = 0;

    cout << "Name (write \"stop\" to stop): ";
    while(cin >> aux && aux.compare("stop") != 0) {
        pushBack(aux, &names);
        cout << "Name (write \"stop\" to stop): ";
    }
    cout << "Number: "; cin >> auxInt;

    findEdithCrush(names, auxInt);
    return 0;
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

bool isVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;

    }
}

node* findElementAtPos(dl names, int pos) {
    int aux = 0;

    while(names.front) {
        if(aux++ == pos)
            return names.front;
        
        names.front = names.front->next;
    }

    return NULL;
}

void findEdithCrush(dl names, int pos) {
    // Default increment
    int increment = 2;

    // Finds reference to name at given position of list
    node* crush = findElementAtPos(names, pos);

    while(true) {
        // Check whether the name ends with vowel or consonant
        if(isVowel((crush->info.at(crush->info.length() - 1))))
            for(int i = 0; i < increment; i++)
                // Moves backward increment times
                if(!crush->prev) {
                    cout << "Wait for Edith to tell you" << endl;
                    return;
                }
                else
                    crush = crush->prev;
        else
            for(int i = 0; i < increment; i++)
                // Moves forward increment times
                if(!crush->next) {
                    cout << "Wait for Edith to tell you" << endl;
                    return;
                }
                else
                    crush = crush->next;

        // If current name starts with d then process ends
        if(crush->info.at(0) == 'd') {
            cout << "You got it!, Edith's crush is " << crush->info << endl;
            return;
        }

        increment++;
    }
}