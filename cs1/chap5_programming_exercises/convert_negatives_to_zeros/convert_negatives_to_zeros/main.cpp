//
//  main.cpp
//  convert_negatives_to_zeros
//
//  Created by Masatoshi Nishiguchi on 11/3/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int NUM_ELEMENTS = 8;   // Number of elements
    int userVals[NUM_ELEMENTS];   // User numbers
    int copiedVals[NUM_ELEMENTS]; // Copied/modified user numbers
    int i = 0;                    // Loop index

    // Prompt user for input values
    cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        cout << "Value: ";
        cin >> userVals[i];
    }

    // Copy userNums to copiedNums array
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        // Convert negatives to 0
        copiedVals[i] = (userVals[i] < 0) ? 0 : userVals[i];
    }

    // Print numbers
    cout << endl << "Original and new values: " << endl;
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        cout << setw(3) << userVals[i] << " became "
             << setw(3) << copiedVals[i] << endl;
    }

    return 0;
}
