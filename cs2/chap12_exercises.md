# Chapter 12 Excercises  
- Due: Tuesday, February 16, 2016
- 1 - 11 beginning on page 853.

## 1. Mark the following statements as true or false.

### a.
In C++, pointer is a reserved word.
[ Answer ]: False

### b.
In C++, pointer variables are declared using the word pointer.
[ Answer ]: False

### c. 
The statement `delete p;` deallocates the variable pointer p.
[ Answer ]: False

### d. 
The statement `delete p;` deallocates the dynamic variable that is pointed to by p.
[ Answer ]: True

### e. 
Given the declaration: `int list[10]; int* p;`, the statement: `p = list;` is valid in C++. 
[ Answer ]: True

### f. 
Given the declaration: `int* p;`, the statement: `p = new int[50];` dynamically allocates an array of 50 components of type int, and p contains the base address of the array.
[ Answer ]: True

### g. 
The address of operator returns the address and value of its operand. 
[ Answer ]: False

### h. 
If `p` is a pointer variable, then the statement `p = p * 2;` is valid in C++.
[ Answer ]: False

==

## 2. Given the following declaration, mark each statement as valid or invalid. If a statement is invalid, explain why.
```cpp
int num;
int* ptr1;
int* ptr2;
double* ptr3;
```

### a.
```cpp
ptr1 = ptr2;
```

[ Answer ]: Valid

### b.
```
num = ptr1;
```

[ Answer ]: Invalid. Because the variable num is of int type, we cannot assign a pointer to it.

### c.
```
ptr3 = ptr1;
```

[ Answer ]: Invalid. We cannot assign an int pointer to a double pointer variable.

### d.
```
*ptr3 = *ptr2;
```

[ Answer ]: Invalid. We cannot assign an int to a double variable.

### e.
```
*ptr1 = *ptr2;
```

[ Answer ]. Valid

### f.
```
num = *ptr2;
```

[ Answer ]. Valid

### g.
```
ptr1 = &ptr2;
```

[ Answer ]: Invalid. We cannot assign an address of an int pointer to a int pointer variable.

### h.
```
ptr1 = &num;
```

[ Answer ]: Valid

### i.
```
num = &ptr1;
```

[ Answer ]: Invalid. We cannot assign an address of an int pointer to a int variable.

==

## 3. Explain how the operator `*` is used to work with pointers.
[ Answer ]: The `*` operator is used in two different ways:

1. Used to declare a pointer.
2. Used to dereference a pointer that has been set to point to some value.

==

## 4. Consider the following statement, this statement could lead to what type of misinterpretation?
`int* p, q;`

[ Answer ]: One can potentially misinterpret that both the variables `p` and `q` are to be declared as int pointers; however, C++ applies the * operator only on the variable `p`, which results in `p` declared as int pointer and `q` delared as int.

==

## 5. Suppose that you have the declaration `int* numPtr;`. What is the difference between the expressions: `*numPtr` and `&numPtr`?

[ Answer ]: 
- `*numPtr`: The int value that is pointed to by the int pointer variable `numPtr`
- `&numPtr`: The address of the int pointer variable `numPtr`

==

## 6. What is the output of the following C++ code?
```cpp
int x;
int y;
int* p = &x; // p is pointing to x
int* q = &y; // q is pointing to y
x = 35;
y = 46;
p = q;       // p is now pointing to y
*p = 27;     // Re-writing the value of y; now y is 27
cout << x << " " << y << endl;    //==> 35 27
cout << *p << " " << *q << endl;  //==> 27 27
```

[ Answer ]: 
35 27
27 27

==

## 7. Given the following statements, write C++ statements that use the variable `numPtr` to increment the value of the variable num.

```cpp
int num;
int* numPtr;
```

[ Answer ]: 

```cpp
// Assign to numPtr the address of num.
numPtr = &num;

// Increment the value of num through the pointer numPtr.
*numPtr += 1;
```

==

## 8. What is the output of the following C++ code?
```cpp
string* str;
string fName, lName;

// Assign to the pointer str the address of fName.
str = &fName;

// Re-write the value that is pointed to by the pointer str.
*str = "Miller";  // fName is now "Miller".

// Assign to the pointer str the address of lName.
str = &lName;

// Re-write the value that is pointed to by the pointer str.
*str = "Tommy";  // lName is now "Tommy".

// Print
cout  <<  fName  <<  " "  <<  lName  <<  endl;  //==>"Miller Tommy"
```

[ Answer ]: 
Miller Tommy

==

## 9. What is the output of the following C++ code?
```cpp
int num1;
int num2;
int* p = &num1;
p = &num2;
*p = 25;
num1 = num2 + 6;
p = &num1;
num2 = 73;
*p = 47;
cout  <<  *p  <<  " "  <<  num1  <<  " "  <<  num2  <<  endl;
```

**TODO**



==

## 10. What is the output of the following C++ code?
```cpp
int* length;
int* width;
length = new int;
*length = 5;
width = length;
length = new int;
*length = 2 * (*width);
cout <<  *length  <<  " "  <<  *width  <<  " "  <<  (*length) * (*width) <<  endl;
```

**TODO**




==

## 11. What is the output of the following C++ code?
```cpp
int* first = new int;
int* second;
*first = 85;
second = first;
*second = *second + *first; first = new int;
*first = *second - 100;
cout <<  *first  <<  " "  <<  *second  <<  endl;
```

**TODO**



