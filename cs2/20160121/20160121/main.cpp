//
//  main.cpp
//  20160121
//
//  Created by Masatoshi Nishiguchi on 1/21/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;


double getLowVal( double* vals, int size ) {

  int lowestIndex = 0;

  for ( int i = 1; i < size; i++ ) {

    if ( vals[ i ] < vals[ lowestIndex ] ) {

      lowestIndex = i;

    }

  }

  return vals[ lowestIndex ];

}


int findValIndex( double* vals, int size, double valToFind ) {

  int index = -1;

  for ( int i = 1; i < size; i++ ) {

    if ( vals[ i ] == valToFind ) {

      index = i;

    }

  }

  return index;

}


int main() {

    double numbers[] = {
      23.4,
      93,
      -85,
      34,
      99
    };

    // cout << getLowVal( numbers, 5 ) << endl;
    // cout << findValIndex( numbers, 5, 34 ) << endl;

    return 0;
}
