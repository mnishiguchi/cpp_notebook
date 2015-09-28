//
//  main.cpp
//  _01_positive_negative_or_zero
//
//  Created by Masatoshi Nishiguchi on 9/28/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Input
    double number;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    // Output
    if (number > 0.0) {
        cout << "Positive" << endl;
    } else if (number < 0.0) {
        cout << "Negative" << endl;
    } else {
        cout << "Zero" << endl;
    }
    
    return 0;
}
