//
//  main.cpp
//  20151001
//
//  Created by Masatoshi Nishiguchi on 10/1/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));  // "Seeds" the random number generator

    const int N = 20;
    double num1;
    double num2;

    // rand(1000000);

    for (int i = 0; i < N; i++) {

        num1 = num2 = rand() % 10000000000;

        cout << "num1: " << num1 << endl;
        cout << "num2: " << num2 << endl;

        if ( num1 == num2 ) {
            cout << "EQUAL" << endl;
        } else {
            cout << "NOT EQUAL" << endl;
        }

        if ( fabs ( num1 - num2 ) < 0.00001 ) {
            cout << "They are close enough!" << endl;
        }
    }

    return 0;
}
