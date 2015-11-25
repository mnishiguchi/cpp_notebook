# BusinessTripCalculator

## struct BusinessTrip
- BusinessTrip is just another data type. You can use it just like int, double, string, etc.
```cpp
// A central place to hold data.
BusinessTrip trip;
```

### Static constants
- I believe that constants are best pre-defined as static constants. We can come up with their names, spell them in all capital letters and initialize them with values.
- We can access static constants within the BusinessTrip data type, just add the prefix `BusinessTrip::` to the field name that we want to read value from.

```cpp
// This is defined at the beginning of the program.
const double BusinessTrip::PRIVATE_CAR_MILAGE_ALLOWANCE =  0.27;
const double BusinessTrip::MAX_DAILY_PARKING_FEE        =  6.00;
const double BusinessTrip::MAX_DAILY_TAXI_FEE           = 10.00;
const double BusinessTrip::MAX_HOTEL_RATE_PER_NIGHT     = 90.00;
const double BusinessTrip::MAX_DAILY_BREAKFAST          =  9.00;
const double BusinessTrip::MAX_DAILY_LUNCH              = 12.00;
const double BusinessTrip::MAX_DAILY_DINNER             = 16.00;

//...

// We can read the value from a constant like this from anywhere in this program.
expenses = milesDriven * BusinessTrip::PRIVATE_CAR_MILAGE_ALLOWANCE;

```

### Member variables
- The set of variables that a BusinessTrip variable holds. Nothing fancy, just a group of variables.
- We can access them by a dot + variable name after the instance of BusinessTrip.

```cpp
// We can read and write data by accessing variables like this.
trip.airfair += expenses;
```

### The main function
- For example, we can write the main like this.
1. Create a variable to store all the trip-related data (of BusinessTrip type).
2. Pass the BusinessTrip variable to each function **by reference**. (NOTE: & required in the parameter list)
3. Inside of each function, we prompt the user for required data, process it and write information into appropriate variables of the BusinessTrip.
4. Print all the information.
```cpp
int main() {

    // 1.
    BusinessTrip trip;

    // 2. and 3.
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

    // 4.
    output(trip);

    return 0;
}
```

### The promptUser(...) utility function
- I wrote a few utility function for this program. Among others, I think this is the most useful.
- This is a reusable function to ask the user for data of the specified data type, with the specified messages and the specified validation function.
- Using this, we do not type the same old prompt code again and again.
```cpp
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
```

**Usage**
```cpp
/**
 * Asks for the number of days spent on the trip.
 * @param &trip  A BusinessTrip object to which we write data.
 */
void inputDaysSpent(BusinessTrip& trip) {

    promptUser<int>(
        trip.totalTripDays,         // a variable to which we write data
        "How many days did you spent on this trip? ",  // Prompt message
        "Invalid trip days : Must be 1 or more",       // Error message
        oneOrGreater<int>);                            // Validation function
}
```
