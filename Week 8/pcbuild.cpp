/*
    You just bought all components for your new PC!
    You start placing the CPU in the moherboard socket, gently applying a small layer of thermal paste.
    Then it's time to place the motherboard in the case, after that the process is pretty straight forward.
    But, the time of cable management has come. You don't like how you made the work so you need to find a way
    to make it look clean and nice.

    Every component has a cable to be conected, each cable has a k value representing the lenght of it.
    The components that go straight into the motherboard (without a cable) have a lenght of 0.

    After giving some thought to it, you think that the best way to make it look clean is to find a nice way to
    sort the process. You then think of an algorithm that follows:
    • You need to place first every component that goes straight into the motherboard
    • All components with even length needs to be placed from higher to lower length
    • All components with odd length needs to be placed from lower to higher length
    • Special components (prime number length) need to be placed last in any particular order

    Your output will be the component names in the order that need to be placed
*/

// Cambiarlo a lista doble
// Implementarlo en un BST -> Usar inOrder, inOrder reverse

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

struct component {
    string name;
    int len;

    component() {}
    component(string _name, int _len) : name(_name), len(_len) {}
};
typedef component T;

bool isPrime(int n);

int main(void) {
    vector<T> odd, even, prime;
    int n = 0, auxLen = 0;
    string auxCom = "";

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> auxCom >> auxLen;

        if(auxLen == 0)
            even.push_back(T(auxCom, auxLen));
        else if(isPrime(auxLen))
            prime.push_back(T(auxCom, auxLen));
        else
            (auxLen % 2 == 0) ? even.push_back(T(auxCom, auxLen)) : odd.push_back(T(auxCom, auxLen));
    }

    even.sort();    // DESC
    odd.sort();     // ASC
    prime.sort();   // ASC - DESC - No sorted

    for(T aux : even) {
        cout << aux.name << endl;
    }

    for(T aux : odd) {
        cout << aux.name << endl;
    }

    for(T aux : prime) {
        cout << aux.name << endl;
    }

    return 0;
}

bool isPrime(int n) {
    for(int i = 2; i < sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}