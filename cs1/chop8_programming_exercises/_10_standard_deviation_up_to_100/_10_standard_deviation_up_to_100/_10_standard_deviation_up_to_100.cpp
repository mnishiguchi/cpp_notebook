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

data set: { 778, 472, 147, 106, 82 }

a) Computing mean

    Formula: x = ( x_1 + x_2 + x_3 + x_4 + x_5) / 5;

    Given the data set above, mean(average) is:
      x = ( 778 + 472 + 147 + 106 + 82 ) / 5 = 317

b) Computing (sample) variance
    Formula:
         [ (x_1 - x)^2 + (x_2 - x)^2 + (x_3 - x)^2 + (x_4 - x)^2 + (x_5 - x)^2 ]
         -----------------------------------------------------------------------
            5 - 1
      where x_1..x_5 are the ten numbers and x is their average.

    Given the data set above, variance is:

      The numerator =
        [ (778 - 317)^2 + (472 - 317)^2 + (147 - 317)^2 + (106 - 317)^2 + (82 - 317)^2 ]
        = 365192

      s^2 = 365192 / 4 = 91298

c) Computing (sample) standard deviation

    Formula:
        s = square_root_of variance = square_root_of 91298 = 302.16

d) Computing (population) variance
    Formula:
            [ (x_1 - x)^2 + (x_2 - x)^2 + (x_3 - x)^2 + ... + (x_5 - x)^2 ]
      s^2 = -----------------------------------------------------------------
              5
      where x_1..x_5 are the ten numbers and x is their average.

    Given the data set above, variance is:

      The numerator =
        [ (778 - 317)^2 + (472 - 317)^2 + (147 - 317)^2 + (106 - 317)^2 + (82 - 317)^2 ]
        = 365192

      s^2 = 365192 / 5 = 73038

e) Computing (population) standard deviation

    Formula:
        s = square_root_of variance = square_root_of 73038 = 270.26
 */


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Function prototypes.
void inputNumbers(double* numbers, int& count, const int MAX_COUNT);
double calcMean(double* numbers, int count);
double calcStandardDeviation(double variance);
double calcSampleVariance(double* numbers, int count, double mean);
double calcPopulationVariance(double* numbers, int count, double mean);
void outputStandardDeviation(double* numbers, int count);


// Configuration.
const int MAX_COUNT = 100;


/**
 * Main funcion of this program.
 */
int main() {

    // Data stores for user's input.
    double numbers[ MAX_COUNT ];

    // Keep track of how many numbers the user inputs.
    int count = 0;

    // Input and output.
    inputNumbers(numbers, count, MAX_COUNT);
    outputStandardDeviation(numbers, count);

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
void inputNumbers(double* numbers, int& count, const int MAX_COUNT) {

    // The prompt message.
    cout << "Enter numbers (Max: " << MAX_COUNT << ", q: quit)" << endl;

    // Accept numbers until max 100 is reached or cin enters fail state.
    count = 0;

    for ( int i = 0; i < MAX_COUNT; i++ ) {

        cout << ">>> ";
        cin >> numbers[ i ];

        // If input is valid, increment the counter.
        if ( cin.fail() || count == MAX_COUNT - 1 ) {
            break;

        } else {
            count += 1;
        }
    }
}


/**
 * Compute the mean of the specified numbers.
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
 * Compute the variance for the sample standard deviation.
 * @param nums   An array of double-type numbers.
 * @param count  How many numbers are to be used for this computation?
 * @param mean   The average of the numbers.
 * @return the standard deviation of the specified numbers.
 */
double calcSampleVariance(double* nums, int count, double mean) {

    double sumOfDifferencesSquared = 0.0;

    // 1. Subtract the mean from each of the values.
    // 2. Square each answer.
    // 3. Add all.
    for (int i = 0; i < count; i++) {

        sumOfDifferencesSquared += pow( nums[ i ] - mean , 2.0 );
    }

    return sumOfDifferencesSquared / (count - 1);
}


/**
 * Compute the variance for the population standard deviation.
 * @param nums   An array of double-type numbers.
 * @param count  How many numbers are to be used for this computation?
 * @param mean   The average of the numbers.
 * @return the standard deviation of the specified numbers.
 */
double calcPopulationVariance(double* nums, int count, double mean) {

    double sumOfDifferencesSquared = 0.0;

    // 1. Subtract the mean from each of the values.
    // 2. Square each answer.
    // 3. Add all.
    for (int i = 0; i < count; i++) {

        sumOfDifferencesSquared += pow( nums[ i ] - mean , 2.0 );
    }

    return sumOfDifferencesSquared / count;
}


/**
 * Compute the standard deviation.
 * @param nums   An array of double-type numbers.
 * @param count  How many numbers are to be used for this computation?
 * @param mean   The average of the numbers.
 * @return the standard deviation of the specified numbers.
 */
double calcStandardDeviation(double variance) {

    return sqrt(variance);
}


/**
 * Output the mean and standard deviation.
 * @param nums     A double-type array which contains user's inputted numbers.
 * @param count    How many numbers are to be used for this computation?
 */
void outputStandardDeviation(double* nums, int count) {

    double mean = calcMean(nums, count);

    // Sample standard deviation.
    double varianceSSD = calcSampleVariance(nums, count, mean);
    double sampleStandardDeviation = calcStandardDeviation(varianceSSD);

    // Population standard deviation.
    double variancePSD = calcPopulationVariance(nums, count, mean);
    double populationStandardDeviation = calcStandardDeviation(variancePSD);

    // Draw a line.
    cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

    // Print the result.
    cout << fixed << showpoint << setprecision(2);  // Format setting.

    cout << "Total numbers:  " << setw(8) << count << endl;
    cout << "Mean (Average): " << setw(8) << mean  << endl;
    cout << endl;

    cout << fixed << showpoint << setprecision(5);  // Format setting.

    cout << "Sample standard deviation:     " << setw(12) << sampleStandardDeviation << endl;
    cout << "Variance:                      " << setw(12) << varianceSSD << endl;
    cout << endl;
    cout << "Population standard deviation: " << setw(12) << populationStandardDeviation << endl;
    cout << "Variance:                      " << setw(12) << variancePSD << endl;
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
------------------------------------------------
Total numbers:         5
Mean (Average):   317.00

Sample standard deviation:        302.15559
Variance:                       91298.00000

Population standard deviation:    270.25617
Variance:                       73038.40000

Program ended with exit code: 0
 */
