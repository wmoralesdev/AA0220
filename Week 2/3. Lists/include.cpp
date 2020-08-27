// Linked list, not circular, not double linked
#include <iostream>
#include <list>
using namespace std;

int main(void) {
    list<int> l;

    // push_back - appends element at list end
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    // push_front - inserts element at list start
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);

    // empty - returns boolean indicating if list has elements
    cout << "List is empty: " << (l.empty() ? "true" : "false") << endl << endl;

    // size - returns elements count
    cout << "Size: " << l.size() << endl << endl;

    #pragma region iterators
    // begin - returns read / write reference to element (similar to front)
    auto itBegin = l.begin();
    cout << "Begin element before modifying  is: " << *itBegin << endl;
    *itBegin = 1;
    cout << "Begin element after modifying is: " << *itBegin << endl << endl;

    // end - returns read / write reference pointing to one past last element
    auto itEnd = l.end();
    // Iterator prev to actual last element of list
    itEnd = prev(itEnd, 1);
    cout << "End element before modifying is: " << *itEnd << endl;
    *itEnd = 999;
    cout << "End element after modifying is: " << *itEnd << endl<< endl;

    // cbegin - returns read only reference to element
    auto cBegin = l.cbegin();
    cout << "Begin element: " << *cBegin << endl;
    
    // cend - returns read only refrerence pointing to one past last element
    auto cEnd = l.cend();
    cEnd = prev(cEnd, 1);
    cout << "End element: " << *cEnd << endl;

    #pragma endregion

    // back - returns read / write referente pointing to last element (not as iterator)
    auto bck = l.back();

    // remove_if - deletes elements based on boolean predicative (boolean typed function)
    cout << "Printing elements before deleting even numbers" << endl;
    for(auto iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter << "  ";
    }
    cout << endl << endl;
    
    // predicative is a lambda
    l.remove_if([](int e) -> bool {
        return e % 2 == 0;
    });
    cout << "Printing elements after deleting even numbers" << endl;
    for(auto iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter << "  ";
    }
    cout << endl << endl;

    return 0;
}
