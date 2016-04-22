//
//  main.cpp
//  recursion
//
//  Created by Masatoshi Nishiguchi on 4/21/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Greatest common divisor using recursion.
 * @param  a number
 * @param  b number
 * @return   [description]
 */
int getGcd( int a, int b ) {

    if ( b == 0 ) { return a; }

  return getGcd( b, a % b );
}


/*
*****
****
***
**
*
*
**
***
****
*****
*/
void printStars( int height ) {

  // reject if height is 0;
  if ( height == 0 ) { return; }

  for (int i = 0; i < height; i++ ) {
    cout << "*";
  }

  cout << '\n';

  printStars( height - 1 );

  for (int i = 0; i < height; i++ ) {
    cout << "*";
  }

  cout << '\n';
}



int main(int argc, const char * argv[]) {

    cout << "GCD: " << getGcd(30, 20) << endl;

    printStars( 5 );

    return 0;
}
