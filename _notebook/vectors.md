# Vectors

- an ordered list of items of a given data type
- added to C++ as a safer and more powerful form of arrays
- #include <vector>
- `vector<dataType> identifier(numElements);`
- [Arrays vs Vectors](http://stackoverflow.com/a/15079462/3837223)

```cpp
// cf. Array
int myArray[100];
myArray[0] = 1;
myArray[1] = 2;
myArray[2] = 3;
```

```cpp
#include <vector>
//... 
vector<int> myVector(4);
myVector.at(0) = 1999;
myVector.at(1) = 2012;
myVector.at(2) = 2025;
```

```cpp
#include <vector>
//... 
// Define an int vector with 50 elements each initialized to 0
vector <int> myVector(50, 0); 
```

### Checking the current vector size

- `myVector.size()` returns the current size of myVector

```cpp
currentSize = sensorReadings.size();
```

### Resizing a vector

- Commonly, the size of a list of items is not known during a program's compile time
- a vector's size can be set or changed while a program is executing
- If the new size is larger, `resize()` adds elements at the end. If smaller, `resize()` deletes elements from the end.
- Immediately after the definition, a vector has no element.
- [doc](http://www.cplusplus.com/reference/vector/vector/)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> userVals; // No elements yet
   int numVals = 0;
   int i = 0;
   
   cout << "Enter number of integer values: ";
   cin >> numVals;
   
   userVals.resize(numVals); // Allocate elements
   
   cout << "Enter " << numVals << " integer values..." << endl;
   for (i = 0; i < numVals; ++i) {
      cout << "Value: ";
      cin >> userVals.at(i);
   }
   cout << "You entered: ";
   for (i = 0; i < numVals; ++i) {
      cout << userVals.at(i) << " ";
   }
   cout << endl;
   
   return 0;
}
```


### Functions dealing with a vector's back

#### void push_back(const int newVal);
- Creates a new element at the end of vector and assigns the given value to that element, thus increasing the vector's size by 1

```cpp
#include <vector>
//... 
// Can just declare it and add elements
vector<int> myVector;
myVector.push_back(2038);
myVector.push_back(2051);
myVector.push_back(2064);
```

#### int back();
- Returns value of vector's last element
- Vector is unchanged.

#### void pop_back(); 
- Removes the last element.
- returns void

### Vector copy operation
- The `=` operator conveniently performs an element-by-element copy of a vector
- The operation vctrB = vctrA resizes vctrB to vctrA's size, appending or deleting elements as needed.
- vctrB commonly has a size of 0 before the operation.

```cpp
vector<int> userVals(4);  // element values 44, 55, 66, 77
vector<int> newVals; // no element
newVals = userVals;  // element values 44, 55, 66, 77
```

### Vector equality operation
- the `==` operator conveniently compares vectors element-by-element
- `vctrA == vctrB` evaluates to true if the vectors are **the same size** AND **each element pair is equal**.

### Reversing a vector

```cpp
   // Reverse by swapping from outermost elements inwards until reaching the middle
   for (i = 0; i < (NUM_ELEMENTS / 2); ++i) {
      tmpValue = myVector.at(i);
      myVector.at(i) = myVector.at(NUM_ELEMENTS - 1 - i);
      myVector.at(NUM_ELEMENTS - 1 - i) = tmpValue;
   }
```

### Arrays vs vectors
- using vectors rather than arrays is good practice
- the compiler does not check for out of range indices, for neither arrays nor vectors.
- Vectors are safer because myVector.at(i) is checked during execution to ensure the index is within the vector's valid range (The program will throw an exception if the index is out of the vector's valid range.)
- Vectors can be accessed using brackets [], but brackets involve no range checking, so a good practice is to use .at() to access vector elements.

### begin and end

[doc](http://www.cplusplus.com/reference/vector/vector/begin/)

```cpp
// vector::begin/end
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```
