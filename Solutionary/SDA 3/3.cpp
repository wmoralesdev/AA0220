#include <vector>
#include <iostream>
using namespace std;

struct node{
    int info;
    node* left,* right;
};

int counter = 0;

int main(void) {
    // Create tree and call preOrderCount
}

void preOrderCount(node* tree) {
    if(tree) {
        counter++;
        preOrderCount(tree->left);
        preOrderCount(tree->right);
    }
}