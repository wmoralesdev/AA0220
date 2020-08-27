#include <iostream>
using namespace std;

struct nodeData {
    int data;
};
typedef nodeData T;

struct node {
    T info;
    node* next;
};

char isEmpty(node*);

int main(void) {
    node* list = NULL;
    
    cout << isEmpty(list) << endl;

    return 0;
}

char isEmpty(node* list) {
    return list == NULL ? '0' : 'N';
}