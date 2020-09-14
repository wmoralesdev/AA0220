#pragma once

typedef const char* documentation;

enum departments { TECH, CLOTHES, GROCERIES };

template<class T>
struct node {
    T info;
    node* next;

    node() { next = NULL; }
    node(T _info) : info(_info) { next = NULL; }
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

    node<product>* articles;

    client() { articles = NULL; }
    client(documentation cID, bool _vip) : clientID(cID), vip(_vip) {
        articles = NULL;
    }

    double calculateTotal() {
        node<product>* aux = articles;
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
    int age, workHoursPerWeek;
    departments dpt;

    node<client>* clients;

    salesman() { clients = NULL; }
    salesman(documentation pID, documentation bID, int _age, int _whpw, departments _dpt) :
    personalID(pID), businessID(bID), age(_age), workHoursPerWeek(_whpw), dpt(_dpt) {
        clients = NULL;
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
void pushFront(T info, node<T>** list) {
    node<T>* n = new node<T>(info);

    n->next = *list;
    *list = n;
}