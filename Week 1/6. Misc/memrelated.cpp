#include <iostream>
using namespace std;

int main(void) {
    /*
        A void pointer is a non type associated pointer. Any type of data can be stored within it as 
        it has no restriction

        PD: A void pointer cannot be deferenced, a explicit cast must exist first
    */
    int ref = 20;
    void* ptr = &ref;

    // ERROR: expression does not detect ptr as pointer
    // cout << *ptr << endl;

    cout << "Value contained in: " << *(int*)ptr << endl;

    // Changing ref type
    char ch = 'C';
    ptr = &ch;
    cout << "Value contained in: " << *(char*)ptr << endl;

    /* 
        C malloc vs C++ new 

        When memory needs to be reserved for a pointer, or another data type as objects or arrays
        malloc and new can be used BUT they are not exactly for the same use, also they have
        proper methods to clean memory after ussage

        malloc - it's a function that returns a void pointer, needs to be casted to required
        type, also size of reservation needs to be sent as parameter (usually used with sizeof). 
        On failure, malloc returns a NULL reference. Every mem reserved with malloc is from heap.
        malloc also allows to reallocate mem with realloc

        new - C++ operator for calling type constructor, allows to initialize primitive data types also.
        Returns the exact data type needed when allocating memory, and size is calculated by the compiler.
        On failure, bad_alloc exception is returned, making it ussage way more secure than malloc

        When malloc reserved, memory should be freed, when new reserving memory should be deleted.
        free and delete cannot be interchanged (e.g. malloc/delete, new/free are incorrect ussages)
    */

    // Creating dynamic arrays 
    int size = 6;
    
    // malloc reserving - (cast)malloc(size)
    // Calculation of space is a must, using size of array times sizeof int (bytes)
    int* mallocArr = (int*)malloc(size * sizeof(int*));

    // Filling array with pointer arithmetics
    for(int i = 0; i < size; i++)
        *(mallocArr + i) = i + 1;

    cout << "Malloc array" << endl;
    for(int i = 0; i < size; i++)
        cout << *(mallocArr + i) << "  ";
    cout << endl << endl;

    // new reserving - size is calculated by compiler
    int* newArr = new int[size];

    // Filling array with pointer arithmetics
    for(int i = 0; i < size; i++)
        *(newArr + i) = *(mallocArr + i) * 2;

    cout << "New array" << endl;
    for(int i = 0; i < size; i++)
        cout << *(newArr + i) << "  ";
    cout << endl << endl;

    // Deallocating malloc reserved memory
    free(mallocArr);

    // Deallocating new reserved memory
    delete[] newArr;

    return 0;
}