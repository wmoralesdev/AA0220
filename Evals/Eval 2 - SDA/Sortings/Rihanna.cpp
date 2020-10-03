#include <iostream>
#define LENGTH 5          //Assumed value, it will be allowed
#define MAX_ITER 100

typedef struct Node{
    float sales;
    struct Node* next;
}Node;

typedef struct LabeledStack{
    int label;
    Node* stack;
}LabeledStack;

Node* Stackify(float* A, int* n){
    Node *S = new Node;
    S->sales = A[0];
    S->next = NULL;
    Node* temp = S->next;
    for(int i=1; i < *n; i++){
        temp->next = new Node;
        temp->next->sales = A[i];
        temp->next->next = NULL;
        temp = temp->next;
    }
    return S;
}

void StackArrays(int** n, float** m, LabeledStack* A){
    for(int k=0; k < **n; k++){
        int l = LENGTH;
        float* R = m[k];
        A[k].stack = Stackify(R, &l);
    }
}

int Decimals(float f){
    int d = 0;
    int maxiter = MAX_ITER;
    for(int i=0; i < maxiter; i++){
        int f_i = f;
        f = f - f_i;
        if(f == 0) break;
        else d++;
    }
    return d;
}

int CountNodes(Node* S){
    int cont = 0;
    Node* copy = S;
    while(copy != NULL){
        if(Decimals(copy->sales) == 3 && copy->next != NULL && Decimals(copy->next->sales) == 0) //It will be allowed
            cont++;
        copy = copy->next;
    }
    return cont;
}

void CountConditionNodes(int** n, LabeledStack* A){
    for(int k=0; k < **n; k++){
        int label = CountNodes(A[k].stack);
        A[k].label = label;
    }
}

void MinHeapify(LabeledStack* A, int i, int n){
    int l = 2 * i - 1;
    int r = l + 1;
    int smallest;
    if(l < n && A[l].label < A[i].label)
        smallest = l;
    else
        smallest = i;
    if(r < n && A[r].label < A[smallest].label)
        smallest = r;
    if(smallest != i){
        LabeledStack temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        MinHeapify(A, smallest, n);
    }
}

void BuildMinHeap(LabeledStack* A, int** n){
    for(int k=**n/2 - 1; k >= 0; k--)
        MinHeapify(A, k, **n);
}

void Heapsort(LabeledStack* A, int** n){
    BuildMinHeap(A, n);
    int l = **n;
    for(int i=**n - 1; i>=1; i--){
        LabeledStack temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        l = l - 1;
        MinHeapify(A, 0, l);
    }
}

void Rihanna(int* n, float** albums){
    LabeledStack A[*n];
    StackArrays(&n, albums, A);
    CountConditionNodes(&n, A);
    Heapsort(A, &n);
}
