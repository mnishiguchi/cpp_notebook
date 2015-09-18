//
//  main.cpp
//  _19_change_in_pennies
//
//  Prompts the user to input a number of quarters, dimes, and nickels.
//  Then outputs the total value of the coins in pennies.
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/* === ANALYSIS ===
 
 // constants
 const int QUARTER_IN_PENNIES = 25;
 const int DIME_IN_PENNIES    = 10;
 const int NICKEL_IN_PENNIES  = 5 ;
 
 // variables
 int numQuarters, numDimes, numNickels, numPennies, totalValueInPennies;
 
 // assignment statement
 cin >> numQuarters;
 cin >> numDimes;
 cin >> numNickels;
 cin >> numPennies;
 
 // calculations
 totalValueInPennies = (numQuarters * QUARTER_IN_PENNIES) +
                       (numDimes    * DIME_IN_PENNIES) +
                       (numNickels  * NICKEL_IN_PENNIES) + numPennies;
 
 If numQuarters is 1, numDimes is 2, numNickels is 3 and numPennies is 4,
    totalValueInPennies = (1 * 25) + (2 * 10) + (3 * 5) + 4 = 64
 */

/* === PROGRAM === */

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // Constants
    const int QUARTER_IN_PENNIES = 25;
    const int DIME_IN_PENNIES    = 10;
    const int NICKEL_IN_PENNIES  = 5 ;
    
    // Variable declaration
    int numQuarters, numDimes, numNickels, numPennies, totalValueInPennies;
    
    // Prompt the number of each coin and store them in the variables
    cout << "Please enter the number of quarters: ";
    cin >> numQuarters;
    
    cout << "Please enter the number of dimes:    ";
    cin >> numDimes;
    
    cout << "Please enter the number of nickels:  ";
    cin >> numNickels;
    
    cout << "Please enter the number of pennies:  ";
    cin >> numPennies;
    cout << endl;
    
    // Calculate the total value of the coins in pennies
    totalValueInPennies = (numQuarters * QUARTER_IN_PENNIES) +
                          (numDimes    * DIME_IN_PENNIES) +
                          (numNickels  * NICKEL_IN_PENNIES) + numPennies;
    
    // Print the result
    cout << "The total value of the coins in pennies: "
         << totalValueInPennies << endl;
    
    return 0;
}

/* === ACTUAL OUTPUT ===
 
 Please enter the number of quarters: 1
 Please enter the number of dimes:    2
 Please enter the number of nickels:  3
 Please enter the number of pennies:  4
 
 The total value of the coins in pennies: 64
 */