#include "../tree.h"

void populateInOrder(node* tree, int* i, int* array);
void toMinHeapConversion(node* tree, int* array, int* i);

int main(void) {
    node* tree = NULL;

    insert(10, &tree);
    insert(9, &tree);
    insert(4, &tree);
    insert(1, &tree);
    insert(2, &tree);
    insert(8, &tree);
    insert(20, &tree);

    int* array = new int[size(tree)], j = 0;
    populateInOrder(tree, &j, array);
    
    j = -1;
    toMinHeapConversion(tree, array, &j);
    preOrder(tree);

    return 0;
}

void populateInOrder(node* tree, int* i, int* array) {
    if(tree) {
        populateInOrder(tree->left, i, array);
        array[(*i)++] = tree->info;
        populateInOrder(tree->right, i, array);
    }
}

void toMinHeapConversion(node* tree, int* array, int* i) {
    if(tree) {
        tree->info = array[++(*i)];

        toMinHeapConversion(tree->left, array, i);
        toMinHeapConversion(tree->right, array, i);
    }
}

/* 
    
    00025318 - Jaime
    00043818 - Migue
    00209317 - Daniel
    00145518 - Miguel Fernandez
    00039718 - Julito
    00156618 - Otaku
    00029117 - Luis
    00002018 - Anaya
*/