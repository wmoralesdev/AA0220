#include "header.h"
#include <string>
#include <iostream>
using namespace std;

int main(void) {
    node<salesman>* employees = NULL;
    int emp = 0, cl = 0, prod = 0;

    cin >> emp;
    for(int i = 0; i < emp; i++) {
        string doc1 = "", doc2 = "";
        int age = 0, wh = 0, area = 0;

        cin >> doc1 >> doc2 >> age >> wh >> area;
        pushFront(S(doc1.c_str(), doc2.c_str(), age, wh, (departments)area), &employees);

        cin >> cl;
        for(int j = 0; j < cl; j++) {
            string clDoc = "";
            int vip = 0;

            cin >> clDoc >> vip;
            pushFront(C(clDoc.c_str(), vip), &employees->info.clients);

            cin >> prod;
            for(int k = 0; k < prod; k++) {
                string prDoc = "";
                double cost = 0, price = 0;

                cin >> prDoc >> cost >> price;
                pushFront(P(prDoc.c_str(), cost, price), &employees->info.clients->info.products);
            }
        }
    }
    cout << endl;

    int aux = 0;
    while(employees) {
        cout << ++aux << ". $" << employees->info.calculateSales() << endl;
        employees = employees->next;
    }

    return 0;
}