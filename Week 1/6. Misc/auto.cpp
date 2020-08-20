#include <iostream>
using namespace std;

int getMax(int, int);

int main(void) {
    // Auto inferres variable type
    auto integer1 = 2, interger2 = 4;
    auto doubleVar = 27.12343131;
    auto stringVar = "Using auto!";

    // Storing function in variable
    auto function = getMax;
    cout << function(2, 4) << endl;

    return 0;
}

int getMax(int a, int b) {
    return a >= b ? a : b;
}