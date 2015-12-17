/**
 * APCT-233C-01
 * C++ Lab
 *
 * business_trip_calculator.cpp
 * 11/20/2015
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


/**
 * BusinessTrip is a data type that holds all the business trip related information.
 */
struct BusinessTrip {

    // Static constants.
    static const double PRIVATE_CAR_MILAGE;
    static const double MAX_DAILY_PARKING;
    static const double MAX_DAILY_TAXI;
    static const double MAX_HOTEL_RATE_PER_NIGHT;
    static const double MAX_DAILY_BREAKFAST;
    static const double MAX_DAILY_LUNCH;
    static const double MAX_DAILY_DINNER;

    // Member variables.
    int totalTripDays;
    int departureTime[2];
    int returnTime[2];
    double totalSpent, totalAllowable, outOfPocket, saved;


    /**
     * Constructor. Initilaizes the members when created.
     */
    BusinessTrip() {

        totalTripDays  = -1;

        // The departure time (first day) and return time (last day)
        // in 24 hour time, [0]: hours, [1]: minutes
        departureTime[ 0 ] = -1;
        departureTime[ 1 ] = -1;
        returnTime[ 0 ]    = -1;
        returnTime[ 1 ]    = -1;

        // The total amount incurred by the businessperson.
        totalSpent = 0.0;

        // The max amount the company allow the businessperson to spend.
        totalAllowable = 0.0;

        // The total amount paid out-of-pocket by the businessperson due to
        // the businessperson spending beyond the company's limit.
        outOfPocket = 0.0;

        // The total amount that the company saved due to the businessperson
        // not using up the full amount allowable.
        saved = 0.0;
    }


    /**
     * Update the record of the expenses by adding the specified values.
     * @param spent      A value to be added to totalSpent.
     * @param allowable  A value to be added to totalAllowable.
     */
    void updateRecord(double spent, double allowable) {

        // Add the specified values to the appropriate variables.
        this->totalSpent     += spent;
        this->totalAllowable += allowable;

        // Determine the out-of-pocket amount or the saved amount.
        if (spent > allowable) {
            this->outOfPocket += (spent - allowable);

        } else {
            this->saved       += (allowable - spent);
        }
    }
};


// Initialize the static constants.
const double BusinessTrip::PRIVATE_CAR_MILAGE       =  0.27;
const double BusinessTrip::MAX_DAILY_PARKING        =  6.00;
const double BusinessTrip::MAX_DAILY_TAXI           = 10.00;
const double BusinessTrip::MAX_HOTEL_RATE_PER_NIGHT = 90.00;
const double BusinessTrip::MAX_DAILY_BREAKFAST      =  9.00;
const double BusinessTrip::MAX_DAILY_LUNCH          = 12.00;
const double BusinessTrip::MAX_DAILY_DINNER         = 16.00;


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Function prototypes.
void inputDaysSpent(BusinessTrip&);
void inputDepartureTime(BusinessTrip&);
void inputReturnTime(BusinessTrip&);
bool isValidTime(int[]);
void inputAirfair(BusinessTrip&);
void inputCarRental(BusinessTrip&);
void inputPrivateVehicle(BusinessTrip&);
void inputParking(BusinessTrip&);
void inputTaxi(BusinessTrip&);
void inputRegistration(BusinessTrip&);
void inputHotel(BusinessTrip&);
void inputBreakfast(double[]);
void inputLunch(double[]);
void inputDinner(double[]);
void inputMeals(BusinessTrip&);
void output(BusinessTrip&);

void fixInputStream();

void promptUserTime(int[], string, string, bool (*)(int[]));

template <typename dataType>
void promptUser(dataType&, string, string, bool (*)(dataType));

template <typename dataType>
bool zeroOrGreater(dataType);

template <typename dataType>
bool oneOrGreater(dataType);


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    // A central place to hold data.
    BusinessTrip trip;

    // Prompt the user for the required data.
    inputDaysSpent(trip);
    inputDepartureTime(trip);
    inputReturnTime(trip);
    inputAirfair(trip);
    inputCarRental(trip);
    inputPrivateVehicle(trip);
    inputParking(trip);
    inputTaxi(trip);
    inputRegistration(trip);
    inputHotel(trip);
    inputMeals(trip);

    // Print the information to the console.
    output(trip);

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Asks for the number of days spent on the trip.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputDaysSpent(BusinessTrip& trip) {

    promptUser<int>(trip.totalTripDays,
        "How many days did you spent on this trip? ",
        "Invalid trip days : Must be 1 or more",
        oneOrGreater<int>);
}


/**
 * Asks for the time of departure.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputDepartureTime(BusinessTrip& trip) {

    promptUserTime(trip.departureTime,
        "Departure time, in 24-hour time (e.g., 07:30, 22:10): ",
        "Invalid time : e.g., 07:30, 22:10",
        isValidTime);
}


/**
 * Asks for the time of arrival.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputReturnTime(BusinessTrip& trip) {

    promptUserTime(trip.returnTime,
        "Return time, in 24-hour time (e.g., 07:30, 22:10): ",
        "Invalid time : e.g., 07:30, 22:10",
        isValidTime);
}


/**
 * Ensure that a time is in the 24 hour format of HH:MM.
 * @param time  An array of integer, [0]: hours, [1]: minutes.
 * @return true if the time format is valid. Otherwise false.
 */
bool isValidTime(int time[]) {

    int hours   = time[ 0 ];
    int minutes = time[ 1 ];

    return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60);
}


/**
 * Asks the user to enter the total airfair the employee incurred.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputAirfair(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Total amount of airfair: ",
        "Invalid airfair : Must be 0 or greater",
        zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = totalSpent;

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
}


 /**
  * Asks the user to enter the total car rental fees the employee incurred.
  * @param &trip  A BusinessTrip object to which we write data.
  */
 void inputCarRental(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
         "Total amount of car rental fees: ",
         "Invalid airfair : Must be 0 or greater",
         zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = totalSpent;

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
 }


/**
 * Asks the user to enter the total milage a private PrivateVehicle was driven.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputPrivateVehicle(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    double milesDriven  = 0.0;

    promptUser<double>(milesDriven,
        "Total miles driven by a private vehicle: ",
        "Invalid MilesDriven : Must be 0 or greater",
        zeroOrGreater<double>);

    // Calculate the amount spent.
    totalSpent = milesDriven * BusinessTrip::PRIVATE_CAR_MILAGE;

    // Get totalAllowable.
    totalAllowable = totalSpent;

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
}


/**
 * Asks the user to enter the total parking fees.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputParking(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Total amount of parking fees: ",
        "Invalid value : Must be 0 or greater",
        zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = BusinessTrip::MAX_DAILY_PARKING * trip.totalTripDays;

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
}


/**
 * Asks the user to enter the total taxi fees.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputTaxi(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Total amount of taxi fees: ",
        "Invalid value : Must be 0 or greater",
        zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = BusinessTrip::MAX_DAILY_TAXI * trip.totalTripDays;

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
}


/**
 * Asks the user for the total conference registration fees incurred by the employee.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputRegistration(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Total amount of registration fees: ",
        "Invalid value : Must be 1 or more",
        oneOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = totalSpent;

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
}


/**
 * Asks the user to enter the nightly rate and computes the total hotel expenses.
 * NOTE: No hotel is allowed on return day.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputHotel(BusinessTrip& trip) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    double nightlyRate  = 0.0;

    // The travel must be more than one day to get allowable hotel expenses.
    if (trip.totalTripDays <= 1) {
        cout << "No hotel allowable for one-day trip" << endl;
        return;
    }

    promptUser<double>(nightlyRate,
        "Nightly hotel rate: ",
        "Invalid value : Must be 1 or more",
        oneOrGreater<double>);

    // Get totalSpent
    totalSpent = nightlyRate * (trip.totalTripDays - 1);

    // Get totalAllowable.
    totalAllowable = BusinessTrip::MAX_HOTEL_RATE_PER_NIGHT * (trip.totalTripDays - 1);

    // Add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(totalSpent, totalAllowable);
}


/**
 * Asks the user for the amount spent on one breakfast meal.
 * Stores the data to a temporary double array so that we can calculate spending
 * for all the meals in the trip.
 * @param spendingData  A double array to which we write data.
 *                      [0]: totalSpent, [1]: totalAllowable
 */
void inputBreakfast(double spendingData[]) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Breakfast: ",
        "Invalid value : Must be 0 or greater.",
        zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = BusinessTrip::MAX_DAILY_BREAKFAST;

    // Add totalSpent and totalAllowable to our temporary storage so that
    // we can add them for the all meals.
    spendingData[ 0 ] += totalSpent;
    spendingData[ 1 ] += totalAllowable;
}


/**
 * Asks the user for the amount spent on one lunch meal.
 * Stores the data to a temporary double array so that we can calculate spending
 * for all the meals in the trip.
 * @param spendingData  A double array to which we write data.
 *                      [0]: totalSpent, [1]: totalAllowable
 */
void inputLunch(double spendingData[]) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Lunch: ",
        "Invalid value : Must be 0 or greater.",
        zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = BusinessTrip::MAX_DAILY_LUNCH;

    // Add totalSpent and totalAllowable to our temporary storage so that
    // we can add them for the all meals.
    spendingData[ 0 ] += totalSpent;
    spendingData[ 1 ] += totalAllowable;
}


/**
 * Asks the user for the amount spent on one dinner meal.
 * Stores the data to a temporary double array so that we can calculate spending
 * for all the meals in the trip.
 * @param spendingData  A double array to which we write data.
 *                      [0]: totalSpent, [1]: totalAllowable
 */
void inputDinner(double spendingData[]) {

    double totalSpent     = 0.0;
    double totalAllowable = 0.0;

    // Get totalSpent.
    promptUser<double>(totalSpent,
        "Dinner: ",
        "Invalid value : Must be 0 or greater.",
        zeroOrGreater<double>);

    // Get totalAllowable.
    totalAllowable = BusinessTrip::MAX_DAILY_DINNER;

    // Add totalSpent and totalAllowable to our temporary storage so that
    // we can add them for the all meals.
    spendingData[ 0 ] += totalSpent;
    spendingData[ 1 ] += totalAllowable;
}


/**
 * Prompts the user to enter the amount of expenses on meals based on the trip schedule.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputMeals(BusinessTrip& trip) {

    // Temporary data store for spending.
    // We add each spending item to this double array.
    // [0]: totalSpent, [1]: totalAllowable
    double spendingData[2] = { 0.0, 0.0 };  // Initially 0.0

    // One day trip.
    if (trip.totalTripDays == 1) {

        if (trip.departureTime[ 0 ] < 7 && trip.returnTime[ 0 ] >= 8) {
            inputBreakfast(spendingData);
        }

        if (trip.departureTime[ 0 ] < 12 && trip.returnTime[ 0 ] >= 13) {
            inputLunch(spendingData);
        }

        if (trip.departureTime[ 0 ] < 18 && trip.returnTime[ 0 ] >= 19) {
            inputDinner(spendingData);
        }

    } else {

        // First day
        cout << "----[Day 1]----" << endl;

        // No dinner allowed if departure is at 6pm or later.
        if (trip.departureTime[ 0 ] >= 18) {
            cout << "No meals allowed due to departure after 6pm" << endl;

        } else {

            if (trip.departureTime[ 0 ] < 7) {
                inputBreakfast(spendingData);  // Get breakfast if departure is at 7am or ealier.
            }

            if (trip.departureTime[ 0 ] < 12) {
                inputLunch(spendingData);      // Get lunch if departure is at 12pm or later.
            }

            inputDinner(spendingData);
        }

        // 2nd day through the day before last.
        for (int count = 2; count < trip.totalTripDays; count++) {

            cout << "----[Day " << count << "]----" << endl;
            inputBreakfast(spendingData);
            inputLunch(spendingData);
            inputDinner(spendingData);
        }

        // Last day
        cout << "----[Day " << trip.totalTripDays << "]----" << endl;

        if (trip.returnTime[ 0 ] < 8) {
            cout << "No meals allowed due to return before 8am" << endl;

        } else {
            inputBreakfast(spendingData);

            if (trip.returnTime[ 0 ] >= 13) {
                inputLunch(spendingData);   // Get lunch if arrival is 1pm or later.
            }

            if (trip.returnTime[ 0 ] >= 19) {
                inputDinner(spendingData);  // Get dinner if arrival is 7pm or later.
            }
        }
    }

    // Finally, add totalSpent and totalAllowable to our data storage.
    trip.updateRecord(spendingData[ 0 ], spendingData[ 1 ]);
}


/**
 * Prints the information on a business trip.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void output(BusinessTrip& trip) {

    // Display duration, departure time and return time.
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Total days:     " << setfill('0')
         << setw(2) << trip.totalTripDays << endl;

    cout << "Departure time: " << setfill('0')
         << setw(2) << trip.departureTime[0] << ":"
         << setw(2) << trip.departureTime[1]
         << setfill(' ') << endl;

    cout << "Return time:    " << setfill('0')
         << setw(2) << trip.returnTime[0] << ":"
         << setw(2) << trip.returnTime[1]
         << setfill(' ') << endl;

    cout << endl;

    // Display totals.
    cout << fixed << showpoint << setprecision(2);
        cout << "Total expenses:     " << "$" << setw(8) << trip.totalSpent << endl;
        cout << "Allowable expenses: " << "$" << setw(8) << trip.totalAllowable << endl;

    // Display amount paid out-of-pocket.
    if (trip.outOfPocket > 0.0) {
        cout << "Out of pocket:      " << "$" << setw(8) << trip.outOfPocket << endl;
    }

    // Display amount saved.
    if (trip.saved > 0.0) {
        cout << "Amount saved:       " << "$" << setw(8) << trip.saved << endl;
    }

    cout << endl;
}


/**
 * Restores the input stream.
 */
void fixInputStream() {
    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer
}


/**
 * Prompts the user for data with the specified message and stores the data
 * in the passed-in variable.
 * NOTE: Must specify a data type we want to process.
 * @param data           A variable in which the data will be stored.
 * @param promtMsg       A prompt message.
 * @param errorMsg       An error message.
 * @param conditionFun   A pointer to a function that accept a value of specified
 *                       data type and returns bool.
 */
template <typename dataType>
void promptUser(dataType& data,
                string promtMsg,
                string errorMsg,
                bool (*conditionFun)(dataType value)) {

    bool isFinished = false;
    while ( !isFinished ) {

        cout << promtMsg << endl;
        cout << ">>> ";
        cin  >> data;

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || !conditionFun(data) ) {
            cout << errorMsg << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }
}


/**
 * Prompts the user for time (hours and minutes, 24-hour time) with the specified
 * message and stores the data into the passed-in int array of size 2.
 * NOTE: Must specify a data type we want to process.
 * @param data           An int array in which the data will be stored.
 * @param promtMsg       A prompt message.
 * @param errorMsg       An error message.
 * @param conditionFun   A pointer to a function that accept a value of specified
 *                       data type and returns bool.
 */
void promptUserTime(int data[],
                    string promtMsg,
                    string errorMsg,
                    bool (*conditionFun)(int value[])) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << promtMsg << endl;
        cout << ">>> ";
        cin >> data[0];  // hours
        cin.ignore(1, ':');
        cin >> data[1];  // minutes

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || !conditionFun(data) ) {
            cout << errorMsg << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }
}


/**
 * NOTE: Must specify a data type we want to process.
 * @param value
 * @return true if the value is zero or greater.
 */
template <typename dataType>
bool zeroOrGreater(dataType value) {
    return value >= 0;
}


/**
 * NOTE: Must specify a data type we want to process.
 * @param value
 * @return true if the value is one or greater.
 */
template <typename dataType>
bool oneOrGreater(dataType value) {
    return value >= 1;
}
