# Classes
- [doc](http://www.cplusplus.com/doc/tutorial/classes/)
- The word `const` at the end of the member functions specifies that these functions cannnot modify the member variables of an object of that class.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

class RightTriangle {
   public:
      void SetSide1(double side1Val);
      void SetSide2(double side2Val);
      double GetHypotenuse() const;

   private:
      double side1;
      double side2;
};

void RightTriangle::SetSide1(double side1Val) {
   side1 = side1Val;
   return;
}

void RightTriangle::SetSide2(double side2Val) {
   side2 = side2Val;
   return;
}

double RightTriangle::GetHypotenuse() const {
   return sqrt((side1 * side1) + (side2 * side2));
}

int main() {
   RightTriangle triangleA;

   triangleA.SetSide1(3.0);
   triangleA.SetSide2(4.0);
   
   cout << "Hypotenuse: " << triangleA.GetHypotenuse() << endl;
   
   return 0;
}
```

==

## Good practice
   + Make ALL data members of a class private, using member functions to access that data
   + Explicitly use the `public:` and `private:` keywords for clarity, rather than relying on defaults
   + Initialize all variables when defined

==

## Class with pointer member variables
- Do three things:
1. Include the **destructor** in the class
2. **Overload the assignment operator** for the class
3. Include the **copy constructor**

==

## Mutator, accessor, and private helper methods

**Getters / Accessors**
- keyword const informs the class user and compiler that the function won't change any data member values.
```cpp
// Accessor functions usually are defined as const, to enforce that they do not change data members.
int getSalary() const; 
```

**Setters / Mutators**
```cpp
// the first line of a function definition for the member function SetSalary
void Employee::setSalary(int salaryAmount) {
   ...
}

```

```cpp
void ShopItem::setNameAndPrice(string itemName, int itemPrice) {
   ...
}
```

**Private helper methods**
- A programmer commonly creates private functions to help public functions carry out their tasks

==

## Constructors
- Special class member function which can be used to **initialize data members**
- A good practice is to initialize all variables when defined
- Called automatically when a variable of that class type is defined
- Has the same name as the class, has no return type
- IMPORTANT:
  + C++ does not automatically initialize the variables
  + If a class has no constructor(s), C++ automatically provides the default constructor; however, the object declared is still uninitialized
  + If a class has a constructor with parameters, C++ does not provide the default constructor
  + If we declare an object and want the default constructor to be excuted, we should not place the empty parentheses after the object name in the object declaration statement

--

### Constructor overloading
- Can create multiple constructors differing in parameter types
- Provides different initialization values when creating a new objectdefining 

--

### Member initialization list
- An alternative approach for initializing data members in a constructor
- Consists of a comma-separated list of variableName(initValue) items

```cpp
class SampleClass {
   public:
      SampleClass();
      void print() const;

   private:
      int field1;
      int field2;
};

// Member initialization list.
SampleClass::SampleClass() : field1( 100 ), field2( 200 ) {
   return;
}
```

==

## Destructors
- Automatically executed when the class object goes out of scope.
- We can put the necessary code in the destructor to ensure that when an object goes out of scope, the memory created by pointer variables is deallocated.
- IMPORTANT: For the destructor to work properly, the pointer p must have a valid value.

```cpp
class ClassName {
public:
  ~ClassName();
  ...
private:
  int x;
  int size;
  int* list;  // Must be deallocated when an object goes out of scope. 
};

ClassName::~ClassName() {

  delete[] list;

}
```

--

### Calling constructor and destructor explicitly
- http://www.geeksforgeeks.org/possible-call-constructor-destructor-explicitly/

==

## Copy constructor

### Default member-wise copy constructor
- Provided by the compiler
- Shallow copy
- Any pointer members will point to the same memory locations as those of the specified existing instance
- Automatically excuted in the following situations:
  + When an object is declared and initialized by using the value of another object
  + When, as a parameter, an object is passed by value
  + When the return value of a function is an object

```cpp
// Bad
// If the class has a pointer memeber and destructor to deallocate it,
// the destructor will be called on the same memory location every time
// an instance is out of scope, which causes a run-time error.
ClassName obj_3( obj_1 );
```

--

### Custom copy constructor
- To force each object to have its own copy of data (deep copy), we must override the definition of the copy constructor provided by the compiler
- We must provide our own definition of the copy constructor.

```cpp
/**
 * The general syntax to include the copy constructor 
 * in the definition of a class
 * @param other an instance of the class as a constant reference parameter
 */
ClassName::ClassName( const ClassName& other ) {

  // Initialize the new instance.
  // (Deep copy the other instance to the new one)

}
```

==

## Declaring objects
- The class should have the default constructor if a class has a constructors and we want to declare an array of that class's objects.

```cpp
// NOTE: Default constructor is required to do this.
VideoGame aGame;
```

```cpp
// NOTE: Default constructor is required to do this.
VideoGame aGame[45];
```

```cpp
// Can use different constructors for different elements.
VideoGame games[] {
   VideoGame( 9 ),
   VideoGame( 10, "Battle", "Wii" ),
   VideoGame( 30, "Larry", "Nintendo64" ),
};
```

==

## Built-in operation on classes
- Most of C++'s built-in operations do not apply to classes.
- e.g., arithmetic operators, rational operators (comparison)
- cf. Operator overloading

==

## Class Scope

- A class object can be either
  + automatic
     * created each time the control reaches its declaration and
     * destroyed when the control exits the surrounding block) or
  + static
     * created once, when the control reaches its declaration, and destroyed when the program terminates).

== 

## Static members

- C++ allocates only one memory space
- static member variables of a class exist even when no object of that class type exists

==

## Struct vs Class

- Both C++ classes ans structs have the same capabilities; however, most programmers ristrict their use of structures to adhere to their C-like structure form and thus do not use them to incude member functions.

==

## object-oriented design (OOD)

### The three basic principles of OOD

- **Encapsulation**: The ability to combine data and operations on that data in a single unit.
- **Inheritance**:   The ability to create new objects (classes) from existing objects (classes).
- **Polymorphism**:  The ability to use the same expression to denote different operations.

==

## The `this` implicit parameter

- Using `this->` makes clear that a class member is being accessed
- Essential if a data member and parameter have the same identifier
