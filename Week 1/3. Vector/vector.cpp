#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // Declaring vector
    vector<int> vct;

    // Declaring iterator for vct
    vector<int>::iterator it;

    // Adding values to vector
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(3);
    vct.push_back(4);
    vct.push_back(5);
    vct.push_back(6);
    vct.push_back(7);
    vct.push_back(8);
    vct.push_back(9);
    vct.push_back(0);

    // Traveling every element with iterator
    cout << "Vector: ";
    for(it = vct.begin(); it != vct.end(); it++)
        cout << *it << "  ";
    cout << endl << endl;

    // Restoring iterator to vector begin
    it = vct.begin();
    
    // Using advance and inserter
    vector<int> medium = {30, 40, 50};

    // Advance increases iterator nth positions
    advance(it, 2);
    cout << "Iterator after advancing: " << *it << endl;

    // Copying medium vector content from begin to end, inserted in vct at iterator position
    copy(medium.begin(), medium.end(), inserter(vct, it));

    // Traveling every element with iterator
    cout << "Vector after inserter(): ";
    for(it = vct.begin(); it != vct.end(); it++)
        cout << *it << "  ";
    cout << endl << endl;

    // Restoring iterator to vector begin
    it = vct.begin();

    // next returns iterator pointing to the element advancing n positions
    vector<int>::iterator nxt = next(it, 2);
    cout << "Iterator at next(): " << *nxt << endl;

    // Restoring iterator to vector end
    it = vct.end();

    // prev returns iterator pointing to the element advancing -n positions
    vector<int>::iterator prv = prev(it, 4);
    cout << "Iterator at prev(): " << *prv << endl;

    return 0;
}