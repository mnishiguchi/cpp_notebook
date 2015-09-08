# cpp_practice_code

===

##  String info functions

|   |   |   |
|---|---|---|
|`at(indx)`   |Accesses the character at a particular index of a string.||
|`length()`   |Number of characters|   |
|`size()`     |Number of characters|   |
|`empty()`    |true if length is 0 |   |
|`find(item)` |Returns index of first item occurrence, else returns string::npos, which is defined with a value of -1. Item may be char, string variable, string literal or char array find(item, indx) starts at index indx.|[doc](http://www.cplusplus.com/reference/string/string/find/)|
|`substr(indx, len)` |Returns substring starting at index and having len characters.|[doc](http://www.cplusplus.com/reference/string/string/substr/)|


### Check if a string contains a certain word.

[`string::find`](http://www.cplusplus.com/reference/string/string/find/)

```cpp

// Print "Censored" if userInput contains the word "darn",
// else print userInput. End with newline. 

#include <iostream>
#include <string>
using namespace std;

int main() {
   string userInput;

   // userInput = "That darn cat.";
   cin >> userInput;

   if (userInput.find("darn") == -1) {
      cout << userInput << endl;
   }
   else {
      cout << "Censored" << endl;
   }

   return 0;
}
```

===

## String modify operations

|   |   |   |
|---|---|---|
|push_back(newChar) |Appends newChar to the end.|   |
|append(moreString) |Appends a copy of string moreString.|   |
|str1 + str2 |Returns a new string having str1 with str2 appended. str1 may be a string variable or string literal (or a character array variable). Likewise for str2. One of str1 or str2 (not both) may be a character.|   |
|insert(indx, subStr) |Inserts string subStr starting at index indx.|   |
|replace(indx, num, subStr) |Replaces characters at indices indx to indx+num with a copy of subStr. subStr's length does not have to be the same as num.|   |
|clear() |Deletes characters, sets size to 0.  |   |
|resize(newLength) |Resize string to have newLength characters. If decrease, drops extra chars. If increase, sets new chars to null ('\0', ASCII value 0).| |

===

## Character operations

- Include the cctype library via `#include <cctype>`
- ctype stands for character type. The first c indicates the library is originally from the C language.
- [doc](http://www.cplusplus.com/reference/cctype/)

isalpha(c)  true if alphabetic: a-z or A-Z
```cpp
isalpha('x') // true
isalpha('6') // false
isalpha('!') // false
```

isdigit(c)  true if digit: 0-9. 
```cpp
isdigit('x') // false
isdigit('6') // true
```

isspace(c)  true if whitespace. 
```cpp
isspace(' ')  // true
isspace('\n') // true
isspace('x')  // false
```

toupper(c)  Uppercase version
```cpp  
toupper('a')  // A
toupper('A')  // A
toupper('3')  // 3
```

tolower(c)  Lowercase version 
```cpp  
tolower('A')  // a
tolower('a')  // a
tolower('3')  // 3
```





