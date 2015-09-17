# Classes

- good practice is to make ALL data members of a class private, using member functions to access that data
- good practice explicitly uses the public: and private: keywords for clarity, rather than relying on defaults
- [doc](http://www.cplusplus.com/doc/tutorial/classes/)

```cpp
// Declare a member function named GetSalary, not changing the value of any data member.
int GetSalary() const; 
```
- keyword const informs the class user and compiler that the function won't change any data member values.

```cpp
// the first line of a function definition for the member function SetSalary
void Employee::SetSalary(int salaryAmount) {
   ...
}
// - Just like a normal function definition, except the function name has Employee:: prepended to tell the compiler this is a member function of class Employee.
```

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


