#include <iostream>
using namespace std;

void printFormat(string);

int odd(int);
int even(int);
bool oddEven(int);
int factorial(int);
int fibonacci(int);
void printPattern(int, int);
string reverseString(string);
void hanoi(int, char, char, char);

int movs = 0;

int main(void) {
    printFormat("Factorial");
    cout << factorial(4) << endl << endl;

    printFormat("Fibonacci");
    cout << fibonacci(5) << endl << endl;

    printFormat("Recursive pattern");
    printPattern(1, 6);
    cout << endl << endl;

    printFormat("Hanoi towers");
    hanoi(3, 'A', 'C', 'B');
    cout << endl << endl;

    printFormat("Odd-Even");
    int num = 8;
    cout << "Number " << num << " is even: " << ((oddEven(num)) ? "true" : "false") << endl << endl;

    printFormat("Reverse string");
    cout << reverseString("Reverting") << endl << endl;
}

void printFormat(string toPrint) {
    cout << "-------------------------" << endl;
    cout << toPrint << endl;
    cout << "-------------------------" << endl;
}

#pragma region factorial
int factorial(int n) {
    // Debugging print
    cout << "Current op: " << n << " * " << ((n - 1) == 0 ? "" : to_string(n - 1)) << endl;

    // Base case: when n == 0 or n == 1 recursion stops
    // Recursive call: implies that there are pending processes -> n * !(n - 1)
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}
#pragma endregion

#pragma region fibonacci
int fibonacci(int n) {
    /*  Base case: when n == 0 or n == 1
        Recursive call: two calls for n - 1 and n - 2
        Recursive formula: 
            {
                F(0) = 1
                F(1) = 1
                F(n) = F(n - 1) + F(n - 2)
            }
    */
    return (n == 0 || n == 1) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}
#pragma endregion

#pragma region pattern
void printPattern(int start, int n) {
    // Base case: when starting number equals limit (n)
    // Recursive call: one call between two prints (before and after incrementing starting number by 1)
    if(start < n) {
        cout << start << " ";
        printPattern(start + 1, n);
        cout << start << " ";
    }
    else
        cout << n << " ";
}
#pragma endregion

#pragma region hanoi
void hanoi(int discs, char from, char to, char aux) {
    /*
        Hanoi restrictions:
            * There are 3 rods: A = origin, B = auxiliar, C = destiny
            * You cannot move more than one disc at a given time
            * You cannot place a bigger disc (current > base) on top of a smaller one
            * Every disc needs to rest in destiny rod (C)
        Base case: when there is only one disc remaining it's moved to destiny rod (C)
        Recursive call: first the smallest disc (sm) needs to be moved to destiny rod (C)
                        so sm - 1 can be moved to auxiliar rod (B),
                        second, sm needs to be moved at auxiliar rod (B) on top of sm - 1
                        so bigger disc can be moved to destiny (C)
    */
    if(discs == 1){
        cout << ++movs << ". Move disk 1 from " << from << " to " << to << endl;
    }
    else {
        hanoi(discs - 1, from, aux, to);
        cout << ++movs << ". Move disk " << discs << " from " << from << " to " << to << endl;
        hanoi(discs - 1, aux, to, from);
    }
}
#pragma endregion

#pragma region odd-even
bool oddEven(int n) {
    // Indirect recursion: n functions calling each other
    return even(n);
}

/*
    Base case:  between even and odd functions, when n == 0 a number should be returned
                to indicate oddity, depending on last called function oddity is determined

    Recursive calls: 
        For even: should call odd with n - 1
        For odd: should call even with n - 1
*/
int even(int n) {
    return (n == 0) ? 1 : odd(n - 1);
}

int odd(int n) {
    return (n == 0) ? 0 : even(n - 1);
}
#pragma endregion

#pragma region reverse-string
string reverseString(string s) {
    cout << "Given s: " << s << endl;

    // Base case: when string length reaches 1 it cannot be reversed
    // Recurive call:   first letter should be send to last position, and reverse
    //                  substring without it
    return (s.length() <= 1) ? s : reverseString(s.substr(1)) + s.at(0);
}
#pragma endregion