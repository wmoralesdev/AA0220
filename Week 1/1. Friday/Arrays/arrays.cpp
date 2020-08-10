#include <iostream>
#include <array>
using namespace std;

void fillArray(int*, int);
void printArray(int*, int);
void printArray(array<int, 4>);

int main(void) {
    // Initialized array
    int arr[] = {1, 2, 3, 4};
    printArray(arr, 4);

    // Fixed size array
    int fixedArray[5];
    fillArray(fixedArray, 5);
    printArray(fixedArray, 5);

    // Dynamic sized array
    int size = 10;
    int dynamicArray[size];
    fillArray(dynamicArray, size);
    printArray(dynamicArray, size);

    // Pointer as array
    int* pointer = new int[size];
    fillArray(pointer, size);
    printArray(pointer, size);

    // Array created with include (since C++ 17)
    array<int, 4> includeArray;

    for(int i = 0; i < 4; i++)
        includeArray.at(i) = i + 1;

    printArray(includeArray);
}

void fillArray(int* arr, int size) {
    for(int i = 0; i < size; i++)
        arr[i] = i + 1;
}

void printArray(int* arr, int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void printArray(array<int, 4> arr) {
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << "\t";
    cout << endl;
}