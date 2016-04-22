//
//  Computer Science II
//  Quiz 5 (Spring 2016)
//
//  Masatoshi Nishiguchi
//
//  4/21/2016.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
Question 1.
Given the isRecurse() function and the call: `cout << isRecurse( 45 );`

    State whether or not this is recursive:
    - This function is not recursive.

    Why not?
    - Because it has no base case and once executed, it cannot stop the recursion.
    In this particular case, the function will repeat decrementing the value by one
    and outputting it until the memory is exhausted.
*/
int isRecurse( int r ) {
    cout << r;
    cout << isRecurse( r - 1 );
    return r;
}


class Valuable {
public:
    Valuable(  ){}
    Valuable( int vD, string vT ) { valueInDollars=vD; valuedThing = vT;
    }
    int valueInDollars;
    string valuedThing;
};


/**
 * @return A pointer to a list of Valuable pointers.
 */
list<Valuable*> * getMyValue() {

    list< Valuable* > * rtn = new list< Valuable* >;

    rtn->push_back( new Valuable( 3,"cash" ) );
    rtn->push_back( new Valuable( 419,"food" ) );
    rtn->push_back( new Valuable( 3894,"jewels" ) );
    rtn->push_back( new Valuable( 12,"coins" ) );
    rtn->push_back( new Valuable( 456,"land" ) );
    rtn->push_back( new Valuable( 9333,"car" ) );
    rtn->push_back( new Valuable( 1,"children" ) );
    rtn->push_back( new Valuable( 149,"computer" ) );
    rtn->push_back( new Valuable( 843,"beer" ) );
    rtn->push_back( new Valuable( 43,"dog" ) );
    rtn->push_back( new Valuable( 59,"whiskey" ) );
    rtn->push_back( new Valuable( 37,"clothes" ) );
    rtn->push_back( new Valuable( 103,"bike" ) );
    rtn->push_back( new Valuable( 299,"game console" ) );
    rtn->push_back( new Valuable( 8232,"gold trinkets" ) );
    rtn->push_back( new Valuable( 912,"compact discs" ) );
    rtn->push_back( new Valuable( 457,"i-devices" ) );
    rtn->push_back( new Valuable( 222,"watches" ) );

    return rtn;
}


string checkPassword( string pw ) {
    if ( pw == "" ){
        throw 0;
    }

    if ( pw.length() > 256 ){
        throw -299;
    }

    if( pw == "secret" ) {
        cout << "PW too simple";
        return "";
    }

    if ( pw == "123" ){
        throw new Valuable( -99, "Password too stupid" );
    }

    return "Granted Access";
}


int main(  ) {

    /*
    Question 2. Write code that will:
    - iterate the vals variable and
    - accumulate the total of all values as reported by the valueInDollars attribute.
     */

    // A pointer to a list of Valuable pointers.
    list< Valuable* > * vals = getMyValue() ;

    int totalValue = 0;  // Accumulator

    // Temp variable to hold a current element each iteration.
    Valuable* currentElement = NULL;

    // Create an iterator of list< Valuable* > type.
    list< Valuable* >::iterator iterator;

    // Iterate over the vector using that iterator.
    for ( iterator  = vals->begin() ;
          iterator != vals->end()   ;
          iterator++ ) {

        currentElement = *iterator;

        // cout << currentElement->valueInDollars << endl; // Debug: Print all valueInDollars

        // Update the totalValue.
        totalValue += currentElement->valueInDollars;
    }
    cout << "Total Value:" << totalValue << endl;


    /*
    Question3. Write code that will properly catch any exception thrown from the following call
    */
    try {
        checkPassword( "secret" );
        // checkPassword( "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam iaculis metus sit amet varius porta. Quisque iaculis sit amet augue sit amet molestie. Nunc hendrerit porttitor urna, at pharetra ex fringilla et. Duis condimentum nulla eget felis consequat, quis luctus ligula vulputate. Mauris dapibus felis vel quam consectetur malesuada. Aenean eu nisi sed dolor scelerisque faucibus. Quisque sed ligula sed enim congue mollis quis vitae velit. Curabitur id erat sit amet eros posuere tristique quis eget neque. Etiam hendrerit odio sit amet mollis laoreet. Nullam vestibulum magna justo, sollicitudin semper massa consectetur eu." );
        // checkPassword( "" );
        // checkPassword( "123" );

    } catch ( int err ) {
        std::cerr << "\nException caught: " << err << '\n';

    } catch ( char* err ) {
        std::cerr << "\nException caught: " << err << '\n';

    } catch ( Valuable* err ) {
        std::cerr << "\nException caught:\n"
                  << "  valueInDollars => " << err->valueInDollars << '\n'
                  << "  valuedThing    => " << err->valuedThing << '\n';
    }

    return 0;
}


