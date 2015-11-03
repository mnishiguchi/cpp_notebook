/*
 *  reverse_array
 *
 *  Prompts user for the size of integer array and interger values for list elements.
 *  Then reverses the list.
 *
 *  Created by Masatoshi Nishiguchi on 11/3/15.
 */

#include <iostream>
using namespace std;

/**
 *  Swaps two interger values passed in by reference.
 */
void swap(int& i1, int& i2) {
    int temp = i1; // Temp for swap
    i1 = i2;       // First part of swap
    i2 = temp;     // Second complete
}

int main() {
    int listSize; // Number of elements

    // Prompt user for the list size
    cout << "Enter the number of the integers you want to enter..." << endl;
    cin >> listSize;

    int userVals[listSize]; // User numbers
    int i = 0;                  // Loop index

    // Prompt user to input values
    cout << "Enter " << listSize << " integer values..." << endl;
    for (i = 0; i < listSize; ++i) {
        cout << "Value: ";
        cin >> userVals[i];
    }

    // Reverse array's elements
    for (i = 0; i < (listSize / 2); ++i) {
        swap(userVals[i], userVals[listSize - 1 - i]);
    }

    // Print numbers
    cout << endl << "New values: ";
    for (i = 0; i < listSize; ++i) {
        cout << userVals[i] << " ";
    }

    return 0;
}
