/*
    math_tutor_1.cpp

    Displays two ramdom numbers to be added, such as:
      247
    + 129
    Pauses while the student works on the problem.
    When the student is ready to check the answer.
    The student can press a key and the problem will display the correnct solution.
      247
    + 129
    -----
      376

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
         << "+ " << setw(3) << nums[1];

    // Pause until enter is pressed
    char ch = 0;
    while(!ch) {
        cin.get(ch);
    }

    // Draw the line
    cout << setfill('-');
    cout << setw(5) << "" << endl;

    // Show the answer
    cout << setfill(' ');
    cout << setw(5) << nums[0] + nums[1] << endl;

    return 0;
}
