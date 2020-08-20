#include <iostream>
using namespace std;

// Declaring enum
enum availableColors { RED, BLACK, WHITE, BLUE };

// Declaring displaced enum
enum tech { SOFTWARE = 1, HARDWARE };

string enumToString(availableColors);

int main(void) {
    availableColors color = RED;

    // ERROR: cannot assing non enum value to enum type
    // color = BROWN;

    // Converting to string - printable format
    cout << enumToString(color) << endl;

    return 0;
}

string enumToString(availableColors e) {
    // Evaluating enums
    switch(e) {
        case RED:
            return "red";
        case BLACK:
            return "black";
        case WHITE:
            return "white";
        case BLUE:
            return "blue";
        default:
            return "not-found";
    }
}