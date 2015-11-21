/**
 * APCT-233C-01
 * C++ Lab
 *
 * business_trip_calclator.cpp
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
int  inputDaysSpent();
void inputDepartureTime(int* dataArray);
void inputReturnTime(int* dataArray);
bool isValidTime(int*);
// double airfare();
// double carRental();
// double vehicle();
// double parking(int);
// double taxi(int);
// double registration();
// double hotel(int);
// double meals(int, double, double);
// double getBreakfast();
// double getLunch();
// double getDinner();
void restoreInputStream();

/**
 * Holds all the business trip related information.
 */
class BusinessTrip {
public:
    // Constructor.
    BusinessTrip() {
        totalAllowable = 0.0;
        totalTripDays  = 0;
        departureTime  = new int[2];  // Departure time (first day)
        returnTime     = new int[2];  // Arrival home time (last day)
        airFare        = 0.0;
        carRental      = 0.0;
        vehicle        = 0.0;
        parking        = 0.0;
        taxi           = 0.0;
        registration   = 0.0;
        hotel          = 0.0;
        meals          = 0.0;
    }

    double totalAllowable = 0.0; // Total allowable expenses
    int totalTripDays ;
    int* departureTime;  // Departure time (first day)
    int* returnTime;     // Arrival home time (last day)
    double airFare;
    double carRental;
    double vehicle;
    double parking;
    double taxi;
    double registration;
    double hotel;
    double meals;

    double getTotalExpenses() {
        return (
            airFare +
            carRental +
            vehicle +
            parking +
            taxi +
            registration +
            hotel +
            meals
        );
    }

    void print() {

        // TODO

    }
};

// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //




int main() {

    BusinessTrip trip;

    // Get the total number of days for the trip.
    trip.totalTripDays = inputDaysSpent();
    //cout << "totalTripDays: " << trip.totalTripDays <<endl;

    // Get the arrival and departure times.
    inputDepartureTime( trip.departureTime );
    inputReturnTime( trip.returnTime );
    cout << "departureTime: " << trip.departureTime[0] << trip.departureTime[1]  << endl;
    cout << "returnTime: "    << trip.returnTime[0]    << trip.returnTime[1]  << endl;

    // // Get the allowable airfare expenses.
    // allowable = airfare();

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
    // allowable += meals(totalTripDays, timeDeparture, timeReturn);

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
        cout << "\nHow many days did you spent on this trip? " << endl;
        cout << ">>> ";
        cin >> totalTripDays;
        cout << endl;

        // Validation.
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the days are less than one.
        if ( !cin || totalTripDays < 1 ) {
            cout << "Invalid trip days : Must be 1 or more" << endl;
            restoreInputStream();

        } else {
            // Exit the loop.
            isFinished = true;
        }
    }

    return totalTripDays;
}


/**
 * Asks for the time of departure.
 * @param dataArray An array of two integers to be used as a container to hold data.
 * [0]: hours, [1]: minutes.
 */
void inputDepartureTime(int* dataArray) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "\nEnter the departure time, in 24-hour time (e.g., 07:30, 22:10): " << endl;
        cout << ">>> ";
        cin >> dataArray[0];  // hours
        cin.ignore(1, ':');
        cin >> dataArray[1];  // minutes
        cout << endl;

        // Validation.
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the time is invalid.
        if ( !cin || !isValidTime(dataArray) ) {
            cout << "Invalid time : Must be in 24-hour time" << endl;
            restoreInputStream();

        } else {
            // Exit the loop.
            isFinished = true;
        }
    }
}


/**
 * Asks for the time of arrival.
 * @param dataArray An array of two integers to be used as a container to hold data.
 * [0]: hours, [1]: minutes.
 */
void inputReturnTime(int* dataArray) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "\nEnter the return time, in 24-hour time (e.g., 07:30, 22:10): " << endl;
        cout << ">>> ";
        cin >> dataArray[0];  // hours
        cin.ignore(1, ':');
        cin >> dataArray[1];  // minutes
        cout << endl;

        // Validation.
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the time is invalid.
        if ( !cin || !isValidTime(dataArray) ) {
            cout << "Invalid time : Must be in 24-hour time" << endl;
            restoreInputStream();

        } else {
            // Exit the loop.
            isFinished = true;
        }
    }
}


/**
 * Ensure that a time is in the 24 hour format of HH.MM.
 * @param time  An array of integer, [0]: hours, [1]: minutes.
 * @return true if the time format is valid. Otherwise false.
 */
bool isValidTime(int time[]) {

    int hours   = time[0];
    int minutes = time[1];

    return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60);
}


/**
 * Asks the user to enter the amount of any airfare the employee incurred,
 * adds the value to the totalExpenses.
 * @return the airfare amount
 */
// double airfare() {

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

/**
 *
 */
void restoreInputStream() {
    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer
}
