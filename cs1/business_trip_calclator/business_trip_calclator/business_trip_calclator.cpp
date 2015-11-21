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
void inputDaysSpent(int& totalTripDays);
void inputDepartureTime(int* timeArray);
void inputReturnTime(int* timeArray);
bool isValidTime(int*);
void inputAirfare(double& airfare);
bool isValidAirfair(double airfare);
double inputCarRental();
bool isValidCarRental(double carRental);
double inputVehicle();
// double parking(int);
// double taxi(int);
// double registration();
// double hotel(int);
// double meals(int, double, double);
// double getBreakfast();
// double getLunch();
// double getDinner();
void restoreInputStream();
template <typename dataType> void input(dataType& data, string msg);

/**
 * Holds all the business trip related information.
 */
class BusinessTrip {
public:
    // Constructor.
    // Initilaizes the members when created.
    BusinessTrip() {
        totalAllowable = 0.0;
        totalTripDays  = 0;
        departureTime  = new int[2];
        returnTime     = new int[2];
        airFare        = 0.0;
        carRental      = 0.0;
        vehicle        = 0.0;
        parking        = 0.0;
        taxi           = 0.0;
        registration   = 0.0;
        hotel          = 0.0;
        meals          = 0.0;
    }

    // Constant for per mile allowance.
    const double MILAGE_ALLOWANCE = 0.27;

    // Expenses.
    double totalAllowable; // Total allowable expenses
    int totalTripDays;
    int* departureTime;   // Departure time (first day)
    int* returnTime;      // Arrival home time (last day)
    double airFare;
    double carRental;
    double vehicle;
    double parking;
    double taxi;
    double registration;
    double hotel;
    double meals;

    // Computes the total expenses.
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

    // Prints the information on this business trip.
    void print() {

        // TODO

    }
};


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    BusinessTrip trip;

    // Get the total trip days.
    inputDaysSpent( trip.totalTripDays );
    cout << "totalTripDays: " << trip.totalTripDays << endl;

    // Get the departure time and the return time.
    inputDepartureTime( trip.departureTime );
    inputReturnTime( trip.returnTime );
    // cout << "departureTime: " << trip.departureTime[0]
    //                           << trip.departureTime[1] << endl;
    // cout << "returnTime:    " << trip.returnTime[0]
    //                           << trip.returnTime[1] << endl;

    // Get the allowable airfare expenses.
    inputAirfare( trip.airFare );
    cout << "airFare: " << trip.airFare << endl;

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
void inputDaysSpent(int& totalTripDays) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        input<int>( totalTripDays, "\nHow many days did you spent on this trip? " );

        // VALIDATION
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the days are less than one.
        if ( !cin || totalTripDays < 1 ) {
            cout << "Invalid trip days : Must be 1 or more" << endl;
            restoreInputStream();

        } else {
            isFinished = true;  // Exit the loop.
        }
    }
}


/**
 * Asks for the time of departure.
 * @param timeArray An array of two integers to be used as a container to hold data.
 * [0]: hours, [1]: minutes.
 */
void inputDepartureTime(int* timeArray) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "\nEnter the departure time, in 24-hour time (e.g., 07:30, 22:10): " << endl;
        cout << ">>> ";
        cin >> timeArray[0];  // hours
        cin.ignore(1, ':');
        cin >> timeArray[1];  // minutes
        cout << endl;

        // VALIDATION
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the time is invalid.
        if ( !cin || !isValidTime(timeArray) ) {
            cout << "Invalid time : Must be in 24-hour time" << endl;
            restoreInputStream();

        } else {
            isFinished = true;  // Exit the loop.
        }
    }
}


/**
 * Asks for the time of arrival.
 * @param timeArray An array of two integers to be used as a container to hold data.
 * [0]: hours, [1]: minutes.
 */
void inputReturnTime(int* timeArray) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "\nEnter the return time, in 24-hour time (e.g., 07:30, 22:10): " << endl;
        cout << ">>> ";
        cin >> timeArray[0];  // hours
        cin.ignore(1, ':');
        cin >> timeArray[1];  // minutes
        cout << endl;

        // VALIDATION
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the time is invalid.
        if ( !cin || !isValidTime(timeArray) ) {
            cout << "Invalid time : Must be in 24-hour time" << endl;
            restoreInputStream();

        } else {
            isFinished = true;  // Exit the loop.
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
void inputAirfare(double& airfare) {

    bool isFinished = false;
    while ( !isFinished ) {

        input<double>( airfare, "\nEnter the amount of airfare: " );

        // VALIDATION
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the airfail is invalid.
        if ( !cin || !isValidAirfair(airfare) ) {
            cout << "Invalid airfare : Must be 0 or greater" << endl;
            restoreInputStream();

        } else {
            isFinished = true;  // Exit the loop.
        }
    }
}

/**
 * @return true if the airfare is valid, otherwise false.
 */
bool isValidAirfair(double airfare) {
    return airfare >= 0;
}


/**
 * Asks the user to enter the amount of car rental fees the employee incurred,
 * returns the amount of car rental fees as a double.
 * @return
 */
double carRental() {

    double carRentalFees = 0.0;

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user
        cout << "\nEnter the amount of car rental fees: " << endl;
        cout << ">>> ";
        cin  >> carRentalFees;
        cout << endl;

        // VALIDATION
        // 1. Reject if input stream is in the fail state.
        // 2. Reject if the car rental is invalid.
        if ( !cin || !isValidCarRental(carRentalFees) ) {
            cout << "Invalid carRentalFees : Must be 0 or greater" << endl;
            restoreInputStream();

        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // Return the value.
    return carRentalFees;
}


/**
 * @return true if the car rental is valid, otherwise false.
 */
bool isValidCarRental(double carRental) {
    return carRental < 0;
}

/**
 * Asks the user to enter the number of miles a private vehicle was driven.
 * Allowable expenses are returned as a double.
 * @return
 */
double inputVehicle() {



//    int miles;      // To hold the miles driven
//    double expense; // To hold the amount spent
//
//    // Get the number of miles driven.
//    cout << "Enter the miles driven by a "
//    << "private vehicle: ";
//    cin >> miles;
//
//    // Validate the number of miles driven.
//    while(miles < 0)
//    {
//        cout << "Miles driven must be 0 or greater.\n"
//        << "Enter the miles driven by a "
//        << "private vehicle: ";
//        cin  >> miles;
//    }
//
//    // Calculate the amount spent.
//    expense = miles * MILAGE_ALLOWANCE;
//
//    // Add amount spent to totalExpenses.
//    totalExpenses += expense;
//
//    // Return the amount spent.
//    return expense;

    return 0.0;
}


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

/**
 *
 */
template <typename dataType>
void input(dataType& data, string msg) {
    cout << msg << endl;
    cout << ">>> ";
    cin  >> data;
    cout << endl;
}
