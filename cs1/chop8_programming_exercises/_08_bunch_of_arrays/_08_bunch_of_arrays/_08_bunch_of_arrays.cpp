/**
 * _08_bunch_of_arrays
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


/** a)
 * Initialize any one-dimensional array of type int to 0.
 * @param numberList An integer array.
 * @param size       The size of the array.
 */
void setZero(int* numberList, int size) {

    for (int i = 0; i < size; i++) {

        numberList[ i ] = 0;

    }
}


/** b)
 * Prompt the user to input 20 numbers and stores the numbers into alpha.
 * @param alpha An integer array to store the user's inputted numbers.
 */
void inputArray(int alpha[20]) {

    bool isAccepted;

    // The prompt message.
    cout << "\nEnter 20 numbers:\n" << endl;

    for (int index = 0; index < 20; index++) {

        isAccepted = false;
        while ( ! isAccepted ) {

            // Read the user's input.
            cout << "  #" << setw(2) << index << ": ";
            cin >> alpha[ index ];

            // Ensure that the input was valid.
            if ( cin.fail() ) {

                cout << "Invalid input" << endl;
                cin.clear();            // Restore input stream.
                cin.ignore(100, '\n');  // Clear the buffer.

            } else {

                isAccepted = true;

            }
        } // end while
    } // end for
}


/** c)
 * Initialize the elements of beta to two times the corresponding elements in alpha.
 * @param alpha An integer array with 20 elements (read-only)
 * @param beta  An integer array with 20 elements that is to be initialzed.
 */
void doubleArray(const int alpha[20], int beta[20]) {

    for (int index = 0; index < 20; index++) {

        beta[ index ] = alpha[ index ] * 2;

    }
}


/** d)
 * Set the elements of the first row of inStock to gamma and the remaining rows
 * of inStock to three times the previous row of inStock.
 * @param gamma    An integer array with 4 elements (read-only).
 * @param inStock  A 2d integer array to be initialzed that has 10 rows and 4 columns.
 */
void copyGamma(const int gamma[4], int inStock[10][4]) {

    for (int row = 0; row < 10; row++) {

        for (int col = 0; col < 4; col++) {

            if (row == 0) {  // The first row.

                // Set the elements of the first row of inStock to gamma.
                inStock[ row ][ col ] = gamma[ col ];

            } else {       // The remaining rows.

                // Set the remaining rows to three times the previous row of inStock.
                inStock[ row ][ col ] = inStock[ row - 1 ][ col ] * 3;

            }
        }
    }
}


/** e)
 * Store alpha into the first five rows of inStock and beta into the last five rows of inStock.
 * @param alpha    An integer array with 20 elements (read-only)
 * @param beta     An integer array with 20 elements (read-only)
 * @param inStock  A 2d integer array to be initialzed that has 10 rows and 4 columns.
 */
void copyAlphaBeta(const int alpha[20], const int beta[20], int inStock[10][4]) {

    int row, col;

    // the first five rows -> Store alpha
    row = 0;
    col = 0;
    for (int index = 0; index < 20; index++) {

        col = index % 4;     // 0,1,2,3,0,1,2,3,0,1,...

        inStock[ row ][ col ] = alpha[ index ];

        if (col == 3) row++; // Update row when col is 3
    }

    // the last five rows -> Store beta
    col = 0;
    for (int index = 0; index < 20; index++) {

        col = index % 4;     // 0,1,2,3,0,1,2,3,0,1,...

        inStock[ row ][ col ] = beta[ index ];

        if (col == 3) row++; // Update row when col is 3
    }
}


/** f)
 * Print a one-dimensional array of type int. Print 15 elements per line.
 * @param numberList
 * @param size
 */
void printArray(int* numberList, int size) {

    for (int index = 0; index < size; index++) {

        cout << setw(2) << numberList[ index ] << " ";

        if (index % 15 == 14) cout << "\n";

    }

    cout << endl;  // Move to next line.
}


/** g)
 * Prompt the user to input the elements for the first column of inStock.
 * Set the elements in the remaining columns to two times the corresponding element
 * in the previous column, minus the corresponding element in delta.
 * @param delta   An integer array with 10 elements (read-only)
 * @param inStock A 2d integer array to be initialzed that has 10 rows and 4 columns.
 */
void setInStock(const int delta[10], int inStock[10][4]) {

    int temp = 0;
    bool isAccepted;

    // The prompt message.
    cout << "Enter 10 numbers for the first column of inStock: " << endl;

    for (int row = 0; row < 10; row++) {

        isAccepted = false;
        while ( ! isAccepted ) {

            // Read the user's input.
            cout << "  Row#" << setw(2) << row << ": ";
            cin >> temp;

            // Ensure that the input was valid.
            if ( cin.fail() ) {

                cout << "Invalid input" << endl;
                cin.clear();            // Restore input stream.
                cin.ignore(100, '\n');  // Clear the buffer.

            } else {  // Success

                // The first column of inStock (col#0)
                inStock[ row ][ 0 ] = temp;  // User's input.

                // The elements in the remaining columns (col#1..3)
                for (int col = 1; col < 4; col++) {

                    // Two times the corresponding element in the previous column
                    // Minus the corresponding element in delta.
                    inStock[ row ][ col ] = (inStock[ row ][ col - 1 ] * 2)
                                            - delta[ col ];
                }

                isAccepted = true;

            } // end if
        } // end while
    } // end for
} // end function


/** (additional)
 * Print a two-dimensional array of type int with 4 columns.
 * @param numberList two-dimensional array of type int with 4 columns
 * @param num_rows
 */
void print2DArray(int numberList[][4], int num_rows) {

    for (int row = 0; row < num_rows; row++) {

        for (int col = 0; col < 4; col++) {

            cout << setw(10) << numberList[ row ][ col ] << " ";

        }

        cout << endl;  // Move to next line.
    }

    cout << endl;      // Insert a blank line.
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * @return
 */
int main() {

    int inStock[10][4];
    int alpha[20];
    int beta[20];
    int gamma[4]  = { 11, 13, 15, 17 };
    int delta[10] = { 3, 5, 2, 6, 10, 9, 7, 11, 1, 8 };

    // h) Call each of the functions in parts a through g.

    // Initialize arrays.
    setZero(alpha, 20);
    cout << "\n-- After setZero(alpha, 20); --\n" << endl;
    cout << "[alpha]" << endl;
    printArray(alpha, 20);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    setZero(beta,  20);
    cout << "\n-- After setZero(beta,  20); --\n" << endl;
    cout << "[beta]" << endl;
    printArray(beta,  20);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    inputArray(alpha);
    cout << "\n-- After inputArray(alpha) --\n" << endl;
    cout << "[alpha]" << endl;
    printArray(alpha, 20);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    doubleArray(alpha, beta);
    cout << "\n-- After doubleArray(alpha, beta) --\n" << endl;
    cout << "[beta]" << endl;
    printArray(beta, 20);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    copyGamma(gamma, inStock);
    cout << "\n-- After copyGamma(gamma, inStock) --\n" << endl;
    cout << "[inStock]" << endl;
    print2DArray(inStock, 10);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    copyAlphaBeta(alpha, beta, inStock);
    cout << "\n-- After copyAlphaBeta(alpha, beta, inStock) --\n" << endl;
    cout << "[inStock]" << endl;
    print2DArray(inStock, 10);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    setInStock(delta, inStock);
    cout << "\n-- After setInStock(delta, inStock) --\n" << endl;
    cout << "[inStock]" << endl;
    print2DArray(inStock, 10);

    return 0;
}

/* OUTPUT

-- After setZero(alpha, 20); --

[alpha]
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


-- After setZero(beta,  20); --

[beta]
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Enter 20 numbers:

  # 0: 0
  # 1: 1
  # 2: 2
  # 3: 3
  # 4: 4
  # 5: 5
  # 6: 6
  # 7: 7
  # 8: 8
  # 9: 9
  #10: 0
  #11: 1
  #12: 2
  #13: 3
  #14: 4
  #15: 5
  #16: 6
  #17: 7
  #18: 8
  #19: 9

-- After inputArray(alpha) --

[alpha]
 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
 5  6  7  8  9

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


-- After doubleArray(alpha, beta) --

[beta]
 0  2  4  6  8 10 12 14 16 18  0  2  4  6  8
10 12 14 16 18

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


-- After copyGamma(gamma, inStock) --

[inStock]
        11         13         15         17
        33         39         45         51
        99        117        135        153
       297        351        405        459
       891       1053       1215       1377
      2673       3159       3645       4131
      8019       9477      10935      12393
     24057      28431      32805      37179
     72171      85293      98415     111537
    216513     255879     295245     334611


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


-- After copyAlphaBeta(alpha, beta, inStock) --

[inStock]
         0          1          2          3
         4          5          6          7
         8          9          0          1
         2          3          4          5
         6          7          8          9
         0          2          4          6
         8         10         12         14
        16         18          0          2
         4          6          8         10
        12         14         16         18


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter 10 numbers for the first column of inStock:
  Row# 0: 12
  Row# 1: 23
  Row# 2: 34
  Row# 3: 45
  Row# 4: 56
  Row# 5: 67
  Row# 6: 78
  Row# 7: 89
  Row# 8: 90
  Row# 9: 12

-- After setInStock(delta, inStock) --

[inStock]
        12         19         36         66
        23         41         80        154
        34         63        124        242
        45         85        168        330
        56        107        212        418
        67        129        256        506
        78        151        300        594
        89        173        344        682
        90        175        348        690
        12         19         36         66

Program ended with exit code: 0
 */
