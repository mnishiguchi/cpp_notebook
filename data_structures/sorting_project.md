# Sorting project
- Due Date: Saturday, November 7, 2015 11:00 PM
- We will discuss in class.  This is not complete yet!


## Requirements

### two comparator functions
- Implement at least two comparator functions.
- must be stand-alone functions NOT methods.
- Each function MUST return a bool and take two VGameNodes and another bool such as:

```cpp
// g2 > g1
bool compareTitlesAfter(VGameNode &g1, VGameNode &g2, bool isAscend);
```

another example would be

```cpp
//
bool compareAgeTitlesAfter(VGameNode &g1, VGameNode &g2, bool isAscend).
```

```cpp
// Example implementation

bool compareTitlesAfter(VGameNode &g1, VGameNode &g2, bool isAscend) {
    bool order = g1.title > g2.title;

    if (order) {
        cout << g1.title << " greater" << g2.title;
    } else {
        cout << g2.title << " greater" << g1.title;
    }
    return order && isAscend;
}
```

### Function Pointers

- It is often necessary to pass a pointer to a function and invoke that function by way of that pointer.

Look at the following declaration:

```cpp
// (*sortFuncPtr) is a pointer to a function
// Can be any function with the required return type and parameters
// Used to pass in comparison functions into a sorting function and
// invoke inside of it.
bool (*sortFuncPtr)(VGameNode&, VGameNode&, bool);
sortFuncPtr = compareTitlesAfter;
```

The variable name is sortFuncPtr and is a pointer like any other, that is, it is merely a memory address.  At the memory address is the executable code for any function that returns a bool and takes two VGameNode pointers and a bool as three parameters.

Note how the first parameter is a function pointer.  We'll see how to invoke such a function.

```cpp
void sortThis(bool (*sortFuncPtr)(VGameNode&,VGameNode&, bool), VGameNode* nodes, int leng)
{
      
// Any sorting algorithm can be implemented here.
// Use the function pointer sortFuncPtr to determine which of any two
// VGameNode's come before the other.  This info will enable the sort algorithm
// to operate as needed.
 
}
```
