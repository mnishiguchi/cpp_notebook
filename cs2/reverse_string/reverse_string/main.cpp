//
//  main.cpp
//  reverse_string
//
//  Created by Masatoshi Nishiguchi on 3/8/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


void printReversedString( string sentence, int length ) {

  string reversed = sentence;

  for ( int i = 0; i < length; i++ ) {

    reversed[ i ] = sentence[ length - 1 - i ];

  }

  cout << sentence << endl;
  cout << reversed << endl;
}


int main() {

  printReversedString( "masatoshi", 9 );
  printReversedString( "gyudon", 6 );

  return 0;
}
