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
     03_7ed. Suppose num1 and num2 are int variables
     x and y are double variables.
     Consider the following input:
     35 28.30 67 12.50

     What value (if any) is assigned to those variables
     after each of the following statements executes? (Use the same input for each statement.)
     */
    int num1, num2;
    double x, y;

    // Input
    cout << "Enter the following data: 35 28.30 67 12.50" << endl;

    /* a */
    // cin >> x >> num1 >> y >> num2;  // num1: 28, num2: 67, x: 35.0, y: 0.3

    /* b */
    // cin >> num1 >> x >> num2 >> y;  // num1: 35, num2: 67, x: 28.3, y: 12.5

    /* c */
    // cin >> x >> y >> num1 >> num2;  // num1: 67, num2: 12, x: 35.0, y: 28.3

    /* d */
    // cin >> num1 >> num2 >> x >> y;  // num1: 35, num2: 28, x: 0.3, y: 67.0

    /* e */
    // cin >> num1 >> x >> y >> num2;  // num1: 35, num2: 12, x: 28.3, y: 67.0

    /* f */
    cin >> x >> num1 >> num2 >> y;  // num1: 28, num2: 0, x: 35.0, y: undefined

    // Inspect the variables
    cout << "num1: " << num1 << endl
         << "num2: " << num2 << endl
         << "x:    " << x << endl
         << "y:    " << y << endl;

    return 0;
}
