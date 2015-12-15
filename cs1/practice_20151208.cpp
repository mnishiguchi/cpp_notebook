/*






13  Fill in the table below so it shows the contents of the following array:
int table[3][4] = {{2, 3}, {7, 9, 2}, {1}};






14. Write a function called displayArray7. The function should accept a two-dimensional array as an argument and display its contents on the screen. The function should work with any of the following arrays:

 int hours[5][7];
 int stamps[8][7];
 int autos[12][7];
 int cats[50][7];




15.  In C++, you can create arrays with virtually any number of dimensions.  Given the definition of a three dimensional below as an example,

  Double seats[3][5][8]

Answer the question below.

A video rental store keeps DVDs on 50 racks with 10 shelves each. Each shelf holds 25 DVDs. Deﬁne a three-dimensional array large enough to represent the store’s storage system.


 */

/*
1. Deﬁne the following arrays:

    A) empNums, a 100-element array of ints
      int empNums[100];

    B) payRates, a 25-element array of floats
      float payRates[25];

    C)  miles, a 14-element array of longs
      long miles[14];

    D) cityName, a 26-element array of string objects
      string cityName[26];

    E)  lightYears, a 1,000-element array of doubles
      double lightYears[1000];


2. What’s wrong with the following array deﬁnitions?

   int readings[-1];         // Negative number is not allowed for array size.

   float measurements[4.5];  // Decimal number is not allowed for array size.

   int size;
   string names[size];       // The size is not defined.


3. What is the output of the following code?

    int values[5], count;
    for (count = 0; count < 5; count++)
      values[count] = count + 1;

      // 0 + 1 = 1
      // 1 + 1 = 2
      // ...

    for (count = 0; count < 5; count++)
      cout << values[count] << endl;

    //=> 1
         2
         3
         4
         5


4. twenty_fishermen.cpp

#include <iostream>
using namespace std;

int main() {

    // 20-element array of ints called fish
    const int NUM_FISH = 20;
    int fish[ NUM_FISH ];

    // Ask how many fish were caught by fishermen 1-20
    cout << "How many fish were caught by fishermen 1-20:" << endl;

    // store this data in the array fish.
    for (int i = 0; i < NUM_FISH; i++) {

        cout << "Fisherman #" << i + 1 << ": ";
        cin >> fish[ i ];  // Store it in the array.

    }

    cout << "--------------------------------------------------"  << endl;

    // Print the array.
    for (int i = 0; i < NUM_FISH; i++) {

        cout << "Fisherman #" << i + 1 << ": ";
        cout << fish[ i ] << endl;  // Print each array element.

    }

    cout << endl;

    return 0;
}


5 Deﬁne the following arrays:

A)  ages, a 10-element array of ints initialized
  with the values 5, 7, 9, 14, 15, 17, 18, 19, 21, and 23.

    int ages[10] = { 5, 7, 9, 14, 15, 17, 18, 19, 21, 23 };

B)  temps, a 7-element array of floats initialized
  with the values 14.7, 16.3, 18.43, 21.09, 17.9, 18.76, and 26.7.

    float temps[7] = { 14.7, 16.3, 18.43, 21.09, 17.9, 18.76, 26.7 };

C)  alpha, an 8-element array of chars initialized
  with the values ‘J’, ‘B’, ‘L’, ‘A’, ‘*’, ‘$’, ‘H’, and ‘M’.

    char alpha[8] = { ‘J’, ‘B’, ‘L’, ‘A’, ‘*’, ‘$’, ‘H’, ‘M’ };


6.  Given the following array deﬁnition:

    int values[] = { 2, 6, 10, 14 };

    What does each of the following display?
    A)  cout <<   values[ 2 ];     // 10
    B)  cout << ++values[ 0 ];     // 3
    C)  cout <<   values[ 1 ]++;   // 7
    D)  x = 2;
        cout <<   values[ ++x ];   // 14


7 Given the following array deﬁnition: int nums[5] = { 1, 2, 3 };
  What will the following statement display?

    cout << nums[ 3 ];  // Unknown number.


8   What is the output of the following code? (You may need to use a calculator.)

      double balance[5] = { 100.0, 250.0, 325.0, 500.0, 1100.0 };
      const double INTRATE = 0.1;
      cout << fixed << showpoint << setprecision(2);

      for (int count = 0; count < 5; count++)
           cout << (balance[count] * INTRATE) << endl;

      0 100 * 0.1   =  10
      1 250 * 0.1   =  25
      2 325 * 0.1   =  32.5
      3 500 * 0.1   =  50
      4 1100 * 0.1  = 110


9 What is the output of the following code? (You may need to use a calculator.)

const int SIZE = 5;
int time[ SIZE ] = {1, 2, 3, 4, 5},
    speed[ SIZE ] = {18, 4, 27, 52, 100},
    dist[ SIZE ];

for (int count = 0; count < SIZE; count++)
    dist[ count ] = time[ count ] * speed[ count ];

    0 1 *  18 =  18
    1 2 *   4 =   8
    2 3 *  27 =  81
    3 4 *  52 = 208
    4 5 * 100 = 500


for (int count = 0; count < SIZE; count++) {
    cout << time[ count ]  << " ";
    cout << speed[ count ] << " ";
    cout << dist[ count ]  << endl;
}

    1  18  18
    2   4   8
    3  27  81
    4  52 208
    5 100 500


10. Deﬁne a two-dimensional array of ints named grades. It should have 30 rows and 10 columns.

    int grades[30][10];


11. How many elements are in the following array? double sales[6][4];

    6 * 4 = 24 elements


12  Deﬁne a two-dimensional array named settings large enough to hold the table of data below.
Initialize the array with the values in the table.

    12  24  32  21  42
    14  67  87  65  90
    19   1  24  12   8

int settings[3][5];


 */





