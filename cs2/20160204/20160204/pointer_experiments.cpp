/**
 * Pointer experiments
 * Created by Masatoshi Nishiguchi on 2/4/16.
 */
#include <iostream>
using namespace std;

int main() {

    int aInt = 24;
    int* ip = &aInt; // aInt and ip now reference the same mermory location.


    cout << "Value:             " << aInt << endl;
    cout << "Value's Address:   " << ip << endl;
    cout << "Pointer's value:   " << &aInt << endl;

    // Change the value of the int variable.
    // *ip = 99  // Error: Cannot assign to a pointer.
    *ip = 99;

    cout << "Value:             " << aInt << endl;
    cout << "Value through ip: " << *ip << endl;

    cout << endl;

    // ============================================== //

    int* ip2;
    ip2 = &aInt;  // Now ip2 also reference aInt's location.

    *ip2 = 18;

    cout << "Value:             " << aInt << endl;

    cout << endl;

    // ============================================== //

    double* dp;

    // dp = &aInt;  // Error: cannnot assign address of int to a double pointer.

    // ============================================== //

    // dp1: double pointer, dp2: double, dp3: double
    // Only the first one becomes a pointer.
    double* dp1, dp2, dp3;

    // ============================================== //


    return 0;
}
