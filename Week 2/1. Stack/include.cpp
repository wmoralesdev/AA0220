#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    // Declaring int stack
    stack<int> s;

    // Empty - returns boolean indicating if stack has elements
    cout << "Stack is empty: " << (s.empty() ? "true" : "false") << endl << endl;

    // Push - stacks elements
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // Size - returns elements count
    cout << "Size: " << s.size() << endl << endl;

    // Top - returns a read/write reference to top element
    cout << "Top before modifying: " << s.top() << endl;
    s.top() = 20;
    cout << "Top after modifying: " << s.top() << endl << endl;
    
    // Pop - removes top element from stack
    s.pop();
    cout << "Top after popping: " << s.top() << endl << endl;

    // Swap - swaps contents from stack1 to stack2, stacks need to be of same type but 
    // can be different size
    stack<int> t;

    t.push(10);
    t.push(20);

    // Verifying top of each stack
    cout << "t top: " << t.top() << endl;
    cout << "s top: " << s.top() << endl << endl;

    s.swap(t);

    // Verifying top of each stack after swapping - now t is s, and s is t
    cout << "t top: " << t.top() << endl;
    cout << "s top: " << s.top() << endl;

    return 0;
}