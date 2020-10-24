#pragma once
#include <iostream>
using namespace std;

struct node {
    int info;
    node* left,* right;

    node() { left = right = nullptr; }
    node(int _info) : info(_info) { left = right = nullptr; }
};

void insert(int info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insert(info, &(*tree)->left);
        else
            insert(info, &(*tree)->right);
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->info << "\t";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->info << "\t";
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << "\t";
        inOrder(tree->right);
    }
}

int size(node* tree) {
    if(tree)
        return size(tree->left) + 1 + size(tree->right);
    else 
        return 0;
}

int inOrderSuccesor(node* rightTree) {
    node* aux = rightTree;

    while(aux->left)
        aux = aux->left;

    return aux->info;
}

void removeData(int e, node** tree) {
    if(*tree) {
        if(e < (*tree)->info)
            removeData(e, &(*tree)->left);
        else if (e > (*tree)->info)
            removeData(e, &(*tree)->right);
        else {
            // If tree is leaf
            if(!(*tree)->left && !(*tree)->right) {
                node* auxDelete = *tree;
                *tree = NULL;
                delete auxDelete;
            }

            // If tree only has L or R
            else if(!(*tree)->left && (*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->right;
                delete root;
            }

            else if((*tree)->left && !(*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->left;
                delete root;
            }

            // If tree is node
            else {
                // Find inOrder succesor, copy inOrder succesor to tree
                (*tree)->info = inOrderSuccesor((*tree)->right);

                // Delete inOrder succesor
                removeData((*tree)->info, &(*tree)->right);
            }
        }
    }
}