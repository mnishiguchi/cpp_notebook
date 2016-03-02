# Char arrays
- Char pointer is special.
- When printed, it prints characters until the null is reached.
- cf. Other pointers will point memory addresses as values.

```cpp
    char*  name    = "Esayas";  // ISO C++11 does not allow conversion from string literal to "char*"
    char   name2[] = "Shewkena";
    string name3   = "Masatoshi";

    cout << ( name2 + 4 ) << endl;  //==> kena
    cout << name2[ 4 ]    << endl;  //==> k
```
