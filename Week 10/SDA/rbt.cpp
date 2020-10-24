#include "colors.h"
#include <iostream>
using namespace std;

// Helper enum to fast determine side of operation
enum Side { LEFT, RIGHT };

// Node structure
struct node{
    // Stores information, color and node references
    int info;

    /* 
        DISCLAIMER: COLOR SHOULD BE ALWAYS A SMALL MEM USSAGE VARIABLE (LIKE ENUMS), 
        STRING IS USED IN THIS CODE IN ADDITION OF COLORS.H SO TRAVERSALS
        PRINTING COLD BE MORE DIDACTIC
    */
    string color;
    

    // A reference to parent node, left and right children
    node* parent,* left,* right;

    // Constructors
    node() { parent = left = right = NULL; }
    node(int _info, string _color) : info(_info), color(_color) { parent = left = right = NULL; }
};

#pragma region prototypes

void inOrder(node* tree);
node* getRoot(node* tree);
void preOrder(node* tree);
void postOrder(node* tree);
void insertRBT(node **tree, int info);
void leftRotation(node** t, node** b);
void rightRotation(node** t, node** b);
void fixRoot(node** tree, node** current);
node* auxiliarInsertion(node** tree, int info);
void fixInsertion(node** tree, node** current);
void leftLeft(node** tree, node** parent, node** grandpa);
void leftRight(node** tree, node** current, node** parent);
void rightLeft(node** tree, node** current, node** parent);
void rightRight(node** tree, node** parent, node** grandpa);

#pragma endregion

#pragma region traversals

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->color << tree->info << RESET << "\t";
        inOrder(tree->right);
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->color << tree->info << RESET << "\t";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->color << tree->info << RESET << "\t";
    }
}

#pragma endregion

#pragma region utilities

// Searchs for an item inside RBT
bool searchForT(node* tree, int info) {
    if(tree) {
        // If item is found, returns true
        if(tree->info == info)
            return true;

        // Searchs for item in left and right subtrees
        else if(info <= tree->info)
            return false + searchForT(tree->left, info);
        else
            return false + searchForT(tree->right, info);
    }
    // If recursion ends, item is not contained within RBT
    else
        return false;
}

// Searchs for inOrderSuccesor
int inOrderSuccesor(node* tree) {
    if(tree->left)
        return inOrderSuccesor(tree->left);
    else
        return tree->info;
}

// Recursively deletes every tree branch in postOrder
void destroyTree(node* tree) {
    if(tree) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

#pragma endregion

#pragma region rotations

// Executes left rotation
void leftRotation(node** t, node** b) {
    // A is B parent
    node* a = (*b)->parent;

    // A right is B left
    a->right = (*b)->left;

    // If B left isn't NULL, then B left parent is A
    if((*b)->left)
        (*b)->left->parent = a;

    // B parent is A parent
    (*b)->parent = a->parent;

    // If A parent isn't NULL, then tree becomes B
    if(!a->parent)
        *t = *b;
    // Else if A is equal to A parent left, then A parent left becomes B
    else if(a == a->parent->left)
        a->parent->left = *b;
    // Else 
    else
        a->parent->right = *b;

    (*b)->left = a;
    a->parent = *b;
}

void rightRotation(node** t, node** b) {
    node* a = (*b)->parent;
    a->left = (*b)->right;

    if((*b)->right)
        (*b)->right->parent = a;

    (*b)->parent = a->parent;
    
    if(!a->parent)
        *t = *b;
    else if(a == a->parent->left)
        a->parent->left = *b;
    else
        a->parent->right = *b;

    (*b)->right = a;
    a->parent = *b;
}

#pragma endregion

node* auxiliarInsertion(node** tree, int info) {
    node* current = NULL;
    
    // BST verifications
    if(info < (*tree)->info) {
        // If info is less than tree information, and tree left is empty create current
        if(!(*tree)->left) {
            current = new node(info, COLOR_RED);
            current->parent = *tree;
            (*tree)->left = current;
        }
        // If tree left is not empty, recurse with left subtree
        else
            current = auxiliarInsertion(&(*tree)->left, info);
    }
    else {
        // If info is more than tree information, and tree right is empty create current
        if(!(*tree)->right) {
            current = new node(info, COLOR_RED);
            current->parent = *tree;
            (*tree)->right = current;
        }
        // If tree right is not empty, recurse with right subtree
        else
            current = auxiliarInsertion(&(*tree)->right, info);
    }

    return current;
}

void insertRBT(node **tree, int info) {
    // If tree is empty, then just create a new BLACK node
    if(!*tree)
        *tree = new node(info, COLOR_BLACK);
    else {
        // Make normal BST insertion saving current reference
        node* current = auxiliarInsertion(tree, info);

        // Fix applying RBT rules
        fixInsertion(tree, &current);
    }
}

void fixInsertion(node** tree, node** current) {
    // Variables declaration
    Side parentSide, childSide;
    node* parent = (*current)->parent,* uncle = NULL,* grandpa = NULL;

    // If current is root, and is red just color it BLACK
    if((*current)->color != COLOR_BLACK && !(*current)->parent) {
        (*current)->color = COLOR_BLACK;
        return;
    }

    // If current has parent, get grandpa
    if(parent) 
        grandpa = parent->parent;

    // If current has parent, has grandpa and parent isn't BLACK
    if(parent && grandpa && parent->color != COLOR_BLACK) {
        // Get parent and current sides
        parentSide = (grandpa->left == parent) ? LEFT : RIGHT;
        childSide = (parent->left == *current) ? LEFT : RIGHT;

        // Get uncle from parent's opposite side
        uncle = (parentSide == LEFT) ? grandpa->right : grandpa->left;

        // If uncle is BLACK
        if(!uncle || uncle->color == COLOR_BLACK) {
            // Check LL, LR, RL or RR
            if(parentSide == LEFT && childSide == LEFT)
                leftLeft(tree, &parent, &grandpa);
            else if(parentSide == LEFT && childSide == RIGHT)
                leftRight(tree, current, &parent);
            else if(parentSide == RIGHT && childSide == LEFT)
                rightLeft(tree, current, &parent);
            else
                rightRight(tree, &parent, &grandpa);
        }
        // Else means that uncle is RED
        else {
            // Color parent and uncle BLACK
            parent->color = COLOR_BLACK;
            uncle->color = COLOR_BLACK;

            // Make grandpa RED
            grandpa->color = COLOR_RED;

            // Restart with grandpa (current becomes grandpa)
            fixInsertion(tree, &grandpa);
        }
    }
}

void leftLeft(node** tree, node** parent, node** grandpa) {
    // Save grandpa before rotation
    node* formerGrandpa = *grandpa;

    // Right rotate tree with parent
    rightRotation(tree, parent);

    // Color parent BLACK and former grandpa RED
    (*parent)->color = COLOR_BLACK;
    formerGrandpa->color = COLOR_RED;
}

void leftRight(node** tree, node** current, node** parent) {
    // Left rotate tree with current
    leftRotation(tree, current);

    // Execute LL with current (parent becomes current)
    leftLeft(tree, current, &(*current)->parent);
}

void rightLeft(node** tree, node** current, node** parent) {
    // Right rotate tree with current
    rightRotation(tree, current);

    // Execute RR with current (parent becomes current)
    rightRight(tree, current, &(*current)->parent);
}

void rightRight(node** tree, node** parent, node** grandpa) {
    // Save grandpa before rotation
    node* formerGrandpa = *grandpa;

    // Left rotate tree with parent
    leftRotation(tree, parent);

    // Color parent BLACK and former grandpa RED
    (*parent)->color = COLOR_BLACK;
    formerGrandpa->color = COLOR_RED;
}

int main() {
    node* tree = NULL;
    
    int array[] = { 4, 7, 12, 15, 3, 5, 14, 18, 16, 17 };

    for(int i = 0; i < 10; i++) {
        insertRBT(&tree, array[i]);
        preOrder(tree); cout << endl;
        cin.get();
    }

    return 0;
}