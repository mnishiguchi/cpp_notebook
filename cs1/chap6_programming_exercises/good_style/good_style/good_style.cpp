//
//  good_style.cpp
//
//  Created by Masatoshi Nishiguchi on 11/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;


// Function prototype
int Power(int x, int pow);


/**
 * The main function of this program
 */
int main () {

    // Variable declaration
    int pow;
    int x;
    
    // Prompt the user for the power.
    cout << "Enter power: ";
    cin >> pow;

    // Prompt the user for the value.
    cout << "Enter value to be raised to power: ";
    cin >> x;

    // Computation and output
    cout << Power(x, pow);
}


/**
 * @param  x    An integer
 * @param  pow  An exponent
 * @return The integer that is raised to specified power.
 */
int Power(int x, int pow) {

    int result = 1;
    
    while (pow > 0) {

        result = result * x;
        pow--;

    }

    return result;
}
