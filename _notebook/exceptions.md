# Exceptions
- Just like any other classes.
- Create your own Exception classes.

## Error-checking
- `assert`
- regular `if` block
- `throw`, `try/catch`

==

## C++ exception classes
- C++ provides support to handle exceptions via a hierarchy of classes. 
- An `exception` is thrown by using the `throw` keyword from inside the `try` block. 
- Exception handlers are declared with the keyword `catch`, which must be placed immediately after the `try` block.

### [`class exception`](http://www.cplusplus.com/reference/exception/exception/)

- The base of the classes designed to handle exceptions. 
- Contains the function `what`, which returns a string containing an appropriate message.
- All derived classes of the `class exception` override the function `what` to issue their own error messages.

### [logic_error](http://en.cppreference.com/w/cpp/error/logic_error) and [runtime_error](http://en.cppreference.com/w/cpp/error/runtime_error)
- Immediately derived from the `class exception`.
- Both of these classes are defined in the header file `stdexcept`.
- http://en.cppreference.com/w/cpp/error/exception

[![](http://www.tutorialspoint.com/cplusplus/images/cpp_exceptions.jpg)](http://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)

```cpp

int main() {

    int number;

    cout << "Give me a positive int: ";
    cin >> number;

    try {

        if ( number <= 0 ) {

          // Throwing an int.
          throw number;

        }

        cout << "You entered a positive int: " << number << endl;

    // In C++, the catch block can catch any data type that is thrown.
    } catch( int error ) {

        cout << "You did not enter a positive int!" << endl;
        cout << "Caught      : " << error  << endl;
        cout << "You entered : " << number << endl;

    }

  return 0;
}

```
