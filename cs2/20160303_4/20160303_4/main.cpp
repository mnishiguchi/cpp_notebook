//
//  Computer Science II
//  Mid-tem exam : Problem 4
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

  Job( int s, bool wh, string jn ) {
    salary = s;
    canWorkFromHome = wh;
    jobName = jn;
  }

};


/**
 * @param  jobs An array of pointers of the Job class.
 * @param  size The size of the list.
 * @return      A pointer to the job that contains the lowest salary.
 */
Job* lowestJob( Job **jobs, int size ) {

  // Initialize the lowest to the index 0.
  int lowIndex = 0;

  // Iterate over the list.
  for ( int i = 0; i < size; i++ ) {

    // Remember the index if the salary is lower than current low.
    if ( jobs[ i ]->salary < jobs[ lowIndex ]->salary ) {

      lowIndex = i;

    }

  }

  // Return the total salary of all telework jobs.
  return jobs[ lowIndex ];

}


int main() {

  Job* jobs[] = {

    new Job(28400, false, "Janitor"),
    new Job(88999, false, "Bricklayer"),
    new Job(78410, true, "Litigation Lawyer"),
    new Job(10707, false, "Rock Breaker"),
    new Job(400, false, "College Prof"),
    new Job(26900, true, "Telemarketer"),
    new Job(698000, false, "Doctor"),
    new Job(74400, true, "Dog Dentist")
  };

  Job* low =  lowestJob(jobs, 8);

  cout << "Lowest salary job:" << low[0].jobName << endl;

}
