#include <iostream>
using namespace std;

// Redefining type as custom, allows to replace int with custom
typedef int Colors;

// Redefining cat struct as pet
typedef struct cat {
    string furColor;
    int age;
} Pet;

// Typedef for int pointer
typedef int* integerPointer;

Colors main(void) {
    // Verifying types ID
    cout << (typeid(Colors).hash_code() == typeid(int).hash_code()) << endl;

    // Using custom type for variable
    Pet aPet;
    aPet.furColor = "White";
    aPet.age = 4;

    // Custom typedef var (pointer) reference to struct int field
    integerPointer pointer = &aPet.age;

    return 0;
}