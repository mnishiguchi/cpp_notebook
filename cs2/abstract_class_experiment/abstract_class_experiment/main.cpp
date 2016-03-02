//
//  main.cpp
//  abstract_class_experiment
//
//  Created by Masatoshi Nishiguchi on 3/1/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;


//============================================//


/**
 * Abstract class.
 */
class Transport {
public:
    int miles;
    
    // Purely virtual methods.
    // This makes the class as an abstract class.
    // Its subclass must implement this method.
    virtual int getTopSpeed() = 0;
    
    // void showWheels() {
    virtual void showWheels() {
        cout << "Regular" << endl;
    }
    
private:
    void doThing() {
        // Do something
    }
    
};


//============================================//


/**
 * Extends the Transport abstract class.
 */
class Truck : public Transport {
public:
    
    // Override the parent's implementation.
    void showWheels() {
        cout << "Wider" << endl;
    }
    
    // Implement the Transport abstract class.
    int getTopSpeed() {
        return 100;
    }
    
};


//============================================//


void showVehichle( Transport& transport ) {
    transport.showWheels();
}

void showAllVehichles( Transport* vehicles, int size ) {
    
    for ( int i = 0; i < size; i++ ) {
        vehicles[ i ].showWheels();
    }
    
}


//============================================//


int main() {
    
    // Declare a Truck object.
    Truck semi;
    
    // If showWheels() declared as a regular member function,
    // ==> Compile-time binding : Execute the parent's version.
    
    // If showWheels() declared as a virtual function,
    // ==> Run-time binding : Execute the child's version, like Java.
    showVehichle( semi );
    
    //------------------//
    
    // Transport transport;  // ERROR : Cannot instantiate an abstract class.
    Transport* transport;    // But this is OK
    
    //------------------//
    
    Truck semis[ 10 ];
    showAllVehichles( semis, 10 );
    
    return 0;
    
}