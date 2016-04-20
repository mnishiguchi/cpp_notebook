# strings
- [C-strings vs. strings](http://www.cs.fsu.edu/~myers/cop3330/notes/strings.html)

**char array**

```cpp
char name[] = "hungry"; // h,u,n,g,r,y,\0 ==> 7 characters
```

```cpp
// A string "Guy"
// Length: 4
// These are all synonymous:
char name[] = { 'G', 'u', 'y', 0 }; 
char name[] = { 'G', 'u', 'y', '\0' }; 
char name[] = "Guy";
char* name  = "Guy";

// Printing the name of the char array.
// NOTE: The array name of any other data types would print its memory address.
// But char array is special. It prints the entire string.
cout << "Printing name        : " << name << endl; //==> Guy

int nums[5] = { 1, 2, 3, 4, 5 };
cout << "Printing nums        : " << nums << endl;

// Printing the memory address.
cout << "Printing (void *)name: " << (void *)name << endl; //==> 0x7fff5fbff818

// Printing a single character.
cout << "Printing *name       : " << *name << endl; //==> G
```

**string type**
- not a built-in type

```cpp
string myName = "Masatoshi";
```


==

##  String info functions

|   |   |   |
|---|---|---|
|`at(indx)`   |Accesses the character at a particular index of a string.||
|`length()`   |Number of characters|   |
|`size()`     |Number of characters|   |
|`empty()`    |true if length is 0 |   |
|`find(item)` |Returns index of first item occurrence, else returns string::npos. Item may be char, string variable, string literal or char array find(item, indx) starts at index indx.|[doc](http://www.cplusplus.com/reference/string/string/find/)|
|`substr(indx, len)` |Returns substring starting at index and having len characters.|[doc](http://www.cplusplus.com/reference/string/string/substr/)|

## std::string::npos
- a static member constant value with the greatest possible value for an element of type size_t.
- when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
- As a return value, it is usually used to indicate no matches.
- This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.
- Note: In my system `npos = 18446744073709551615`
- [doc](http://www.cplusplus.com/reference/string/string/npos/)

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
   getline(cin, userInput);

   if (userInput.find("darn") == -1) {
      cout << userInput << endl;
   }
   else {
      cout << "Censored" << endl;
   }

   return 0;
}
```

==

## String modify operations

#### push_back(newChar)
- Appends newChar to the end.       

#### append(moreString)
- Appends a copy of string moreString. 
      
#### str1 + str2
- Returns a new string having str1 with str2 appended. str1 may be a string variable or string literal (or a character array variable). Likewise for str2. One of str1 or str2 (not both) may be a character.

#### insert(indx, subStr)
- Inserts string subStr starting at index indx.       

#### replace(indx, num, subStr)
- Replaces characters at indices indx to indx+num with a copy of subStr. subStr's length does not have to be the same as num.       

#### clear()
- Deletes characters, sets size to 0.         

#### resize(newLength)
- Resize string to have newLength characters. If decrease, drops extra chars. If increase, sets new chars to null ('\0', ASCII value 0).     

#### substr(position, **length**)
- Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
- The substring is the portion of the object that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).
- [doc](http://www.cplusplus.com/reference/string/string/substr/)

==

## Character operations

- Include the cctype library via `#include <cctype>`
- ctype stands for character type. The first c indicates the library is originally from the C language.
- [doc](http://www.cplusplus.com/reference/cctype/)

####isalpha(c)
- true if alphabetic: a-z or A-Z
```cpp
isalpha('x') // true
isalpha('6') // false
isalpha('!') // false
```

####isdigit(c)
- true if digit: 0-9. 
```cpp
isdigit('x') // false
isdigit('6') // true
```

####isspace(c)
- true if whitespace. 
```cpp
isspace(' ')  // true
isspace('\n') // true
isspace('x')  // false
```

####toupper(c)
- Uppercase version
```cpp  
toupper('a')  // A
toupper('A')  // A
toupper('3')  // 3
```

####tolower(c)
- Lowercase version 
```cpp  
tolower('A')  // a
tolower('a')  // a
tolower('3')  // 3
```

==

## Floating-point comparison

- should not be compared using `==`
- set a threshould(e.g. 0.0001)
- `fabs()` computes floating-point absolute value

```cpp
// Determine if double variable x is 98.6.
fabs(x - 98.6) < 0.0001;
```

```cpp
// Determine if double variables x and y are equal. Threshold is 0.0001.
// (If difference is less than 0.0001, values are close enough.)
fabs(x - y) < 0.0001;
```

==

## C string vs string type

### Char arrays / C strings

- Must end with a null character `\0`.
- Given a string literal, the compiler automatically appends a null character.
- Known as a null-terminated string.
- When printed, printing stops at the null character.
- Once a string is assigned, a C string cannot be assigned later. Functions exist to copy one string's characters to another.
- When iterating over a string, the loop should iterate until reaching the null character, rather than relying on index

```cpp
// the compiler automatically appends a null character
char movieTitle[20] = "Dragonball";
```

If a char array is initialized when declared, the char array's size may be omitted.
```cpp
// The compiler determines the size from the string literal
// in this case 9 + 1 (for the null character)
char userName[] = "Masatoshi";
```

#### Checking if a character array is empty
```cpp
if(text[0] == '\0') {}
```


### C++ string type

- accessible after `#include <string>`
- Help reduce errors and increase programmer convenience
- Yet legacy code uses C strings
- some commonly-used C++ functions only accept C strings as parameters (e.g., ofstream myfile; myfile.open ("somefile.txt");)
- C++ provides common functions for handling C strings, which can be used by  `#include <cstring>`. [[doc](http://www.cplusplus.com/reference/cstring/)]

### Some C string modification functions
`#include <cstring>`. [[doc](http://www.cplusplus.com/reference/cstring/)]

#### strcpy(destStr, sourceStr)
- Copies sourceStr (up to and including null character) to destStr.
-  a common error is to copy a source string that is too large, causing an out-of-range access in the destination string. 

#### strncpy(destStr, sourceStr, numChars)
- Copies up to numChars characters.
- Does not append a null character.
- [doc](http://www.cplusplus.com/reference/cstring/strncpy/)

#### strcat(destStr, sourceStr) 
- Copies sourceStr (up to and including null character) to end of destStr (starting at destStr's null character).`
- second parameter must be a string, not a single character.

#### strncat(destStr, sourceStr, numChars)
- Copies up to numChars characters to destStr's end, then appends null character.

### Some C string info functions
`#include <cstring>`. [[doc](http://www.cplusplus.com/reference/cstring/)]

#### strchr(sourceStr, searchChar)
- stands for "string character"
- Returns NULL if searchChar does not exist in sourceStr.
- (Else, returns address of first occurrence). 
- NULL is defined in the cstring library.

#### size_t strlen(sourceStr) 
- Returns number of characters in sourceStr up to, but not including, first null character.
- size_t is integer type.

#### int strcmp(str1, str2) 
- Returns 0 if str1 and str2 are equal, non-zero if they differ.

### String functions with pointers
`#include <cstring>`. [[doc](http://www.cplusplus.com/reference/cstring/)]

```cpp
char string1[10] = "abcxyz"; 
char string2[10] = "xyz";
char newText[10] = ""; 
char* subStr = 0; 

if (strcmp(string1, string2) == 0) {     // abcxyz does not equal xyz
   // ...
}
if (strcmp(&string1[3], "xyz") == 0) {   // xyz equals xyz
   // ...
}
subStr = &string1[3];                     // Points to 'x' in string1
if (strcmp(subStr, string2) == 0) {       // xyz equals xyz
   // ...
}
strcpy(newText, subStr);                  // newText is now "xyz"
```

#### strchr(sourceStr, searchChar)
- Returns 0 if searchChar does not exist in sourceStr.
- Else, returns pointer to first occurrence. 

```cpp
if (strchr(orgName, 'D') != 0) {     // 'D' exists in orgName?
   subString = strchr(orgName, 'D'); // Points to first 'D'
   strcpy(newText, subString);       // newText now "Dept. of Redundancy Dept."
}  
if (strchr(orgName, 'Z') != 0) {     // 'Z' exists in orgName?
   ... // Doesn't exist, branch not taken
}
```

#### strrchr(sourceStr, searchChar)
- Returns 0 if searchChar does not exist in sourceStr.
- Else, returns pointer to LAST occurrence
- (searches in reverse, hence middle 'r' in name)

```cpp
if (strrchr(orgName, 'D') != 0) {    // 'D' exists in orgName?
   subString = strrchr(orgName);     // Points to last 'D'
   strcpy(newText, subString);       // newText now "Dept."
}
```

#### strstr(str1, str2) 
- Returns char* pointing to first occurrence of string str2 within string str1.
- Returns 0 if not found

```cpp
subString = strstr(orgName, "Dept"); // Points to first 'D'
if (subString != 0) {
   strcpy(newText, subString);       // newText now "Dept. of Redundancy Dept."
}
```

==

## [Comparing character arrays and string literals in C++](http://stackoverflow.com/a/1639437/3837223)
- Use std::strcmp
    + `int strcmp( const char *lhs, const char *rhs );` 
    + returns 0 if strings are equal.
    + `#include <cstring>`
