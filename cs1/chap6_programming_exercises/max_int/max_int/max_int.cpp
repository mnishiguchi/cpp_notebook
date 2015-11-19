//
//  max_int.cpp
//
//  Created by Masatoshi Nishiguchi on 11/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;


// #1 - the heading of the function

/**
 * Computes the max value of the specified two numbers and places the result
 * into the variable passed in as the last argument.
 * --
 * @param int num1 : passed in from the caller
 * @param int num2 : passed in from the caller
 * @param int& greatest : a container for the result of the computation
 */
// void Max(int num1, int num2, int& greatest)


// #2 - the function prototype for the function

void Max(int num1, int num2, int& greatest);


// #3 - the function definition of the function

/**
 * Computes the max value of the specified two numbers and places the result
 * into the variable passed in as the last argument.
 * --
 * @param int num1 : passed in from the caller
 * @param int num2 : passed in from the caller
 * @param int& greatest : a container for the result of the computation
 */
void Max(int num1, int num2, int& greatest) {

  greatest = (num1 > num2) ? num1 : num2;

}

/**
 * Computes the max value of the specified two numbers and return the result.
 * --
 * @param int num1 : passed in from the caller
 * @param int num2 : passed in from the caller
 * @return : the max of the specified two integers
 */
int Max(int num1, int num2) {

  return (num1 > num2) ? num1 : num2;

}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    int num1, num2, greatest;

    // Prompt user for two integers.
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    cout << endl;

    // Compute the max value. (Using void function)
    greatest = std::numeric_limits<int>::min();  // Initialize.
    cout << "Using void function..." << endl;
    Max(num1, num2, greatest);
    cout << "Greatest: " << greatest << endl;

    cout << "----------------------------------------" << endl;

    // Compute the max value. (Using value-returning function)
    greatest = std::numeric_limits<int>::min();  // Initialize.
    cout << "Using value-returning function..." << endl;
    greatest = Max(num1, num2);
    cout << "Greatest: " << greatest << endl;

    return 0;
}
