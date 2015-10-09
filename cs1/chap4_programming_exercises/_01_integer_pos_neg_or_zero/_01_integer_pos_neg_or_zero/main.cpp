//
//  main.cpp
//  _01_integer_pos_neg_or_zero
//
//  Created by Masatoshi Nishiguchi on 10/8/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Prompts the user to input a number.
 * Output the number and a message saying whether
 * the number is positive, negative, or zero
 */
int main() {

    cout << "Enter an integer: ";
    int num;
    cin >> num;
    cout << endl;
    
    if (num > 0) {
        cout << "positive" << endl;
    } else if (num < 0) {
        cout << "negative" << endl;
    } else {
        cout << "zero" <<endl;
    }
    
    return 0;
}
