/**
 * _09_temperature_highest_lowest
 *
 * - Uses a two-dimensional array to store the highest and
 * lowest temperatures for each month of the year.
 * - Outputs the average high, average low, and the highest and lowest temperatures
 * for the year.
 */

#include <iostream>
#include <iomanip>
using namespace std;


// Function prototypes.
void fixInputStream();
void getData(double dataArray[12][2]) ;
double averageHigh(double dataArray[12][2]);
double averageLow(double dataArray[12][2]);
int indexHighTemp(double dataArray[12][2]);
int indexLowTemp(double dataArray[12][2]);
void printData(double dataArray[12][2]);


int main() {

    // The array to store the highest and lowest temperatures for each month of the year.
    double temperatures[12][2] = {};  // Initialize all elements to 0.

    getData(temperatures);
    printData(temperatures);

    return 0;
}


/**
 * Restores the input stream.
 */
void fixInputStream() {
    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer
}


/**
 * Reads and stores data in the two-dimensional array.
 * @param dataArray An double array for us to write data to.
 */
void getData(double dataArray[12][2]) {

    // Print explanation.
    cout << "Enter the highest and lowest temperatures for each month of the year:" << endl;

    // For each month...
    for (int month = 0; month < 12; month += 1) {

        // Print the month number.
        cout << "Month " << setw(2) << month + 1 << endl;

        // Get the highest.
        cout << "  highest temperature: ";
        cin >> dataArray[ month ][ 0 ];
        fixInputStream();

        // Get the lowest.
        cout << "  lowest temperature:  ";
        cin >> dataArray[ month ][ 1 ];
        fixInputStream();

        cout << endl; // Insert a blank line.
    }

}


/**
 * Calculates and returns the average high temperature for the year.
 * @param dataArray An double array.
 * @return
 */
double averageHigh(double dataArray[12][2]) {

    double sum = 0.0;

    // For each month...
    for (int month = 0; month < 12; month += 1) {

        // Add the high temperature to the sum.
        sum += dataArray[ month ][ 0 ];

    }

    return sum / 12;

}


/**
 * Calculates and returns the average low temperature for the year.
 * @param dataArray An double array.
 * @return
 */
double averageLow(double dataArray[12][2]) {

    double sum = 0.0;

    // For each month...
    for (int month = 0; month < 12; month += 1) {

        // Add the high temperature to the sum.
        sum += dataArray[ month ][ 1 ];

    }

    return sum / 12;

}


/**
 * @return the index of the highest high temperature in the array.
 */
int indexHighTemp(double dataArray[12][2]) {

    int highestIndex = 0;

    // For each month...
    for (int month = 1; month < 12; month += 1) {

        if (dataArray[ month ][ 0 ] > highestIndex) {
            highestIndex = dataArray[ month ][ 0 ];
        }

    }

    return highestIndex;

}


/**
 * @return the index of the lowest temperature in the array.
 */
int indexLowTemp(double dataArray[12][2]) {

    int lowestIndex = 0;

    // For each month...
    for (int month = 1; month < 12; month += 1) {

        if (dataArray[ month ][ 1 ] > lowestIndex) {
            lowestIndex = dataArray[ month ][ 1 ];
        }

    }

    return lowestIndex;

}


/**
 * Prints all the the highest and lowest temperature values in the 2-D array.
 */
void printData(double dataArray[12][2]) {

    // For each month...
    for (int month = 0; month < 12; month += 1) {

        // Print the month number.
        cout << "Month " << setw(2) << month + 1 << endl;

        // Pritn the highest.
        cout << "  highest temperature: " << dataArray[ month ][ 0 ] << endl;
        cout << "  lowest temperature:  " << dataArray[ month ][ 1 ] << endl;

        cout << endl;  // Insert a blank line.
    }

    cout << endl;

}
