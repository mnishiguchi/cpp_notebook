//
//  main.cpp
//  20160324
//
//  Created by Masatoshi Nishiguchi on 3/24/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


/**
 * An exception class.
 */
class WhatsWrong {
public:
  string problem = "undefined";
};


int main(int argc, const char * argv[]) {

  // int number;

  // cout << "Give me a positive int: ";
  // cin >> number;

  // try {

  //   if ( number <= 0 ) {
  //     // Throwing an int.
  //     throw number;

  //   }

  //   cout << "You entered a positive int: " << number << endl;

  //   // In C++, the catch block can catch any data type.
  // } catch( int error ) {

  //   cout << "You did not enter a positive int!" << endl;
  //   cout << "Caught      : " << error  << endl;
  //   cout << "You entered : " << number << endl;

  // }
  //
  // ======================

  // int number;

  // cout << "Give me a positive int: ";
  // cin >> number;

  // try {

  //   if ( number <= 0 ) {

  //     // Instantiate a WhatsWrong.
  //     WhatsWrong ww;

  //     // Set a problem.
  //     ww.problem = "You did not enter a positive int";

  //     // Throwing that WhatsWrong object.
  //     throw ww;
  //   }

  //   cout << "You entered a positive int" << number << endl;

  //   // In C++, the catch block can catch any data type that is thrown.
  //   // In this case, catch the WhatsWrong object that was thrown.
  // } catch( WhatsWrong ww ) {

  //   cout << "Caught     : " << ww.problem << endl;
  //   cout << "You entered: " << number     << endl;
  //   cout << endl;

  // }
  //
  // ======================


  int number;

  cout << "Give me a positive int: ";
  cin >> number;

  try {

    if ( number <= 0 ) {

      // Instantiate a WhatsWrong.
      WhatsWrong ww;

      // Set a problem.
      ww.problem = "You did not enter a positive int";

      // Throwing that WhatsWrong object.
      throw ww;
    }

    cout << "You entered a positive int" << number << endl;

    // In C++, the catch block can catch any data type that is thrown.
    // In this case, catch the WhatsWrong object that was thrown.
  } catch( WhatsWrong ww ) {

    cout << "Caught     : " << ww.problem << endl;
    cout << "You entered: " << number     << endl;
    cout << endl;

  }



  return 0;
}
