//
//  season_print.cpp
//
//  Created by Masatoshi Nishiguchi on 11/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/*
For the purposes of this exercise,
    - spring - begins on March(3) 21
    - summer - begins on June(6) 21
    - fall   - begins on September(9) 21
    - winter - begins on December(12) 21

OUTPUT

    Month : 12
    Day   : 20
    ----------------------------------------
    Season: Fall
 */


// #10
/**
 * cout the name of the season
 * @param month
 * @param day
 */
void SeasonPrint(int month, int day) {

    string season;

    // Day 21 is the starting point.
    // If the day is before 21, consider the month as previous month.
    month = (day >= 21) ? month : month - 1;
    month = (month == 0) ? 12 : month;

    // Determine the season.
    switch(month) {
        case 12:
        case 1:
        case 2:
            season = "winter";
            break;
        case 3:
        case 4:
        case 5:
            season = "Spring";
            break;
        case 6:
        case 7:
        case 8:
            season = "Summer";
            break;
        case 9:
        case 10:
        case 11:
            season = "Fall";
            break;
        default:
            season = "Error determining the season";
    }

    // Print the season
    cout << "Season: " << season << endl;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    int month, day;

    // Prompt user for month and day.
    cout << "Month : ";
    cin >> month;

    cout << "Day   : ";
    cin >> day;

    cout << "----------------------------------------" << endl;

    SeasonPrint(month, day);

    return 0;
}

