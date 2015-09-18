//
//  dynamic_2d_array.cpp
//
//  Reference: C++ Programming by D. S. Malik, p838
//
//  Created by Masatoshi Nishiguchi on 9/17/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes of utility functions
void fill(int** p, int rowSize, int columnSize);
void print(int** p, int rowSize, int columnSize);

int main() {

    int** board;

    int numRows;
    int numColumns;

    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numColumns;

    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer

    cout << endl;

    // Create the rows of the board
    board = new int* [numRows];

    // Create the columns of the board
    for (int row = 0; row < numRows; row++) {
        // For each row, create an int array
        board[row] = new int[numColumns];
    }

    // Insert elements into the board
    fill(board, numRows, numColumns);

    cout << "------------------------------------" << endl;

    // Output the elements of the board
    print(board, numRows, numColumns);

    return 0;
}

void fill(int** p, int rowSize, int columnSize) {

    for (int row = 0; row < rowSize; row++) {

        cout << "Enter " << columnSize << " number(s) for row #" << row << ": ";

        for (int column = 0; column < columnSize; column++) {
            cin >> p[row][column];
        }

        cin.clear();            // Restore input stream
        cin.ignore(100, '\n');  // Clear the buffer

        cout << endl;
    }
}

void print(int** p, int rowSize, int columnSize) {

    for (int row = 0; row < rowSize; row++) {

        for (int column = 0; column < columnSize; column++) {
            cout << setw(5) << p[row][column];
        }
        cout << endl;
    }
}
