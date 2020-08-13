#include <iostream>
#include <functional>
using namespace std;

#pragma region struct
/*
    Functional include approach
        * A function can be declared as function<returnType(parameters)> signature;
        * Works as a variable, can be overwritten
*/
struct storedLambdas {
    function<int(int, int)> getMin, getMax;
};
#pragma endregion

int main(void) {
    /*
    Lambda syntax
        [] : lambda begin
        () : parameters (optional)
        -> type : return type (optional)
        {
            // lambda body
        }
    */

    auto parameterlessLambda = []() -> string {
        return "Lambda execution";
    };

    auto lambda = [](int age, string name) {
        cout << name << " greets you!" << endl;
        return age * 2;
    };

    cout << "Parameterless lambda begin: " << parameterlessLambda() << endl;
    cout << "Lambda begin: " << parameterlessLambda() << endl;

    // Storing lambdas in struct field
    storedLambdas sl;

    sl.getMin = [](int a, int b) -> int {
        return a >= b ? b : a;
    };

    sl.getMax = [](int a, int b) -> int {
        return a >= b ? a : b;
    };

    cout << "Min in storedLambdas: " << sl.getMin(9, 0) << endl;
    cout << "Max in storedLambdas: " << sl.getMax(9, 0) << endl;

    return 0;
}