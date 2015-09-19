//
//  main.cpp
//  _18_exciting_summer_job
//
//  Prompts the user to enter the pay rate for an hour and the number of hours you worked each week.
//  Outputs the following:
//    a. Your income before and after taxes from your summer job.
//    b. The money you spend on clothes and other accessories.
//    c. The money you spend on school supplies.
//    d. The money you spend to buy savings bonds.
//    e. The money your parents spend to buy additional savings bonds for you.
//
//  Created by Masatoshi Nishiguchi on 9/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/*
 After paying the taxes, you spend:
   10% of your net income to buy new clothes and other accessories for the next school year and
   1% to buy school supplies.
 
 After buying clothes and school supplies, you use
   25% of the remaining money to buy savings bonds.
 
 For each dollar you spend to buy savings bonds, your parents spend
   $0.50 to buy additional savings bonds for you.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Constants
    const double RATE_TAX                 = 0.14;
    const double RATE_CLOTHES_ACCESSORIES = 0.10;
    const double RATE_SCHOOL_SUPPLIES     = 0.01;
    const double RATE_SAVINGS             = 0.25;
    const double RATE_PARENT_SAVINGS      = 0.50;
    
    // Variables
    double wage;
    double incomeBeforeTax;
    double incomeAfterTax;
    double tax;
    double hoursWorked;
    double moneyClothesAndAccessories;
    double moneySchoolSupplies;
    double moneySavings;
    double moneyParentSavings;
    double remainder;
    
    // Prompts the user to enter the pay rate for an hour and the number of hours worked
    cout << "Enter the pay rate for an hour:       ";
    cin >> wage;
    cout << "Enter the number of hours you worked: ";
    cin >> hoursWorked;
    cout << endl;
    
    // Process income and tax
    incomeBeforeTax = wage * hoursWorked;
    tax             = incomeBeforeTax * RATE_TAX;
    incomeAfterTax  = incomeBeforeTax + tax;
    
    remainder       = incomeAfterTax;
    
    // Process spendings
    moneyClothesAndAccessories = incomeAfterTax * RATE_CLOTHES_ACCESSORIES;
    remainder -= moneyClothesAndAccessories;
    
    moneySchoolSupplies = incomeAfterTax * RATE_SCHOOL_SUPPLIES;
    remainder -= moneySchoolSupplies;
    
    // Process the remaining money
    moneySavings = remainder * RATE_SAVINGS;
    remainder -= moneySavings;
    
    // Process the parents additional savings
    moneyParentSavings = moneySavings * RATE_PARENT_SAVINGS;
    
    // Output settings
    cout << fixed << setprecision(2) << right;
    
    // a. Your income before and after taxes from your summer job.
    cout << "incomeBeforeTax:             " << setw(8) << incomeBeforeTax << endl;
    cout << "incomeAfterTax:              " << setw(8) << incomeAfterTax << endl;
    
    // b. The money you spend on clothes and other accessories.
    cout << "moneyClothesAndAccessories:  " << setw(8) << moneyClothesAndAccessories << endl;
    
    // c. The money you spend on school supplies.
    cout << "moneySchoolSupplies:         " << setw(8) << moneySchoolSupplies << endl;

    // d. The money you spend to buy savings bonds.
    cout << "moneySavings:                " << setw(8) << moneySavings << endl;

    // e. The money your parents spend to buy additional savings bonds for you.
    cout << "moneyParentSavings:          " << setw(8) << moneyParentSavings << endl;

    return 0;
}

