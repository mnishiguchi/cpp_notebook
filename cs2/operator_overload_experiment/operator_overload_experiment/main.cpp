//
//  main.cpp
//  operator_overload_experiment
//
//  Created by Masatoshi Nishiguchi on 3/1/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Z {
public:
    int val;

    // Member Operator Overload
    bool operator<( const Z& rhs ) {
        return val < rhs.val;
    }
    bool operator>( const Z& rhs ) {
        return val > rhs.val;
    }
    bool operator==( const Z& rhs ) {
        return val == rhs.val;
    }
    bool operator!=( const Z& rhs ) {
        return ! operator==( rhs );
    }

}; // end class Z


class A {
public:
    int val;

}; // end class A


// Non-member Operator Overload
// http://en.cppreference.com/w/cpp/language/operators.
// cout is an instance of ostream class.
ostream& operator<<( ostream& os, const Z& obj ) {
    return os << "The val is: " << obj.val;
}


// Non-member Operator Overload
bool operator==( A& lhs, Z& rhs ) {
    return lhs.val == rhs.val;
}


void usePtr( Z* z ) {

}


int main() {

    Z z1, z2;

    z1.val = 11;
    z2.val = 99;

    //========================//

    cout << z1 << endl;

    //========================//


    if ( z1 == z2 ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //========================//

    // Pattern 1
    // Compare objects using the overloaded operator.
    if ( z1 > z2 ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //------------------------//

    // Pattern 2
    // Compare objects by one of their members.
    if ( z1.val > z2.val ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //------------------------//

    // Pattern 3
    if ( z1.operator>( z2 ) ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //------------------------//

    return 0;
}
