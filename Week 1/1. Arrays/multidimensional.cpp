#include <iostream>
using namespace std;

int main(void) {
    // Initialized matrix
    int initMatrix[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // Fixed size matrix
    int fixedMatrix[4][5];

    // Dynamic rows matrix
    int rows = 3;
    int rowMatrix[rows][5];

    // Dynamic cols matrix
    int cols = 4;
    int colsMatrix[5][rows];

    // Dynamic matrix
    int dynamicMatrix[rows][cols];

    // Matrix as double pointer
    int** doublePointer;
    doublePointer = new int* [rows];

    for(int i = 0; i < rows; i++)
        doublePointer[i] = new int [cols];

    int counter = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            doublePointer[i][j] = ++counter;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << doublePointer[i][j] << "\t";
        cout << endl;
    }

    return 0;
}