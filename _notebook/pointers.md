# Pointers

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

### Linked list

- a list wherein each item contains not just data but also a pointer—a link—to the next item in the list.

### Linked list vs vector

#### Vector
- Stores items in contiguous memory locations.
- Supports quick access to i'th element via v.at(i),
- but may be slow for inserts or deletes on large lists due to necessary shifting of elements.

#### Linked list
- Stores each item anywhere in memory, with each item pointing to the next item in the list.
- Supports fast inserts or deletes,
- but access to i'th element may be slow as the list must be traversed from the first item to the i'th item.
- Also uses more memory due to storing a link for each item.






