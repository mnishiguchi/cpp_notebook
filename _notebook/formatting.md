# Output formatting

## printf()

- http://www.cplusplus.com/reference/cstdio/printf/

```cpp
    printf( "Characters: %c %c \n", 'a', 65 );
    printf( "Decimals: %d %ld\n", 1977, 650000L );
    printf( "Preceding with blanks: %10d \n", 1977 );
    printf( "Preceding with zeros: %010d \n", 1977 );
    printf( "Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100 );
    printf( "floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416 );
    printf( "Width trick: %*d \n", 5, 10 );
    printf( "%s \n", "A string" );
```

==

## manipulator
- An item designed to be used with the insertion operator << or extraction operator >>
- Adjusts the way output appears
- Available via `#include <iomanip>` or `#include <ios>` in `namespace std`
- The manipulation affects all subsequent output, not just the next output (The exception is setw(), which only affects the next output item)
- Manipulating floating-point output is commonly done
- [doc](http://www.cplusplus.com/reference/ios/)

```cpp
// causes the floating-point variable myFloat to be output with only 3 digits; // if myFloat was 12.34, the output would be 12.3
cout << setprecision(3) << myFloat;
```

### fixed
- Use fixed-point notation.
- From `<ios>`
- E.g., `12.34`

### scientific
- Use scientific notation.
- From `<ios>`
- E.g., `1.234e+01`

### setprecision(p)
- From `<iomanip>`
- http://www.cplusplus.com/reference/iomanip/setprecision/

#### Case1: If stream has NOT been manipulated to fixed or scientific
- Sets max number of digits in number
- **applies to entire number**
- E.g., p=3 yields `12.3`
- E.g., p=5 yields `12.34`

```cpp
cout << setprecision(3);
```

#### Case2: If stream has been manipulated to fixed or scientific
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
