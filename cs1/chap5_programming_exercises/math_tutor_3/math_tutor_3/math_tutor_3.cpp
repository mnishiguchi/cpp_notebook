/*
 math_tutor_3.cpp

 Dispalys a menu allowing the user to select an adition, subtraction,
 multiplication or division problem. Also selection to quit.

 Displays two ramdom numbers to be added, such as:
   247
 + 129
 Pauses while the student works on the problem.
 When the student is ready to check the answer.
 The student can press a key and the problem will display the correnct solution.

 If the answer is correct, prints a message of congratulations.
 If the answer is incorrect, prints the correct answer.

 Created by Masatoshi Nishiguchi on 11/3/15.
 Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
 */

#include <iostream>
#include <cstdlib>     // Enables use of rand()
#include <ctime>       // Enables use of time()
#include <iomanip>
using namespace std;

int printAndComputeAdditionProblem(int i1, int i2) {
    cout << "  " << setw(3) << i1 << endl
         << "+ " << setw(3) << i2 << endl;
    return i1 + i2;
}

int printAndComputeSubtractionProblem(int i1, int i2) {
    cout << "  " << setw(3) << i1 << endl
         << "- " << setw(3) << i2 << endl;
    return i1 - i2;
}

int printAndComputeMultiplicationProblem(int i1, int i2) {
    cout << "  " << setw(3) << i1 << endl
         << "x " << setw(3) << i2 << endl;
    return i1 * i2;
}

int printAndComputeDivisionProblem(int i1, int i2) {
    cout << "  " << setw(3) << i1 << endl
         << "/ " << setw(3) << i2 << endl;
    return i1 / i2;
}

int main() {
    srand((int)time(0));     // Seeds the random number generator

    int nums[2];
    int code = -1;
    bool isFinished;

    while (true) {
        isFinished = false;
        
        do {
            // Explanation
            cout << "1: adition problem" << endl;
            cout << "2: subtraction problem" << endl;
            cout << "3: multiplication problem" << endl;
            cout << "4: division problem" << endl;
            cout << "5: quit" << endl;
            cout << "\nEnter a code (1-5): ";

            // Read the user's inputted code
            cin >> code;
            cout << endl;

            // Validate user input (5: quit)
            if (code == 5) {
                cout << "Good bye!" << endl;
                return 0;
            }

            // Validate user input (1-4: Calculation problems)
            if (!cin || (code < 1 || code > 4)) {
                cout << "Invalid input: Must be 1 to 5" << endl;
            } else {
                isFinished = true;
            }
        } while (!isFinished);

        // Generate two random numbers
        nums[0] = (rand() % 1000);
        nums[1] = (rand() % 1000);

        int answer = -1;
        char sign = '?';
        // Evaluate the menu selection and compute the correct answer
        switch (code) {
            case 1:
                sign   = '+';
                answer = printAndComputeAdditionProblem(nums[0], nums[1]);
                break;
            case 2:
                sign   = '-';
                answer = printAndComputeSubtractionProblem(nums[0], nums[1]);
                break;
            case 3:
                sign   = 'x';
                answer = printAndComputeMultiplicationProblem(nums[0], nums[1]);
                break;
            case 4:
                sign   = '/';
                answer = printAndComputeDivisionProblem(nums[0], nums[1]);
                break;
            default:
                cout << "Good bye!" << endl;
                return 0;
        }

        // Pause until user enter the value
        int userVal = 0;
        while(!cin || !userVal) {
            cout << "Enter your answer: ";
            cin >> userVal;
        }

        // Evaluate the user's input
        if (answer == userVal) {
            cout << "Correct. Congratulations!!!" << endl;
        } else {
            cout << "Incorrect." << endl;
            cout << "The answer is "
            << nums[0] << " " << sign << " " << nums[1] << " = " << answer << endl;
        }

        // Insert a new line
        cout << endl;
        cout << setfill('~') << setw(48) << "" << setfill(' ') << endl;
    }

    return 0;
}
