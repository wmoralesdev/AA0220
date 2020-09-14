#include <iostream>
#include <string>
using namespace std;

struct person {
    string name, lastName;
    int age;

    person() {}
    
    person(string _name, string _lastName, int _age) :
    name(_name), lastName(_lastName), age(_age) {}

    /*
        str1.compare(str2) returns a integer
        
        0 if strings are equals
        1 if str1 goes after str2 in alphabetical order
        -1 if str1 goes before str2 in alphabetical order
    */
    bool operator<(const person& r) {
        return this->lastName.compare(r.lastName) == -1 ? true : false;
    }

    bool operator>(const person& r) {
        return this->lastName.compare(r.lastName) == 1 ? true : false;
    }

    bool operator==(const person& r) {
        return this->name.compare(r.name) == 0 && this->lastName.compare(r.lastName) == 0 && this->age == r.age;
    }

    /*
        A friend function inside a struct/class allows it to access at private or protected members
        of another classes. To overload << operator an output stream is necessary, and ostream
        is a protected C++ class so a friend overload must be implemented
    */
    friend ostream& operator<<(ostream& os, const person& p) {
        os << (p.name + ", " + p.lastName + ", " + to_string(p.age));
        return os;
    }
};
typedef person T;

struct node {
    T info;
    node* left,* right;

    node() : left(NULL), right(NULL) {}
    node(T _info) : info(_info), left(NULL), right(NULL) {}
};

void inOrder(node* tree);
void preOrder(node* tree);
void postOrder(node* tree);
void removeData(T e, node** tree);
T inOrderSuccesor(node* rightTree);
void insertInTree(T info, node** tree);

int main(void) {
    node* tree = NULL;

    insertInTree(T("Daniela", "Huezo", 22), &tree);
    insertInTree(T("Walter", "Morales", 20), &tree);
    insertInTree(T("Miguel", "Mesquita", 22), &tree);
    insertInTree(T("Enmanuel", "Amaya", 35), &tree);
    insertInTree(T("Xiomara", "Xiomara", 21), &tree);
    insertInTree(T("Andrea", "De Xiomara", 19), &tree);
    insertInTree(T("Edith", "Lopez", 80), &tree);
    insertInTree(T("Alejandro", "Pinto", 20), &tree);
    insertInTree(T("Jaime", "Serrano", 22), &tree);
    insertInTree(T("Alejandro", "Cader", 22), &tree);

    cout << "******************** InOrder traversal ********************" << endl;
    inOrder(tree);
    cout << endl << endl;

    cout << "******************** PreOrder traversal ********************" << endl;
    preOrder(tree);
    cout << endl << endl;

    cout << "******************** PostOrder traversal ********************" << endl;
    postOrder(tree);
    cout << endl << endl;

    cout << "******************** InOrder traversal after remove ********************" << endl;
    removeData(T("Walter", "Morales", 20), &tree);
    inOrder(tree);
    return 0;
}

/*
    Works for insertion in BST
    Receives T info to insert and double pointer node of root
    When tree is empty a node is created, otherwise searchs for 
    a correct insertion place depending of alphabetical order
*/
void insertInTree(T info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(info, &(*tree)->left);
        else
            insertInTree(info, &(*tree)->right);
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << endl;
        inOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->info << endl;
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->info << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

/*
    InOrder succesor is the element most at to the left of right
    subtree, if left subtree of right subtree is empty then
    succesor is rightsubtree.info
*/
T inOrderSuccesor(node* rightTree) {
    node* aux = rightTree;

    while(aux->left != NULL) {
        aux = aux->left;
    }

    return aux->info;
}

void removeData(T e, node** tree) {
    if(*tree) {
        if(e < (*tree)->info) {
            removeData(e, &(*tree)->left);
        }
        else if (e > (*tree)->info) {
            removeData(e, &(*tree)->right);
        }
        else {
            // If node to be deleted is leaf
            if(!(*tree)->left && !(*tree)->right) {
                node* auxDelete = *tree;
                *tree = NULL;
                delete auxDelete;
            }
            // If tree only has right side
            else if(!(*tree)->left && (*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->right;
                delete root;
            }
            // If tree only has left side
            else if((*tree)->left && !(*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->left;
                delete root;
            }
            // If tree is root
            else {
                // Find inorder succesor
                (*tree)->info = inOrderSuccesor((*tree)->right);
                // Delete inorder succesor
                removeData((*tree)->info, &(*tree)->right);
            }
        }
    }
}