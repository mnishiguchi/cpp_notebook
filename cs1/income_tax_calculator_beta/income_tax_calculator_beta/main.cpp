//
//  main.cpp
//  income_tax_calculator_beta
//
//  Created by Masatoshi Nishiguchi on 10/13/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    // Prompt the user to enter filing status
    cout << "0: single filer," << endl
    << "1: married jointly or qualifying widow(er)," << endl
    << "2: married separately," << endl
    << "3: head of household" << endl << endl;
    cout << "Enter your filing status: " << endl;

    int status;
    cin >> status;

    // Prompt the user to enter taxable income
    cout << "Enter the taxable income: ";
    double income;
    cin >> income;

    // Compute tax
    double tax = 0;

    // Compute tax for single filers
    if (status == 0) {
        if (income <= 8025) {
            tax = income * 0.10;

        } else if (income <= 32550) {
            tax = 8025 * 0.10 +
            (income - 8025) * 0.15;

        } else if (income <= 78850) {
            tax = 8025 * 0.10 +
            (32550 - 8025) * 0.15 +
            (income - 32550) * 0.25;

        } else if (income <= 164550) {
            tax = 8025 * 0.10 +
            (32550 - 8025) * 0.15 +
            (78850 - 32550) * 0.25 +
            (income - 78850) * 0.28;

        } else if (income <= 357700) {
            tax = 8025 * 0.10 +
            (32550 - 8025) * 0.15 +
            (78850 - 32550) * 0.25 +
            (164550 - 78850) * 0.28 +
            (income - 164550) * 0.33;

        } else {
            tax = 8025 * 0.10 +
            (32550 - 8025) * 0.15 +
            (78850 - 32550) * 0.25 +
            (164550 - 78850) * 0.28 +
            (357700 - 164550) * 0.33 +
            (income - 357700) * 0.35;
        }
    }
    // Compute tax for married file jointly
    else if (status == 1) {
        // TODO: Left as exercise
    }
    // Compute tax for married separately
    else if (status == 2) {
        // TODO: Left as exercise
    }
    // Compute tax for head of household
    else if (status == 3) {
        // TODO: Left as exercise
    }
    else {
        cout << "Error: invalid status";
        return 0;
    }

    // Display the result
    cout << "Tax is " << static_cast<int>(tax * 100) / 100.0 << endl;

    return 0;
}

/* ACTUAL OUTPUT

Enter your filing status
(0-single filer, 1-married jointly, or qualifying widow(er),
2-married separately, 3-head of household)
0
Enter the taxable income: 42400
Tax is 6943.75
*/
