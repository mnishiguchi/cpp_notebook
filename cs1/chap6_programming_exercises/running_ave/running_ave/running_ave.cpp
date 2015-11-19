//
//  running_ave.cpp
//
//  Created by Masatoshi Nishiguchi on 11/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Function prototypes.
double average(double bucket[], int count);
double RunningAvg();


// #13
/**
 * @param bucket  A container for numbers that the user has entered.
 * @param count   The total number of the user's inputted numbers.
 * @return        The average
 */
double average(double bucket[], int count) {

    int sum = 0;

    // Get the sum.
    for (int i = 0; i < count; i++) {
        sum += bucket[i];
    }

    // Debug dump.
    cout << "(Sum: " << sum << ", Count: " << count << ")" << endl;

    // Return the average
    return sum / count;
}


/**
 * @return average of all the values that have been passed
 */
double RunningAvg() {

    double* bucket = new double[100];
    int count = 0;
    double data;

    // Prompt user for numbers.
    cout << "Enter as many numbers as you like (q to quit): " << endl;

    // Read user's numbers one by one and compute the average.
    while (true) {

        // Read the number.
        cin >> bucket[count];

        // Update the counter.
        count += 1;

        // Print the average thus far.
        data = average(bucket, count);
        cout << "Average: " << data << endl;

        // Terminating condition is the failing input stream.
        if (!cin) {
            break;
        }
    }

    return data;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    cout << "Final average: " << RunningAvg() << endl;

    return 0;
}
