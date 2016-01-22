# Memo

## Char array

```cpp
// A string "Guy"
// Length: 4
// These are all synonymous:
char name[] = { 'G', 'u', 'y', 0 }; 
char name[] = { 'G', 'u', 'y', '\0' }; 
char name[] = "Guy";
char* name  = "Guy";

// Printing the name of the char array.
// NOTE: The array name of any other data types would print its memory address.
// But char array is special. It prints the entire string.
cout << "Printing name        : " << name << endl; //==> Guy

int nums[5] = { 1, 2, 3, 4, 5 };
cout << "Printing nums        : " << nums << endl;

// Printing the memory address.
cout << "Printing (void *)name: " << (void *)name << endl; //==> 0x7fff5fbff818

// Printing a single character.
cout << "Printing *name       : " << *name << endl; //==> G
```


## The string type
- not a built-in type

```cpp
string myName = "Masatoshi";
```

## ENUM
-  used for better readability.

```cpp
#include <iostream>
using namespace std;

// Enum is used for better readability.
enum PEOPLE { PERSON_1, PERSON_2, PERSON_3}; // Use instead of 0..2
enum REGION { REGION_1, REGION_2 };          // Use instead of 0..1

int main() {
     double sales[3][2];

     sales[PERSON_1][REGION_1] = 23.2;
     sales[PERSON_1][REGION_2] = 87.66;
     sales[PERSON_2][REGION_1] = 96.3;
     sales[PERSON_2][REGION_2] = 34.6;
     sales[PERSON_3][REGION_1] = 2;
     sales[PERSON_3][REGION_2] = 102.4;

    // ...

    return 0;
}
```
