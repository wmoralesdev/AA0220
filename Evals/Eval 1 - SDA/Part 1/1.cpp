// Pascal's triangle - with vector of pointers
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // Vector containing ptrs
    vector<int*> pascal;

    // Exemplify for n = 12
    int n = 12;

    // Instantiating every position of the vector
    for(int i = 0; i < n; i++)
        pascal.push_back(new int[i + 1]);

    // Filling for n = 0 or n = 1
    pascal.at(0)[0] = 1;
    pascal.at(1)[0] = pascal.at(1)[1] = 1;
    

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= i; j++)
            // if j is first or last element, fill with 1
            if(j == i || j == 0)
                pascal.at(i)[j] = 1;
            else
            // else calculate current with the two above
                pascal.at(i)[j] = pascal.at(i - 1)[j - 1] + pascal.at(i - 1)[j];

    // Print vector
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            cout << pascal.at(i)[j] << "\t";
        cout << endl;
    }
}