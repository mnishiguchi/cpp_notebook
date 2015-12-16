# arrays

- For non-dynamic arrays, whenever we declare an array, its size must be known.
- cf. dynamic arrays: Arrays that are created by using pointers during program execution

## Array Initialization During Declaration

```cpp
double sales[5] = { 12.25, 32.50, 16.90, 23, 45.68 };  // Good.
```

```cpp
// The size is determined by the number of initial values in the braces.
// Although it is not necessary to specify the size of the array if it is
// initialized during declaration, it is a good practice to do so.
double sales[] = { 12.25, 32.50, 16.90, 23, 45.68 };  // Good.
```

## Partial Initialization of Arrays During Declaration
- When we declare and initialize an array simultaneously, we do not need to initialize all components of the array.
```cpp
// Declares list to be an array of 10 components and
// initializes all of the components to 0.
int list[10] = { 0 };
```

```cpp
// Declares list to be an array of 25 components.
// The first two components are initialized to 4 and 7, respectively, and
// all other components are initialized to 0.
int list[25] = { 4, 7 };
```

```cpp
// When we partially initialize an array, then all of the elements that
// follow the last uninitialized elements must be uninitialized.
int list[10] = {2, 5, 6, , 8}; //  syntax error
```

## Array size
```cpp
// Bad example.
// 1. Not initialized.
// 2. Size must be a constant.
int arraySize;
string names[ arraySize ];

// Good example.
const int arraySize = 10;
string names[ arraySize ];
```

```cpp
// Bad example.
// when the compiler compiles Line 5, the size of the array is unknown and
// the compiler will not know how much memory space to allocate for the array.
int arraySize;
cout << "Enter the size of the array: ";
cin >> arraySize;
cout << endl;

int list[ arraySize ];  // not allowed
```

## Arrays as Parameters to Functions
- In C++, arrays are passed by reference only.
- NOTE: Because arrays are passed by reference only, we do not use the symbol `&` when declaring an array as a formal parameter.
- When declaring a one-dimensional array as a formal parameter, the size of the array can be omitted.

```cpp
void initialize(int list[], int listSize) {

    int count;
    for (count = 0; count < listSize; count++) {
        list[count] = 0;      
    }
}
```

## Constant Arrays as Formal Parameters
- Prevent the function from changing the actual parameter
- Any attempt to change constant results in a compile-time error.
- It is a good programming practice to declare an array to be constant as a formal parameter if we do not want the function to modify the array.

## The reason why arrays are passed by reference only
- If C++ allowed arrays to be passed by value, the computer would have to allocate memory for the components of the formal parameter and copy the contents of the actual array into the corresponding formal parameter when the function is called. If the array size was large, this process would waste memory as well as the computer time needed for copying the data. That is why in C++ arrays are always passed by reference.

## Functions Cannot Return a Value of the Type Array
- C++ does not allow functions to return a value of the type array.

## Arrays with enum
- Integral Data Type that can be used for array indices.
- Greatly enhance a program’s readability.

```cpp
enum paintType { GREEN, RED, BLUE, BROWN, WHITE, ORANGE, YELLOW };

double paintSale[7];
paintType paint;

// initializes each component of the array paintSale to 0:
for (paint = GREEN;
     paint <= YELLOW;
     paint = static_cast<paintType>( paint + 1 ) ) {

    paintSale[ paint ] = 0.0;
}


```

## Checking if a character array is empty
```cpp
if (text[ 0 ] == '\0') {}
```

## Two-dimensional arrays

```cpp
// Defining a two dimensional array of integers
int numVals[2][3];
```

```cpp
// Initializing a 2D array
int numVals[2][3] = { {22, 44, 66}, {97, 98, 99} };
```

```cpp
// Use multiple lines to make rows more visible
int numVals[2][3] = {
   {22, 44, 66}, // Row 0
   {97, 98, 99}  // Row 1
};
```

==

## Dynamic 2D arrays

```cpp
// Pointer to the 2D array
int** board;

// Decide on the size
int numRows;
int numColumns;

// Create rows
board = new int* [numRows];  // Create an array of int pointers

// Create columns for each row
for (int row = 0; row < numRows; row++) {
    // For each row, create an int array
    board[row] = new int[numColumns];
}
```

==

## Initialiing an array to NULL
- http://stackoverflow.com/questions/629017/how-does-array100-0-set-the-entire-array-to-0
```cpp
// C++ empty initializer
char aArray[100] = {};
```

==

## Passing a 2D array to a C++ function
- http://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
- When passing an array to a function, it is common to pass array size so that function knows how many elements to process. 

```cpp
void showScores(int [], int);          // function prototype
void showScores(int tests[], int size) // function header
```

## const Parameters
- Put the const keyword before the array parameter to tell the compiler that the array cannot be changed.
The compiler will report errors if the code in the function attempts to modify the array.
```cpp
void p(const int list[], int arraySize)
```

## Returning an Array from a Function 
- Not allowed in C++

```cpp
// Bad example.
int[] reverse(const int list[], int size)               // NG

// Good example.
void reverse(const int list[], int newList[], int size) // GOOD
```

## Prompt the user for an arbitrary number of elements

```cpp
/**
 * Prompts the user for numbers up to the specified maximum count.
 * @param numbers    An array of double-type numbers in which user's inputted
 *                   numbers are to be stored.
 * @param itemCount  An variable in which we record how many numbers the user enter.
 * @param MAX_COUNT  The maximum count of the numbers we can accept as input.
 */
void inputNumbers(double* numbers, int& itemCount, const int MAX_COUNT) {

    // The prompt message.
    cout << "Enter numbers (Max: " << MAX_COUNT << ", q: quit)" << endl;

    // Accept numbers until max 100 is reached or cin enters fail state.
    itemCount = 0;

    for ( int i = 0; i < MAX_COUNT; i++ ) {

        cout << ">>> ";
        cin >> numbers[ i ];

        // If input is valid, increment the counter.
        if ( cin.fail() || itemCount == MAX_COUNT - 1 ) {

            break;

        } else {

            itemCount += 1;

        }
    }
}
```

==

## Library arrays
- http://www.cplusplus.com/doc/tutorial/arrays/
- both kinds of arrays use the same syntax to access its elements: myarray[i]. Other than that, the main differences lay on the declaration of the array, and the inclusion of an additional header for the library array. Notice also how it is easy to access the size of the library array.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {

  array<int,3> myarray { 10, 20 ,30 };

  for (int i = 0; i < myarray.size(); ++i) {
    ++myarray[i];
  }

  for (int elem : myarray) {
    cout << elem << '\n';
  }

}
```
