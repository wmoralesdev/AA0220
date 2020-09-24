#include <functional>
#include <iostream>
using namespace std;

template<class T>
struct node {
    T info;
    node<T>* next;

    node() {}
    node(T _info) : info(_info) { next = NULL; }
};

template <class T>
T sumatory(T* arr, int size);

template<class T>
void pushBack(node<function<void()>>** de, T info);

template <class T, class E>
void printData(T d1, E d2);

int main(void) {
    printData(20, "salu2");
    // node<int>* listInt = NULL;
    // node<double>* listDouble = NULL;
    // node<string>* listString = NULL;
    // node<function<void()>>* listFunction = NULL;

    // auto lambda = []() {
    //     cout << "Hola ";
    // };

    // auto lambda2 = []() {
    //     cout << "que ";
    // };

    // auto lambda3 = []() {
    //     cout << "tal";
    // };

    // pushBack(&listFunction, lambda);
    // pushBack(&listFunction, lambda2);
    // pushBack(&listFunction, lambda3);

    // while(listFunction) {
    //     listFunction->info();
    //     listFunction = listFunction->next;
    // }

    // tempStruct<int> a;
    // tempStruct<double> d;
    // tempStruct<string> s;
    // double arr[] = { 1.12, 1.13 };
    // int arrInt[] = { 1, 2, 3 };
    // float arrFloat[] = { 1.12, 1.13 };

    // cout << sumatory(arr, 2) << endl;
    // cout << sumatory(arrInt, 3) << endl;
    // cout << sumatory(arrFloat, 2) << endl;

    return 0;
}

template<class T>
void pushBack(node<function<void()>>** de, T info) {
    node<function<void()>>* n = new node<function<void()>>(info);

    node<function<void()>>* aux = *de;

    if(!*de) {
        *de = n;
    }
    else {
        while (aux->next)
        aux = aux->next;
    
        aux->next = n;
    }
}

template <class T, class E>
void printData(T d1, E d2) {
    cout << d1 << " " << d2 << endl;
}

template <class T>
T sumatory(T* arr, int size) {
    T total = 0;

    for(int i = 0; i < size; i++)
        total += arr[i];

    return total;
}