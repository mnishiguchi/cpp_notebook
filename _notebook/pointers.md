# Pointers
- [Why should I use a pointer rather than the object itself?](http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself)
- IMPORTANT: An array is a constant pointer. We cannot change its memory address

==

## Variables and Memory

- When declaring a variable, the computer associates the variable name with a particular location in memory and stores a value there.
- When refering to the variable by name , the computer must take two steps:
    + 1. Look up the address that the variable name corresponds to
    + 2. Go to that location in memory and retrieve or set the value it contains

==

## The` *` operator
1. to declare a pointer
2. to dereference a pointer that has been set to point to some value

==

## The `&` operator
1. to indicate a reference data type (as in `int &x;`)
2. to take the address of a variable (as in `int *ptr = &x;`)
3. to create aliases to an object (as in `int x; int &y = x;`)

==

## vector insert/erase performance problem

- For vectors with thousands of elements, a single call to insert() or erase() can require thousands of instructions, so a program with many inserts or erases on large vectors may run very slowly

==

## Initializing the pointer to 0
- `0`, `NULL`, `nullptr`
- Used to indicate that the pointer variable points to nothing
- Initialize the pointer to 0, avoiding use of NULL
  + C++ creator Bjarne Stroustrup's advice: "In C, it has been popular to define a macro NULL to represent the zero pointer. Because of C++'s tighter type checking, the use of plain 0, rather than any suggested NULL macro, leads to fewer problems."
- The `nullptr` keyword (see Wikipedia: C++11) in newer versions of the C++ standard would be even better, but is not yet supported by many C++ compilers
- The number `0` is the only number that can be directly assigned to a pointer variable

```
int* p = nullptr;
```

==

## Dynamic variables

- Variables that are created during program excution
- When a program requires a new variable, the operator `new` is used
- When a program no longer neds a dynamic variable, the operator `delete` is used
- IMPORTANT: Because a dynamic variable is unnamed, it cannot be accessed directly. It is accessed indirectly by the pointer returned by `new`.

```cpp
  // Declare a double pointer.
  double* dp;

  // Allocate memory for a double value and assign its address to the pointer.
  dp = new double;

  // Deallocate the memory location that dp points to.
  delete dp;
```

--

### The `new` operator
- Allocates memory for the given type and returns a pointer (i.e., the address) to that allocated memory
- Returns 0 if the operator failed to allocate memory

```cpp
new DataType;            // Allocate a single variable
new DataType[ intExp ];  // Allocate an array of variables
                         // intExp: any expression evaluating to a positive integer
```

```cpp
pointerVariable = new type;
```

```cpp
  double* d_1;
  d_1 = new double(11);

  double* d_2 = new double;
  *d_2 = 22;

  cout << "d_1: "  << d_1 << endl;  // d_1: 0x100100020
  cout << "d_2: "  << d_2 << endl;  // d_2: 0x100102c80
  cout << "*d_1: " << *d_1 << endl; // *d_1: 11
  cout << "*d_2: " << *d_2 << endl; // *d_2: 22
```

--

### The `delete` operator
- Does the opposite of the `new` operator
- Deallocates a memory block pointed to by a pointer variable, which must have been previously allocated by `new`
- IMPORTANT: 
  + Dereferencing a pointer whose memory has been deallocated is a common error, and may cause strange program behavior that is difficult to debug
  + For the operator `delete` to work properly, the pointer must point to a valid memory space

```cpp
delete pointerVariable;    // Deallocate a single variable
delete[] pointerVariable;  // Deallocate an array of variables
                     
```

--

### Memory leak

When a dynamic memory space gets inaccessible, it cannot be freed of reallocated. This is called, memory leak. That is, there is an unused memory space that cannot be allocated.
- Precaution:
  - When a dynamic variable is no longer needed, deallocate its memory.

--

### Dangling pointers

The pointers that still containthe addresses of the deallocated memory spaces.
- Precaution:
  - Set pointers to `NULL` after the `delete` operation

--

###` ->`: member access operator

Accesses a class's member functions by first dereferencing a pointer

```cpp
a->b   // Equivalent to (*a).b
```

==

## Pointer arithmetic

- Different from the arithmetic operations on numbers
- The increment operator increments the value of a pointer variable by the size of the data type or structure to which it is pointing
- IMPORTANT:
  + Pointer arithmetic can be dangerous
  + The program can accidentally access the memory locations of other variables and change thir content without warning 

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

==

## Deep copy v Shallow copy

- **Shallow copy**: Two or more pointers of the same type point to the same memory; that is, they point to the same data.
- **Deep copy**: Two or more pointers of the same type point to their own copy of the data.

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


