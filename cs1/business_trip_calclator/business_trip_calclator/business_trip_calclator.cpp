/**
 * APCT-233C-01
 * C++ Lab
 *
 * business_trip_calclator.cpp
 */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
int    inputDaysSpent();
void   times(double&, double&);
bool   isValidTime(double);
double airFare();
double carRental();
double vehicle();
double parking(int);
double taxi(int);
double registration();
double hotel(int);
double meals(int, double, double);
double getBreakfast();
double getLunch();
double getDinner();

// Global variable to hold total expenses of employee
double totalExpenses = 0;


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {
    // Total allowable expenses
    //double totalAllowable = 0.0;

    // Departure time (first day)
    //double timeDeparture;

    // Arrival home time (last day)
    //double timeReturnHome;

    // Get the total number of days for the trip.
    int totalTripDays = inputDaysSpent();
    cout << totalTripDays <<endl;


    // Get the arrival and departure times.
    //times(timeDeparture, timeReturnHome);

    // // Get the allowable airfare expenses.
    // allowable = airFare();

    // // Get the allowable car rental expenses.
    // allowable += carRental();

    // // Get the allowable vehicle expenses.
    // allowable += vehicle();

    // // Get the allowable parking expenses.
    // allowable += parking(totalTripDays);

    // // Get the allowable taxi expenses.
    // allowable += taxi(totalTripDays);

    // // Get the allowable registration expenses.
    // allowable += registration();

    // // Get allowable hotel expenses if travel is
    // // more than one day.
    // if (totalTripDays > 1)
    //     allowable += hotel(totalTripDays);

    // // Get allowable meal expenses.
    // allowable += meals(totalTripDays, timeDeparture, timeReturnHome);

    // // Display Totals.
    // cout << fixed << showpoint << setprecision(2);
    // cout << "\nTotal expenses: $" << totalExpenses << endl;
    // cout << "\nAllowable expenses: $" << allowable << endl;

    // // Display amount to be reimbursed.
    // if (totalExpenses > allowable)
    //     cout << "Amount to be reimbursed: $"
    //     << (totalExpenses - allowable);
    // // Display amount saved.
    // else if (totalExpenses < allowable)
    //     cout << "Amount saved: $"
    //     << (allowable - totalExpenses);

    // cout << endl << endl;

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Asks for the number of days spent on the trip.
 * @return The number of days spent on the trip as an integer
 */
int inputDaysSpent() {

    int totalTripDays = 0;
    bool isFinished = false;

    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "How many days did you spent on this trip? ";
        cin >> totalTripDays;

        // Validation.
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the days are less than one.
        if ( !cin || totalTripDays < 1 ) {
            cout << "Invalid: Minimum number of trip days is 1" << endl;

        } else {
            // Exit the loop.
            isFinished = true;
        }
    }

    return totalTripDays;
}


// TODO: Standardize on the time format
/**
 * Asks for the time of departure and the time of return.
 * The times are validated and stored in the reference parameter variables.
 * @param departureTime  A reference parameter variable
 * @param returnTime     A reference parameter variable
 */
// void times(long& departureTime, long& endTime) {

//     // the time of departure
//     cout << "the time of departure: ";
//     do {
//         cin >> departureTime;

//     } while ( !cin && isValidTime(departureTime) );

//     // the time of return
//     cout << "the time of return: ";
//     do {
//         cin >> returnTime;

//     } while ( !cin && isValidTime(returnTime) );
// }


// TODO: Assumed to be a time in the 24 hour format of HH.MM.

/**
 * Assumed to be a time in the 24 hour format of HH.MM.
 * The value is tested, and if it is valid the function.
 * @param time
 * @return true. Otherwise it returns false.
 */
// bool isValidTime(long time) {

//     // TODO

//     return true; // TODO
// }


/**
 * Asks the user to enter the amount of any airfare the employee incurred,
 * adds the value to the totalExpenses.
 * @return the airfare amount
 */
// double airFare() {

//     double amount = 0.0;

//     cout << "Enter the amount of any airfare: ";
//     cin >> amount;

//     // Adds the value to the totalExpenses.
//     totalExpenses += amount;

//     // Return the value.
//     return amount;
// }


/**
 * The carRental function asks the user to enter the
 * amount of car rental fees the employee incurred, adds
 * the value to the totalExpenses, and returns the amount
 * of car rental fees as a double.
 * @return
 */
// double carRental() {

//     return 0.0; // TODO
// }


/**
 * The vehicle function asks the user to enter the number
 * of miles a private vehicle was driven.The expenses are
 * added to the totalExpenses global variable. Allowable
 * expenses are returned as a double.
 * @return
 */
// double vehicle() {

//     return 0.0; // TODO
// }


/**
 * Asks the user to enter the amount of any parking fees.
 * The expenses are added to the totalExpenses global variable.
 * Allowable expenses are returned as a double.
 * @param
 * @return
 */
// double parking(int) {

//     double amount = 0.0;

//     cout << "Enter the amount of any parking fees: ";
//     cin >> amount;

//     // Adds the value to the totalExpenses.
//     totalExpenses += amount;

//     // Return the value.
//     return amount;
// }


/**
 * Asks the user to enter the amount of any taxi fees.
 * The expenses are added to the totalExpenses global variable.
 * @param
 * @return Allowable expenses
 */
// double taxi(int) {

//     double amount = 0.0;

//     cout << "Enter the amount of any taxi fees: ";
//     cin >> amount;

//     // Adds the value to the totalExpenses.
//     totalExpenses += amount;

//     // Return the value.
//     return amount;
// }


/**
 * Asks the user to enter the amount of conference registration fees
 * incurred by the employee, adds the amount to totalExpenses.
 * @return the amount spent
 */
// double registration() {

//     return 0.0; // TODO
// }


/**
 * Asks the user to enter the amount of hotel expenses.
 * The expenses are added to the totalExpenses global variable.
 * Allowable expenses are returned as a double.
 *
 * VALIDATION:
 * - The company allowes up to $90 per night for lodging.
 * - Anything in excess of this must be paid by thie employee
 *
 * @param
 * @return
 */
// double hotel(int) {

//     double amount = 0.0;

//     cout << "Enter the amount of any hotel expenses: ";
//     cin >> amount;



//     return 0.0; // TODO
// }


/**
 * TCalls the getBreakfast, getLunch, and getDinner functions
 * to calculate the employee's meal expenses.
 * The expenses are added to the totalExpenses global variable.
 * Allowable expenses are returned as a double.
 * @param
 * @param
 * @param
 * @return
 */
// double meals(int, double, double) {

//     return 0.0; // TODO
// }


/**
 * Asks the user for the amount spent on a breakfast meal.
 * The expenses are added to the totalExpenses global variable.
 * Allowable expenses are returned as a double.
 * @return
 */
// double getBreakfast() {

//     return 0.0; // TODO
// }


/**
 * Asks the user for the amount spent on a lunch meal.
 * The expenses are added to the totalExpenses global variable.
 * Allowable expenses are returned as a double.
 * @return
 */
// double getLunch() {

//     return 0.0; // TODO
// }


/**
 * Asks the user for the amount spent on a dinner meal.
 * The expenses are added to the totalExpenses global variable.
 * Allowable expenses are returned as a double.
 * @return
 */
// double getDinner() {

//     return 0.0; // TODO
// }
