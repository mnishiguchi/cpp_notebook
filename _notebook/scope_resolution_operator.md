# C++ Scope Resolution Operator (::)

```cpp
// Global h
int h = 9;

int main() {

    // Local h
    int h = 999;

    printf( "Global: %d\n", ::h ); // get global h
    printf( "Local:  %d\n", h );   // get local h
    
    return 0;
}
```

```cpp
int count = 0;
 
int main() {
    int count = 0;

    ::count = 1;  // set global count to 1
    count   = 2;  // set local count to 2

    return 0;
}
```
