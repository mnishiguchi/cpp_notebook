//
//  main.cpp
//  at_mark_pyramid
//
//  Created by Masatoshi Nishiguchi on 10/29/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    double outerCount, innerCount;
    
    cout << "Enter the number of the rows: ";
    cin >> outerCount;
    cout << endl;
    
    outerCount = 1;
    while (outerCount <= 11) {
        
        // Print spaces
        innerCount = 1;
        while (innerCount <= (12 - outerCount) / 2) {
            cout << " ";
            innerCount++;
        }
        
        // Print @ symbols
        innerCount = 1;
        while (innerCount <= outerCount) {
            cout << "@";
            innerCount++;
        }
        cout << endl;
        
        outerCount++;  // Update the outer counter
    }
}
