#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;

};
typedef node N;

void printStk(node *);
void push(node ** , int );
int pop(node** );
void pushNode(node **, node*);

 void Invert(node **,node **,int x);

int main (void){
    node *stk = NULL ;
    node *newStk = NULL ;
    int c;

    for(int i=0; i<5 ;i++){
        cout << "Dijite un numero " ; cin >> c;
    push(&stk,c);
    }
    cout<< "La pila es: " <<endl; 
    printStk(stk) ;
    cout << endl;

     cout<< "La pila invertida es: " <<endl; 
    
    
    Invert(&stk,&newStk,5);
   
    return 0;
}

void push(node ** stack, int data){
 node * n = new node;
    n->data = data;

    n->next = *stack;
    *stack = n;
}

void printStk(node *stk){
    if(stk){
        cout << stk->data << " ";
        printStk(stk->next);
    }
}
void pushNode(node ** nueva, node * n){
    node * nodo = new node;
    nodo->data = n->data;

    nodo->next = *nueva;
    *nueva = nodo;
}

void Invert( node **stk, node **nueva,int x) {
    node * aux = NULL;
   if(*stk){
       push(nueva, pop(stk));
        Invert (stk,nueva,5);
   }else{
       aux=*nueva;
     printStk(aux);
     cout << endl;
   }
 }
    
  
   


int pop(node** s) {
    node* aux = *s;

    *s = (*s)->next;

    return aux->data;

    delete aux;
}