# Virtual

## Virtual functions

- **Run-time binding** (instead of compile-time binding)
- In run-time binding, the compiler does not generate the code to call a specific funtion. Instead, it generates enough information to enable the run-time system to generate the specific code for the appropreate function call
- IMPORTANT: Parameters must be
    - **pointers** or
    - **reference variables** 
- (If passed by value, the compiler will always pass it as the base class)
- **Declared in a base class**
- If a base class contains virtual functions, make the destructor of the base class virtual

==

## Virtual destructors

- Logically, the destructor of the derived class should be executed when the derived class object goes out of scope

- The destructor of the base class must be virtual.
- The virtual destructor of a base class automatically makes the destructor of a derived class virtual.
- When a derived class object is passed to a formal parameter of the base class type, then when the object goes out of scope:
    1. the destructor of the derived class executes
    2. the destructor of the base class executes
        * the base class part (the members inherited from the base class) of the derived class object is also destroyed.

==

## Abstract class and Pure virtual functions

- **Pure virtual functions**: the expression `= 0` before the semiclolon 
- **Abstract class**: a class that contains one or more pure virtual functions
- IMPORTANT:
    + An abstract class can contain instance variables, constructors, and functoins that are not pure virtual; however,
    + The abstract class must provide the definitions of the constructor and functons that are not pure virtual.
    + Its subclass must implement the pure virtual functions before being used.

```cpp
/**
 * To exclude the definitions of the functions draw and move and
 * to prevent the user from creating objects of the class shape.
 */
class shape {
public:
    // Pure virtual function
    // Function to draw the shape
    virtual void draw() = 0;                   
    
    // Pure virtual function
    // Function to move the shape at the position (x, y).
    virtual void move(double x, double y) = 0; 
    ...
};
```

==

## Abstract Classes and Virtual Methods

- Using subclasses and classes lead to possible problems when passing to functions
    + Allowed due to the “is-a” relationship
    + Passing a parameter by reference (&) or pointer (*) to a function
    + Methods may need virtual keyword to control compile-time binding vs. runtime binding
    + Passing a parent class by value will always use the parent’s copy of things.

- By making some of the methods purely virtual, an abstract class is created
Subclasses MUST implement a method body of purely virtual methods at some point before it is declared
A class with ALL purely virtual methods is considered an interface
    + Controlling behavior
    + Dictating what is done not how it’s done




