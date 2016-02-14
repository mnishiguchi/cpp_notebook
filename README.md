# cpp_practice_code

- This repo is for me to practice the c++ programming.
- I write notes on what I learned for future reference.

==

## Data types

### Integer numeric data types

| Definition | Size | Supported number range | Standard-defined minimum size |
|---|---|---|---|
|char myVar;     |8 bits |-128 to 127                     |8 bits|
|short myVar;    |16 bits|-32,768 to 32,767               |16 bits|
|long myVar;     |32 bits|-2,147,483,648 to 2,147,483,647 |32 bits|
|long long myVar;|64 bits|-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |64 bits|
|int myVar;      |32 bits|-2,147,483,648 to 2,147,483,647 |16 bits|

### Floating-point numeric data types

|Definition | Size     |Supported number range |
|---        |---       |---                    |
|float x;   |  32 bits |-3.4x1038 to 3.4*1038  |
|double x;  |  64 bits |-1.7x10308 to 1.7*10308|

### unsigned vs signed

- Sometimes a programmer knows that a variable's numbers will always be positive (0 or greater), such as when the variable stores a person's age or weight.
- The programmer can prepend the word "unsigned" to inform the compiler that the integers will always be positive.
- Because the integer's sign needs not be stored, the integer range reaches slightly higher numbers.

**unsigned vs signed int**
```
1 byte: 0..255
  |--> unsigned 0..255
  |--> signed   -128..127
```

==

## Ternary operator
- https://en.wikipedia.org/wiki/%3F:#C.2B.2B

```cpp
if (amount1 > amount2) {
    cout << amount1 << endl;
} else {
    cout << amount2 << endl;
}

cout << (amount1 > amount2 ? amount1 : amount2);
```

==

## [Standard Containers](http://www.cplusplus.com/reference/stl/)
- array, vector, list, stack, queue, map, etc
- A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.

==

## Overloading a function

- We can define functions with the same identifier if they have different signatures (e.g., different return type, different arguments)

==

# Implicit and explicit conversion

## Promotion of data type (Implicit)

```cpp
cout << 10   / 4   << endl; //=> 2
cout << 10.0 / 4   << endl; //=> 2.5
cout << 10.0 / 4.0 << endl; //=> 2.5
```

## Casting (Explicit)
```cpp
cout << static_cast<double>(10) / 4 << endl; //=> 2.5
cout << double(10)              / 4 << endl; //=> 2.5
cout << (double)10              / 4 << endl; //=> 2.5
```

==
