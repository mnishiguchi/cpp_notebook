//
//  square_km.cpp
//
//  Created by Masatoshi Nishiguchi on 11/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/*

 outputs a return value that is in square kilometers.
 The parameters are the length and width of an area in miles.
 The conversion factor for kilometers from miles is 1.6.
 */

// #15

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Function prototypes
float Miles2Km(float miles);
float SquareKm(float lengthInMiles, float widthInMiles);


/**
 * @param lengthInMiles
 * @param widthInMiles
 * @return The area in square kilometers
 */
float SquareKm(float lengthInMiles, float widthInMiles) {

    return Miles2Km(lengthInMiles) * Miles2Km(widthInMiles);
}


/**
 * @param   A distance in miles
 * @return  The distance that is converted into kilometers
 */
float Miles2Km(float miles) {

    const float KM_PER_MILE = 1.6;

    return miles * KM_PER_MILE;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    float length, width;

    // Prompt user for length and width in miles.
    cout << "Length in miles : ";
    cin >> length;

    cout << "Width in miles  : ";
    cin >> width;

    cout << "----------------------------------------" << endl;

    cout << "The area in kilometer: ";
    cout << SquareKm(length, width);

    return 0;
}
