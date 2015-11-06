# cpp_practice_code

- This repo is for me to practice the c++ programming.
- I write notes on what I learned for future reference.

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

## Operator overloading

- http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

==

## Ternary operator
- https://en.wikipedia.org/wiki/%3F:#C.2B.2B

```cpp
if (amount1 > amount2) {
    cout << amount1 << endl;
} else {
    cout << amount2 << endl;
}

cout << (amount1 > amount2 ? amount1 : amount2);
```

==

## Calling constructor and destructor explicitly
- http://www.geeksforgeeks.org/possible-call-constructor-destructor-explicitly/


