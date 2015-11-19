//
//  month_abbreviation.cpp
//
//  Created by Masatoshi Nishiguchi on 11/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/*
OUTPUT

    Month : 5
    ----------------------------------------
    abbreviation: May

    Month : 13
    ----------------------------------------
    abbreviation: Inv
 */


// #11 & #12
/**
 * @param represents the month (1..12)
 * @return the three-letter abbreviation for the corresponding month number
 */
string MonthAbbrev(int month) {

    string abbreviation;

    // Determine the abbreviation.
    switch(month) {
        case 1:
            abbreviation = "Jan";
            break;
        case 2:
            abbreviation = "Feb";
            break;
        case 3:
            abbreviation = "Mar";
            break;
        case 4:
            abbreviation = "Apr";
            break;
        case 5:
            abbreviation = "May";
            break;
        case 6:
            abbreviation = "Jun";
            break;
        case 7:
            abbreviation = "Jul";
            break;
        case 8:
            abbreviation = "Aug";
            break;
        case 9:
            abbreviation = "sep";
            break;
        case 10:
            abbreviation = "Oct";
            break;
        case 11:
            abbreviation = "Nov";
            break;
        case 12:
            abbreviation = "Dec";
            break;
        default:
            abbreviation = "Inv";
    }

    return abbreviation;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    int month;

    // Prompt user for month.
    cout << "Month : ";
    cin >> month;

    cout << "----------------------------------------" << endl;

    // Print the abbreviation
    cout << "abbreviation: " << MonthAbbrev(month) << endl;

    return 0;
}
