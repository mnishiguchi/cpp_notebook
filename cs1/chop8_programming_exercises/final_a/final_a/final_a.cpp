/**
 * APCT-233C-01
 * C++ Lab final 2015 - PART A
 * December 15, 2015
 *
 * Masatoshi Nishiguchi
 */
#include <iostream>
using namespace std;

void lab2015Final_P1() {

  int a = 5, b = 5,
      c = 3, d = 7;

  cout << a-- << ' ';
  cout << a   << ' ';
  cout << a-- << ' ' << a-- << ' ';
  cout << a-- << ' ' << a << endl;

  cout << ++b << ' ';
  cout << b   << ' ';
  cout << ++b << ' ' << ++b << ' ';
  cout << ++b << ' ' << b << endl;

  a = c++ * d--;
  cout << a << "  " << c << ' ' << d << endl;
}

void lab2015Final_P2() {

  int i,       // Loop control variable
      sum;     // Accumulator

  i = 1;
  while (i < 10)
  {  cout << i << ' ';
     i +=2;
  }
  cout << "\nAfter loop i = " << i
       << endl << endl;

  i = 5;
  while (i > 0)
     cout << i-- << ' ';
  cout << "\nAfter loop i = " << i
       << endl << endl;

  i = 1;
  do
  {  cout << i * i << ' ';
     i++;
  } while (i <= 3);
  cout << "\nAfter loop i = " << i
       << endl << endl;

  sum = 0;
  for (i = 0; i < 4; i++)
     sum += i;
  cout << "After loop i = " << i << endl;
  cout << "sum = " << sum << endl << endl;

  for (i = 0; i++ < 4;)
     cout << i << ' ';
  cout << "\nAfter loop i = " << i << endl;
}


int main() {

    lab2015Final_P1();
    cout << "-------------------------------------" << endl;
    lab2015Final_P2();

    return 0;
}
