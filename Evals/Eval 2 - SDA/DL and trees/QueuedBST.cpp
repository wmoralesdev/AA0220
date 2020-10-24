#include <iostream>
using namespace std;

struct queue {
    int info;
    queue* next;

    queue() { next = NULL; }
    queue(int _info) : info(_info) { next = NULL; }
};

struct node {
    queue* q;
    node* left, *right;

    node() { left = right = NULL; q = NULL; }
    node(int info) {
        left = right = NULL; q = NULL;

        pushBack(info);
    }
    
    void pushBack(int info) {
        queue* n = new queue(info);

        if(!q)
            q = n;
        else {
            queue* aux = q;

            while(aux->next)
                aux = aux->next;
            
            aux->next = n;
        }
    }

    void printData() {
        queue* aux = q;

        cout << "(";
        while(aux) {
            cout << aux->info << ",";
            aux = aux->next;
        }
        
        cout << ")\t";
    }
};

void printInOrder(node* tree);
void insertInTree(int info, node** tree);

int main(void) {
    node* tree = NULL;
    int aux = 0;

    cout << "N (Ctrl + D to end input): ";
    while(cin >> aux) {
        insertInTree(aux, &tree);
        cout << "N (Ctrl + D to end input): ";
    }

    printInOrder(tree);

    return 0;
}

// Not required
void printInOrder(node* tree) {
    if(tree) {
        printInOrder(tree->left);
        tree->printData();
        printInOrder(tree->right);
    }
}

void insertInTree(int info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->q->info)
            insertInTree(info, &(*tree)->left);
        else if(info > (*tree)->q->info)
            insertInTree(info, &(*tree)->right);
        else
            (*tree)->pushBack(info);
    }
}