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
     5. Given the input: 46 A 49
     and the C++ code:
         int x = 10, y = 18;
         char z = '*';

         cin >> x >> y >> z;
         cout << x << " " << y << " " << z << endl;
     What is the output?
     */
    int x = 10, y = 18;
    char z = '*';

    // User input
    cout << "Enter the following data: 46 A 49" << endl;

    /* a */
    cin >> x;  // OK
    if(cin.fail()) { cout << "Error reading x" << endl; }

    cin >> y;  // Error due to invalid data type; 0 is assigned to y
    if(cin.fail()) { cout << "Error reading y" << endl; }

    cin >> z;  // Input stream is still in the fail state
    if(cin.fail()) { cout << "Error reading z" << endl; }

    // Inspect the variables
    cout << "x: " << x << endl
         << "y: " << y << endl
         << "z: " << z << endl;  // x: 46, y: 0, z: '*'  // !!!CAREFUL

    return 0;
}
