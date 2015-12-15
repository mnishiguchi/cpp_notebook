/**
 * max_three_integer.cpp
 */
#include <iostream>
#include <cmath>
using namespace std;


/**
 * @param An integer
 * @param An integer
 * @param An integer
 * @return The greatest of the three integers.
 */
int max(int n_1, int n_2, int n_3) {

    return max( n_1, max(n_2, n_3) );

}


int main() {

    const int ARRAY_SIZE = 3;
    int nums[ARRAY_SIZE];
    int temp = 0;

    cout << "Enter three integers: " << endl;

    int index = 0;
    while (index < ARRAY_SIZE) {

        cout << ">>> ";
        cin >> temp;

        if ( cin.fail() ) {
            cout << "Invalid input" << endl;
            cin.clear();            // Restore input stream
            cin.ignore(100, '\n');  // Clear the buffer

        } else {
            nums[ index ] = temp;
            index += 1;
        }
    }

    cout << "Max: " << max( nums[ 0 ], nums[ 1 ], nums[ 2 ] ) << endl;

    return 0;
}
