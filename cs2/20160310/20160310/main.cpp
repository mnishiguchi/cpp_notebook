//
//  main.cpp
//  20160310
//
//  Created by Masatoshi Nishiguchi on 3/10/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;


class Destination {
public:
    string name;

    Destination( string name, int rating, double cost ) {
        this->name   = name;
        this->rating = rating;
        this->cost   = cost;
    }

    // Custom copy constructor.
    Destination( Destination& other ) {

    }

    // Oveload the assignment operator( = ).
    // Equivalent of copy constructor.
    const Destination& operator=( const Destination& other ) {

        if ( this != &other ) { // Avoid self-assignment.

            // Algorithm to copy the other into this object.
            this->cost   = other.cost;
            this->rating = other.rating;
            this->cost   = other.cost;
        }

        // It is a self-assignment, just return that instance.
        return *( this );
    }

    // Overload comparison operators.
    const bool operator==( const Destination& other ) {
        return this->rating == other.rating;
    }
    const bool operator>( const Destination& other ) {
        return this->rating > other.rating;
    }
    const bool operator<( const Destination& other ) {
        return this->rating < other.rating;
    }

protected:
    int rating;
private:
    double cost;
};


int getGreater( int num_1, int num_2 ) {

  return ( num_1 > num_2 ) ? num_1 : num_2;

}

template<typename Type>
Type getGreater( Type num_1, Type num_2 ) {

  return ( num_1 > num_2 ) ? num_1 : num_2;

}

int getGreatest( int* numbers, int size ) {

  int highIndex = 0;

  for ( int i = 0; i < size; i++ ) {

    if ( numbers[ i ] > numbers[ highIndex ] ) { highIndex = i; }

  }

  return numbers[ highIndex ];

}

template<typename Type>
Type getGreatest( Type* items, int size ) {

  int highIndex = 0;

  for ( int i = 0; i < size; i++ ) {

    if ( items[ i ] > items[ highIndex ] ) { highIndex = i; }

  }

  return items[ highIndex ];

}

template<typename Type>
void printNumber( Type number ) {

  cout << "The number is " << number << endl;

}


int main() {

  printNumber( getGreater( 33, 66 ) );
  printNumber( getGreater( 4.4, 5.5 ) );

  cout << "==================================================" << endl;

  int numbers[] = { 23,34,5,12,45,75,8,3,6,33 };
  printNumber( getGreatest( numbers, 10 ) );

  cout << "==================================================" << endl;

  Destination list[] = {

    Destination("Buri", 10, 10),
    Destination("Maguro", 9, 2.3),
    Destination("Hamachi", 5, 7.2),
    Destination("Sakana", 3, 2.5),
    Destination("Tako", 12, 6.7),
    Destination("Ika", 7, 2.4)

  };

  return 0;
}

