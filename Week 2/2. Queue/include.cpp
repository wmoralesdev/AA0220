#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    // Declaring in queue
    queue<int> q;

    // Pushing elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Empty - returns boolean indicating if queue has elements
    cout << (q.empty() ? "true" : "false") << endl << endl;

    // Size - returns element count
    cout << "Size: " << q.size() << endl << endl;

    // Front / Back - return reference to corresponding element position
    cout << "Front and back before modifying: " << q.front() << ", " << q.back() << endl;
    q.front() = 100;
    q.back() = 500;
    cout << "Front and back after modifying: " << q.front() << ", " << q.back() << endl << endl;

    // Pop - removes element at front of queue 
    q.pop();
    cout << "Front: " << q.front() << endl << endl;

    // Swap - swaps contents from queue1 to queue2, queues need to be of same type but differente size
    queue<int> r;

    r.push(4);
    r.push(6);

    // Verifying front of each queue
    cout << "q top: " << q.front() << endl;
    cout << "r top: " << r.front() << endl << endl;

    q.swap(r);

    // Verifying top of each stack after swapping - now t is s, and s is t
    cout << "q top: " << q.front() << endl;
    cout << "r top: " << r.front() << endl;

    return 0;
}