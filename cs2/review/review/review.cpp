//
//  review.cpp
//
//  Created by Masatoshi Nishiguchi on 1/20/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


// Q11
/**
 * Returns the sum of two numbers passed as arguments.
 */
double sum( double d1, double d2 ) {
    return d1 + d2;
}


int main() {

    // Q3
    // Output to the screen the result of the math problem 23 - 87 X 45.
    // Have the program calculate the result.
    cout << (23 - 87 * 45) << endl;

    cout << "-----" << endl;

    // Q4
    // Output (without quotes) "The square root of 87 is:xx", where xx is the
    // actual square root of 87. Have the program calculate the square root value.
    cout << "The square root of 87 is:" << sqrt( 87 ) << endl;

    cout << "-----" << endl;

    // Q5

    // Get a char from the user.
    char userChar;
    cout << "Enter a character: ";
    cin >> userChar;

    // If the value of the char is 'U', output, "It's You.",
    // if the value is 'I', output, "I did it.",
    // otherwise, output, "I don't know who did it."
    if ( userChar == 'U' ) {

        cout << "It's You." << endl;

    } else if ( userChar == 'I' ) {

        cout << "I did it." << endl;

    } else {

        cout << "I don't know who did it." << endl;

    }

    cout << "-----" << endl;

    // Q6
    // Output the following, showing the quotes as shown below:
    // MLK said, "the measure of a man is where he stands in times of adversity."
    cout << "MLK said, \"the measure of a man is where he stands in times of adversity.\"" << endl;

    cout << "-----" << endl;

    // Q7
    // Output the ASCII value of the plus sign (+). You must do this without consulting the ASCII table.
    cout << static_cast<int>( '+' ) << endl;

    cout << "-----" << endl;

    // Q8
    // Output the char value that corresponds to the ASCII value 93.
    cout << static_cast<char>( 93 ) << endl;

    cout << "-----" << endl;

    // Q10
    // Have the user input two doubles and display the sum and the product of those numbers.

    double d1, d2;
    cout << "Enter two decimal numbers: ";
    cin  >> d1 >> d2;
    cout << endl;

    cout << "Sum:     " << d1 + d2 << endl;
    cout << "Product: " << d1 * d2 << endl;

    cout << "-----" << endl;

    // Q11

    // Output the return value in the place from which it was called to ensure it works properly.
    cout << "The return value of sum( 2, 5 ): " << sum( 2, 5 ) << endl;
    cout << "The return value of sum( 1, 9 ): " << sum( 1, 9 ) << endl;

    cout << "-----" << endl;

    // Q13

    bool b = 5 == 6;

    cout << b << endl;

    cout << "-----" << endl;

    // Q14
    for (int i = 0; i < 4; i++) {
        cout << "Hello" << endl;
    }

    cout << "-----" << endl;

    // Q15
    int i = 0;
    while ( i < 4 ) {
        cout << "Hello" << endl;
        i++;
    }


    // Q16
    // Input an integer from a user.
    int userInt;
    cout << "Enter an integer: ";
    cin >> userInt;

    switch ( userInt ) {
        case 0:
            cout << "Nothing here" << endl;
            break;
        case 1:
            cout << "You have one" << endl;
            break;
        case 2:
        case 3:
        case 4:
            cout << "You have multiple things" << endl;
            break;
        case -1:
            cout << "You owe me." << endl;
            break;
        default:
            cout << "I'm not sure what you have." << endl;
    }
}
