// Function that receives conditional
#include <iostream>
using namespace std;

template<class Conditional>
bool evaluateConditional(Conditional c, string s);

int main(void) {
    // Examples of condition

    // Test condition - search for blank spaces in string
    cout << evaluateConditional([](string s) -> bool {
        return s.find(' ') != -1;
    }, "Hola que tal") << endl;

    // Test condition - determine if string starts with vowel
    cout << evaluateConditional([](string s) -> bool {
        return s.at(0) == 'a' || s.at(0) == 'e'|| s.at(0) == 'i' || s.at(0) == 'o' || s.at(0) == 'u';
    }, "Hola que tal") << endl;
}

template<class Conditional>
bool evaluateConditional(Conditional c, string s) {
    return c(s);
}