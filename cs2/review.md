# Review
January 23, 2016

==

## QUESTION 1
Declare an int variable called aNumber and assign it a value of 24.

ANS.
```cpp
int aNumber = 24;
```
    
==

## QUESTION 2
Declare 2 double variables, myMoney and yourMoney on the same line.  Do NOT give them initial values.

ANS.
```cpp
double myMoney, yourMoney;
```    
    
==

## QUESTION 3
Output to the screen the result of the math problem 23 - 87 X 45. Have the program calculate the result.

ANS.
```cpp
// Assuming that `using namespace std;` is placed earlier in the code.
cout << ( 23 - 87 * 45 ) << endl; // -3892
```    
 
==

## QUESTION 4
Output (without quotes) "The square root of 87 is:xx", where xx is the actual square root of 87.  Have the program calculate the square root value.

ANS.
```cpp
// Assuming that #include<cmath> is placed at the beginning of the file.
cout << "The square root of 87 is:" << sqrt( 87 ) << endl;
```

==

## QUESTION 5
Get a char from the user.  If the value of the char is 'U', output, "It's You.", if the value is 'I', output, "I did it.", otherwise, output, "I don't know who did it."

ANS.
```cpp
// Get a char from the user.
char userChar;
cout << "Enter a character: ";
cin >> userChar;

// If the value of the char is 'U', output, "It's You.",
// if the value is 'I', output, "I did it.",
// otherwise, output, "I don't know who did it."
if ( userChar ==
 'U' ) {

    cout << "It's You." << endl;

} else if ( userChar ==
 'I' ) {

    cout << "I did it." << endl;

} else {

    cout << "I don't know who did it." << endl;

}
```     
    
==

## QUESTION 6
Output the following, showing the quotes as shown below:
MLK said, "the measure of a man is where he stands in times of adversity."

ANS.
```cpp
cout << "MLK said, \"the measure of a man is where he stands in times of adversity.\"" << endl;
```     
    
==

## QUESTION 7
Output the ASCII value of the plus sign (+). You must do this without consulting the ASCII table.

ANS.
```cpp
cout << static_cast<int>( '+' ) << endl;
```      
    
==

## QUESTION 8
Output the char value that corresponds to the ASCII value 93.

ANS.
```cpp
cout << static_cast<char>( 93 ) << endl;
```  
    
==

## QUESTION 9
Declare a double array of 4 elements.

ANS.
```cpp
double aList[4];
```      

==

## QUESTION 10
Have the user input two doubles and display the sum and the product of those numbers.

ANS.
```cpp
double d1, d2;
cout << "Enter two decimal numbers: ";
cin  >> d1 >> d2;

cout << "Sum:     " << d1 + d2 << endl;
cout << "Product: " << d1 * d2 << endl;
```      

==

## QUESTION 11
Write and call a function to return the sum of two numbers passed as arguments. Output the return value in the place from which it was called to ensure it works properly.

ANS.
```cpp
#include <iostream>
using namespace std;

/**
 * Returns the sum of two numbers that are passed in.
 */
double sum( double d1, double d2 ) {
    return d1 + d2;
}

int main() {

    // Output the return value in the place from which it was called to ensure it works properly.
    cout << "The return value of sum( 2, 5 ): " << sum( 2, 5 ) << endl;
    cout << "The return value of sum( 1, 9 ): " << sum( 1, 9 ) << endl;

    return 0;
}
```      
==

## QUESTION 12

DESCRIBE the problem with the following code:

int ii=0;

cout << "the value is:" << 5 / ii;

ANS.
```
Division by zero is illigal.
```      
    
==

## QUESTION 13

Is the following line an error?  If so, what is the problem, if not, what is the value of the b variable?

bool b = 5 == 6;

ANS.
```
No, it is not an error. 
Since the == operator has precedence over the = operator, the comparison statement 5 == 6 is evaluated before assignment is performed. Also (5 == 6) is a valid comparison statement, which evaluates to false. Thus, the value of the b variable will be 0 (false).
```

```cpp
bool b = ( 5 == 6 ); //==> b = false;
```  
    
==

## QUESTION 14

Code a for loop to iterate and output "Hello" four times

ANS.
```cpp
for ( int i = 0; i < 4; i++ ) {
    cout << "Hello" << endl;
}
```      

==

## QUESTION 15

Code a while loop to iterate and output "Hello" four times.

ANS.
```cpp
int i = 0;
while ( i < 4 ) {
    cout << "Hello" << endl;
    i++; 
}
```      
    
==

## QUESTION 16

Do all of these dependently, that is, use one of the multiple path structures to process this logic.

Input an integer from a user.
If the integer is 0, output, "Nothing here"
If the number is 1, output, "You have one"
If the number is 2,3, or 4, output, "You have multiple things"
If the number is -1, output, "You owe me."
If the number matches none of the above criteria, output, "I'm not sure what you have."

ANS.
```cpp
// Input an integer from a user.
int userInt;
cout << "Enter an integer: ";
cin >> userInt;

switch ( userInt ) {
    case 0:
        cout << "Nothing here" << endl;
        break;
    case 1:
        cout << "You have one" << endl;
        break;
    case 2:
    case 3:
    case 4:
        cout << "You have multiple things" << endl;
        break;
    case -1:
        cout << "You owe me." << endl;
        break;
    default:
        cout << "I'm not sure what you have." << endl;
}
```  
