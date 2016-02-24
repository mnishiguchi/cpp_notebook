//
//  main.cpp
//  20160218
//
//  Created by Masatoshi Nishiguchi on 2/18/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    // int iv;

    // int* ip;
    int* ipa[10];            // Array of int pointer.

    int** ipaa = new int*;
    (*ipaa) = new int[10];  // Array of int pointer.

    // ipa    = new int[10];  // Invalid
    // ipa[ 0 ] = new int;    // Valid
    // ipa[ 1 ] = new int;    // Valid
    // ipa[ 2 ] = &iv;        // Valid
    // *ipa[ 2 ] = iv;        // Valid


    // --
    // Working on ipa.
    // --


    // Initialize all the elements to NULL.
    for ( int i = 0; i < 10; i++ ) {

        ipa[ i ] = NULL;

    }

    // Assign the address of a dynamic instance to each element.
    for ( int i = 0; i < 10; i++ ) {

        ipa[ i ] = new int( i );

    }

    // Print each element, which is an int pointer.
    for ( int i = 0; i < 10; i++ ) {

        cout << i << ": " << ipa[ i ] << endl;

    }

    // Print the value of the address pointed to by each element.
    for ( int i = 0; i < 10; i++ ) {

        cout << i << ": " << *( ipa[ i ] ) << endl;

    }

    // Delete all the dynamic instances that each element points to.
    for ( int i = 0; i < 10; i++ ) {

        delete ipa[ i ];

    }

    // Print each element, which is an int pointer.
    for ( int i = 0; i < 10; i++ ) {

        cout << i << ": " << ipa[ i ] << endl;

    }

    // // Try to delete all again.  // Runtime error
    // for ( int i = 0; i < 10; i++ ) {

    //     delete ipa[ i ];

    // }


    cout << "================================================" << endl;


    // --
    // Working on ipaa.
    // --


    // Initialize all the elements to NULL.
    for ( int i = 0; i < 10; i++ ) {

        ipaa[ i ] = NULL;

    }

    // Assign the address of a dynamic instance to each element.
    for ( int i = 0; i < 10; i++ ) {

        ipaa[ i ] = new int( i );

    }

    // Print each element, which is an int pointer.
    for ( int i = 0; i < 10; i++ ) {

        cout << i << ": " << ipaa[ i ] << endl;

    }

    // Print the value of the address pointed to by each element.
    for ( int i = 0; i < 10; i++ ) {

        cout << i << ": " << *( ipaa[ i ] ) << endl;

    }

    return 0;
}
