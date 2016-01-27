# Random numbers

e.g. Four dice rolls
```cpp
#include <iostream>
#include <cstdlib>     // Enables use of rand()
#include <ctime>       // Enables use of time()
using namespace std;

int main() {
   srand(time(0));     // "Seeds" the random number generator

   cout << "Four rolls of a dice..." << endl;

   // rand() % 6 yields 0, 1, 2, 3, 4, or 5
   // so + 1 makes that 1, 2, 3, 4, 5, or 6
   cout << ((rand() % 6) + 1) << endl;
   cout << ((rand() % 6) + 1) << endl;
   cout << ((rand() % 6) + 1) << endl;
   cout << ((rand() % 6) + 1) << endl;
   
   return 0;
}
```

```cpp
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

//...

std::srand ( unsigned ( std::time(0) ) );

for (int i = 0; i < ARRAY_SIZE; i++) {

  // Generate an index randomly
  int index = rand() % ARRAY_SIZE;
  double temp = myList[i];
  aList[i] = aList[index]; 
  aList[index] = temp;
}


```


http://www.cplusplus.com/reference/algorithm/random_shuffle/
```cpp
// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand() % i; }

int main () {
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  std::random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
```
