# arrays

## Checking if a character array is empty
```cpp
if(text[0] == '\0') {}
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




