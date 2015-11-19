//
//  time_add
//
//  Created by Masatoshi Nishiguchi on 11/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;


/*
ANALYSIS

If 3 days, 17 hours, and 49 minutes is added to 12 days, 22 hours, and 14 minutes:

    days    =  3 days    + 12 = 15
    hours   = 17 hours   + 22 = 39
    minutes = 49 minutes + 14 = 63

    Since minutes >= 60,

        a) carry the excessive amount of minutes over to hours, then
            hours   =  39 + (63 / 60) = 40

        b) remainder becomes the new value for the minutes
            minutes = 63 % 60 = 3

    Since hours >= 24,

        a) carry the excessive amount of hours over to days, then
            days  = 15 + (40 / 24) = 15 + 1 = 16

        b) remainder becomes the new value for the hours
            hours = 40 % 24 = 16

    The result is:
        days    = 16
        hours   = 16
        minutes = 3

OUTPUT

    Enter time...
      Days: 3
      Hours: 17
      Minutes: 49
    ----------------------------------------
    Enter time to be added...
      Days: 12
      Hours: 22
      Minutes: 14
    ----------------------------------------
    Before:    3:17:49
    After:    16:16: 3
    ----------------------------------------

 */


// #8
/**
 * @param days          the time to be modified
 * @param hours         the time to be modified
 * @param minutes       the time to be modified
 * @param daysToAdd     the amount of days to be added
 * @param hoursToAdd    the amount of hours to be added
 * @param minutesToAdd  the amount of minutes to be added
 */
void TimeAdd(int& days, int& hours, int& minutes,
             int daysToAdd, int hoursToAdd, int minutesToAdd) {

    // Add time
    days    += daysToAdd;
    hours   += hoursToAdd;
    minutes += minutesToAdd;

    // If minutes >= 60...
    if (minutes >= 60) {
        hours   += minutes / 60;
        minutes %= 60;
    }

    // If hours >= 24...
    if (hours >= 24) {
        days  += hours / 24;
        hours %= 24;
    }

}


// #9 - extended versiion of #8
/**
 * @param days          the time to be modified
 * @param hours         the time to be modified
 * @param minutes       the time to be modified
 * @param seconds       the time to be modified
 * @param daysToAdd     the amount of days to be added
 * @param hoursToAdd    the amount of hours to be added
 * @param minutesToAdd  the amount of minutes to be added
 * @param secondsToAdd  the amount of secondes to be added
 */
void TimeAdd(int& days, int& hours, int& minutes, int& seconds,
             int daysToAdd, int hoursToAdd, int minutesToAdd, int secondsToAdd) {

    // Add time
    days    += daysToAdd;
    hours   += hoursToAdd;
    minutes += minutesToAdd;
    seconds += secondsToAdd;

    // If seconds >= 60...
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }

    // If minutes >= 60...
    if (minutes >= 60) {
        hours   += minutes / 60;
        minutes %= 60;
    }

    // If hours >= 24...
    if (hours >= 24) {
        days  += hours / 24;
        hours %= 24;
    }

}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    int days, hours, minutes;
    int daysToAdd, hoursToAdd, minutesToAdd;

    cout << "----------------------------------------" << endl;

    // Prompt user for time.
    cout << "Enter time..." << endl;

    cout << "  Days: ";
    cin >> days;

    cout << "  Hours: ";
    cin >> hours;

    cout << "  Minutes: ";
    cin >> minutes;

    cout << "----------------------------------------" << endl;

    // Prompt user for time to be added
    cout << "Enter time to be added..." << endl;

    cout << "  Days: ";
    cin >> daysToAdd;

    cout << "  Hours: ";
    cin >> hoursToAdd;

    cout << "  Minutes: ";
    cin >> minutesToAdd;

    cout << "----------------------------------------" << endl;

    // Process the addition and output the result
    cout << "Before: " << setw(4) << days << ":"
                       << setw(2) << hours << ":"
                       << setw(2) << minutes << endl;

    TimeAdd(days, hours, minutes,
            daysToAdd, hoursToAdd, minutesToAdd);

    cout << "After:  " << setw(4) << days << ":"
                       << setw(2) << hours << ":"
                       << setw(2) << minutes << endl;

    cout << "----------------------------------------" << endl;

    return 0;
}

