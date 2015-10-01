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
     6. Suppose that x and y are int variables, z is a double variable, and ch is a
     char variable. Suppose the input statement is: cin >> x >> y >> ch >> z;
     What values, if any, are stored in x, y, z, and ch if the input is:
         a. 35 62.78
         b. 86 32A 92.6
         c. 12 .45A 32
     */
    int x, y;
    char ch;
    double z;

    /* a */

    cout << "a. Enter the following data: 35 62.78" << endl;

    cin >> x;  // OK; x: 35
    if(cin.fail()) { cout << "Error reading x" << endl; }

    cin >> y;  // OK; y: 62  // Note: cin stops reading at a decimal point
    if(cin.fail()) { cout << "Error reading y" << endl; }

    cin >> ch; // OK; ch: '.'
    if(cin.fail()) { cout << "Error reading ch" << endl; }

    cin >> z;  // OK; z: 78.0
    if(cin.fail()) { cout << "Error reading z" << endl; }

    // Inspect the variables
    cout << "x:  " << x << endl
         << "y:  " << y << endl
         << "ch: " << ch << endl
         << "z:  " << z << endl;

    cout << endl;

    /* b */

    cout << "b. Enter the following data: 86 32A 92.6" << endl;

    cin >> x;  // OK; x: 86
    if(cin.fail()) { cout << "Error reading x" << endl; }

    cin >> y;  // OK; y: 32
    if(cin.fail()) { cout << "Error reading y" << endl; }

    cin >> ch; // OK; ch: 'A'
    if(cin.fail()) { cout << "Error reading ch" << endl; }

    cin >> z;  // OK; z: 92.6
    if(cin.fail()) { cout << "Error reading z" << endl; }

    // Inspect the variables
    cout << "x:  " << x << endl
         << "y:  " << y << endl
         << "ch: " << ch << endl
         << "z:  " << z << endl;

    cout << endl;

    /* c */

    cout << "c. Enter the following data: 12 .45A 32" << endl;

    cin >> x;  // OK; x: 12
    if(cin.fail()) { cout << "Error reading x" << endl; }

    cin >> y;  // Error because there is no integer; y: 0
    if(cin.fail()) { cout << "Error reading y" << endl; }

    cin >> ch; // The input stream is still in the fail state; ch: undefined
    if(cin.fail()) { cout << "Error reading ch" << endl; }

    cin >> z;  // The input stream is still in the fail state; z: undefined
    if(cin.fail()) { cout << "Error reading z" << endl; }

    // Inspect the variables
    cout << "x:  " << x << endl
         << "y:  " << y << endl
         << "ch: " << ch << endl
         << "z:  " << z << endl;

    return 0;
}
