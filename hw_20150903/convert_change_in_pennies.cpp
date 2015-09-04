//
//  convert_change_in_pennies.cpp
//  pp25-26, #16
//
//  Created by Masatoshi Nishiguchi on 9/4/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int changeInPennies(int numQuarters, int numDimes, int numNickels, int numPennies);

int main(int argc, const char * argv[]) {
    cout << changeInPennies(2,33,44,5) << endl;
    
    return 0;
}

// #16 Converts the change given in quarters, dimes, nickels and pennies into pennies.
int changeInPennies(int numQuarters, int numDimes, int numNickels, int numPennies) {
    int output = 0;
    output += numQuarters * 25;
    output += numDimes    * 10;
    output += numNickels  * 5;
    output += numPennies;
    return output;
}
