//
//  main.cpp
//  20160308
//
//  Created by Masatoshi Nishiguchi on 3/8/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int getGreater( int num_1, int num_2 ) {

  return ( num_1 > num_2 ) ? num_1 : num_2;

}


template<typename Type>
Type getGreater( Type num_1, Type num_2 ) {

  return ( num_1 > num_2 ) ? num_1 : num_2;

}


template<typename Type>
void printNumber( Type number ) {

  cout << "The number is " << number << endl;

}


int main() {

  printNumber( getGreater( 33, 66 ) );
  printNumber( getGreater( 4.4, 5.5 ) );

  return 0;
}
