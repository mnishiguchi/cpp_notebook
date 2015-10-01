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
     02. Suppose num1 and num2 are int variables and symbol is a char variable.
     Consider the following input:
     47 18 * 28 $

     What value (if any) is assigned to num1, num2, and symbol
     after each of the following statements executes? (Use the same input for each statement.)
         a. cin >> num1 >> symbol >> num2;               // 47 '1' 8
         b. cin >> symbol >> num1 >> num2;               // '4' 7 18
         c. cin >> num1; cin.get (symbol); cin >> num2;  // 4 '7' 18
         d. cin >> num1 >> num2; cin.get (symbol);
         e. cin.get (symbol);
            cin >> num1 >> num2;
     */
    int num1, num2;
    char symbol;

    cout << "Enter the following data: 47 18 * 28 $" << endl;

    /* a */
    // cin >> num1 >> symbol >> num2;  // num1: 47, num2: 8,  symbol: '1'

    /* b */
    // cin >> symbol >> num1 >> num2;  // num1: 7,  num2: 18, symbol: '4'

    /* c */
    // cin >> num1;
    // cin.get (symbol); cin >> num2;  // num1: 47, num2: 18, symbol: ' '

    /* d */
    // cin >> num1 >> num2;
    // cin.get(symbol);                // num1: 47, num2: 18, symbol: ' '

    /* e */
    // cin.get(symbol);                // num1: 7, num2: 18, symbol: '4'
    // cin >> num1 >> num2;

    cout << "num1:   " << num1 << endl
         << "num2:   " << num2 << endl
         << "symbol: " << symbol << endl;

    return 0;
}
