//
//  atm_withdrawal.cpp
//  pp25-26, #22
//
//  Created by Masatoshi Nishiguchi on 9/4/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    const double MAX_WITHDRAWAL_PER_DAY = 500.0;
    double customerAccount = 0.0;
    double withdrawal      = 0.0;
    double serviceCharge   = 0.0;
    
    // set initial amount
    cout << "Set the current amount in your accont: ";
    cin >> customerAccount;
    cout << endl;
    
    // Welcome message and show current amount
    cout << "Welcome to Masa's Bank" << endl;
    cout << "You have $" << customerAccount << " in your account." << endl;
    cout << endl;
    
    // Return if there is no money in the customer's account
    if (customerAccount <= 0) {
        cout << "You have no money in your account." << endl;
        cout << "Good-bye." << endl;
        return 0;
    }
    
    // User inputs the amount of withdrawal
    cout << "How much do you want to withdraw? (example: 30.00): ";
    cin >> withdrawal;
    cout << endl;
    
    // Check if customer has enough money for this withdrawal
    if (customerAccount < withdrawal) {
        cout << "You don't have enough money in your account." << endl;
        cout << "If you really want money, you can proceed by paying a service fee of $25.00." << endl;
        cout << "Do you want to pay $25.00 and proceed? (Y/N): ";
        char userChar = '?';
        cin >> userChar;
        
        switch (userChar) {
            case 'Y':
            case 'y':
                serviceCharge += 25.0;
                cout << "Thank you." << endl;
                break;
            default:
                cout << "Good-bye!!!" << endl;
                return 0;
        }
    }
    
    // Service charge of 4% when withdrawal is greater than 300.
    if (withdrawal > 300.0) {
        cout << "There will be service charge of 4% of the amount over $300." << endl;
        cout << "Do you want to proceed? (Y/N): ";
        char userChar = '?';
        cin >> userChar;
        
        switch (userChar) {
            case 'Y':
            case 'y':
                serviceCharge += (withdrawal - 300.0) * 0.04;
                cout << "Thank you." << endl;
                break;
            default:
                cout << "Good-bye!!!" << endl;
                return 0;
        }
    }
    
    // Enforce MAX_WITHDRAWAL_PER_DAY.
    if (withdrawal >= MAX_WITHDRAWAL_PER_DAY) {
        withdrawal = MAX_WITHDRAWAL_PER_DAY;
    }
    
    // Process the withdrawal
    customerAccount = customerAccount - withdrawal - serviceCharge;
    
    // check total amount in account, withdrawal, debit, service charges
    cout << "You withdrew:                   $" << withdrawal << endl;
    cout << "Service charges:                $" << serviceCharge << endl;
    cout << "--------------------------------------" << endl;
    cout << "Updated amount in your account: $" << customerAccount << endl;
    cout << endl;
    cout << "Thank you for using Masa bank. See you later!" << endl;
    
    return 0;
}
