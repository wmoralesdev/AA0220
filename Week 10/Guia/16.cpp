#include "../tree.h"

void preOrderInsertion(node* tree, node** asciiTree);

int main(void) {
    node* tree = NULL,* asciiTree = NULL;

    insert(7, &tree);
    insert(9, &tree);
    insert(5, &tree);
    insert(4, &tree);
    insert(0, &tree);
    insert(1, &tree);
    insert(3, &tree);

    preOrderInsertion(tree, &asciiTree);
    inOrder(asciiTree);

    return 0;
}

void preOrderInsertion(node* tree, node** asciiTree) {
    if(tree) {
        insert('0' + tree->info, asciiTree);
        preOrderInsertion(tree->left, asciiTree);
        preOrderInsertion(tree->right, asciiTree);
    }
}