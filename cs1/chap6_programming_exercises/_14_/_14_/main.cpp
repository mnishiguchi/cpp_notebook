/**
 * _14_
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

 OUTPUT


TEST a) void initialize(int& x, int& y, char& z);

  x: 0
  y: 0
  z:

---------------------------------------------------------


TEST b) void getHoursRate(double& hoursWorked, double& ratePerHour);


Enter the hours worked: 50

Enter the rate per hour: 20
  hoursWorked: 50
  ratePerHour: 20

---------------------------------------------------------


TEST c) double payCheck(double hoursWorked, double ratePerHour);

  Salary: 1100

---------------------------------------------------------


TEST d) void printCheck(double hoursWorked, double ratePerHour, double payCheck);

The hours worked   :    50.00
The rate per hour  :    20.00
The paycheck       :  1100.00


---------------------------------------------------------


TEST e) void funcOne(int& x, int y);

Set x: 40
Set y: 60

Before calling funcOne(int& x, int y)
  x: 40
  y: 60

Enter your number: 88
x * 2 + y - your number = 40 * 2 + 60 - 88 = 52

After calling funcOne(int& x, int y)
  x: 52
  y: 60

---------------------------------------------------------


TEST f) void nextChar(char& ch);

Enter a character: G
  z: G
Changing the character to the next one...
  z: H

 */

// Function prototypes
void initialize(int&, int&, char&);
void getHoursRate(double&, double&);
double payCheck(double, double);
void printCheck(double, double, double);
void funcOne(int&, int);
void nextChar(char&);

void drawLine() {
    cout << "\n---------------------------------------------------------\n" << endl;
}

// g)

/**
 * Main funcion of this program.
 */
int main() {

    int x, y;
    char z;
    double hoursWorked, ratePerHour;
    double salary;

    cout << "\nTEST a) void initialize(int& x, int& y, char& z);\n" << endl;

    initialize(x, y, z);
    cout << "  x: " << x << endl;
    cout << "  y: " << y << endl;
    cout << "  z: " << z << endl;

    drawLine();
    cout << "\nTEST b) void getHoursRate(double&, double&);\n" << endl;

    getHoursRate(hoursWorked, ratePerHour);
    cout << "  hoursWorked: " << hoursWorked << endl;
    cout << "  ratePerHour: " << ratePerHour << endl;

    drawLine();
    cout << "\nTEST c) double payCheck(double, double);\n" << endl;

    salary = payCheck(hoursWorked, ratePerHour);
    cout << "  Salary: " << salary << endl;

    drawLine();
    cout << "\nTEST d) void printCheck(double, double, double);\n" << endl;

    printCheck(hoursWorked, ratePerHour, salary);

    drawLine();
    cout << "\nTEST e) void funcOne(int&, int);\n" << endl;

    cout << "Set x: ";
    cin >> x;
    cout << "Set y: ";
    cin >> y;

    cout << "\nBefore calling funcOne(int&, int)" << endl;
    cout << "  x: " << x << endl;
    cout << "  y: " << y << endl;

    funcOne(x, y);

    cout << "\nAfter calling funcOne(int&, int)" << endl;
    cout << "  x: " << x << endl;
    cout << "  y: " << y << endl;

    drawLine();
    cout << "\nTEST f) void nextChar(char&);\n" << endl;

    cout << "Enter a character: ";
    cin >> z;
    cout << "  z: " << z << endl;
    cout << "Changing the character to the next one..." << endl;
    nextChar(z);
    cout << "  z: " << z << endl;

    return 0;
}


// a)

/**
 * @param x  An integer to be initialized
 * @param y  An integer to be initialized
 * @param z  A character to be initialized
 */
void initialize(int& x, int& y, char& z) {

    x = 0;
    y = 0;
    z = ' ';
}

// b)

/**
 * Prompts the user for hours worked and rate per hour and
 * stores those in the variables that are passed in as arguments.
 * @param hoursWorked  A variable in which we place user's inputted value.
 * @param ratePerHour  A variable in which we place user's inputted value.
 */
void getHoursRate(double& hoursWorked, double& ratePerHour) {

    cout << "\nEnter the hours worked: ";
    cin >> hoursWorked;

    cout << "\nEnter the rate per hour: ";
    cin >> ratePerHour;
}

// c)

/**
 * Computes paycheck based on the specified hours worked and hourly rate.
 * For the first 40 hours rate is the given rate,
 * for hours over 40, the rate is 1.5 times the given rate.
 * @param hoursWorked
 * @param ratePerHour
 * @return The amount of the paycheck
 */
double payCheck(double hoursWorked, double ratePerHour) {

    double amount = 0.0;
    double hoursOvertime;

    if (hoursWorked > 0 && hoursWorked <= 40) {
        amount += hoursWorked * ratePerHour;

    } else {
        // Determine the amount of overtime hours.
        hoursOvertime = hoursWorked - 40;

        // The first 40 hours => given rate
        amount += 40 * ratePerHour;

        // The hours over 40 hours => 1.5x
        amount += hoursOvertime * (ratePerHour * 1.5);
    }

    return amount;
}

// d)

/**
 * Prints the hours worked, rate per hour and the salary.
 * @param hoursWorked
 * @param ratePerHour
 * @param payCheck
 */
void printCheck(double hoursWorked, double ratePerHour, double payCheck) {

    cout << fixed << showpoint << setprecision(2);
    cout << "The hours worked   : " << setw(8) << hoursWorked << endl;
    cout << "The rate per hour  : " << setw(8) << ratePerHour << endl;
    cout << "The paycheck       : " << setw(8) << payCheck << endl;
    cout << endl;
}

// e)

/**
 * Prompts the user to input a number.
 * Changes the value of x by assigning the value of the expression 2 times the
 * old value of x plus the value of y minus the value entered by the user.
 * @param x The reference to the integer x that is to be modified
 * @param y A copy of the integer y.
 */
void funcOne(int& x, int y) {
    int user_num;
    cout << "\nEnter your number: ";
    cin >> user_num;

    cout << "x * 2 + y - your number = ";
    cout << x << " * 2 + " << y << " - " << user_num << " = ";

    x *= 2;         // 2 times the old value of x
    x += y;         // plus the value of y
    x -= user_num;  // minus the value entered by the user

    cout << x << endl;
}

// f)

/**
 * Sets the value of the specified character to the next one.
 */
void nextChar(char& ch) {
    ch += 1;
}
