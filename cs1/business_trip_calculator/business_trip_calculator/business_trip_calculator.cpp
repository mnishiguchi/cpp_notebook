/**
 * APCT-233C-01
 * C++ Lab
 *
 * business_trip_calculator.cpp
 * 11/20/2015
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
           hotel, breakfast, lunch, dinner, outOfPocket, totalExpenses;

    // Constructor. Initilaizes the members when created.
    BusinessTrip() {

        totalTripDays  = 0;

        // The departure time (first day) and return time (last day)
        // in 24 hour time, [0]: hours, [1]: minutes
        departureTime  = new int[2];
        returnTime     = new int[2];

        // The total expenses incurred by the businessperson.
        totalExpenses  = 0.0;

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
        return airfair + carRental + privateVehicle + parking + taxi +
               registration + hotel + breakfast + lunch + dinner;
    }

    // Computes the total expenses.
    void updateTotalExpenses(double expenses) {
        totalExpenses += expenses;
    }

    // Computes the total amount that the businessperson needs to reimburse.
    void payOutOfPocket(double expenses) {
        outOfPocket += expenses;
    }

    // Prints the information on this business trip.
    void print() {

        // Display duration, departure time and return time.
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "Total days:    " << setfill('0')
             << setw(2) << totalTripDays << endl;

        cout << "departureTime: " << setfill('0')
             << setw(2) << departureTime[0] << ":"
             << setw(2) << departureTime[1]
             << setfill(' ') << endl;

        cout << "returnTime:    " << setfill('0')
             << setw(2) << returnTime[0] << ":"
             << setw(2) << returnTime[1]
             << setfill(' ') << endl;

        cout << endl;

        double allowable = getTotalAllowable();
        double saved     = allowable - totalExpenses;

        // Display totals.
        cout << fixed << showpoint << setprecision(2);
            cout << "Total expenses:          " << "$" << setw(8) << totalExpenses << endl;
            cout << "Allowable expenses:      " << "$" << setw(8) << allowable << endl;

        // Display amount to be reimbursed.
        if (outOfPocket > 0.0) {
            cout << "Amount to be reimbursed: " << "$" << setw(8) << outOfPocket << endl;
        }

        // Display amount saved.
        if (totalExpenses < allowable) {
            cout << "Amount saved:            " << "$" << setw(8) << saved << endl;
        }

        cout << endl;
    }
};


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Function prototypes.
void inputDaysSpent(BusinessTrip&);
void inputDepartureTime(BusinessTrip&);
void inputReturnTime(BusinessTrip&);
bool isValidTime(int*);
void inputAirfair(BusinessTrip&);
void inputCarRental(BusinessTrip&);
void inputPrivateVehicle(BusinessTrip&);
void inputParking(BusinessTrip&);
void inputTaxi(BusinessTrip&);
void inputRegistration(BusinessTrip&);
void inputHotel(BusinessTrip&);
void inputBreakfast(BusinessTrip&);
void inputLunch(BusinessTrip&);
void inputDinner(BusinessTrip&);
void inputMeals(BusinessTrip&);

void fixInputStream();

void promptUserTime(int[], string, string, bool (*conditionFun)(int[]));

template <typename dataType>
void promptUser(dataType&, string, string, bool (*conditionFun)(dataType));

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
    trip.print();

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
        "Enter the departure time, in 24-hour time: ",
        "Invalid time : e.g., 07:30, 22:10",
        isValidTime);
}


/**
 * Asks for the time of arrival.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputReturnTime(BusinessTrip& trip) {

    promptUserTime(trip.returnTime,
        "Enter the return time, in 24-hour time: ",
        "Invalid time : e.g., 07:30, 22:10",
        isValidTime);
}


/**
 * Ensure that a time is in the 24 hour format of HH:MM.
 * @param time  An array of integer, [0]: hours, [1]: minutes.
 * @return true if the time format is valid. Otherwise false.
 */
bool isValidTime(int time[]) {

    int hours   = time[0];
    int minutes = time[1];

    return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60);
}


/**
 * Asks the user to enter the total airfair the employee incurred.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputAirfair(BusinessTrip& trip) {

    double expenses = 0.0;

    promptUser<double>(expenses,
        "Enter the amount of airfair: ",
        "Invalid airfair : Must be 0 or greater",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // Add it to the allowable.
    trip.airfair += expenses;
}


/**
 * Asks the user to enter the total car rental fees the employee incurred.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputCarRental(BusinessTrip& trip) {

    double expenses = 0.0;

    promptUser<double>(expenses,
        "Enter the amount of car rental fees: ",
        "Invalid airfair : Must be 0 or greater",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // Add it to the allowable.
    trip.carRental += expenses;
}


/**
 * Asks the user to enter the total milage a private PrivateVehicle was driven.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputPrivateVehicle(BusinessTrip& trip) {

    double expenses    = 0.0;
    double milesDriven = 0.0;

    promptUser<double>(milesDriven,
        "Enter the miles driven by a private vehicle: ",
        "Invalid MilesDriven : Must be 0 or greater",
        zeroOrGreater<double>);

    // Calculate the amount spent.
    expenses = milesDriven * BusinessTrip::PRIVATE_CAR_MILAGE_ALLOWANCE;

    trip.updateTotalExpenses(expenses);

    // Add it to the allowable.
    trip.privateVehicle += expenses;
}


/**
 * Asks the user to enter the total parking fees.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputParking(BusinessTrip& trip) {

    double expenses   = 0.0;

    // Calculate the maximum allowance for parking fees.
    double maxParking = BusinessTrip::MAX_DAILY_PARKING_FEE * trip.totalTripDays;

    promptUser<double>(expenses,
        "Enter the amount of total parking fees: ",
        "Invalid value : Must be 0 or greater",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // If the expenses exceed the allowance, the businessperson must pay out of pocket.
    if (expenses > maxParking) {
        trip.payOutOfPocket( expenses - maxParking );
        trip.parking += maxParking;
    } else {
        trip.parking += expenses;
    }
}


/**
 * Asks the user to enter the total taxi fees.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputTaxi(BusinessTrip& trip) {

    double expenses   = 0.0;

    // Calculate the maximum allowance for parking fees.
    double maxTaxi = BusinessTrip::MAX_DAILY_TAXI_FEE * trip.totalTripDays;

    promptUser<double>(expenses,
        "Enter the amount of total taxi fees: ",
        "Invalid value : Must be 0 or greater",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // If the expenses exceed the allowance, the businessperson must pay out of pocket.
    if (expenses > maxTaxi) {
        trip.payOutOfPocket( expenses - maxTaxi );
        trip.taxi += maxTaxi;
    } else {
        trip.taxi += expenses;
    }
}


/**
 * Asks the user for the total conference registration fees incurred by the employee.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputRegistration(BusinessTrip& trip) {

    double expenses   = 0.0;

    promptUser<double>(expenses,
        "Enter the amount of registration fees: ",
        "Invalid value : Must be 1 or more",
        oneOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // Add it to the allowable.
    trip.registration += expenses;
}


/**
 * Asks the user to enter the nightly rate and computes the total hotel expenses.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputHotel(BusinessTrip& trip) {

    double expenses    = 0.0;
    double nightlyRate = 0.0;

    // The travel must be more than one day to get allowable hotel expenses.
    if (trip.totalTripDays <= 1) {
        cout << "No hotel allowable for one-day trip" << endl;
        return;
    }

    // Calculate the maximum allowance for hotel expenses.
    // No hotel is used on return day.
    double maxHotelExpenses =
        BusinessTrip::MAX_HOTEL_RATE_PER_NIGHT * (trip.totalTripDays - 1);

    promptUser<double>(nightlyRate,
        "Enter the nightly hotel room rate: ",
        "Invalid value : Must be 1 or more",
        oneOrGreater<double>);

    // Compute the total hotel expenses.
    expenses = nightlyRate * (trip.totalTripDays - 1);

    trip.updateTotalExpenses(expenses);

    // If the expenses exceed the allowance, the businessperson must pay out of pocket.
    if (expenses > maxHotelExpenses) {
        trip.payOutOfPocket(expenses - maxHotelExpenses);
        trip.hotel += maxHotelExpenses;
    } else {
        trip.hotel += expenses;
    }
}


/**
 * Asks the user for the amount spent on one breakfast meal.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputBreakfast(BusinessTrip& trip) {

    double expenses = 0.0;
    double dailyMax = BusinessTrip::MAX_DAILY_BREAKFAST;

    promptUser<double>(expenses,
        "Enter the amount spent for breakfast: ",
        "Invalid value : Must be 0 or greater.",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // If the expenses exceed the allowance, the businessperson must pay out of pocket.
    if (expenses > dailyMax) {
        trip.payOutOfPocket( expenses - dailyMax );
        trip.breakfast += dailyMax;
    } else {
        trip.breakfast += expenses;
    }
}


/**
 * Asks the user for the amount spent on one lunch meal.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputLunch(BusinessTrip& trip) {

    double expenses = 0.0;
    double dailyMax = BusinessTrip::MAX_DAILY_LUNCH;

    promptUser<double>(expenses,
        "Enter the amount spent for lunch: ",
        "Invalid value : Must be 0 or greater.",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // If the expenses exceed the allowance, the businessperson must pay out of pocket.
    if (expenses > dailyMax) {
        trip.payOutOfPocket( expenses - dailyMax );
        trip.lunch += dailyMax;
    } else {
        trip.lunch += expenses;
    }
}


/**
 * Asks the user for the amount spent on one dinner meal.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputDinner(BusinessTrip& trip) {

    double expenses = 0.0;
    double dailyMax = BusinessTrip::MAX_DAILY_DINNER;

    promptUser<double>(expenses,
        "Enter the amount spent for dinner: ",
        "Invalid value : Must be 0 or greater.",
        zeroOrGreater<double>);

    trip.updateTotalExpenses(expenses);

    // If the expenses exceed the allowance, the businessperson must pay out of pocket.
    if (expenses > dailyMax) {
        trip.payOutOfPocket( expenses - dailyMax );
        trip.dinner += dailyMax;
    } else {
        trip.dinner += expenses;
    }
}


/**
 * Prompts the user to enter the amount of expenses on meals based on the trip schedule.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputMeals(BusinessTrip& trip) {

    // One day trip.
    if (trip.totalTripDays == 1) {

        if (trip.departureTime[0] < 7 && trip.returnTime[0] >= 8) {
            inputBreakfast(trip);
        }

        if (trip.departureTime[0] < 12 && trip.returnTime[0] >= 13) {
            inputLunch(trip);
        }

        if (trip.departureTime[0] < 18 && trip.returnTime[0] >= 19) {
            inputDinner(trip);
        }

    } else {

        // First day
        cout << "[Day 1]" << endl;

        // No dinner allowed if departure is at 6pm or later.
        if (trip.departureTime[0] >= 18) {
            cout << "No meals allowed due to departure after 6pm" << endl;

        } else {

            if (trip.departureTime[0] < 7) {
                inputBreakfast(trip);  // Get breakfast if departure is at 7am or ealier.

            } else if (trip.departureTime[0] < 12) {
                inputLunch(trip);      // Get lunch if departure is at 12pm or later.

            } else {
                inputDinner(trip);
            }
        }

        // 2nd day through the day before last.
        for (int count = 2; count < trip.totalTripDays; count++) {

            cout << "[Day " << count << "]" << endl;
            inputBreakfast(trip);
            inputLunch(trip);
            inputDinner(trip);
        }

        // Last day
        cout << "[Day " << trip.totalTripDays << "]" << endl;

        if (trip.returnTime[0] < 8) {
            cout << "No meals allowed due to return before 8am" << endl;

        } else {
            inputBreakfast( trip );

            if (trip.returnTime[0] >= 13) {
                inputLunch(trip);   // Get lunch if arrival is 1pm or later.
            }

            if (trip.returnTime[0] >= 19) {
                inputDinner(trip);  // Get dinner if arrival is 7pm or later.
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
 * @param data           A variable in which the data will be stored.
 * @param promtMsg       A prompt message.
 * @param errorMsg       An error message.
 * @param conditionFun   A pointer to a function that returns bool.
 */
template <typename dataType>
void promptUser(dataType& data, string promtMsg, string errorMsg,
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
 * @param data           An int array in which the data will be stored.
 * @param promtMsg       A prompt message.
 * @param errorMsg       An error message.
 * @param conditionFun   A pointer to a function that returns bool.
 */
void promptUserTime(int data[], string promtMsg, string errorMsg,
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
 * @param value
 * @return true if the value is zero or greater.
 */
template <typename dataType>
bool zeroOrGreater(dataType value) {
    return value >= 0;
}


/**
 * @param value
 * @return true if the value is one or greater.
 */
template <typename dataType>
bool oneOrGreater(dataType value) {
    return value >= 1;
}
