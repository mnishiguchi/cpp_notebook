# Chapter 12 Excercises  
# Due: Tuesday, February 16, 2016

- 1 - 11 beginning on page 853.
- Note that number 2d seems to have a misprint and should read:
   + `*ptr3 = *ptr2;  //Assume it should say this`
   + it currently reads: `*prt3 = *ptr2;  //incorrect`

1. Mark the following statements as true or false.
a. In C++, pointer is a reserved word.
b. In C++, pointer variables are declared using the word pointer.
c. The statement delete p; deallocates the variable pointer p.
d. The statement delete p; deallocates the dynamic variable that is pointed to by p.

e. Given the declaration:
int list[10]; int *p;
the statement:
p = list;
is valid in C++. 



f. Given the declaration:
int *p;
the statement:
p = new int[50];
dynamically allocates an array of 50 components of type int, and p contains
the base address of the array.

g. The address of operator returns the address and value of its operand. 

h. If p is a pointer variable, then the statement p = p * 2; is valid in C++.

2. Given the following declaration:
int num;
int *ptr1; int *ptr2; double *ptr3;
Mark the following statements as valid or invalid. If a statement is invalid, explain why.
a. b. c. d. e. f. g. h. i.
ptr1 = ptr2; num = ptr1; ptr3 = ptr1;
*prt3 = *ptr2; *ptr1 = *ptr2; num = *ptr2;
ptr1 = &ptr2; ptr1 = &num; num = &ptr1;

3. Explain how the operator * is used to work with pointers.

4. Consider the following statement:
int* p, q;
This statement could lead to what type of misinterpretation?

5. Suppose that you have the declaration int *numPtr;. What is the differ- ence between the expressions: *numPtr and &numPtr?

6. What is the output of the following C++ code?
int x;
int y;
int *p = &x;
int *q = &y;
x = 35;
y = 46;
p = q;
*p = 27;
cout<<x<<" "<<y<<endl; cout<<*p<<" "<<*q<<endl;

7. Given the following statements: int num;
int *numPtr;
Write C++ statements that use the variable numPtr to increment the value
of the variable num.

8. What is the output of the following C++ code?
    string *str;
    string fName, lName;
    str = &fName;
    *str = "Miller";
    str = &lName;
    *str = "Tommy";
    cout << fName << " " << lName << endl;

9. What is the output of the following C++ code?
int num1;
int num2;
int *p = &num1;
p = &num2;
*p = 25;
num1 = num2 + 6;
p = &num1;
num2 = 73;
*p = 47;
cout << *p << " " << num1 << " " << num2 << endl;

10. What is the output of the following C++ code?
int *length;
int *width;
length = new int;
*length = 5;
width = length;
length = new int;
*length = 2 * (*width);
cout << *length << " " << *width << " " << (*length) * (*width)
<< endl;

11. What is the output of the following C++ code?
int *first = new int;
int *second;
*first = 85;
second = first;
*second = *second + *first; first = new int;
    *first = *second - 100;
    cout << *first << " " << *second << endl;

