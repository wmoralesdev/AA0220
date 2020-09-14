#include <iostream>
#include "LinkedList.h"
using namespace std;

int size(node*);
node* mergeSort(node*);
void traverseList(node*);
node* merge(node*, node*);

int main(void) {
    srand(time(NULL));
    node* list = NULL;

    // Assuming 50 elements per list
    for(int i = 0; i < 5; i++)
        pushBack(T(rand() % 1000), &list);

    list = mergeSort(list);
    traverseList(list);

    return 0;
}

int size(node* list) {
    if(list) {
        return 1 + size(list->next);
    }
    else
        return 0;
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

node* mergeSort(node* list) {
    if(!list || !list->next)
        return list;

    int listSize = size(list);    
    node* left = NULL,* right = NULL,* aux = list;

    for(int i = 0; i < listSize; i++) {
        if(i < listSize / 2)
            pushBack(aux->info, &left);
        else
            pushBack(aux->info, &right);

        aux = aux->next;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

node* merge(node* left, node* right) {
    node* resultList = NULL;

    while(left && right) {
        if(left->info <= right->info){
            pushBack(left->info, &resultList);
            left = left->next;
        }
        else {
            pushBack(right->info, &resultList);
            right = right->next;
        }
    }

    while(left) {
        pushBack(left->info, &resultList);
        left = left->next;
    }

    while(right) {
        pushBack(right->info, &resultList);
        right = right->next;
    }

    return resultList;
}