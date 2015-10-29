# Sorting project
- Due Date: Saturday, November 7, 2015 11:00 PM
- We will discuss in class.  This is not complete yet!


## Requirements
- Implement at least two comparator functions. These must be stand-alone functions NOT methods.
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



These functions will look at the two VGameNode parameters and decide which of them would be "greater" in terms of order.
In other words, does g1 come "after" g2 or not.  This decision is based on how the particular function is ordering two nodes and whether the nodes are ordered ascending or descending.  The second question is answered on whether the isAscend argument is true or false.  So, to demonstrate, assume we want to sort by the game title, ascending, that is alphabetically A-Z.

A game held in g1 titled "Zombie" would come after a game held in g2 named "Grand Theft".

if isAscend is true, then the return would be true, because g1 comes after g2 if viewed top to bottom like:

Grand Theft (g1)
Zombie (g2)

If the isAscend is false (ordered Z-A), then false should be returned since g1 would NOT come before g2 or if seen top to bottom:

Zombie (g2)
Grand Theft (g1)

 

Function Pointers

It is often necessary to pass a pointer to a function and invoke that function by way of that pointer.

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
