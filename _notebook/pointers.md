# Pointers
- [Why should I use a pointer rather than the object itself?](http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself)
- An array is a constant pointer.
    - We cannot change its memory address.

==

## Variables and Memory

- When declaring a variable, the computer associates the variable name with a particular location in memory and stores a value there.
- When refering to the variable by name , the computer must take two steps:
    + 1. Look up the address that the variable name corresponds to
    + 2. Go to that location in memory and retrieve or set the value it contains

==

## `*` and `&`

### The` *` operator is used in two different ways:
1. Used to declare a pointer.
2. Used to dereference a pointer that has been set to point to some value.

### The `&` operator (used in two different ways)
1. to indicate a reference data type (as in int &x;)
2. to take the address of a variable (as in int *ptr = &x;)

### vector insert/erase performance problem

- For vectors with thousands of elements, a single call to insert() or erase() can require thousands of instructions, so a program with many inserts or erases on large vectors may run very slowly

==

## initializing the pointer to 0
- 0, NULL, nullptr keyword
- Used to indicate that the pointer variable points to nothing
- initialize the pointer to 0, avoiding use of NULL
- C++ creator Bjarne Stroustrup's advice: "In C, it has been popular to define a macro NULL to represent the zero pointer. Because of C++'s tighter type checking, the use of plain 0, rather than any suggested NULL macro, leads to fewer problems."
- the nullptr keyword (see Wikipedia: C++11) in newer versions of the C++ standard would be even better, but is not yet supported by many C++ compilers

==

## Operators: `new`, `delete`, and `->`

```cpp
  // Declare a double pointer.
  double* dp;

  // Allocate memory for a double value and assign its address to the pointer.
  dp = new double;

  // Deallocate the memory location that dp points to.
  delete dp;
```

### The `new` operator
- Allocates memory for the given type and returns a pointer(i.e., the address) to that allocated memory
- returns 0 if the operator failed to allocate memory

```cpp
pointerVariable = new type;
```

###` ->`: member access operator

Accesses a class's member functions by first dereferencing a pointer

```cpp
a->b   // Equivalent to (*a).b
```

### The `delete` operator
- does the opposite of the new operator
- deallocates a memory block pointed to by a pointer variable, which must have been previously allocated by new
- Dereferencing a pointer whose memory has been deallocated is a common error, and may cause strange program behavior that is difficult to debug

```cpp
delete pointerVariable;
```

==

## Deep copy v Shallow copy

```cpp
// We have two instances of Bus.
Bus bolt;
Bus metro;

// Create a passenger to metro.
metro.pas = new Passenger;

// Shallow copy - Both pointing to the same object.
bolt = metro;
```

==

## Misc.

```cpp
Bus busses[10];  // Array is a constant pointer.
Bus* d13;

// We can assign an array to a pointer.
d13 = busses;  // OK

busses = d13;  // NG - busses is a constant pointer.

// These are synonymous.
d13[5]    = new Passenger;
busses[5] = new Passenger;

//-------------------------------------------

Passenger* folks[12];  // An array of pointers.

//-------------------------------------------
```

```cpp
/**
 * Pointer experiments
 * Created by Masatoshi Nishiguchi on 2/4/16.
 */
#include <iostream>
using namespace std;

int main() {

    int aInt = 24;
    int* ip = &aInt; // aInt and ip now reference the same mermory location.


    cout << "Value:             " << aInt << endl;
    cout << "Value's Address:   " << ip << endl;
    cout << "Pointer's value:   " << &aInt << endl;

    // Change the value of the int variable.
    // *ip = 99  // Error: Cannot assign to a pointer.
    *ip = 99;

    cout << "Value:             " << aInt << endl;
    cout << "Value through ip: " << *ip << endl;

    cout << endl;

    // ============================================== //

    int* ip2;
    ip2 = &aInt;  // Now ip2 also reference aInt's location.

    *ip2 = 18;

    cout << "Value:             " << aInt << endl;

    cout << endl;

    // ============================================== //

    double* dp;

    // dp = &aInt;  // Error: cannnot assign address of int to a double pointer.

    // ============================================== //

    // dp1: double pointer, dp2: double, dp3: double
    // Only the first one becomes a pointer.
    double* dp1, dp2, dp3;

    // ============================================== //


    return 0;
}
```


```cpp
  int ages[] = { 23, 6, 39, 2 };

  cout << *(ages)     << endl;  // [0]
  cout << *(ages + 1) << endl;  // [1]
  cout << *(ages + 2) << endl;  // [2]
  cout << *(ages + 3) << endl;  // [3]
  cout << *(ages + 4) << endl;  // Out of bounds

  // C++ know the size of the data type.
  cout << "sizeof(ages):    " << sizeof(ages) << endl;
  cout << "sizeof(ages[0]): " << sizeof(ages[0]) << endl;
  cout << "sizeof(int):     " << sizeof(int)    << endl;
  cout << (long)(ages)     << endl;
  cout << (long)(ages + 1) << endl;
```
