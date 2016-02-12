//
//  main.cpp
//  cmath_experiments
//
//  Created by Masatoshi Nishiguchi on 2/12/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double d_1, d_2;

    cout << "Give me two numbers: ";

    cin >> d_1 >> d_2;

    cout << d_1 << " ^ " << d_2 << " = " << pow( d_1, d_2 ) << endl;
    cout << "square root of " << d_1 << " = " << sqrt( d_1 ) << endl;
    cout << "square root of " << d_2 << " = " << sqrt( d_2 ) << endl;

    cout << endl;

    return 0;

}

/* OUTPUT

Give me two numbers: 2 3
2 ^ 3 = 8
square root of 2 = 1.41421
square root of 3 = 1.73205

Program ended with exit code: 0
 */
