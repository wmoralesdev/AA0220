/*
    Description:
    The problem states that a tree with operators and chars (T) needs to evaluate the expression.
    It also says that every inner node will be an operator, and every leaf will be a char representing
    a number.

    So a tree as the following (example) will be sent to the function:

                                +
                -                   A
        B               /
                    C       D

    In further inspection, a right way to make the evaluation is with a inOrder traversal, operating:
    left will be a leaf or already evaluated expression
    root will be an operand
    right will be a leaf or already evaluated expression
*/

#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// Assuming number is double
struct list {
    pair<char, double> p;
    list* next;

    list() { next = NULL; }
    list(pair<char, double> _p) : p(_p) { next = NULL; }
};

struct node{
    char info;
    node* left,* right;

    node() { left = right = NULL; }
    node(char _info) : info(_info) { left = right = NULL; }
};

void printInOrder(node* tree);
double findNumericValue(char, list*);
double inOrderEvaluate(node*, list*);
double operate(double, double, char);
void pushBack(pair<char, double>, list**);

int main(void) {
    /*
        Tree creation
        A = 6, B = 20, C = 8, D = 5
        
        Tree visualization
                            +
                -                   A
        B               /
                    C       D
    */
    node* tree = new node('+');
    tree->left = new node('-');
    tree->right = new node('A');
    tree->left->left = new node('B');
    tree->left->right = new node('/');
    tree->left->right->left = new node('C');
    tree->left->right->right = new node('D');

    // List with values of chars creation
    list* lst = NULL;

    pair<char, double> aux('A', 6.0);
    pushBack(aux, &lst);

    aux = make_pair('B', 20.0);
    pushBack(aux, &lst);

    aux = make_pair('C', 8.0);
    pushBack(aux, &lst);

    aux = make_pair('D', 5.0);
    pushBack(aux, &lst);

    cout << inOrderEvaluate(tree, lst) << endl;
    // printInOrder(tree);
    return 0;
}

void printInOrder(node* tree) {
    if(tree) {
        printInOrder(tree->left);
        cout << tree->info << endl;
        printInOrder(tree->right);
    }
}

void pushBack(pair<char, double> info, list** lst) {
    list* n = new list(info);

    if(!*lst)
        *lst = n;
    else {
        list* aux = *lst;

        while(aux->next)
            aux = aux->next;
        
        aux->next = n;
    }
}

double findNumericValue(char c, list* lst) {
    while(lst) {
        if(lst->p.first == c)
            return lst->p.second;
        lst = lst->next;
    }
    
    // Just to return something, we assume value is always inside list
    return -1;
}

double operate(double left, double right, char op) {
    switch(op) {
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '+':
            return left + right;   
        case '-':
            return left - right;
        default:
            return 0;
    }
}

double inOrderEvaluate(node* tree, list* lst) {
    if(tree) {
        // When current char is not an operator, return the numeric value of leaf
        // searching in lst
        if(tree->info != '*' && tree->info != '/' && tree->info != '+' && tree->info != '-')
            return findNumericValue(tree->info, lst);
        
        // Save left operation with recursion
        double left = inOrderEvaluate(tree->left, lst);

        // Save right operation with recursion
        double right = inOrderEvaluate(tree->right, lst);

        // Printing for visualization of current operation
        cout << left << tree->info << right << endl;

        // Return value of left operated with right
        return operate(left, right, tree->info);
    }
}