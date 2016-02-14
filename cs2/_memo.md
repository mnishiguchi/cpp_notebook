# Memo

## Passing by value v passing by reference
- passing by reference
- Passing &argument into a function

```
// A Hero pointer is passed by value.
// NOTE: Since there is no &, this is not a reference.

/**
 * @param  {[type]} Hero* h             [description]
 * @return {[type]}       [description]
 */
void saveHero( Hero* h ) {

}

``` 

## Inheritance
- A subclass must call one of its parent's constructors.

```cpp
#include <iostream>
using namespace std;

/**
 * A parent class.
 */
class Parent {
public:

  int secret;

  Parent( int secret ) {

    this->secret = secret;

  }

};


/**
 * A subclass of the Parent class.
 * NOTE: A subclass must call one of its parent's constructors.
 */
class Child : public Parent {
public:

  /**
   * Constructor with a param.
   * Calls its parent's constructor with a specified argument.
   */
  Child( int secret ) : Parent( secret ) {

  }

  /**
   * Default constructor.
   * Calls its parent's constructor with a default value.
   */
   Child() : Parent( -1 ) {

   }

};


int main() {

    Child c1;        // Calling the default constructor.
    Child c2( 36 );  // Calling a constructor with one param.

    cout << "c1: " << c1.secret << endl;
    cout << "c2: " << c2.secret << endl;

    return 0;
}
```

==

## sizeof oprator

```cpp
    int i;
    double d;
    cout << "sizeof int:    " << sizeof i << endl;  //==> 4
    cout << "sizeof double: " << sizeof d << endl;  //==> 8
```

==

## C++ pointer arithmetic

- The four arithmetic operators that can be used on pointers:
  + `++`, 
  + `--`, 
  + `+`, 
  + `-`

==

`&` is the address-of operator, and can be read simply as "address of"
`*` is the dereference operator, and can be read as "value pointed to by"

