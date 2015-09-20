//
//  assignment1.cpp
//  data structures
//
//  Created by Masatoshi Nishiguchi on 9/2/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include "assignment1.h"

// 1)  Below, you will find a partially completed function implementation.
// Using the call code below and the partial function,
// fill in the blanks with the most appropriate data types.

// ALSO, state what will be output when the code is run.
// You should NOT type this in to answer the questions!

void main()
{
    int m=23, distance=200;
    
    _____   folks = !false;
    
    if( areWeThereYet(m + distance, !folks, 23 * 1.2) )
        cout << "We've arrived\n";
    else
        cout << "Still on the road\n";
}

____ areWeThereYet(____ milesToGo, ____ havePassengers, ____ MPG)
{
    if(MPG < 10.9)
        return false;
    else if(MPG > 90.1)
        return true;
    
    if(milesToGo < 100)
    {
        if(!havePassengers && MPG > 20.6)
            return true;
    }
    return false;
}


// 2)  Assume this code for the essay question below.

char r = 'M';
char mfn[] = "My full name";

// Explain the difference between the two variables.
// Include in your discussion any similarities or differences in the data they hold.
// Be specific as to their data and the amount of memory occupied.
// For sake of this discussion, assume a single char uses one (1) byte.
// Include any other pertinent info.





// 3)  Given the declarations for a and b, what value does the boolean expression evaluate to?
// You MUST show your work for credit!

int a = 4;
int b = -3;

!( !(a == 4 && b == -3) && (6 <= 3 || a > 1) ) && true || false || ( b > (5 - 10) || !(a > 0) )





// 4) Declare a double array of 4 elements and code a loop to efficiently
// assign the following numbers to the four elements:

1.0,1.1,1.2,1.3

// Ensure the proper values were assigned by coding a loop to output the values
// after they have been assigned.





// 5)  Given the following code, write a class definitions as appropriate.
// Do NOT implement the class.  Do not try to make any logical sense of the class, just define it.

Database *connect, *offsite;
DBInfo t;

int results;
char _8 = '8';

connect = new Database("location", 23 + 3.5, false);
results = connect->fill(&t);

offsite = new Database[20];
offsite->open("8", _8);
offsite->flag = _8;
offsite[1].open("another location", 'r');

for(int a=1;a<20;a++)
offsite[a].closeIt(a);

connect->closeIt( t.getRows("8") );

delete connect;
delete[] offsite;


// 6)  Use these declarations for the following 6 problems

int I=6, *val = new int;
int ps[200];
double* showMoney = new double;
bool* upOrDowns   = new bool[200];
char msg[]        = "Secret Message";

// Show the function declarations corresponding to the function calls.
// Use the return types and the arguments as hints.
// If a value is not being assigned, assume the function return type is void.
// DO NOT IMPLEMENT THE FUNCTIONS!  You don't have enough info to know what they are doing.

// a)
*showMoney = getLocation(val);



________________________________________________________

// b)
I = getIndex(msg[5]) * 45;



________________________________________________________

// c)
ps[24] = processThis(msg, &I);


________________________________________________________

// d)
*showMoney = f(upOrDowns[2], *val);



________________________________________________________

// e)
ZZ( showMoney[0] + 34.5, msg[3 + 2] );



________________________________________________________

// f)
*val = grandCall( 2 + 30, I - .335, *showMoney, *msg, ps[1] + 1 ) * 7;



________________________________________________________

// 7) Assume this class definition

class Country
{
public:
    // returns the country's population
    int getPopulation();
    // returns true if the country has a major coast
    bool hasACoast();
    
private:
    
    //...
    
};

// Write a function that will accept an array of Country instances and
// any other parameters needed to process an array.
// The function must calculate and then return the total population of countries
// in the array that do NOT have a coastal area.

