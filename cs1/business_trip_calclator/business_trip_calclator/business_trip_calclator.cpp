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


/**
 * Defines the new data type, BusinessTrip.
 * Holds all the business trip related information.
 */
class BusinessTrip {
public:
    // Static constant.
    constexpr static const double PRIVATE_CAR_MILAGE_ALLOWANCE =  0.27;
    constexpr static const double MAX_DAILY_PARKING_FEE        =  6.00;
    constexpr static const double MAX_DAILY_TAXI_FEE           = 10.00;
    constexpr static const double MAX_HOTEL_RATE_PER_NIGHT     = 90.00;
    constexpr static const double MAX_DAILY_BREAKFAST          =  9.00;
    constexpr static const double MAX_DAILY_LUNCH              = 12.00;
    constexpr static const double MAX_DAILY_DINNER             = 16.00;

    // Member variables.
    int totalTripDays;
    int* departureTime;
    int* returnTime;
    double airfair, carRental, privateVehicle, parking, taxi, registration,
           hotel, breakfast, lunch, dinner, outOfPocket;

    // Constructor. Initilaizes the members when created.
    BusinessTrip() {

        totalTripDays  = 0;

        // The departure time (first day) and return time (last day)
        // in 24 hour time, [0]: hours, [1]: minutes
        departureTime  = new int[2];
        returnTime     = new int[2];

        // The allowable.
        airfair        = 0.0;
        carRental      = 0.0;
        privateVehicle = 0.0;
        parking        = 0.0;
        taxi           = 0.0;
        registration   = 0.0;
        hotel          = 0.0;
        breakfast      = 0.0;
        lunch          = 0.0;
        dinner         = 0.0;

        // The amount to be reimbursed by the businessperson.
        outOfPocket    = 0.0;
    }

    // Computes the total amount of the allowable.
    double getTotalAllowable() {
        return (
            airfair +
            carRental +
            privateVehicle +
            parking +
            taxi +
            registration +
            hotel +
            breakfast +
            lunch +
            dinner
        );
    }

    // Computes the total expenses.
    double getTotalExpensesIncurred() {
        return getTotalAllowable() + outOfPocket;
    }

    // Computes the total expenses.
    void payOutOfPocket(double amount) {
        outOfPocket += amount;
    }

    // Prints the information on this business trip.
    void print() {

        cout << "departureTime: " << setw(2) << departureTime[0] << ":"
                                  << setw(2) << departureTime[1] << endl;
        cout << "returnTime:    " << setw(2) << returnTime[0] << ":"
                                  << setw(2) << returnTime[1] << endl;

        double totalExpenses = getTotalExpensesIncurred();
        double allowable     = getTotalAllowable();
        double reimburse     = outOfPocket;
        double saved         = allowable - totalExpenses;

        // Display Totals.
        cout << fixed << showpoint << setprecision(2);
        cout << "\nTotal expenses:            $" << setw(8) << totalExpenses << endl;
        cout << "\nAllowable expenses:        $" << setw(8) << allowable << endl;

            // Display amount to be reimbursed.
        if (outOfPocket > 0.0) {
            cout << "Amount to be reimbursed: $" << setw(8) << reimburse << endl;

            // Display amount saved.
        } else if (totalExpenses < allowable) {
            cout << "Amount saved:            $" << setw(8) << saved << endl;
        }

        cout << endl;
    }
};


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Function prototypes.
void inputDaysSpent(BusinessTrip);
void inputDepartureTime(BusinessTrip);
void inputReturnTime(BusinessTrip);
bool isValidTime(int*);
void inputAirfair(BusinessTrip);
void inputCarRental(BusinessTrip);
void inputPrivateVehicle(BusinessTrip);
void inputParking(BusinessTrip);
void inputTaxi(BusinessTrip);
void inputRegistration(BusinessTrip);
void inputHotel(BusinessTrip);
void inputBreakfast(BusinessTrip);
void inputLunch(BusinessTrip);
void inputDinner(BusinessTrip);
void inputMeals(BusinessTrip);

void fixInputStream();
template <typename dataType> void promptUser(dataType& data, string msg);


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
    trip.print();

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Asks for the number of days spent on the trip.
 * @return The number of days spent on the trip as an integer
 */
void inputDaysSpent(BusinessTrip trip) {

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<int>(trip.totalTripDays, "\nHow many days did you spent on this trip? " );

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || trip.totalTripDays < 1 ) {
            cout << "Invalid trip days : Must be 1 or more" << endl;
            fixInputStream();
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
void inputDepartureTime(BusinessTrip trip) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "\nEnter the departure time, in 24-hour time (e.g., 07:30, 22:10): " << endl;
        cout << ">>> ";
        cin >> trip.departureTime[0];  // hours
        cin.ignore(1, ':');
        cin >> trip.departureTime[1];  // minutes
        cout << endl;

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || !isValidTime(trip.departureTime) ) {
            cout << "Invalid time : Must be in 24-hour time" << endl;
            fixInputStream();
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
void inputReturnTime(BusinessTrip trip) {

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        cout << "\nEnter the return time, in 24-hour time (e.g., 07:30, 22:10): " << endl;
        cout << ">>> ";
        cin >> trip.returnTime[0];  // hours
        cin.ignore(1, ':');
        cin >> trip.returnTime[1];  // minutes
        cout << endl;

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || !isValidTime(trip.returnTime) ) {
            cout << "Invalid time : Must be in 24-hour time" << endl;
            fixInputStream();
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
 * Asks the user to enter the amount of any Airfair the employee incurred,
 * adds the value to the totalExpenses.
 * @return the airfair amount
 */
void inputAirfair(BusinessTrip trip) {

    double expenses = 0.0;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<double>(expenses, "\nEnter the amount of Airfair: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid Airfair : Must be 0 or greater" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // Add it to the allowable.
    trip.airfair += expenses;
}


/**
 * Asks the user to enter the amount of car rental fees the employee incurred,
 * @param carRental  The amount of car rental fees as a double.
 */
void inputCarRental(BusinessTrip trip) {

    double expenses = 0.0;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<double>(expenses, "\nEnter the amount of car rental fees: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid carRental : Must be 0 or greater" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // Add it to the allowable.
    trip.carRental += expenses;
}


/**
 * Asks the user to enter the number of miles a private PrivateVehicle was driven.
 * @param Vehicle  An amount of the allowable expenses in the Vehicle category.
 */
void inputPrivateVehicle(BusinessTrip trip) {

    double expenses    = 0.0;
    double milesDriven = 0.0;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<double>(milesDriven, "\nEnter the miles driven by a private vehicle: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || milesDriven < 0 ) {
            cout << "Invalid MilesDriven : Must be 0 or greater" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // Calculate the amount spent.
    expenses = milesDriven * BusinessTrip::PRIVATE_CAR_MILAGE_ALLOWANCE;

    // Add it to the allowable.
    trip.privateVehicle += expenses;
}


/**
 * Asks the user to enter the amount of any parking fees.
 * @param
 * @return
 */
void inputParking(BusinessTrip trip) {

    double expenses   = 0.0;

    // Calculate the maximum allowance for parking fees.
    double maxParking = BusinessTrip::MAX_DAILY_PARKING_FEE * trip.totalTripDays;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<double>(expenses, "\nEnter the amount of total parking fees: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid value : Must be 0 or greater" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // If the expenses exceed the allowance,
    // the businessperson must pay out of pocket.
    if (expenses > maxParking) {
        trip.payOutOfPocket( expenses - maxParking );
        trip.parking += maxParking;
    } else {
        trip.parking += expenses;
    }
}


/**
 * Asks the user to enter the amount of any taxi fees.
 * @param
 * @return Allowable expenses
 */
void inputTaxi(BusinessTrip trip) {

    double expenses   = 0.0;

    // Calculate the maximum allowance for parking fees.
    double maxTaxi = BusinessTrip::MAX_DAILY_TAXI_FEE * trip.totalTripDays;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<double>(expenses, "\nEnter the amount of total taxi fees: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid value : Must be 0 or greater" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // If the expenses exceed the allowance,
    // the businessperson must pay out of pocket.
    if (expenses > maxTaxi) {
        trip.payOutOfPocket( expenses - maxTaxi );
        trip.parking += maxTaxi;
    } else {
        trip.parking += expenses;
    }
}


/**
 * Asks the user to enter the amount of conference registration fees
 * incurred by the employee, adds the amount to totalExpenses.
 * @return the amount spent
 */
void inputRegistration(BusinessTrip trip) {

    double expenses   = 0.0;

    bool isFinished = false;
    while ( !isFinished ) {

        // Prompt the user fot the total days spent.
        promptUser<double>(expenses, "\nEnter the amount of registration fees: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 1 ) {
            cout << "Invalid value : Must be 1 or more" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // Add it to the allowable.
    trip.registration += expenses;
}


/**
 * Asks the user to enter the amount of hotel expenses.
 *
 * VALIDATION:
 * - The company allowes up to $90 per night for lodging.
 * - Anything in excess of this must be paid by the employee
 *
 * @param
 * @return
 */
void inputHotel(BusinessTrip trip) {

    double expenses    = 0.0;
    double nightlyRate = 0.0;

    // VALIDATION:
    // The travel must be more than one day to get allowable hotel expenses.
    if (trip.totalTripDays <= 1) {
        cout << "No hotel allowable for one-day trip" << endl;
        return;
    }

    // Calculate the maximum allowance for hotel expenses.
    // No hotel is used on return day.
    double maxHotelExpenses =
        BusinessTrip::MAX_HOTEL_RATE_PER_NIGHT * (trip.totalTripDays - 1);

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser<double>(nightlyRate, "\nEnter the nightly hotel room rate: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || nightlyRate < 1 ) {
            cout << "Invalid value : Must be 1 or more" << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // Compute the total hotel expenses.
    expenses = nightlyRate * (trip.totalTripDays - 1);

    // If the expenses exceed the allowance,
    // the businessperson must pay out of pocket.
    if (expenses > maxHotelExpenses) {
        trip.payOutOfPocket(expenses - maxHotelExpenses);
        trip.hotel += maxHotelExpenses;
    } else {
        trip.hotel += expenses;
    }
}


/**
 * Asks the user for the amount spent on a breakfast meal.
 * @return
 */
void inputBreakfast(BusinessTrip trip) {

    double expenses = 0.0;
    double dailyMax = BusinessTrip::MAX_DAILY_BREAKFAST;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser(expenses, "\nEnter the amount spent for breakfast: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid value : Must be 0 or greater." << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // If the expenses exceed the allowance,
    // the businessperson must pay out of pocket.
    if (expenses > dailyMax) {
        trip.payOutOfPocket( trip.breakfast - dailyMax );
        trip.breakfast += dailyMax;
    } else {
        trip.breakfast += expenses;
    }
}


/**
 * Asks the user for the amount spent on a lunch meal.
 * @return
 */
void inputLunch(BusinessTrip trip) {

    double expenses = 0.0;
    double dailyMax = BusinessTrip::MAX_DAILY_LUNCH;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser(expenses, "\nEnter the amount spent for lunch: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid value : Must be 0 or greater." << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // If the expenses exceed the allowance,
    // the businessperson must pay out of pocket.
    if (expenses > dailyMax) {
        trip.payOutOfPocket( trip.lunch - dailyMax );
        trip.lunch += dailyMax;
    } else {
        trip.lunch += expenses;
    }
}


/**
 * Asks the user for the amount spent on a dinner meal.
 * @return
 */
void inputDinner(BusinessTrip trip) {

    double expenses = 0.0;
    double dailyMax = BusinessTrip::MAX_DAILY_DINNER;

    bool isFinished = false;
    while ( !isFinished ) {

        promptUser(expenses, "\nEnter the amount spent for dinner: ");

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin || expenses < 0 ) {
            cout << "Invalid value : Must be 0 or greater." << endl;
            fixInputStream();
        } else {
            isFinished = true;  // Exit the loop.
        }
    }

    // If the expenses exceed the allowance,
    // the businessperson must pay out of pocket.
    if (expenses > dailyMax) {
        trip.payOutOfPocket( trip.dinner - dailyMax );
        trip.dinner += dailyMax;
    } else {
        trip.dinner += expenses;
    }
}


void inputMeals(BusinessTrip trip) {

    // Handle special case of a one day trip.
    if (trip.totalTripDays == 1) {

        if (trip.departureTime[0] < 7 &&
            trip.returnTime[0]   >= 8) {
            inputBreakfast(trip);    // Get breakfast
        }

        if (trip.departureTime[0] < 12 &&
            trip.returnTime[0]   >= 13) {
            inputLunch(trip);        // Get lunch
        }

        if (trip.departureTime[0] < 18 &&
            trip.returnTime[0]   >= 19) {
            inputDinner(trip);       // Get dinner
        }


    // Get meal amounts allowed for the first day.
    } else {

        cout << "Day 1:\n";

        // Determine if departure is at 6pm or later.
        if (trip.departureTime[0] >= 18) {
            cout << "No meals allowed due to departure after 6:00 p.m.\n";

        } else {
            // Determine if departure is at 7am or ealier.
            if (trip.departureTime[0] < 7) {
                inputBreakfast(trip); // Get breakfa trip st

                // Determine if departure is at 12pm or later.
            } else if (trip.departureTime[0] < 12) {
                inputLunch(trip);     // Get lunch

            } else {
                inputDinner(trip);    // Get dinner
            }
        }

        // Get meal amounts for the 2nd day through
        // the next-to-last day.
        for (int count = 2; count < trip.totalTripDays; count++) {
            cout << "Day " << count << ":\n";
            inputBreakfast(trip);    // Get breakfast
            inputLunch(trip);        // Get lunch
            inputDinner(trip);       // Get dinner
        }

        // Get meal amounts for last day of trip.
        cout << "Day " << trip.totalTripDays << ": \n";
        if (trip.returnTime[0] < 8) {
            cout << "No meals allowed due to return before 8:00 a.m." << endl;

        } else {
            // Get amount spent for breakfast.
            inputBreakfast( trip );

            // Determine if arrival is 1pm or later.
            if (trip.returnTime[0] >= 13) {
                inputLunch(trip);
            }

            // Determine if arrival is 7pm or later.
            if (trip.returnTime[0] >= 19) {
                inputDinner(trip);
            }

        }
    }
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
 * @param data  A variable in which the data will be stored.
 * @param msg   A prompt message.
 */
template <typename dataType>
void promptUser(dataType& data, string msg) {
    cout << msg << endl;
    cout << ">>> ";
    cin  >> data;
    cout << endl;
}
