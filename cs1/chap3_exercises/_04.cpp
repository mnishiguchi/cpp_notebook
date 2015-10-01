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
     4. Suppose x and y are int variables and symbol is a char variable.
     Assume the following input data:
     38 26 * 67 33
     24 $ 55 # 34
     # & 63 85
     
     What value (if any) is assigned to x, y, and symbol after
     each of the following statements executes? (Use the same input for each statement.)
     */
    int x, y;
    char symbol;

    // User input
    cout << "Enter the following data: 38 26 * 67 33" << endl;
    cout << "                          24 $ 55 # 34" << endl;
    cout << "                          # & 63 85" << endl;

    /* a */
//    cin >> x >> y;
//    cin.ignore(100, '\n');
//    cin >> symbol;             // x: 38, y: 26, symbol: '2'

    // /* b */
//     cin >> x;
//     cin.ignore(100, '*');
//     cin >> y;
//     cin.get(symbol);        // x: 38, y: 67, symbol: ' '  // !!!CAREFUL

    // /* c */
//     cin >> y;
//     cin.ignore(100, '\n');
//     cin >> x >> symbol;     // x: 24, y: 38, symbol: '$'

     /* d */
//     cin.get(symbol);
//     cin.ignore(100, '*');
//     cin >> x;
//     cin.ignore(100, '\n');
//     cin >> y;               // x: 67, y: 24, symbol: '3'

    // /* e */
//     cin.ignore(100, '\n');
//     cin >> x >> symbol;
//     cin.ignore(100, '\n');
//     cin.ignore(100, '&');
//     cin >> y;               // x: 24, y: 63, symbol: '$'

    // Inspect the variables
    cout << "x: " << x << endl
         << "y: " << y << endl
         << "symbol: " << symbol << endl;

    return 0;
}
