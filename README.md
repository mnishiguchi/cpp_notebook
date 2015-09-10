# cpp_practice_code

==

##  String info functions

|   |   |   |
|---|---|---|
|`at(indx)`   |Accesses the character at a particular index of a string.||
|`length()`   |Number of characters|   |
|`size()`     |Number of characters|   |
|`empty()`    |true if length is 0 |   |
|`find(item)` |Returns index of first item occurrence, else returns string::npos, which is defined with a value of -1. Item may be char, string variable, string literal or char array find(item, indx) starts at index indx.|[doc](http://www.cplusplus.com/reference/string/string/find/)|
|`substr(indx, len)` |Returns substring starting at index and having len characters.|[doc](http://www.cplusplus.com/reference/string/string/substr/)|


### Check if a string contains a certain word.

[`string::find`](http://www.cplusplus.com/reference/string/string/find/)

```cpp

// Print "Censored" if userInput contains the word "darn",
// else print userInput. End with newline. 

#include <iostream>
#include <string>
using namespace std;

int main() {
   string userInput;

   // userInput = "That darn cat.";
   cin >> userInput;

   if (userInput.find("darn") == -1) {
      cout << userInput << endl;
   }
   else {
      cout << "Censored" << endl;
   }

   return 0;
}
```

==

## String modify operations

|   |   |   |
|---|---|---|
|push_back(newChar) |Appends newChar to the end.|   |
|append(moreString) |Appends a copy of string moreString.|   |
|str1 + str2 |Returns a new string having str1 with str2 appended. str1 may be a string variable or string literal (or a character array variable). Likewise for str2. One of str1 or str2 (not both) may be a character.|   |
|insert(indx, subStr) |Inserts string subStr starting at index indx.|   |
|replace(indx, num, subStr) |Replaces characters at indices indx to indx+num with a copy of subStr. subStr's length does not have to be the same as num.|   |
|clear() |Deletes characters, sets size to 0.  |   |
|resize(newLength) |Resize string to have newLength characters. If decrease, drops extra chars. If increase, sets new chars to null ('\0', ASCII value 0).| |

==

## Character operations

- Include the cctype library via `#include <cctype>`
- ctype stands for character type. The first c indicates the library is originally from the C language.
- [doc](http://www.cplusplus.com/reference/cctype/)

isalpha(c)  true if alphabetic: a-z or A-Z
```cpp
isalpha('x') // true
isalpha('6') // false
isalpha('!') // false
```

isdigit(c)  true if digit: 0-9. 
```cpp
isdigit('x') // false
isdigit('6') // true
```

isspace(c)  true if whitespace. 
```cpp
isspace(' ')  // true
isspace('\n') // true
isspace('x')  // false
```

toupper(c)  Uppercase version
```cpp  
toupper('a')  // A
toupper('A')  // A
toupper('3')  // 3
```

tolower(c)  Lowercase version 
```cpp  
tolower('A')  // a
tolower('a')  // a
tolower('3')  // 3
```

==

## Floating-point comparison

- should not be compared using `==`
- set a threshould(e.g. 0.0001)
- `fabs()` computes floating-point absolute value

```cpp
// Determine if double variable x is 98.6.
fabs(x - 98.6) < 0.0001;
```

```cpp
// Determine if double variables x and y are equal. Threshold is 0.0001.
// (If difference is less than 0.0001, values are close enough.)
fabs(x - y) < 0.0001;
```

==

## Random numbers

e.g. Four dice rolls
```cpp
#include <iostream>
#include <cstdlib>     // Enables use of rand()
#include <ctime>       // Enables use of time()
using namespace std;

int main() {
   srand(time(0));     // "Seeds" the random number generator

   cout << "Four rolls of a dice..." << endl;

   // rand() % 6 yields 0, 1, 2, 3, 4, or 5
   // so + 1 makes that 1, 2, 3, 4, 5, or 6
   cout << ((rand() % 6) + 1) << endl;
   cout << ((rand() % 6) + 1) << endl;
   cout << ((rand() % 6) + 1) << endl;
   cout << ((rand() % 6) + 1) << endl;
   
   return 0;
}
```

==

## Integer numeric data types

| Definition | Size | Supported number range | Standard-defined minimum size |
|---|---|---|---|
|char myVar;     |8 bits |-128 to 127                     |8 bits|
|short myVar;    |16 bits|-32,768 to 32,767               |16 bits|
|long myVar;     |32 bits|-2,147,483,648 to 2,147,483,647 |32 bits|
|long long myVar;|64 bits|-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |64 bits|
|int myVar;      |32 bits|-2,147,483,648 to 2,147,483,647 |16 bits|

==

## Floating-point numeric data types

|Definition | Size     |Supported number range |
|---|---|---|
|float x;   |  32 bits |-3.4x1038 to 3.4*1038  |
|double x;  |  64 bits |-1.7x10308 to 1.7*10308|

==

## Unsigned

Sometimes a programmer knows that a variable's numbers will always be positive (0 or greater), such as when the variable stores a person's age or weight. The programmer can prepend the word "unsigned" to inform the compiler that the integers will always be positive. Because the integer's sign needs not be stored, the integer range reaches slightly higher numbers.

==

## math functions

- has about 20 math operations available for floating-point values
- `#include <cmath>`
- [doc](http://www.cplusplus.com/reference/cmath/)

```cpp
#include <iostream>
#include <cmath>
using namespace std;

// ...

double sideSquare = 0.0;
double areaSquare = 49.0;

sideSquare = sqrt(areaSquare);

```

==

## std::cin vs std::cin.getline

|   |   |   |
|---|---|---|
|std::cin         |getting first word| |
|std::cin.getline |getting line      |[doc](http://www.cplusplus.com/reference/string/string/getline/)|

==

## Pointers

### Variables and Memory

- When declaring a variable, the computer associates the variable name with a particular location in memory and stores a value there.
- When refering to the variable by name , the computer must take two steps:
    + 1. Look up the address that the variable name corresponds to
    + 2. Go to that location in memory and retrieve or set the value it contains

### * and &

#### The * operator (used in two different ways)
1. When declaring a pointer, indicates that the variable being declared is a pointer
2. When using a pointer that has been set to point to some value, dereferences it (accessing or setting the value it points to)

#### The & operator (used in two different ways)
1. to indicate a reference data type (as in int &x;)
2. to take the address of a variable (as in int *ptr = &x;)

==

## Vectors

- an ordered list of items of a given data type
- added to C++ as a safer and more powerful form of arrays
- #include <vector>
- `vector<dataType> identifier(numElements);`
- [Arrays vs Vectors](http://stackoverflow.com/a/15079462/3837223)

```cpp
// cf. Array
int myArray[100];
myArray[0] = 1;
myArray[1] = 2;
myArray[2] = 3;
```

```cpp
#include <vector>
//... 
vector<int> myVector(4);
myVector.at(0) = 1999;
myVector.at(1) = 2012;
myVector.at(2) = 2025;
```

```cpp
#include <vector>
//... 
// just declare it and add elements
vector<int> myVector;
myVector.push_back(2038);
myVector.push_back(2051);
myVector.push_back(2064);
// ...
```

```cpp
#include <vector>
//... 
// Define an int vector with 50 elements each initialized to 0
vector <int> myVector(50, 0); 
```

### Vector resize

- Commonly, the size of a list of items is not known during a program's compile time
- a vector's size can be set or changed while a program is executing
- If the new size is larger, resize() adds elements at the end. If smaller, resize() deletes elements from the end.
- Immediately after the definition, a vector has no element.
- [doc](http://www.cplusplus.com/reference/vector/vector/)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> userVals; // No elements yet
   int numVals = 0;
   int i = 0;
   
   cout << "Enter number of integer values: ";
   cin >> numVals;
   
   userVals.resize(numVals); // Allocate elements
   
   cout << "Enter " << numVals << " integer values..." << endl;
   for (i = 0; i < numVals; ++i) {
      cout << "Value: ";
      cin >> userVals.at(i);
   }
   cout << "You entered: ";
   for (i = 0; i < numVals; ++i) {
      cout << userVals.at(i) << " ";
   }
   cout << endl;
   
   return 0;
}
```

==










