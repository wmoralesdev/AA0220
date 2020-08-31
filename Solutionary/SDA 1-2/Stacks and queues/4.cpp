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
    node *stk_pairs = NULL ;
    node *stk_odds = NULL ;
    int c,counter_pairs=0,counter_odds=0;

    for(int i=0; i<5 ;i++){
        cout << "Dijite un numero " ; cin >> c;
        if(c % 2== 0){
           cout<< "El numero es par" << endl;
            counter_pairs++;
           push(&stk_pairs,c);
        }
        else
        {
            cout<< "El numero es impar" << endl;
            push(&stk_odds,c);
            counter_odds++;
        }
        
   
    }
        cout<<"Cola de numeros pares: " <<endl;
        printStk(stk_pairs);
        cout << endl;
        cout<<"Cola de numeros impares: " <<endl;
        printStk(stk_odds);
        cout << endl;
        
        if(counter_odds >= counter_pairs){
            cout<<" Hay mas impares que pares" <<endl;
        }else{
            cout<<" Hay mas ares que impares" <<endl;
        }

    
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
   if(*stk){
       push(nueva, pop(stk));
        Invert (stk,nueva,5);
   }else{
     printStk(*nueva);
     cout << endl;
   }
 }
    
  
   


int pop(node** s) {
    node* aux = *s;

    *s = (*s)->next;

    return aux->data;

    delete aux;
}