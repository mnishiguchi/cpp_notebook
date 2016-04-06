//
//  main.cpp
//  container_and_iterator
//
//  Created by Masatoshi Nishiguchi on 4/5/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>
using namespace std;

class Airplane {
public:
  string name;

  Airplane( string name ) {
    this->name = name;
  }

  bool operator<( Airplane& rhs ) {

    return this->name < rhs.name;

  }
};


int main() {

    // Create Airplanes.
    Airplane* b747 = new Airplane( "b747" );
    Airplane* abdd = new Airplane( "abdd" );
    Airplane* cessna = new Airplane( "cessna" );

    //===================================

    // // Create a collection.
    // deque<Airplane*> queue;

    // // Add Airplanes to the collection.
    // queue.push_back( b747 );
    // queue.push_back( abdd );
    // queue.push_back( cessna );

    // // Create an iterator.
    // deque<Airplane*>::iterator it;

    // // Iterate over the collection using the iterator.
    // for ( it = queue.begin(); it != queue.end(); it++ ) {

    //     cout << "Name: " << (**it).name << endl;

    // }

    //===================================

    // Create another collection.
    list<Airplane*> hangar;

    // Add Airplanes to the collection.
    hangar.push_back( b747 );
    hangar.push_back( abdd );
    hangar.push_back( cessna );

    // List has a built-in sort function.
    hangar.sort();

    // Create an iterator.
    list<Airplane*>::iterator it_2;

    // Iterate over the collection using the iterator.
    for ( it_2 = hangar.begin(); it_2 != hangar.end(); it_2++ ) {

        cout << "Name: " << (**it_2).name << endl;

    }

    return 0;
}
