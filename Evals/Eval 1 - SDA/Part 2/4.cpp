// Create a function that recursively calculates the sum
// of every element in a matrix

#include <iostream>
using namespace std;

int matrixSumatory(int** mat, int cols, int dims);

int main(void) {
    int n = 2;

    int** mat = new int*[n];

    for(int i = 0; i < n; i++)
        mat[i] = new int[n];

    // Filling matrix
    int counter = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = ++counter;

    cout << matrixSumatory(mat, 0, n) << endl;
}

int matrixSumatory(int** mat, int rows, int dims) {
    int aux = 0;
    // Recursing until rows value is equal to matrix dimension
    if(rows < dims) {
        for(int i = 0; i < dims; i++) {
            // Accumulate value in aux
            aux += mat[rows][i];
        }
        cout << endl;

        // Recurse accumulating current aux with return value of next row sumatory
        return aux + matrixSumatory(mat, rows + 1, dims);
    }
    else
        return 0;
}