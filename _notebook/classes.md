# Classes

- good practice is to make ALL data members of a class private, using member functions to access that data
- good practice explicitly uses the public: and private: keywords for clarity, rather than relying on defaults
- [doc](http://www.cplusplus.com/doc/tutorial/classes/)

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
- Special class member function which can be used to initialize data members
- A good practice is to initialize all variables when defined
- Called automatically when a variable of that class type is defined
- Has the same name as the class, has no return type

### Constructor overloading
- Can create multiple constructors differing in parameter types
- Provides different initialization values when creating a new objectdefining 

#### Declaring an array of objects

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

### Member initialization list
- an alternative approach for initializing data members in a constructor
- consists of a comma-separated list of variableName(initValue) items

```cpp
class SampleClass {
   public:
      SampleClass();
      void print() const;

   private:
      int field1;
      int field2;
};

SampleClass::SampleClass() : field1(100), field2(200) {
   return;
}
```

### Calling constructor and destructor explicitly
- http://www.geeksforgeeks.org/possible-call-constructor-destructor-explicitly/

