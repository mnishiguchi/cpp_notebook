//
//  Computer Science II
//  Mid-tem exam : Problem 1
//
//  Masatoshi Nishiguchi
//
//  Created by Masatoshi Nishiguchi on 3/3/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


/**
 * An abstract class that represents a table.
 */
class Table {
public:

  // Purely virtual function.
  virtual int getRowCount()=0;

  // Virtual function.
  virtual int getColCount() { return 1; }

  int rowCount, colCount;

};


//===================================================================//


/**
 * A subclass of the Table abstract class.
 * Problem #1 - Required
 * You are ONLY allowed to make changes to the Data class
 * not including the definition of the class.
 *
 */
class Data : public Table {
public:
  // Default constructor.
  Data() {

    this->rowCount = 0;
    this->colCount = 0;

  }
  // Constructor with 2 parameters.
  Data( int rowCount, int colCount ) {

    this->rowCount = rowCount;
    this->colCount = colCount;

  }
  // Implement a virtual method.
  int getRowCount() {
    return this->rowCount;
  }
  // Implement a virtual method.
  int getColCount() {
    return this->colCount;
  }
  // Operator overload.
  bool operator==( const Data& other ) {
    return  this->rowCount == other.rowCount
         && this->colCount == other.colCount;
  }

};


//===================================================================//


/**
 * The main function.
 */
int main() {

  Data *dTab = new Data( 20, 9 ), eTable[ 3 ];

  if( *dTab == eTable[ 1 ] ) {

    cout << "Same tables\n";

  } else {

    cout << "Table has " << eTable[ 1 ].getRowCount() << " rows\n";

  }

}
