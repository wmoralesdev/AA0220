#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

struct node {
    int info;
    node* left, *right;

    node() { left = right = NULL; }
    node(int _info) : info(_info) { left = right = NULL; }
};

void printInOrder(node* tree);
void insertInTree(int info, node** tree);

int main(void) {
    node* A = NULL,* B = NULL;

    for(int i = 0; i < 27; i++) {
        int aux = rand() % 50 + 1;

        (aux % 2 == 0) ? insertInTree(aux, &A) : insertInTree(aux, &B);
    }

    printInOrder(A);
    cout << endl;
    printInOrder(B);

    return 0;
}

// Not required
void printInOrder(node* tree) {
    if(tree) {
        printInOrder(tree->left);
        cout << tree->info << "\t";
        printInOrder(tree->right);
    }
}

void insertInTree(int info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(info, &(*tree)->left);
        else
            insertInTree(info, &(*tree)->right);
    }
}