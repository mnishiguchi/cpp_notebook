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
     05_7ed. Given the following input:
        12.8 Bill 15

     What value (if any) is assigned to those variables
     after each of the following statements executes? (Use the same input for each statement.)
     */
    double x = 3.5;
    int y = 18;
    string name = "Lisa";

    // Input
    cout << "Enter the following data: 35 28.30 67 12.50" << endl;

    /* a */
    // cin >> x >> name >> y;       // x: 35.0, y: 67, name: "28.30"

    /* b */
    // cin >> y >> x >> name >> y;  // x: 28.30, y: 12, name: "67"  // !!!Tricky

    /* c */
    cin >> x >> y >> name;       // x: 35.0, y: 28, name: ".30"

    // Inspect the variables
    cout << "x:    " << x << endl
         << "y:    " << y << endl
         << "name: " << name << endl;

    return 0;
}
