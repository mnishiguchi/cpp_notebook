//
//  main.cpp
//  20160223
//
//  Created by Masatoshi Nishiguchi on 2/23/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Z {
public:
  int val;

  bool operator>( const Z& rhs ) {

      if ( val > rhs.val ) {
          return true;
      }
      return false;
  }


};

void usePtr( Z* z ) {

}




int main() {

    // double* dp;

    // // delete dp;  // Error: dp is not dynamically allocated.

    // dp = new double;
    // delete dp;  // Good

    //======================//

    // Z z1, z2, *zp;

    // usePtr( z1 );  // Error

    // usePtr( &z1 );    // Good
    // usePtr( new Z );  // Good

    // zp = new Z;
    // cout << zp[ zp->val ].val;  // Good

    //======================//

    Z z1, z2;

    z1.val = 11;
    z2.val = 99;

    // if ( z1 > z2 ) {

    //   cout << "True" << endl;

    // } else {

    //   cout << "False" << endl;

    // }

    //------------------------//

    // if ( z1.operator>( z2 ) ) {

    //   cout << "True" << endl;

    // } else {

    //   cout << "False" << endl;

    // }

    return 0;
}
