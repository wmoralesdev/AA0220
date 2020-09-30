#include <vector>
#include <iostream>
using namespace std;

struct node{
    int info;
    node* left,* right;
};

int counter = 0;

int main(void) {
    // Create tree and call levelOrder
}

int treeHeight(node* tree) {
    if(tree) {
        int left = treeHeight(tree->left);
        int right = treeHeight(tree->right);

        return (left < right) ? right + 1 : left + 1;
    }
}

void levelOrder(node* tree) {
    int height = treeHeight(tree);

    for(int i = 0; i < height; i++) {
        printLevel(tree, i);
        cout << endl;
    }
}

void printLevel(node* tree, int level) {
    if (tree) {
        if (level == 1)  
            cout << tree->info << "\t";  
        else if (level > 1) {  
            printLevel(tree->left, level - 1);  
            printLevel(tree->right, level - 1);  
        }  
    }
}