// Pascal's triangle - with vector of vectors
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // Vector of vectors to store data
    vector<vector<int>> pascal;

    // Exemplify for n = 12
    int n = 12;

    // Filliing for n = 0 or n = 1
    pascal.push_back(vector<int> {1});
    pascal.push_back(vector<int> {1, 1});
    
    for(int i = 2; i < n; i++){
        // Declaring aux vector to fill with elements for current triangle row
        vector<int> auxiliar = {};
        for(int j = 0; j <= i; j++) {
            // Using aux value to push at vector
            int aux = 0;
            
            // If j == end or first fill with 1
            if(j == i || j == 0)
                aux = 1;
            else
            // else calculate current with the two above it
                aux = pascal[i - 1][j - 1] + pascal[i - 1][j];

            // Push aux every time to auxiliar vector
            auxiliar.push_back(aux);
        }
        // Push auxiliar vector to main vector
        pascal.push_back(auxiliar);
    }

    // Print triangle with format
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            cout << pascal[i][j] << "\t";
        cout << endl;
    }
}