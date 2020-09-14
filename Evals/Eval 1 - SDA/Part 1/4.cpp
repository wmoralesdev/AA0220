// Recursive matrix pattern fill
#include <iostream>
using namespace std;

void storeInMatrix(int** matrix, int size, int val);

int main(void) {
    int n = 0;
    cin >> n;

    // Create matrix as double ptr
    int** mat = new int*[n];

    for(int i = 0; i < n; i++)
        mat[i] = new int[n];

    // Fill matrix
    storeInMatrix(mat, n, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    cout << endl;
    return 0;
}

void storeInMatrix(int** matrix, int size, int val) {
    // Base case: if value to fill is less than size
    if(val < size) {
        // Store in every col
        for(int i = 0; i < size; i++)
            matrix[i][val] = val + 1;

        // Store in every row
        for(int i = 0; i < size; i++)
            matrix[val][i] = val + 1;

        // Recurse with next val 
        storeInMatrix(matrix, size, val + 1);
    }
}