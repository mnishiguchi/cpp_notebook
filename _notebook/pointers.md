# Pointers
- [Why should I use a pointer rather than the object itself?](http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself)

## Variables and Memory

- When declaring a variable, the computer associates the variable name with a particular location in memory and stores a value there.
- When refering to the variable by name , the computer must take two steps:
    + 1. Look up the address that the variable name corresponds to
    + 2. Go to that location in memory and retrieve or set the value it contains

## * and &

### The * operator (used in two different ways)
1. When declaring a pointer, indicates that the variable being declared is a pointer
2. When using a pointer that has been set to point to some value, dereferences it (accessing or setting the value it points to)

### The & operator (used in two different ways)
1. to indicate a reference data type (as in int &x;)
2. to take the address of a variable (as in int *ptr = &x;)

### vector insert/erase performance problem

- For vectors with thousands of elements, a single call to insert() or erase() can require thousands of instructions, so a program with many inserts or erases on large vectors may run very slowly

## initializing the pointer to 0
- 0, NULL, nullptr keyword
- Used to indicate that the pointer variable points to nothing
- initialize the pointer to 0, avoiding use of NULL
- C++ creator Bjarne Stroustrup's advice: "In C, it has been popular to define a macro NULL to represent the zero pointer. Because of C++'s tighter type checking, the use of plain 0, rather than any suggested NULL macro, leads to fewer problems."
- the nullptr keyword (see Wikipedia: C++11) in newer versions of the C++ standard would be even better, but is not yet supported by many C++ compilers

## Operators: new, delete, and ->

### The new operator
- Allocates memory for the given type and returns a pointer(i.e., the address) to that allocated memory
- returns 0 if the operator failed to allocate memory

```cpp
pointerVariable = new type;
```

### ->: member access operator

Accesses a class's member functions by first dereferencing a pointer

```cpp
a->b   // Equivalent to (*a).b
```

### The delete operator
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







