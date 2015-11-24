# Propmpt user

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

```

## Usage

```cpp
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
```
