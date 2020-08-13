#include <iostream>
using namespace std;

// template<class type> must be above every function prototype
template<class T>
T getMax(T a, T b);

int main(void) {
    // Using template with int type
    int a = 9, b = 15;
    cout << getMax<int>(a, b) << endl;

    // Using template with double type
    double c = 9.231, d = 123.212;
    cout << getMax<double>(c, d) << endl;

    return 0;
}

// Template allows to receive and return generic type
template<class T>
T getMax(T a, T b) {
    return a >= b ? a : b;
}