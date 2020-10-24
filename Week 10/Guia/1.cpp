#include "../tree.h"

void inOrderDelete(int, node**);

int main(void) {
    node* tree = NULL;

    insert(10, &tree);
    insert(9, &tree);
    insert(4, &tree);
    insert(1, &tree);
    insert(2, &tree);
    insert(8, &tree);
    insert(20, &tree);

    inOrder(tree); cout << endl;
    inOrderDelete(4, &tree);
    inOrder(tree); cout << endl;

    return 0;
}

void inOrderDelete(int toDelete, node** tree) {
    if(*tree) {
        inOrderDelete(toDelete, &(*tree)->left);

        if(toDelete == (*tree)->info)
            removeData(toDelete, tree);

        inOrderDelete(toDelete, &(*tree)->right);
    }
}