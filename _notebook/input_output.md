# input and output
- The variables cin and cout are automatically defined and associated with teh standard input/output devices
- This is not the case for file stream variables. We must declare variables, which include ifstream variables for input and ofstream variables for output

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

==

## Valid Input for a Variable of the Simple Data Type

### char
- One printable character except the blank

### int
- An integer (possibly preceded by a +/- sign)

### double
- A decimal number (possibly preceded by a +/- sign)
- If the actual data input is an integer, the input is converted to a decimal number with the zero decimal part.

==

## Some functions

### cin
- Inputs first word

### Reading a single character, incl. whitespace
- `cin.get(varChar)`
- Inputs the very next character, incl. whitespace characters, from the input stream.
- Stores it in memory loacation indicated by its argment.

```cpp
// User's input: A 25
char ch1, ch2;
cin.get(ch1);  // 'A'
cin.get(ch2);  // ' '
cin > num;     // 25
```

### Reading a whole line
- `getline(istream&  is, string& str)`
- Inputs a line
- Reads until it reaches the end of the current line
- The newline character is also read but not stored in the string variable
- [doc](http://www.cplusplus.com/reference/string/string/getline/)

```cpp
// User's input: "    Hello, anybody there?"
string myLine;
getline(cin, myLine);  // myLine: "    Hello, anybody there?"
```

```cpp
    // Output all uppercase letters
    
    cout << "\nEnter a sentence: ";

    // Read a line
    getline(cin, input);

    // Iterate over the line and print all the uppercase letters
    len = (int)input.length();
    for (idx = 0; idx < len; idx++) {
        if (input[idx] >= 'A' && input[idx] <= 'Z') {  // Uppercase
            cout << input[idx] << " ";
        }
    }
    cout << endl;
```

### Reading a string
- `getline(istream&  is, string& str, char delim)`
- Extracts characters from istream and stores them into str until the delimitation character delim is found

```cpp
// User's input: "Masatoshi Nishiguchi 1234"
string firstName;
getline(inFile, firstName, ' ');  // firstName: "Masatoshi" 
```

### Reading a whole line and extracting data from it
- `#include <sstream>`

```cpp
    // Read each line from the file
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        ss >> firstName >> lastName >> currentSalary >> payIncreasePercentage;
        
        //...
    }
```

### cin.ignore(intExp, chExp)
- Discards a portion of the input

```cpp
// Ignores either the next 100 characters or
// all characters until the newline character is found.
cin.ignore(100, '\n');
```

```cpp
cin.ignore(100, 'A');
```

### Prompt the user for an arbitrary number of elements

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

## The putback and peek functions
### istreamVar.putback(ch);
- Put the last character extracted from the input stream by the `get(varChar)` function back into the input stream.

### istreamVar.peek(ch);
- Returns the next character from the input stream but does not remove the character from that stream.
- Used to check the next input without removing it from the input stream.

==

## Input failure
1. Occurs when attempting to read invalid data
2. The input stream enters the fail state
3. All further I/Ostatements using that stream are ignored
4. The program quietly continues to execute with whatever values are stored in variables and produces incorrect results 

Note: Restore the input stream by calling `istreamVar.clear()`

==

## istreamVar.clear();

- Restores the input stream to a working state
- Still need to clear the rest of the garbage from the input stream by using `ignore(intExp, chExp)`

```cpp
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numColumns;
    
    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer
```

==

## cin.fail()
- returns true if the input stream encounters errors, most commonly which happens due to reading incorrect data type.

```cpp
int i;
cin >> i;

if(cin.fail()) {
  // error handling
  cout << "Error reading input" << endl;
}
```

```cpp
int num;
cin >> num;  // Read a number

if (!cin) {  // If cin is in a bad state
    cin.clear();
    cin.ignore(1024, '\n');
}
```

==

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

==

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
- E.g., `12.34`

#### scientific
- Use scientific notation.
- From `<ios>`
- E.g., `1.234e+01`

#### setprecision(p)
- From `<iomanip>`
- http://www.cplusplus.com/reference/iomanip/setprecision/

##### Case1: If stream has NOT been manipulated to fixed or scientific
- Sets max number of digits in number
- **applies to entire number**
- E.g., p=3 yields `12.3`
- E.g., p=5 yields `12.34`

```cpp
cout << setprecision(3);
```

##### Case2: If stream has been manipulated to fixed or scientific
- Sets max number of digits **in fraction only (after the decimal point)**
- E.g., fixed: p=1 yields `12.3`
- E.g., scientific: p=1 yields `1.2e+01`

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
    + `99` (default or noshowpoint)
    + `99.00` (showpoint)

#### setw(n)
- Sets the number of characters **for the next output item only**
- (does not persist, in contrast to other manipulators).
- By default, the item will be right-aligned, and filled with spaces.
- From `<iomanip>`
- E.g., For n=7: `"    Amy"`

#### setfill(c)
- Sets the fill to character c. 
- From `<iomanip>`
- E.g., For c=`'*'`: `"****Amy"`

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
- also, `cout.setf(ios::left)` and `cout.unsetf(ios::left)`
- E.g., `"Amy    "`

```cpp
cout << left;
```

#### right
- Changes back to right alignment. 
- From `<ios>`
- also, `cout.setf(ios::left)` and `cout.unsetf(ios::left)`
- E.g., `"    Amy"`

```cpp
cout << right;
```

#### endl
- Inserts a newline character `'\n'` into the output buffer
- **informs the system to flush the buffer**
- From `<iostream>`

#### flush
- Informs the system to flush the buffer
- Flushes any characters in its buffer to the screen before doing each task, otherwise the characters may be held in the buffer until after a later task completes. 
- From `<iostream>`

```cpp
cout << "  Resizing vector..." << flush;
```
