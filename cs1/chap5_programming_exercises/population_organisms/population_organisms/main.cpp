/*
 population_organisms

 Predicts the size of a population of organisms.
 Asks the user for:
    - the starting number of organisms,
    - their average daily population increase (as a percentage), and
    - the number of days they will multiply.

 Displays the size of the population for each day.

 Input Validation:
    - Do not accept a number less than 2 for the starting size of the population.
    - Do not accept a negative number for average daily population increase.
    - Do not accept a number less than 1 for the number of days they will multiply

 Created by Masatoshi Nishiguchi on 10/29/15.
 Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
 */

/*
 ANALYSIS

 If the input is the starting population is 200, the dayly groth rate is 50% and
 the organisms multiply for 3 days,

     Day 1 - 200 * 1.5 = 300
     Day 2 - 300 * 1.5 = 450
     Day 3 - 450 * 1.5 = 675

 OUTPUT

    >>>Enter the starting number of organisms:
    200
    >>>Enter the average daily population increase (in %):
    50
    >>>Enter the the number of days they will multiply:
    3
    The starting population: 200
    After 1 day(s): 300
    After 2 day(s): 450
    After 3 day(s): 675
    The population of the organisms after 3 days is 675
 */

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Represents a Organism.
 */
class Organism {
public:
    int population;
    double dailyGrowthRate;

    /**
     * Update the population computing the growth for the specified days.
     * Displays the size of the population for each day.
     */
    void growForDays(int days) {
        cout << "The starting population: " << population << endl;
        for (int i = 0; i < days; i++) {
            population = static_cast<int>( population * (1 + dailyGrowthRate / 100.0) );
            cout << "After " << setw(3) << i + 1 << " day(s): "
                 << setw(6) << population << endl;
        }
        cout << "The population of the organisms after "
             << setw(3) << days << " days is " << setw(6) << population << endl;
    }
};

/**
 * The main function of this program.
 */
int main() {

    Organism organism;
    int numDaysMultiply;

    // Prompt for the starting number of organisms.
    // Do not accept a number less than 2 for the starting size of the population.
    bool finished = false;
    while (!finished) {
        cout << ">>>Enter the starting number of organisms: " << endl;
        cin >> organism.population;  // Read the input

        // If cin is in a bad state or inputted data is invalid, retry.
        if (!cin || organism.population < 2) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << ">>>Invalid input: The starting size of the population "
                 << "must be less than 2" << endl;
        } else {
            finished = true;
        }
    }

    // Prompt for their average daily population increase (as a percentage).
    // Do not accept a negative number for average daily population increase.
    finished = false;
    while (!finished) {
        cout << ">>>Enter the average daily population increase (in %): " << endl;
        cin >> organism.dailyGrowthRate;  // Read the input

        // If cin is in a bad state or inputted data is invalid, retry.
        if (!cin || organism.dailyGrowthRate < 0) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << ">>>Invalid input: The average daily population increase "
                 << "must be greater than or equal to 0" << endl;
        } else {
            finished = true;
        }
    }

    // Prompt for the number of days they will multiply.
    // Do not accept a number less than 1 for the number of days they will multiply.
    finished = false;
    while (!finished) {
        cout << ">>>Enter the the number of days they will multiply: " << endl;
        cin >> numDaysMultiply;  // Read the input

        // If cin is in a bad state or inputted data is invalid, retry
        if (!cin || numDaysMultiply < 1) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << ">>>Invalid input: The number of days "
                 << "must be greater than or equal to 1" << endl;
        } else {
            finished = true;
        }
    }

    // Compute and output the result.
    organism.growForDays(numDaysMultiply);

    return 0;
}
