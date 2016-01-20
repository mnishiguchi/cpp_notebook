# Memo

PP506-527 (no enum), 535 - 541

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
