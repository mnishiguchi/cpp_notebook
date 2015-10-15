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
