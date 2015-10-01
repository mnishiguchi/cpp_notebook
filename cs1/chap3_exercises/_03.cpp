//  Chap 3 - Exercises
//  main.cpp
//  20150930
//
//  Created by Masatoshi Nishiguchi on 9/30/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {

    /*
     3. Suppose x and y are int variables and z is a double variable.
     Assume the following input data:
     37 86.56 32
     What value (if any) is assigned to x, y, and z after each of the following
     statements executes? (Use the same input for each statement.)
         a. cin >> x >> y >> z;
         b. cin >> x >> z >> y;
         c. cin >> z >> x >> y;
     */
    int x, y;
    double z;

    // User input: 37 86.56 32
    cout << "Enter the following data: 37 86.56 32" << endl;

    /* a */
    // cin >> x >> y >> z;  // x: 37, y: 86, z: 0.56 // !!!CAREFUL

    /* b */
    // cin >> x >> z >> y;  // x: 37, y: 32, z: 86.56

    /* c */
    // cin >> z >> x >> y;  // x: 86, y: 0, z: 37.0  // !!!CAREFUL

    // Inspect the variables
    cout << "x: " << x << endl
         << "y: " << y << endl
         << "z: " << z << endl;

    return 0;
}
