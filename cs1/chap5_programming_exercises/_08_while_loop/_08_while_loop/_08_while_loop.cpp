/**
 * APCT-233C-01
 * Chapter 5 - Programming Exercise 8
 * _08_while_loop.cpp
 *
 * Masatoshi Nishiguchi
 * 11/05/2015
 */

/* OUTPUT

A. Enter two integers: 1 9

B. All the odd numbers between the two numbers
1 3 5 7 9

C. All the even numbers between the two numbers
20

D. The numbers and their squares between 1 and 10
     1      1
     2      4
     3      9
     4     16
     5     25
     6     36
     7     49
     8     64
     9     81
    10    100


E. The sum of the square of the odd numbers between the two numbers
165

F. Enter a sentence: Masatoshi Nishiguchi the Ruby programmer UDC
M N R U D C
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    // Variable declaration
    int firstNum  = 0;
    int secondNum = 0;
    int idx       = 0;
    int sum       = 0;
    int len       = 0;
    bool finished = false;
    string input;

    // A. Prompt the user to input two integers

    cout << "\nA. Enter two integers: ";

    while (!finished) {
        cin >> firstNum >> secondNum;  // Read two numbers

        // Two numbers must be different values
        if (!cin || (firstNum == secondNum)) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Two numbers must be different values" << endl;
        } else {
            finished = true;
        }
    }

    // firstNum must be less than secondNum
    if (firstNum > secondNum) {
        int temp  = firstNum;
        firstNum  = secondNum;
        secondNum = temp;
    }

    cin.ignore(1024, '\n');
    cin.clear();

    // B. Output all the odd numbers between the two numbers

    cout << "\nB. All the odd numbers between the two numbers" << endl;
    idx = firstNum;
    while (idx <= secondNum) {
        if (idx % 2 == 1) {
            cout << idx << " ";
        }
        idx++;
    }
    cout << endl;

    // C. Output all the even numbers between the two numbers

    cout << "\nC. All the even numbers between the two numbers" << endl;
    idx = firstNum;
    sum = 0;
    while (idx <= secondNum) {
        if (idx % 2 == 0) {
            sum += idx;
        }
        idx++;
    }
    cout << sum << endl;

    // D. Output the numbers and their squares between 1 and 10

    cout << "\nD. The numbers and their squares between 1 and 10" << endl;
    idx = 1;
    while (idx <= 10) {
        cout << setw(6) << idx << " " << setw(6) << idx * idx << endl;
        idx++;
    }
    cout << endl;

    // E. Output the sum of the square of the odd numbers between firstNum and secondNum

    cout << "\nE. The sum of the square of the odd numbers between the two numbers" << endl;
    sum = 0;
    idx = firstNum;
    while (idx <= secondNum) {
        if (idx % 2 == 1) {  // Odd
            sum += idx * idx;
        }
        idx++;
    }
    cout << sum << endl;

    // F. Output all uppercase letters

    cout << "\nF. Enter a sentence: ";

    // Read a line
    getline(cin, input);

    // Iterate over the line and print all the uppercase letters
    len = (int)input.length();
    idx = 0;
    while (idx < len) {
        if (input[idx] >= 'A' && input[idx] <= 'Z') {  // Uppercase
            cout << input[idx] << " ";
        }
        idx += 1;
    }
    cout << endl;

    return 0;
}
