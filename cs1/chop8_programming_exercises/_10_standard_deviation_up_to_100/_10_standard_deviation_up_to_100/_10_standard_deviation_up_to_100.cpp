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

analysis and test data: 778, 472, 147, 106, 82

a) Computing mean of five numbers

    Formula: x = ( x1 + x2 + x3 + x4 + x5 ) / 5;

    If the numbers are 778, 472, 147, 106, 82 , mean(average) is:

      x = ( 778 + 472 + 147 + 106 + 82 ) / 5 = 1585 / 5 = 317


b) Computing standard deviation of five numbers

    Formula:

      s = square_root_of
         [ (x_1 - x)^2 + (x_2 - x)^2 + (x_3 - x)^2 + (x_4 - x)^2 + (x_5 - x)^2 ]
         -----------------------------------------------------------------------
            5

      where x_1..x_5 are the five numbers and x is their average.


    If the numbers are 12, 34, 55, 23 and 11, standard deviation is:

      s = square_root_of
         [ (778 - 317)^2 + (472 - 317)^2 + (147 - 317)^2 + (106 - 317)^2 + (82 - 317)^2 ]
         -----------------------------------------------------------------------
            5

        = square_root_of 365192 / 5
        = square_root_of 73038
        = 270.25543
 */


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Function prototypes.
void promptNumbers(double* numbers, int& count, const int MAX_COUNT);
double calcMean(double* numbers, int count);
double calcStandardDeviation(double* numbers, int count, double mean);
void printMeanAndStandardDeviation(double* numbers, int count);


/**
 * Main funcion of this program.
 */
int main() {

    // Configuration.
    const int MAX_COUNT = 100;

    // Data stores for user's input.
    double numbers[ MAX_COUNT ];
    int count = 0;

    // Input.
    promptNumbers(numbers, count, MAX_COUNT);

    // Output.
    printMeanAndStandardDeviation(numbers, count);

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Prompts the user for numbers up to the specified maximum count.
 * @param numbers    An array of double-type numbers in which user's inputted
 *                   numbers are to be stored.
 * @param count      An variable in which we record how many numbers the user enter.
 * @param MAX_COUNT  The maximum count of the numbers we can accept as input.
 */
void promptNumbers(double* numbers, int& count, const int MAX_COUNT) {

    // The prompt message.
    cout << "Enter numbers (Max: " << MAX_COUNT << ", q: quit)" << endl;

    // Accept numbers until max 100 is reached or cin enters fail state.
    count = 0;

    for ( int i = 0; i < MAX_COUNT; i++ ) {

        cout << ">>>";
        cin >> numbers[ i ];

        // If input is valid, increment the counter.
        if ( cin.fail() || count == MAX_COUNT - 1 ) {
            break;

        } else {
            count += 1;
        }
    }

    cout << setfill('-') << setw(32) << "" << setfill(' ') << endl;
}


/**
 * @param nums   An array of double-type numbers.
 * @param count  How many numbers are to be used for this computation?
 * @return the average value of the specified numbers.
 */
double calcMean(double* nums, int count) {

    double sum = 0.0;

    // Get the sum of all the numbers.
    for (int i = 0; i < count; i++) {

        sum += nums[ i ];
    }

    return sum / count;
}


/**
 * @param nums   An array of double-type numbers.
 * @param count  How many numbers are to be used for this computation?
 * @param mean   The average of the numbers.
 * @return the standard deviation of the specified numbers.
 */
double calcStandardDeviation(double* nums, int count, double mean) {

    double numerator = 0.0;

    // Prepare the numerator of the fraction inside the sqrt.
    // (x_1 - x)^2 + (x_2 - x)^2 + (x_3 - x)^2 + ...
    for (int i = 0; i < count; i++) {

        numerator += pow( nums[ i ] - mean , 2.0 );
    }

    return sqrt( numerator / 5 );
}


/**
 * Output the mean and standard deviation.
 * @param numbers  A double-type array which contains user's inputted numbers.
 * @param count    How many numbers are to be used for this computation?
 */
void printMeanAndStandardDeviation(double* numbers, int count) {

    double mean = calcMean(numbers, count);
    double sd   = calcStandardDeviation(numbers, count, mean);

    cout << fixed << showpoint << setprecision(2);
    cout << "Mean (Average):     " << mean << endl;
    cout << "Standard deviation: " << sd << endl;
    cout << endl;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/*
OUTPUT

Enter numbers (Max: 100, q: quit)
>>>778
>>>472
>>>147
>>>106
>>>82
>>>q
--------------------------------
Mean (Average):     317.00
Standard deviation: 270.26

Program ended with exit code: 0
 */
