#include <vector>
#include <iostream>
using namespace std;

struct node{
    int info;
    node* left,* right;
};

vector<int> inOrder;

int main(void) {
    // Create a tree and call checkIfBST
}

void inOrderTraversal(node* tree) {
    if(tree) {
        inOrderTraversal(tree->left);
        inOrder.push_back(tree->info);
        inOrderTraversal(tree->right);
    }
}

bool checkIfBST(node* tree) {
    inOrderTraversal(tree);

    for(int i = 0; i < inOrder.size() - 1; i++)
        if(inOrder.at(i) > inOrder.at(i + 1))
            return false;
    
    return true;
}