#include <iostream>
using namespace std;

void parameterAsValue(int);
void parameterAsReference(int&);
void parameterAsReferencePtr(int*);

int main(void) {
    int variable = 20;
    int* pointer = NULL;

    // ERROR: cannot assing value to mem address
    // pointer = 45;

    pointer = &variable;

    // Accessing to pointing mem address
    cout << "Mem address: " << pointer << endl;

    // Accessing to mem address value contained
    cout << "Value contained: " << *pointer << endl << endl;

    // Pointer to access a mem contained in pointer already
    int** pointerToPointer;
    pointerToPointer = &pointer;

    // Double pointer mem address
    cout << "DoublePointer mem address: " << pointerToPointer << endl;

    // Double pointer containing mem address
    cout << "Mem address contained in DoublePointer: " << *pointerToPointer << endl;

    // Value contained at double pointer mem address
    cout << "Value contained at DoublePointer mem address: " << **pointerToPointer << endl << endl;

    int*** triplePointer;
    triplePointer = &pointerToPointer;

    // TriplePointer mem address
    cout << "Triple pointer mem address: " << triplePointer << endl;

    // Mem address contained in TriplePointer
    cout << "Mem address contained in TriplePointer: " << *triplePointer << endl;

    // TriplePointer contained address address
    cout << "Mem address contained in TriplePointer mem address: " << **triplePointer << endl;

    // TriplePointer last references = contained value
    cout << "Value contained at TriplePointer: " << ***triplePointer << endl << endl;

    // Parameter types - value, ref, and ptr ref
    cout << "Variable before every function invoke: " << variable << endl << endl;

    cout << "Variable before parameterAsReference: " << variable << endl;
    parameterAsReference(variable);
    cout << "Variable after parameterAsReference: " << variable << endl << endl;

    cout << "Variable before parameterAsValue: " << variable << endl;
    parameterAsValue(variable);
    cout << "Variable after parameterAsValue: " << variable << endl << endl << endl;

    cout << "Variable before parameterAsReferencePtr: " << variable << endl;
    parameterAsReferencePtr(&variable);
    cout << "Variable after parameterAsReferencePtr: " << variable << endl << endl;

    return 0;
}

void parameterAsReference(int& ref) {
    cout << "Value in function: " << (ref *= 2) << endl;
}

void parameterAsReferencePtr(int* ptr) {
    cout << "Value in function: " << (*ptr *= 2) << endl;
}

void parameterAsValue(int val) {
    cout << "Value in function: " << (val *= 2) << endl;
}