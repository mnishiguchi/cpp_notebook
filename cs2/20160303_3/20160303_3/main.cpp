//
//  Computer Science II
//  Mid-tem exam : Problem 3
//
//  Masatoshi Nishiguchi
//
//  Created by Masatoshi Nishiguchi on 3/3/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;


class Job {
public:
  int salary;
  bool canWorkFromHome;
  string jobName;

  // Constructor.
  Job( int s, bool wh, string jn ) {
    salary =  s;
    canWorkFromHome = wh;
    jobName = jn;
  }

};


/**
 * @param  jobs An array of pointers of the Job class.
 * @param  size The size of the list.
 * @return      Total salary of all telework jobs.
 */
int talleyHomework( Job **jobs, int size ) {

  int totalSalary = 0;

  // Iterate over the list.
  for ( int i = 0; i < size; i++ ) {

    // Add salary to the accumulator if canWorkFromHome member is true.
    if ( jobs[ i ]->canWorkFromHome ) {

      totalSalary += jobs[ i ]->salary;

    }

  }

  // Return the total salary of all telework jobs.
  return totalSalary;

} // end totalSalary


//===================================================================//


int main() {
  Job* jobs[] = {

    new Job( 28400, false, "Janitor" ),
    new Job( 88999, false, "Bricklayer" ),
    new Job( 78410, true, "Litigation Lawyer" ),
    new Job( 10707, false, "Rock Breaker" ),
    new Job( 400, false, "College Prof" ),
    new Job( 26900, true, "Telemarketer" ),
    new Job( 698000, false, "Doctor" ),
    new Job( 26900, true, "Dog Dentist" )

  };

  // 78410 + 26900 + 26900

  cout << "Tally for home jobs:" << talleyHomework( jobs, 8 ) << endl;

}
