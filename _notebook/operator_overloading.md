# Operator overloading

- http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

```cpp
// Overloaded < operator
bool operator>( const Z& rhs ) {

    return val > rhs.val;
}

// How to use
// `z1.operator>( z2 )` or simply `z1 > z2`
```


