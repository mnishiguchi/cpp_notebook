/*
 math_tutor_2.cpp

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

int main() {
    srand((int)time(0));     // Seeds the random number generator

    int nums[2];

    // Generate two random numbers
    nums[0] = (rand() % 1000);
    nums[1] = (rand() % 1000);

    // Prints an addition problem
    cout << "  " << setw(3) << nums[0] << endl
         << "+ " << setw(3) << nums[1] << endl;

    // Pause until user enter the value
    int userVal = 0;
    while(!cin || !userVal) {
        cout << "Enter your answer: ";
        cin >> userVal;
    }

    // Compute the correct answer
    int answer = nums[0] + nums[1];

    // Evaluate the user's input
    if (answer == userVal) {
        cout << "Correct. Congratulations!!!" << endl;
    } else {
        cout << "Incorrect." << endl;
        cout << "The answer is "
             << nums[0] << " + " << nums[1] << " = " << answer << endl;
    }

    return 0;
}
