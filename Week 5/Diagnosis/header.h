#pragma once

typedef const char* documentation;

enum departments { TECH, CLOTHES, GROCERIES };

template <class T>
struct node {
    T info;
    node* next;

    node() { next = nullptr; }
    node(T _info) : info(_info) {
        next = nullptr;
    }
};

struct product {
    documentation productID;
    double cost, price;

    product() {}
    product(documentation pID, double _cost, double _price) : 
    productID(pID), cost(_cost), price(_price) {}
};
typedef product P;

struct client {
    documentation clientID;
    bool vip;

    node<product>* products;

    client() { products = nullptr; }
    client(documentation cID, bool _vip) : clientID(cID), vip(_vip) { products = nullptr; }

    double calculateTotal() {
        node<product>* aux = products;
        double total = 0;

        while(aux) {
            total += aux->info.price;
            aux = aux->next;
        }

        return total;
    }
};
typedef client C;

struct salesman {
    documentation personalID, businessID;
    int age, workedHours;
    departments dpt;

    node<client>* clients;

    salesman() { clients = nullptr; }
    salesman(documentation pID, documentation bID, int _age, int wh, departments _dpt) :
    personalID(pID), businessID(bID), age(_age), workedHours(wh), dpt(_dpt) {
        clients = nullptr;
    }

    double calculateSales() {
        node<client>* aux = clients;
        double total = 0;

        while(aux) {
            total += aux->info.calculateTotal();
            aux = aux->next;
        }

        return total;
    }
};
typedef salesman S;

template <class T>
void pushFront(T info, node<T>** stack) {
    node<T>* n = new node<T>(info);

    n->next = *stack;
    *stack = n;
}