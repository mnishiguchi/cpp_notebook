//
//  calculate_cost_of_each_class.cpp
//  pp25-26, #24
//
//  Created by Masatoshi Nishiguchi on 9/4/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

double calcCostEachClass();

int main(int argc, const char * argv[]) {
    cout << calcCostEachClass() << endl;
    
    return 0;
}

double calcCostEachClass() {
    // General data
    const double TUITION_PER_SEMESTER = 25000;
    const double AVERAGE_TOTAL_UNITS  = 15;

    // Data about the course
    int courseUnits      = 4;
    double hoursPerClass = 1.0;
    int daysPerWeek      = 3;
    int weeksPerSemester = 15;
    
    // Average cost per unit
    double costPerUnit = TUITION_PER_SEMESTER / AVERAGE_TOTAL_UNITS;
    
    // Total cost of the course for a semester
    double courseCost = costPerUnit * courseUnits;
    
    // Hourly cost of the course
    double totalHoursInSemester = hoursPerClass * daysPerWeek * weeksPerSemester;
    double hourlyCost           = courseCost / totalHoursInSemester;
    
    // cost of each class for this course
    return hourlyCost * hoursPerClass;
}
