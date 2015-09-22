# input and output

## std::cin vs std::cin.getline

### std::cin
- getting first word

### std::cin.getline
- getting line
- [doc](http://www.cplusplus.com/reference/string/string/getline/)

## istreamVar.clear();

- Restores the input stream to a working state
- Still need to clear the rest of the garbage from the input stream by using the function ignore

```cpp
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numColumns;
    
    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer
```

## << flush

- The << flush forces cout to flush any characters in its buffer to the screen before doing each task, otherwise the characters may be held in the buffer until after a later task completes. 

```cpp
cout << "  Resizing vector..." << flush;
```

## The ostream and cout streams

### ostream
- short for "output stream"
- a class that supports output
- available via `#include <iostream>` and in namespace "std".
- provides the << operator, known as the insertion operator, for converting different types of data into a sequence of characters
- That sequence is normally placed into a buffer, and the system then outputs the buffer at various times.

### cout
- a predefined ostream object
- pre-associated with a system's standard output, usually a computer screen. 

### The << operator
- known as the insertion operator
- overloaded with functions to support the various standard data types, such as int, bool, float, etc., each function converting that data type to a sequence of characters
- may be further overloaded by the string library from `#include <string>` or by the programmer for programmer-created classes
- returns a reference to the ostream that called it
- evaluated from left to right like most operators
- [doc](http://www.cplusplus.com/reference/ostream/ostream/)


## The istream and cin streams

### istream
- short for "input stream"
- a class that supports input
- Available via '#include <iostream>'

### the >> operator
- known as the extraction operator
- to extract data from a data buffer and to write the data into different types of variables

### cin
- a predefined istream
- pre-associated with a system's standard input, which is usually a computer keyboard
- The system automatically puts the standard input into a data buffer associated with cin, from which >> can extract data
- [doc](http://www.cplusplus.com/reference/istream/istream/)

## Output formatting
- adjust the way that output appears

### manipulator
- an item designed to be used with the insertion operator << or extraction operator >>
- adjusts the way output appears
- available via `#include <iomanip>` or `#include <ios>` in `namespace std`
- the manipulation affects all subsequent output, not just the next output (The exception is setw(), which only affects the next output item)
- Manipulating floating-point output is commonly done
- [doc](http://www.cplusplus.com/reference/ios/)

```cpp
// causes the floating-point variable myFloat to be output with only 3 digits; // if myFloat was 12.34, the output would be 12.3
cout << setprecision(3) << myFloat;
```

#### fixed
- Use fixed-point notation.
- From `<ios>`
- E.g., 12.34

#### scientific
- Use scientific notation.
- From `<ios>`
- E.g., 1.234e+01

#### setprecision(p)
- From `<iomanip>`

##### If stream has NOT been manipulated to fixed or scientific:
- Sets max number of digits in number
- **applies to entire number**
- E.g., p=3 yields 12.3
- E.g., p=5 yields 12.34

```cpp
cout << setprecision(3);
```

##### If stream has been manipulated to fixed or scientific:
- Sets max number of digits **in fraction only (after the decimal point)**
- E.g., fixed: p=1 yields 12.3
- E.g., scientific: p=1 yields 1.2e+01

```cpp
#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

int main() {
   double outsideTemperature = 103.45632;
    
   //  prints outsideTemperature with 2 digits in the fraction
   cout << fixed << setprecision(2) << outsideTemperature << endl;

   return 0;
}
```

```cpp
cout << scientific << setprecision(2);
```

#### showpoint
- Even if fraction is 0, show decimal point and trailing 0s. 
- Opposite is `noshowpoint`. 
- From `<ios>`
- E.g., For 99.0 with precision=2 and fixed: 
    + 99 (default or noshowpoint)
    + 99.00 (showpoint)

#### setw(n)
- Sets the number of characters **for the next output item only**
- (does not persist, in contrast to other manipulators).
- By default, the item will be right-aligned, and filled with spaces.
- From `<iomanip>`
- E.g., For n=7: "    Amy"

#### setfill(c)
- Sets the fill to character c. 
- From `<iomanip>`
- E.g., For c='*': "****Amy"

```cpp
// creating a line of 30 asterisks, without having to type 30 asterisks
cout << setfill('*') << setw(30) << "" << endl;

void drawLine() {
    cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;
}

void drawLine(char c, int n) {
    cout << setfill(c) << setw(n) << "" << setfill(' ') << endl;
}
```

#### left
- Changes to left alignment. 
- From `<ios>`
- E.g., "Amy    "

#### right
- Changes back to right alignment. 
- From `<ios>`
- E.g., "    Amy"

#### endl
- Inserts a newline character '\n' into the output buffer
- **informs the system to flush the buffer**
- From `<iostream>`

#### flush
- Informs the system to flush the buffer
- From `<iostream>`


