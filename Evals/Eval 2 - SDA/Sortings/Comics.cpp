#include <iostream>
#define LENGTH 5          //Assumed value, it will be allowed
#define SENTINEL 999999   //Sentinel value for Merge Sort

typedef struct Node{
    int issue;
    struct Node* next;
}Node;

typedef struct LabeledQueue{
    int label;
    Node* queue;
}LabeledQueue;

// Al declarar
node* tree = NULL;
// Al enviar
insertInTree(3, &tree);

Node* Queueify(int* A, int* n){
    Node *Q = new Node;
    Q->issue = A[0];
    Q->next = NULL;
    Node* temp = Q->next;
    for(int i=1; i < *n; i++){
        temp->next = new Node;
        temp->next->issue = A[i];
        temp->next->next = NULL;
        temp = temp->next;
    }
    return Q;
}

void QueueArrays(int** n, int** m, LabeledQueue* A){
    for(int k=0; k < **n; k++){
        int l = LENGTH;
        int* R = m[k];
        A[k].queue = Queueify(R, &l);
    }
}

bool Prime(int n){
    if(n==1) return false;    //Some methods would say true here
    for(int i=2; i<=n-1; i++) //There are better methods, but this one is enough
        if(n % i == 0)
            return false;
    return true;
}

int CountNodes(Node* Q){
    int cont = 0;
    Node* copy = Q;
    while(copy != NULL){
        if(Prime(copy->issue) && copy->next != NULL && copy->next->next !=NULL && Prime(copy->next->next->issue)) //It will be allowed
            cont++;
        copy = copy->next;
    }
    return cont;
}

void CountConditionNodes(int** n, LabeledQueue* A){
    for(int k=0; k < **n; k++){
        int label = CountNodes(A[k].queue);
        A[k].label = label;
    }
}

void Merge(LabeledQueue* A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;
    LabeledQueue L[n1+1], R[n2+1];
    for(i=0; i < n1; i++)
        L[i] = A[p+i];
    for(j=0; j < n2; j++)
        R[j] = A[q+j+1];
    L[n1].label = R[n2].label = SENTINEL;
    i = j = 0;
    for(int k=p; k <= r; k++)
        if(L[i].label <= R[j].label){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
}

void MergeSort(LabeledQueue* A, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

void Comics(int* n, int** superheroes){
    LabeledQueue A[*n];
    QueueArrays(&n, superheroes, A);
    CountConditionNodes(&n, A);
    MergeSort(A, 0, *n - 1);
}

// Para modificar el arbol o acceder a su nodo actual
*tree = new node(20);

insertInTree(info, &(*tree)->left);