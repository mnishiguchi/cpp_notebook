/**
 * _10_standard_deviation_up_to_100
 *
 * Finds the mean and standard deviation of up to 100 numbers.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
ANALYSIS

a) Computing mean of five numbers

    Formula: x = ( x1 + x2 + x3 + x4 + x5 ) / 5;

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
 */


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Function prototyping.
double computeMean(double* nums, int size);
double computeStandardDeviation(double* nums, int size);
void promptNumbers(double* numbers, int& count, const int MAX_NUMBERS);
void drawLine();
void printStandardDeviation(double* numbers, int count);


/**
 * Main funcion of this program.
 */
int main() {

    const int MAX_NUMBERS = 100;
    double numbers[ MAX_NUMBERS ];
    int count = 0;

    promptNumbers(numbers, count, MAX_NUMBERS);
    drawLine();
    printStandardDeviation(numbers, count);

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * @param nums  an array of numbers of double-type
 * @param size  the size of the array
 * @return the average value of the specified numbers.
 */
double computeMean(double* nums, int size) {

    double sum = 0.0;

    // Get the sum of all the numbers.
    for (int i = 0; i < size; i++) {

        sum += nums[ i ];
    }

    return sum / size;
}


/**
 * @param nums  an array of numbers of double-type
 * @param size  the size of the array
 * @return the standard deviation of the specified numbers.
 */
double computeStandardDeviation(double* nums, int size) {

    double x = computeMean(nums, size);

    double numerator = 0.0;

    // Get the numerator of the fraction inside the sqrt.
    for (int i = 0; i < size; i++) {

        numerator += pow( nums[ i ] - x , 2.0 );
    }

    return sqrt( numerator / 5 );
}


/**
 * @param
 */
void promptNumbers(double* numbers, int& count, const int MAX_NUMBERS) {

    // Prompt the user for five numbers.
    cout << "Enter numbers (Max: 100, q: quit)" << endl;

    // Accept numbers until max 100 is reached or cin enters fail state.
    count = 0;
    for ( int i = 0; i < MAX_NUMBERS; i++ ) {

        cout << ">>>";
        cin >> numbers[ i ];

        // If input is valid, increment the counter.
        if ( cin.fail() ) {
            break;

        } else {
            count += 1;
        }
    }
}


/**
 * Draw a separator line.
 */
void drawLine() {

    cout << setfill('-') << setw(32) << "" << setfill(' ') << endl;
}


/**
 * Output the mean and standard deviation.
 * @param numbers
 * @param count
 */
void printStandardDeviation(double* numbers, int count) {

    cout << fixed << showpoint << setprecision(2);
    cout << "Mean (Average):     " << computeMean(numbers, count) << endl;
    cout << "Standard deviation: " << computeStandardDeviation(numbers, count) << endl;
    cout << endl;
}

// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/*
OUTPUT

  Enter five numbers: 12 34 55 23 11
  --------------------------------
  Mean (Average):     27.00
  Standard deviation: 16.31
 */
