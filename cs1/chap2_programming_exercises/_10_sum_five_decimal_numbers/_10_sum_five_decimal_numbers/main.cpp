//
//  main.cpp
//  _10_sum_five_decimal_numbers
//
//  Prompts the user to input five decimal numbers, add the five decimal numbers,
//  convert the sum to the nearest integer, and print the result.
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/* === ANALYSIS ===
 
 // constant
 N/A
 
 // variables
 double n1, n2, n3, n4, n5;
 int sum;
 
 // assignment statement
 cin >> n1 >> n2 >> n3 >> n4 >> n5;
 
 // calculations
 sum = n1 + n2 + n3 + n4 + n5
 
 If the five numbers are 1.1, 2.2, 3.3, 4.4, 5.5,
    1.1 + 2.2 + 3.3 + 4.4 + 5.5 = 16.5
 
 The output is expected to be its nearest integer of 17.
 */

/* === PROGRAM === */

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // Variable declaration
    double n1, n2, n3, n4, n5;
    int sum;
    
    // Prompt five decimal numbers and store them in the variables
    cout << "Please enter five decimal numbers: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    cout << endl;
    
    // Calculate the sum and convert it into its nearest integer
    sum = static_cast<int>(n1 + n2 + n3 + n4 + n5 + 0.5);
    
    // Print the sum
    cout << "The sum of " << n1 << ", " << n2 << ", " << n3 << ", "
         << n4 << " and " << n5 << " is: " << sum << endl;
    
    return 0;
}

/* === ACTUAL OUTPUT ===
 
 Please enter five decimal numbers: 1.1 2.2 3.3 4.4 5.5
 
 The sum of 1.1, 2.2, 3.3, 4.4 and 5.5 is: 17
 */