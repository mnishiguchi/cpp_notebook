/**
 * _13_windchill_factor.cpp
 *
 * Created by Masatoshi Nishiguchi on 11/20/15.
 *
 * Prompts the user for the wind speed and the temperature and
 * outputs the windchill factor.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
ANALYSIS

National weather service (http://www.nws.noaa.gov/om/winter/windchill.shtml)

The formula to compute the windchill factor, W:
W = 35.74 + (0.6215 * T) - (35.75 * V^0.16) + (0.4275 * T * V^0.16)

where V: wind speed in miles per hour
      T: air temperature in degrees Fahrenheit

If V = 10, T = 40,
W = 35.74 + (0.6215 * 40) - (35.75 * 10^0.16) + (0.4275 * 40 * 10^0.16)
  = 35.74 + 24.86 - 51.6744718 + 24.71702
  = 33.6425482

==

OUTPUT

Enter the wind speed in mph: 10
Enter the temperature in F: 40
--------------------------------------
The windchill factor: 33.64

 */


// Function prototypes.
double promptWindSpeed();
double promptTemperature();
double calcWindchillFactor(double windSpeed, double temperature);


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Main funcion of this program.
 */
int main() {

    // Prompt the user for wind speed and temperature and
    // compute the windchill factor.
    double factor = calcWindchillFactor( promptWindSpeed(), promptTemperature() );

    cout << "--------------------------------------" << endl;

    // Output the windchill factor.
    cout << fixed << showpoint << setprecision(2);
    cout << "The windchill factor: " << factor << endl;

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //

/**
 * Prompts the user for the wind speed.
 * @return The wind speed that the user inputted.
 */
double promptWindSpeed() {

    double windSpeed;
    cout << "Enter the wind speed in mph: ";
    cin >> windSpeed;

    return windSpeed;
}


/**
 * Prompts the user for the temperature.
 * @return The temperature that the user inputted.
 */
double promptTemperature() {

    double temperature;
    cout << "Enter the temperature in F: ";
    cin >> temperature;

    return temperature;
}


/**
 * Computes the windchill factor.
 * W = 35.74 + (0.6215 * T) - (35.75 * V^0.16) + (0.4275 * T * V^0.16)
 * @param v The wind speed
 * @param t The temperature
 * @return The windchill factor for the specified wind speed and temperature.
 */
double calcWindchillFactor(double v, double t) {

    return 35.740
            + ( 0.6215 * t )
            - ( 35.750 * pow(v, 0.16) )
            + ( 0.4275 * t * pow(v, 0.16) );
}
