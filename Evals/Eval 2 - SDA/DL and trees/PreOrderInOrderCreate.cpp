/*
    NOTE: USES TEMPLATE BECAUSE THE INSERTION LOGI IS THE SAME FOR CHAR AND INTEGER VECTORS
*/

#include <vector>
#include <iostream>
using namespace std;

template<class T>
struct node {
    T info;
    node* left, *right;

    node() { left = right = NULL; }
    node(T _info) : info(_info) { left = right = NULL; }
};

template<class T>
void printInOrder(node<T>* tree);

template<class T>
int search(vector<T> inOrder, int start, int end, T val);

template<class T>
node<T>* createFromTraversals(vector<T> preOrder, vector<T> inOrder, int start, int end);

int main(void) {
    // Example will use char vector, change type to test
    vector<char> preOrder, inOrder;

    char aux = 0;
    int size = 0;

    cout << "Size: ";
    cin >> size;

    cout << "PreOrder" << endl;
    for(int i = 0; i < size; i++) {
        cout << "N: "; cin >> aux;
        preOrder.push_back(aux);
    }

    cout << "InOrder" << endl;
    for(int i = 0; i < size; i++) {
        cout << "N: "; cin >> aux;
        inOrder.push_back(aux);
    }

    node<char>* tree = createFromTraversals(preOrder, inOrder, 0, inOrder.size() - 1);
    printInOrder(tree);
    return 0;
}

// A B D E C F
// D B E A F C

// Not required printing
template<class T>
void printInOrder(node<T>* tree) {
    if(tree) {
        printInOrder(tree->left);
        cout << tree->info << "\t";
        printInOrder(tree->right);
    }
}

int preIndex = 0;
template<class T>
node<T>* createFromTraversals(vector<T> preOrder, vector<T> inOrder, int start, int end) {

    if (start > end)  
        return NULL;  

    node<T>* tree = new node<T>(preOrder.at(preIndex++));  

    if (start == end)  
        return tree;  

    int inIndex = search(inOrder, start, end, tree->info);  

    tree->left = createFromTraversals(preOrder, inOrder, start, inIndex - 1);  
    tree->right = createFromTraversals(preOrder, inOrder, inIndex + 1, end);  

    return tree; 
}

template<class T>
int search(vector<T> inOrder, int start, int end, T val) {
    for (int i = start; i <= end; i++) {  
        if (inOrder.at(i) == val)  
            return i;  
    } 
}