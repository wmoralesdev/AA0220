#include <iostream>
using namespace std;

struct node {
    int tireness, time;
    node* next,* prev;

    node() { next = prev = NULL; }
    node(int _tireness, int _time) : tireness(_tireness), time(_time) { next = prev = NULL; }
};

struct dl {
    node* front,* back;

    dl() { front = back = NULL; }
};

void pushBack(int tireness, int time, dl* d);
void pushBack(int tireness, int time, dl* d);
void checkIfPintoWillSurvive(int n, int h, dl list);

int main(void) {
    dl list;
    int n = 0, h = 0;
    int auxTireness = 0, auxTime = 0;

    cin >> n >> h;
    while(cin >> auxTireness >> auxTime && auxTireness != -1) {
        pushBack(auxTireness, auxTime, &list);
    }

    checkIfPintoWillSurvive(n, h, list);
}

void checkIfPintoWillSurvive(int n, int h, dl list) {
    // Since excercise didn't specify time unit you could assume minutes, hours, etc
    // Minute will be assumend for every element store in nodes
    int actualTireness = 0;
    double actualTime = 0;

    node* aux = list.front;

    // Accumulate tireness and time consumed in every dish
    while(aux) {
        actualTireness += aux->tireness;
        actualTime += aux->time;
        aux = aux->next;
    }
    
    // If max tireness is less than actual tireness and the current time (arrived time + time spent eating) are less
    // than 21 (9:00 PM militar format) then Pinto will live
    if(n > actualTireness && (h + (actualTime / 60)) < 21)
        cout << "Yay!";
    else
        cout << "F";
}

void pushBack(int tireness, int time, dl* d) {
    node* n = new node(tireness, time);

    if(!d->front)
        d->front = d->back = n;
    else {
        d->back->next = n;
        n->prev = d->back;
        d->back = n;
    }
}