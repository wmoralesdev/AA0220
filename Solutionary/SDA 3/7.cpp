#include <vector>
#include <iostream>
using namespace std;

struct node{
    int info;
    node* left,* right;

    node() {}
    node(int _info) : info(_info) {}
};

int main(void) {
    // Create tree A, and null tree B and call preOrderCopy
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

void preOrderCopy(node* tree, node** copy) {
    if(tree) {
        insertInTree(tree->info, copy);
        preOrderCopy(tree->left, copy);
        preOrderCopy(tree->right, copy);
    }
}