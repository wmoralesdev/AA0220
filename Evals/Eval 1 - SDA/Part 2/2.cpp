/* 
    Create template functions to execute the following operations with any number type of variables:
        * Sumatory of an array
        * Sumatory of a vector
        * Multiplicatory of an array
        * Multiplicatory of a vector
        * Average of an array
        * Average of a vector
*/

#include <vector>
#include <iostream>
#include <functional>
using namespace std;

// Templates return Num value and receive Num array or vector
template<class Num>
Num arraySumatory(int size, Num array);

template<class Num>
Num arrayMultiplicatory(int size, Num array);

template<class Num>
Num arrayAverage(int size, Num array);

template<class Num>
Num vectorSumatory(vector<Num> v);

template<class Num>
Num vectorMultiplicatory(vector<Num> v);

template<class Num>
Num vectorAverage(vector<Num> v);

int main(void) {
    
}

template <class Num>
Num arraySumatory(int size, Num array) {
    int aux = 0;

    for(int i = 0; i < size; i++)
        aux += array[i];
    return aux;
}

template <class Num>
Num arrayMultiplicatory(int size, Num array) {
    int aux = 0;
        for(int i = 0; i < size; i++)
            aux *= array[i];
        return aux;
}

template <class Num>
Num arrayAverage(int size, Num array) {
    return (double)arraySumatory(size, array) / size;
}

template <class Num>
Num vectorSumatory(vector<Num> v) {
    int aux = 0;
    for(int e : v)
        aux += e;
    
    return aux;
}

template <class Num>
Num vectorMultiplicatory(vector<Num> v) {
    int aux = 1;
    for(int e : v)
        aux *= e;
    
    return aux;
}

template <class Num>
Num vectorAverage(vector<Num> v) {
    return (double)vectorSumatory(v) / v.size();
}