/**
 *  20160112
 */

#include <iostream>
using namespace std;

int main() {

    // Sanity check.
    cout << "Hello world!!!" << endl;

    // Send a command to OS.
    system( "ls -hartl" );

    cout << endl;

    // Formatting
    // http://www.cplusplus.com/reference/cstdio/printf/
    printf ("Characters: %c %c \n", 'a', 65);
    printf ("Decimals: %d %ld\n", 1977, 650000L);
    printf ("Preceding with blanks: %10d \n", 1977);
    printf ("Preceding with zeros: %010d \n", 1977);
    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
    printf ("Width trick: %*d \n", 5, 10);
    printf ("%s \n", "A string");

    // C++ Operator Precedence
    // http://en.cppreference.com/w/cpp/language/operator_precedence




    return 0;
}
