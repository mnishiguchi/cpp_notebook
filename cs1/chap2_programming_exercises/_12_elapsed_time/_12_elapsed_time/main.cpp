//
//  main.cpp
//  _12_elapsed_time
//
// Prompts the user to input the elapsed time for an event in seconds.
// The program then outputs the elapsed time in hours, minutes, and seconds.
// (For example, if the elapsed time is 9630 seconds, then the output is 2:40:30.)
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    const int MINUTE_IN_SECONDS = 60;
    const int HOUR_IN_SECONDS   = 60 * MINUTE_IN_SECONDS;
    
    int elapsedSeconds = 0;
    int hours     = 0;
    int minutes   = 0;
    int remainder = 0;
    
    // Prompt the user to input the elapsed time for an event in seconds.
    cout << "Please enter the elapsed time in seconds: ";
    cin >> elapsedSeconds;
    
    cin.clear();
    cin.ignore(100, '\n');
    
    cout << endl;
    
    // Calculate hours, minutes and seconds
    hours     = elapsedSeconds / HOUR_IN_SECONDS;
    remainder = elapsedSeconds % HOUR_IN_SECONDS;
    minutes   = remainder / MINUTE_IN_SECONDS;
    remainder = remainder % MINUTE_IN_SECONDS;

    // Output the elapsed time in hours, minutes, and seconds.
    cout << hours << ":" << minutes << ":" << remainder << endl;
    
    return 0;
}
