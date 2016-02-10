//
//  main.cpp
//  20160209
//
//  Created by Masatoshi Nishiguchi on 2/9/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

/*
  Inheritance experiments
  - A subclass must call one of its parent's constructors.
 */

#include <iostream>
using namespace std;

/**
 * A parent class.
 */
class Parent {
public:

  int secret;

  Parent() {

    this->secret = 9999;

  }


  Parent( int secret ) {

    this->secret = secret;

  }

};


/**
 * A subclass of the Parent class.
 * NOTE: A subclass must call one of its parent's constructors.
 */
class Child : public Parent {
public:

  /**
   * Constructor with a param.
   * Calls its parent's constructor with a specified argument.
   */
  Child( int secret ) : Parent( secret ) {

  }

  /**
   * Default constructor.
   * Calls its parent's constructor with a default value.
   */
   Child() : Parent( -1 ) {

   }

};


int main() {

    // Child c1;        // Calling the default constructor.
    // Child c2( 36 );  // Calling a constructor with one param.

    // cout << "c1: " << c1.secret << endl;
    // cout << "c2: " << c2.secret << endl;

    // cout << "sizeof &c1: " << sizeof &c1 << endl;
    // cout << "sizeof &c2: " << sizeof &c2 << endl;

    // cout << "sizeof c1: " << sizeof c1 << endl;
    // cout << "sizeof c2: " << sizeof c2 << endl;

    // // ------------------------------------------ //

    // int i;
    // double d;
    // cout << "sizeof int:    " << sizeof i << endl;  //==> 4
    // cout << "sizeof double: " << sizeof d << endl;  //==> 8

    Parent p1( 9 );
    Parent* ptr1;

    // Runtime error : ptr1 is not initialized.
    // cout << "Pointer: " << ptr1 << endl;

    // Assign to ptr1 the address of the Parent object, p1.
    ptr1 = &p1;

    // Printing the value of ptr1.
    cout << "ptr1: " << ptr1 << endl;         // Hexadecimal
    cout << "ptr1: " << (long)(ptr1) << endl; // Base 10

    // ------------------------------------------ //

    // Dynamically create a Parent object.
    ptr1 = new Parent( 99 );

    // Printing the value of ptr1.
    cout << "ptr1: " << ptr1         << endl; // Hexadecimal

    // Base 10
    cout << "ptr1: " << (long)(ptr1) << endl;
    cout << "ptr1: " << (size_t)(ptr1) << endl;
    // cout << "ptr1: " << (int)(ptr1) << endl;
    // cout << "ptr1: " << (unsigned int)(ptr1) << endl;
    // cout << "ptr1: " << static_cast<int>(ptr1) << endl;
    // cout << "ptr1: " << static_cast<long>(ptr1) << endl;
    // cout << "ptr1: " << dynamic_cast<int>(ptr1) << endl;
    // cout << "ptr1: " << dynamic_cast<long>(ptr1) << endl;

    // Printing the secret of ptr1.
    cout << "ptr1's secret: " << ptr1->secret << endl;

    // ------------------------------------------ //

    // Dynamically create Parent objects.
    ptr1 = new Parent[10];

    for ( int i = 0; i < 10; i++ ) {

      ptr1[ i ].secret = 1000 + i;

    }

    // Accessing the attribute of an object.
    cout << "ptr1: " << ptr1->secret << endl;
    cout << "ptr1: " << ptr1[ 0 ].secret << endl;
    cout << "ptr1: " << ( *ptr1 ).secret << endl;
    cout << "ptr1: " << ( *( ptr1 + 1 ) ).secret << endl;
    cout << "ptr1: " << ( ptr1 + 8 )->secret << endl;
    cout << "ptr1: " << ( ptr1 + 9 )->secret << endl;

    // Deleting dynamically created object.
    delete[] ptr1;


    return 0;
}
