#include <iostream>
#define LENGTH 5          //Assumed value, it will be allowed

typedef struct Node{
    struct Node* parent;
    char unown;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct LabeledTree{
    int label;
    Node* tree;
}LabeledTree;

void Treeify(Node* T, int p, int l, int r, char* A, int *n){
    if(p < *n){
        T = new Node;
        T->parent = NULL;
        T->unown = A[p];
        Treeify(T->left, 2*p-1, 2*(2*p-1)-1,2*(2*p-1),A,n);
        if(T->left != NULL) T->parent = T;
        Treeify(T->right, 2*p, 2*(2*p)-1,2*(2*p),A,n);
        if(T->right != NULL) T->parent = T;
    }
}

void TreeArrays(int** n, char** m, LabeledTree* A){
    for(int k=0; k < **n; k++){
        int l = LENGTH;
        char* R = m[k];
        Treeify(A[k].tree, 0, 1, 2, R, &l);
    }
}

int CountNodes(Node* T){
    if(T == NULL) return 0;
    int counted = 0;
    if(T->unown >= 'A' && T->unown <= 'Z' && T->parent != NULL && T->parent->parent != NULL
                    && T->parent->parent->unown >= 'A' && T->parent->parent->unown <= 'Z')
        counted = 1;
    return counted + CountNodes(T->left) + CountNodes(T->right);
}

void CountConditionNodes(int** n, LabeledTree* A){
    for(int k=0; k < **n; k++){
        int label = CountNodes(A[k].tree);
        A[k].label = label;
    }
}

void InsertionSort(LabeledTree* A, int** n){
    for(int j=1; j<**n; j++){
        LabeledTree key = A[j];
        int i = j - 1;
        while(i > -1 && A[i].label > key.label){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void Unown(int* n, char** regions){
    LabeledTree A[*n];
    TreeArrays(&n, regions, A);
    CountConditionNodes(&n, A);
    InsertionSort(A, &n);
}
