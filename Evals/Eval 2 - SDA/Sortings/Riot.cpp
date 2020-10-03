#include <string>
#define LENGTH 5          //Assumed value, it will be allowed

using namespace std;

typedef struct Node{
    struct Node* prev;
    string team_name;
    struct Node* next;
}Node;

typedef struct LabeledDList{
    int label;
    Node* list;
}LabeledDList;

Node* DListify(string* A, int* n){
    Node *D = new Node;
    D->team_name = A[0];
    D->prev = D->next = NULL;
    Node* temp = D->next;
    for(int i=1; i < *n; i++){
        temp->next = new Node;
        temp->next->prev = temp;
        temp->next->team_name = A[i];
        temp->next->next = NULL;
        temp = temp->next;
    }
    return D;
}

void DListArrays(int** n, string** m, LabeledDList* A){
    for(int k=0; k < **n; k++){
        int l = LENGTH;
        string* R = m[k];
        A[k].list = DListify(R, &l);
    }
}

int CountNodes(Node* D){
    int cont = 0;
    Node* copy = D;
    while(copy != NULL){
        if(copy->team_name.length() >= 7 && copy->prev != NULL && copy->prev->team_name.length() % 2  == 0 &&
                    copy->next != NULL && copy->next->team_name.length() % 2  == 0)
            cont++;
        copy = copy->next;
    }
    return cont;
}

void CountConditionNodes(int** n, LabeledDList* A){
    for(int k=0; k < **n; k++){
        int label = CountNodes(A[k].list);
        A[k].label = label;
    }
}

void MaxHeapify(LabeledDList* A, int i, int n){
    int l = 2 * i - 1;
    int r = l + 1;
    int largest;
    if(l < n && A[l].label > A[i].label)
        largest = l;
    else
        largest = i;
    if(r < n && A[r].label > A[largest].label)
        largest = r;
    if(largest != i){
        LabeledDList temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest, n);
    }
}

void BuildMaxHeap(LabeledDList* A, int** n){
    for(int k=**n/2 - 1; k >= 0; k--)
        MaxHeapify(A, k, **n);
}

void Heapsort(LabeledDList* A, int** n){
    BuildMaxHeap(A, n);
    int l = **n;
    for(int i=**n - 1; i>=1; i--){
        LabeledDList temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        l = l - 1;
        MaxHeapify(A, 0, l);
    }
}

void Riot(int* n, string** branches){
    LabeledDList A[*n];
    DListArrays(&n, branches, A);
    CountConditionNodes(&n, A);
    Heapsort(A, &n);
}
