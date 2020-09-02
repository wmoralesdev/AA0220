/* 
    Create a struct that holds a lambda function for each of this scenarios:
        * A lambda that returns the sumatory of an array
        * A lambda that returns the sumatory of a vector
        * A lambda that returns the multiplicatory of an array
        * A lambda that returns the multiplicatory of a vector
        * A lambda that returns the average of an array
        * A lambda that returns the average of a vector
*/
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

// Struct with every lambda
struct storedLambdas{
    function<int(vector<int>)> vectorSumatory, vectorMultiplicatory, vectorAverage;
    function<int(int, int*)> arraySumatory, arrayMultiplicatory, arrayAverage;
};

int main(void) {
    // Struct var
    storedLambdas sl;

    // Lambda definitions
    sl.arraySumatory = [](int size, int* array) -> int {
        int aux = 0;
        for(int i = 0; i < size; i++)
            aux += array[i];
        return aux;
    };

    sl.arrayMultiplicatory = [](int size, int* array) -> int {
        int aux = 1;
        for(int i = 0; i < size; i++)
            aux *= array[i];
        return aux;
    };

    // [sl] is capture clause, allows to use external variables inside lambda
    sl.arrayAverage = [sl](int size, int* array) -> int {
        return (double)sl.arraySumatory(size, array) / size;
    };

    /*
        Also valid
        
        sl.arrayAverage = [](int size, int* array) -> int {
            int aux = 0;
            for(int i = 0; i < size; i++)
                aux += array[i];
            return (double)aux / size;
        };

    */

    sl.vectorSumatory = [](vector<int> v) -> int {
        int aux = 0;
        for(int e : v)
            aux += e;
        
        return aux;
    };

    sl.vectorMultiplicatory = [](vector<int> v) -> int {
        int aux = 1;
        for(int e : v)
            aux *= e;
        
        return aux;
    };

    sl.vectorAverage = [sl](vector<int> v) {
        return (double)sl.vectorSumatory(v) / v.size();
    };

    /*
        Also valid

        sl.vectorAverage = [](vector<int> v) -> int {
            int aux = 0;
            for(int e : v)
                aux += e;

            return (double)aux / v.size();
        };
    */

    return 0;
}