//
//  main.cpp
//  _10_mean_and_standard_deviation
//
//  Created by Masatoshi Nishiguchi on 11/17/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
ANALYSIS

  a) Computing mean of five numbers

    Formula:
      x = ( x1 + x2 + x3 + x4 + x5 ) / 5;

    If the numbers are 12, 34, 55, 23 and 11, mean(average) is:

      x = ( 12 + 34 + 55 + 23 + 11 ) / 5 = 135 / 5 = 27


  b) Computing standard deviation of five numbers

    Formula:
      s = square_root_of
           [ (x_1 - x)^2 + (x_2 - x)^2 + (x_3 - x)^2 + (x_4 - x)^2 + (x_5 - x)^2 ]
           -----------------------------------------------------------------------
              5
      where x_1..x_5 are the five numbers and x is their average.

    If the numbers are 12, 34, 55, 23 and 11, standard deviation is:

      s = square_root_of
           [ (12 - 27)^2 + (34 - 27)^2 + (55 - 27)^2 + (23 - 27)^2 + (11 - 27)^2 ]
           -----------------------------------------------------------------------
              5

        = square_root_of
           [ 225 + 49 + 784 + 16 + 256 ]
           -----------------------------------------------------------------------
              5

        = square_root_of 266
        = 16.30950643030009

==

OUTPUT

  Enter five numbers: 12 34 55 23 11
  --------------------------------
  Mean (Average):     27.00
  Standard deviation: 16.31
 */


// Function prototyping.
double computeMean(double x1, double x2, double x3, double x4, double x5);
double computeStandardDeviation(double x1, double x2, double x3, double x4, double x5);


// Main funcion of this program.
int main() {

    double x1, x2, x3, x4, x5;

    // Prompt the user for five numbers.
    cout << "Enter five numbers: ";
    cin >> x1 >> x2 >> x3 >> x4 >> x5;

    // Draw a separator.
    cout << setfill('-') << setw(32) << "" << setfill(' ') << endl;

    // Output the mean and standard deviation.
    cout << fixed << showpoint << setprecision(2);
    cout << "Mean (Average):     " << computeMean(x1, x2, x3, x4, x5) << endl;
    cout << "Standard deviation: " << computeStandardDeviation(x1, x2, x3, x4, x5) << endl;

    return 0;
}


/**
 * @param x1
 * @param x2
 * @param x3
 * @param x4
 * @param x5
 * @return the average value of the specified five numbers.
 */
double computeMean(double x1, double x2, double x3, double x4, double x5) {

    return ( x1 + x2 + x3 + x4 + x5 ) / 5;
}


/**
 * @param x1
 * @param x2
 * @param x3
 * @param x4
 * @param x5
 * @return the standard deviation of the specified five numbers.
 */
double computeStandardDeviation(double x1, double x2, double x3, double x4, double x5) {

    double x = computeMean(x1, x2, x3, x4, x5);

    return sqrt(
       (
          pow(x1 - x, 2.0) +
          pow(x2 - x, 2.0) +
          pow(x3 - x, 2.0) +
          pow(x4 - x, 2.0) +
          pow(x5 - x, 2.0)
       ) / 5
    );
}
