//
//  main.cpp
//  20160407
//
//  Created by Masatoshi Nishiguchi on 3/24/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


/**
 * An exception class.
 */
class Airplane {
public:
  int age;
  string model;
  string carrier;
};

bool operator<( const Airplane& lhs, const Airplane& rhs ) {
  return lhs.model < rhs.model;
}

void modifyAirplane( Airplane& airplane ) {

  // Do something.
  cout << airplane.model << endl;

}

ostream& operator<<( ostream& os, Airplane& airplane) {

  return os << "model: " << airplane.model << endl;
}

int main() {

  vector<Airplane> hangar;

  Airplane smallPlanes[ 9 ], model_1, model_2, model_3, model_4, model_5, model_6;

  model_1.model = "model_1";
  model_2.model = "model_2";
  model_3.model = "model_3";
  model_4.model = "model_4";
  model_5.model = "model_5";
  model_6.model = "model_6";

  for ( int i = 0; i < 9; i++ ) {

    smallPlanes[ i ].model = "Lear jet";
    hangar.push_back( smallPlanes[ i ] );

  }

  hangar.push_back( model_1 );
  hangar.push_back( model_2 );
  hangar.push_back( model_3 );
  hangar.push_back( model_4 );
  hangar.push_back( model_5 );
  hangar.push_back( model_6 );

  cout << "Planes in my hangar: " << hangar.size() << endl;

  // Create an iterator of Airplane type.
  vector<Airplane>::iterator it;


  //=============================//


  // for ( it = hangar.begin();  // Set the iterator pointing to the first element.
  //       it != hangar.end();   // Terminating condition.
  //       it++ ) {              // Move the cursor to next.

  //   it->carrier = "Delta";

  //   modifyAirplane( *it );

  // }

  // for ( it = hangar.begin();  // Set the iterator pointing to the first element.
  //       it != hangar.end();   // Terminating condition.
  //       it++ ) {              // Move the cursor to next.

  //   cout << ( * it ) << endl;
  // }


  //=============================//


  // // Make sure that you include algorithm.
  // // for_each( InputIt first, InputIt last, UnaryFunction f );
  // for_each( hangar.begin(),      // Start
  //           hangar.end(),        // End
  //           modifyAirplane );    // Function pointer - address of a function.


  //=============================//


  // // Make sure that you include algorithm.
  // // for_each( InputIt first, InputIt last, UnaryFunction f );
  // for_each( hangar.begin(),      // Start.
  //           hangar.begin() + 6,  // Up to 6 elements.
  //           modifyAirplane );    // Function pointer - address of a function.

  //=============================//


  // One of the many algorithms, max_elememt.
  vector<Airplane>::iterator it_max;
  it_max = max_element( hangar.begin(), hangar.end() );
  cout << "Max plane: " << it_max->model << endl;


  //=============================//


  // Create a map.
  map<int, string> words;

  // Add values to the map.
  words[ 56 ] = "fifty-six";
  words[ -1 ] = "negative one";

  // Retrieve data from the map.
  string word = words[ -1 ];  // key: -1, value: "negative one"

  cout << word << endl;

  return 0;
}

