#include <iostream>
using namespace std;

// Anidated structure (inner)

struct addressMod {
    string state, city;
};

// Struct for Person data
struct person {
    string name, lastname;
    addressMod address;
    int age;
};

int main(void) {
    // Person variable
    person onePerson;

    // Accessing data fields inside struct
    onePerson.name = "Walter";
    onePerson.lastname = "Morales";
    onePerson.age = 20;

    // Accessing anidated data fields inside struct
    onePerson.address.city = "Santa Tecla";
    onePerson.address.state = "La Libertad";

    // Dynamic array of structures - Always initialized to null or declare instantiated
    person* algorithmClass = NULL;
    algorithmClass = new person[2];

    // Ways to access pointer type struct fields
    // With [] notation
    // Accessing data fields inside struct
    algorithmClass[0].name = "Walter";
    algorithmClass[0].lastname = "Morales";
    algorithmClass[0].age = 20;

    // Accessing anidated data fields inside struct
    algorithmClass[0].address.city = "Santa Tecla";
    algorithmClass[0].address.state = "La Libertad";

    // With -> notation: replaces *.
    // Accessing data fields inside struct
    (algorithmClass + 1)->name = "Enmanuel";
    (algorithmClass + 1)->lastname = "Amaya";
    (algorithmClass + 1)->age = 35;

    // Accessing anidated data fields inside struct
    (algorithmClass + 1)->address.city = "Santa Tecla";
    (algorithmClass + 1)->address.state = "La Libertad";


    /*
        Freeing and deleting mem allocated spaces

        When a pointer or array var type is allocated malloc reserved should be freed,
        in any other case should be deleted
    */

    int referenceVar;

    // Free example
    int* pointer1 = (int *)malloc(sizeof(int));

    // After ussage
    free(pointer1);

    // Delete example - Safe to use because there aren't any stack related mem allocations
    int* pointer2 = new int;
    int* pointer3 = NULL;

    delete pointer2;
    delete pointer3;

    return 0;
}