# Templates with the generic type
- relieving the programmer from having to write redundant code that differs only by type
- Take place of any data type including user-defined data types.

==

## Type parameter
- `template<typename TheType>` (or `template<class TheType>`)
- can be used throughout the function for any parameter types, return types, or local variable types
- The compiler automatically generates a unique function definition for each type appearing in function calls to the function template
- Note: Earlier versions of C++ used the word "class" rather than "typename". Though misleading (the type need not be a class, but can be int or double, for example), the word class is still allowed for backwards compatibility, and much existing C++ code uses that word.

==

## Function templates
- A function definition having a special type parameter that may be used in place of types in the function

### Function template with one parameter
```cpp
template<typename MyType>
MyType FunctionName(MyType i, MyType j, MyType k) { 
   //...
}
```

### Function template with multiple parameters
```cpp
template<typename T1, typename T2>
ReturnType FunctionName(Parameters) {
   //... 
}
```

### Function template that takes two arguments of different types
```cpp
#include <iostream>
using namespace std;

template<typename T1, typename T2>
T1 tripleMin(T1 item1, T2 item2, T2 item3) {
   T1 minVal = item1; // Holds min item value, init to first item
   if (item2 < minVal) {
      minVal = item2;
   }
   if (item3 < minVal) {
      minVal = item3;
   }
   
   return minVal;
}

int main() {
   int num1 = 55;
   int num2 = 99;
   int num3 = 66;
   double dbl1 = 12.5;
   
   cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
   cout << "Min: " << TripleMin(num1, num2, num3) << endl << endl;
   
   cout << "Items: " << dbl1 << " " << num2 << " " << num3 << endl;
   cout << "Min: " << TripleMin(dbl1, num2, num3) << endl << endl;
      
   return 0;
}
```

==

## Class templete
- A class definition having a special type parameter that may be used in place of types in the class
- A variable defined of that class type must indicate a specific type.
- http://www.tenouk.com/cpluscodesnippet/cplusnestedclasstemplate.html

### Template parameter
- can be used throughout the class, such as for parameter types, function return types, or local variable types
- Any of the class's functions defined outside the class declaration must also be preceded by the template declaration
- `void TripleItem<TheType>::Print()`

```cpp

#include <iostream>
using namespace std;

template<typename TheType>
class TripleItem {
public:
   TripleItem(TheType val1 = 0, TheType val2 = 0, TheType val3 = 0);
   void PrintAll() const;   // Print all data member values
   TheType MinItem() const; // Return min data member value
private:
   TheType item1;           // Data value 1
   TheType item2;           // Data value 2
   TheType item3;           // Data value 3
};

template<typename TheType>
TripleItem<TheType>::TripleItem(TheType i1, TheType i2, TheType i3) {
   item1 = i1;
   item2 = i2;
   item3 = i3;
}

// Print all data member values
template<typename TheType>
void TripleItem<TheType>::PrintAll() const {
   cout << "(" << item1 << "," << item2
        << "," << item3 << ")" << endl;
   return;
}

// Return min data member value
template<typename TheType>
TheType tripleItem<TheType>::MinItem() const {
   TheType minVal = 0; // Holds value of min item, init to first item
   
   if (item2 < minVal) {
      minVal = item2;
   }

   if (item3 < minVal) {
      minVal = item3;
   }
   
   return minVal;
}

int main() {
   tripleItem<int> triInts(9999, 5555, 6666); // tripleItem class with ints
   tripleItem<short> triShorts(99, 55, 66);   // tripleItem class with shorts
   
   // Try functions from TripleItem
   triInts.PrintAll();
   cout << "Min: " << triInts.MinItem() << endl << endl;
   
   triShorts.PrintAll();
   cout << "Min: " << triShorts.MinItem() << endl << endl;
   
   return 0;
}
```

==

## Overloading operators
- http://www.cplusplus.com/doc/tutorial/templates/
- http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html




