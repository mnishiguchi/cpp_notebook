/*
   main.cpp
   _01_individual_digits_and_sum

   Created by Masatoshi Nishiguchi on 11/5/15.
   Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.

  prompts the user to input an integer and then outputs both the individual digits
  of the number and the sum of the digits.

  E.g., 3456 as 3 4 5 6,
*/

#include <iostream>
#include <string>
using namespace std;

void swap(double& d1, double& d2) {
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

int main() {
    string inputString;
    int nums[16];
    int idx = 0;

    cout << "Enter a positive integer: ";
    getline(cin, inputString);

    for (int i = 0, len = inputString.length(); i < len; i++) {
        if ( isdigit( inputString[i] ) ) {
            nums[idx] = inputString[i];
        }
    }

    /*
     Conver digit char => int
     char c = '1';
     int i = c - '0'; // i is now equal to 1, not '1'
     */
    return 0;
}
