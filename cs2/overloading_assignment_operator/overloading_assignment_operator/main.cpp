//
//  main.cpp
//  overloading_assignment_operator
//
//  Created by Masatoshi Nishiguchi on 3/10/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Destination {
public:
    string name;
    
    // Default constructor must be implemented because we have a custom copy constructor.
    Destination() {
        
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
    
protected:
    int rating;
private:
    double cost;
};

class Planet : public Destination {
public:
    void doIt() {
        name   = "Masatoshi";
        rating = 10;
        // cost   = 9;   // Cannot access a private member of its superclass.
    }
};


int main() {
    
    Destination jamaica;
    Destination test_1, test_2, test_3;
    
    // Instantiate an object using a custom copy constructor.
    test_1 = Destination( jamaica );
    
    // Use assignment operator.
    test_2.operator=( jamaica );  // Using operator=()
    test_3 = jamaica;             // Using overloaded operator.
    
    return 0;
}
