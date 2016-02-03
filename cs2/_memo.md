# Memo

## ENUM
-  used for better readability.

```cpp
#include <iostream>
using namespace std;

// Enum is used for better readability.
enum PEOPLE { PERSON_1, PERSON_2, PERSON_3 }; // Use instead of 0..2
enum REGION { REGION_1, REGION_2 };          // Use instead of 0..1

int main() {
     double sales[3][2];

     sales[PERSON_1][REGION_1] = 23.2;
     sales[PERSON_1][REGION_2] = 87.66;
     sales[PERSON_2][REGION_1] = 96.3;
     sales[PERSON_2][REGION_2] = 34.6;
     sales[PERSON_3][REGION_1] = 2;
     sales[PERSON_3][REGION_2] = 102.4;

    // ...

    return 0;
}
```

==

## Unified modeling languages (UML)

- List class members

==

## Class Scope

- A class object can be either
    + automatic
        * created each time the control reaches its declaration and
        * destroyed when the control exits the surrounding block) or
    + static
        * created once, when the control reaches its declaration, and destroyed when the program terminates).

==

## Polymorphism

- having many forms
- occurs when there is a hierarchy of classes and they are related by inheritance
- a call to a member function will cause a different function to be executed depending on the type of object that invokes the function


### Two common ways to relate classes in a meaningful way
- Inheritance (‘‘is-a’’ relationship)
- Composition (aggregation) (‘‘has-a’’ relationship)


### Base Access Specifier
- [Difference between private, public, and protected inheritance](http://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance)

```cpp
class A 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
```

==

## “super” in C++

- http://stackoverflow.com/a/180633/3837223

