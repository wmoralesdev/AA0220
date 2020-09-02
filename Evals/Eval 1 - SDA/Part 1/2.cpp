// Daniela's puzzle
#include <iostream>
#include <vector>
using namespace std;

bool searchForWord(char** mat, int rows, int cols, string search);

int main(void) {
    int rows = 0, cols = 0;

    cin >> rows >> cols;

    char** mat = new char* [rows];

    for(int i = 0; i < rows; i++)
        mat[i] = new char[cols];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> mat[i][j];

    string read = "";

    cin >> read;

    cout << searchForWord(mat, rows, cols, read) << endl;

    return 0;
}

// Returs true or false depending if the word can be made
// Receives matrix, dims and string to find
bool searchForWord(char** mat, int rows, int cols, string search) {
    // Vector to store boolean values
    vector<bool> word;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // If current matrix pos is inside string, push a true into vector
            if(search.find(mat[i][j]) != -1){
                word.push_back(true);
                cout << "found " << mat[i][j] << endl;
                
                // Alter current letter to avoid repetition
                mat[i][j] = '*';

                // If vector size == word length then the word is found before finishing the matrix traversal
                if(word.size() == search.length())
                    return true;
            }
        }
    }

    // Return boolean comparing vector size with string size
    return word.size() == search.length();
}