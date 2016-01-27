//
//  Classes
//  main.cpp
//  20160126
//
//  See examples on the book p632
//
//  Created by Masatoshi Nishiguchi on 1/26/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;


class Shoe {
public:
    // Attributes - Descriptions.
    // int size;
    string color;

    // Methods - Behavior / Operations.
    void walk();

    // Getters and setters
    void setSize( int size ) { this->size = size; }

    int getSize() const { return this->size; }

// Convention: All attributes should be private if possible.
private:
    int size;
};


void Shoe::walk() {

   this->color = "Nice color";

}


/**
 * A function that counts yellow shoes.
 * @param  list A list of shoes.
 * @param  size The size of the list.
 * @return      The count of yellow shoes.
 */
int countYellowShoes( Shoe list[], int size ) {

    int count = 0;

    for ( int i = 0; i < size; i++ ) {

        if ( list[ i ].color == "Yellow" ) { count += 1; }

    }

    return count;

} // end countYellowShoes



int main() {

    // ------------------------------------------ //
    // ------------------------------------------ //

    // // Declaration for primitive data types.
    // // int i;

    // // Declaration for user-defined data types.
    // Shoe myShoe;
    // Shoe yourShoe;

    // // Set the color attribute.
    // myShoe.color = "white";
    // yourShoe.color = "red";

    // // Access the color attribute and output that.
    // cout << "myShoe:   " << myShoe.color << endl;
    // cout << "yourShoe: " << yourShoe.color << endl;


    // ------------------------------------------ //
    // ------------------------------------------ //


    // Declaration for array of user-defined data types.
    Shoe shoeStore[5];

    // Initialize all the shoes.
    for ( int i = 0; i < 5; i++ ) {

      shoeStore[ i ].color = "Yellow";
      shoeStore[ i ].setSize( 11 );

    }

    shoeStore[ 2 ].color = "Blue";
    shoeStore[ 4 ].color = "Red";


    // Access the attributes and output those.
    for ( int i = 0; i < 5; i++ ) {

      cout << "Shoe #" << i + 1 << ": " << shoeStore[ i ].color << " "
                                       << shoeStore[ i ].getSize() << endl;

    }

    cout << endl;

    cout << "countYellowShoes: " << countYellowShoes( shoeStore, 5 ) << endl;


    // ------------------------------------------ //
    // ------------------------------------------ //


    cout << endl;

    // Access the attributes and output those.
    for ( int i = 0; i < 5; i++ ) {

      shoeStore[ i ].walk();

    }

    cout << "After shoeStore[ i ].walk invoked:" << endl;
    for ( int i = 0; i < 5; i++ ) {

      cout << "Shoe #" << i + 1 << ": " << shoeStore[ i ].color << " "
                                        << shoeStore[ i ].getSize() << endl;

    }


    // ------------------------------------------ //
    // ------------------------------------------ //


    return 0;
}
