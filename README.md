# cpp_practice_code

- This repo is for me to practice the c++ programming.
- I write notes on what I learned for future reference.

==

## std::cin vs std::cin.getline

|   |   |   |
|---|---|---|
|std::cin         |getting first word| |
|std::cin.getline |getting line      |[doc](http://www.cplusplus.com/reference/string/string/getline/)|

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

#### push_back(newChar)
- Appends newChar to the end.       

#### append(moreString)
- Appends a copy of string moreString. 
      
#### str1 + str2
- Returns a new string having str1 with str2 appended. str1 may be a string variable or string literal (or a character array variable). Likewise for str2. One of str1 or str2 (not both) may be a character.

#### insert(indx, subStr)
- Inserts string subStr starting at index indx.       

#### replace(indx, num, subStr)
- Replaces characters at indices indx to indx+num with a copy of subStr. subStr's length does not have to be the same as num.       

#### clear()
- Deletes characters, sets size to 0.         

#### resize(newLength)
- Resize string to have newLength characters. If decrease, drops extra chars. If increase, sets new chars to null ('\0', ASCII value 0).     

==

## Character operations

- Include the cctype library via `#include <cctype>`
- ctype stands for character type. The first c indicates the library is originally from the C language.
- [doc](http://www.cplusplus.com/reference/cctype/)

####isalpha(c)
- true if alphabetic: a-z or A-Z
```cpp
isalpha('x') // true
isalpha('6') // false
isalpha('!') // false
```

####isdigit(c)
- true if digit: 0-9. 
```cpp
isdigit('x') // false
isdigit('6') // true
```

####isspace(c)
- true if whitespace. 
```cpp
isspace(' ')  // true
isspace('\n') // true
isspace('x')  // false
```

####toupper(c)
- Uppercase version
```cpp  
toupper('a')  // A
toupper('A')  // A
toupper('3')  // 3
```

####tolower(c)
- Lowercase version 
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

## Data types

### Integer numeric data types

| Definition | Size | Supported number range | Standard-defined minimum size |
|---|---|---|---|
|char myVar;     |8 bits |-128 to 127                     |8 bits|
|short myVar;    |16 bits|-32,768 to 32,767               |16 bits|
|long myVar;     |32 bits|-2,147,483,648 to 2,147,483,647 |32 bits|
|long long myVar;|64 bits|-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |64 bits|
|int myVar;      |32 bits|-2,147,483,648 to 2,147,483,647 |16 bits|

### Floating-point numeric data types

|Definition | Size     |Supported number range |
|---|---|---|
|float x;   |  32 bits |-3.4x1038 to 3.4*1038  |
|double x;  |  64 bits |-1.7x10308 to 1.7*10308|

### Unsigned

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
// Define an int vector with 50 elements each initialized to 0
vector <int> myVector(50, 0); 
```

### Checking the current vector size

- `myVector.size()` returns the current size of myVector

```cpp
currentSize = sensorReadings.size();
```

### Resizing a vector

- Commonly, the size of a list of items is not known during a program's compile time
- a vector's size can be set or changed while a program is executing
- If the new size is larger, `resize()` adds elements at the end. If smaller, `resize()` deletes elements from the end.
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


### Functions dealing with a vector's back

#### void push_back(const int newVal);
- Creates a new element at the end of vector and assigns the given value to that element, thus increasing the vector's size by 1

```cpp
#include <vector>
//... 
// Can just declare it and add elements
vector<int> myVector;
myVector.push_back(2038);
myVector.push_back(2051);
myVector.push_back(2064);
```

#### int back();
- Returns value of vector's last element
- Vector is unchanged.

#### void pop_back(); 
- Removes the last element.
- returns void

### Vector copy operation
- The `=` operator conveniently performs an element-by-element copy of a vector
- The operation vctrB = vctrA resizes vctrB to vctrA's size, appending or deleting elements as needed.
- vctrB commonly has a size of 0 before the operation.

```cpp
vector<int> userVals(4);  // element values 44, 55, 66, 77
vector<int> newVals; // no element
newVals = userVals;  // element values 44, 55, 66, 77
```

### Vector equality operation
- the `==` operator conveniently compares vectors element-by-element
- `vctrA == vctrB` evaluates to true if the vectors are **the same size** AND **each element pair is equal**.

### Reversing a vector

```cpp
   // Reverse by swapping from outermost elements inwards until reaching the middle
   for (i = 0; i < (NUM_ELEMENTS / 2); ++i) {
      tmpValue = myVector.at(i);
      myVector.at(i) = myVector.at(NUM_ELEMENTS - 1 - i);
      myVector.at(NUM_ELEMENTS - 1 - i) = tmpValue;
   }
```

### Arrays vs vectors
- using vectors rather than arrays is good practice
- the compiler does not check for out of range indices, for neither arrays nor vectors.
- Vectors are safer because myVector.at(i) is checked during execution to ensure the index is within the vector's valid range (The program will throw an exception if the index is out of the vector's valid range.)
- Vectors can be accessed using brackets [], but brackets involve no range checking, so a good practice is to use .at() to access vector elements.

### begin and end

[doc](http://www.cplusplus.com/reference/vector/vector/begin/)

```cpp
// vector::begin/end
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```


==

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

## C string vs string type

### Char arrays / C strings

- Must end with a null character `\0`.
- Given a string literal, the compiler automatically appends a null character.
- Known as a null-terminated string.
- When printed, printing stops at the null character.
- Once a string is assigned, a C string cannot be assigned later. Functions exist to copy one string's characters to another.
- When iterating over a string, the loop should iterate until reaching the null character, rather than relying on index

```cpp
// the compiler automatically appends a null character
char movieTitle[20] = "Dragonball";
```

If a char array is initialized when declared, the char array's size may be omitted.
```cpp
// The compiler determines the size from the string literal
// in this case 9 + 1 (for the null character)
char userName[] = "Masatoshi";
```

### C++ string type

- accessible after `#include <string>`
- Help reduce errors and increase programmer convenience
- Yet legacy code uses C strings
- some commonly-used C++ functions only accept C strings as parameters (e.g., ofstream myfile; myfile.open ("somefile.txt");)
- C++ provides common functions for handling C strings, which can be used by  `#include <cstring>`. [[<cstring> doc](http://www.cplusplus.com/reference/cstring/)]

### Some C string modification functions

#### strcpy(destStr, sourceStr)
- Copies sourceStr (up to and including null character) to destStr.
-  a common error is to copy a source string that is too large, causing an out-of-range access in the destination string. 

#### strncpy(destStr, sourceStr, numChars)
- Copies up to numChars characters.
- Does not append a null character.
- [doc](http://www.cplusplus.com/reference/cstring/strncpy/)

#### strcat(destStr, sourceStr) 
- Copies sourceStr (up to and including null character) to end of destStr (starting at destStr's null character).`
- second parameter must be a string, not a single character.

#### strncat(destStr, sourceStr, numChars)
- Copies up to numChars characters to destStr's end, then appends null character.

### Some C string info functions

#### strchr(sourceStr, searchChar)
- stands for "string character"
- Returns NULL if searchChar does not exist in sourceStr.
- (Else, returns address of first occurrence). 
- NULL is defined in the cstring library.

#### size_t strlen(sourceStr) 
- Returns number of characters in sourceStr up to, but not including, first null character.
- size_t is integer type.

#### int strcmp(str1, str2) 
- Returns 0 if str1 and str2 are equal, non-zero if they differ.

==

## Classes

- good practice is to make ALL data members of a class private, using member functions to access that data
- good practice explicitly uses the public: and private: keywords for clarity, rather than relying on defaults
- [doc](http://www.cplusplus.com/doc/tutorial/classes/)

```cpp
// Declare a member function named GetSalary, not changing the value of any data member.
int GetSalary() const; 
```
- keyword const informs the class user and compiler that the function won't change any data member values.

```cpp
// the first line of a function definition for the member function SetSalary
void Employee::SetSalary(int salaryAmount) {
   ...
}
// - Just like a normal function definition, except the function name has Employee:: prepended to tell the compiler this is a member function of class Employee.
```

```cpp
#include <iostream>
#include <cmath>
using namespace std;

class RightTriangle {
   public:
      void SetSide1(double side1Val);
      void SetSide2(double side2Val);
      double GetHypotenuse() const;

   private:
      double side1;
      double side2;
};

void RightTriangle::SetSide1(double side1Val) {
   side1 = side1Val;

   return;
}

void RightTriangle::SetSide2(double side2Val) {
   side2 = side2Val;
   return;
}

double RightTriangle::GetHypotenuse() const {

   return sqrt((side1 * side1) + (side2 * side2));
}

int main() {
   RightTriangle triangleA;

   triangleA.SetSide1(3.0);
   triangleA.SetSide2(4.0);
   
   cout << "Hypotenuse: " << triangleA.GetHypotenuse() << endl;
   
   return 0;
}
```


## << flush

- The << flush forces cout to flush any characters in its buffer to the screen before doing each task, otherwise the characters may be held in the buffer until after a later task completes. 


