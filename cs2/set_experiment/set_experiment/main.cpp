//
//  main.cpp
//  set_experiment
//
//  Created by Masatoshi Nishiguchi on 4/5/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {

  // Set automatically sort the elements when an item is added to it.
  // Set does not accept duplicate items.
  set<int> stuff;

  // Insert items in an unsorted order.
  stuff.insert( 24 );
  stuff.insert( -2 );
  stuff.insert( 47 );
  stuff.insert( -198 );
  stuff.insert( 1002 );
  stuff.insert( 327 );
  stuff.insert( 1002 );

  // Create an iterator for set of int type.
  set<int>::iterator it;

  for ( it = stuff.begin(); it != stuff.end(); it++ ) {

    cout << "Val: " << *it << endl;

  }

  return 0;
}
