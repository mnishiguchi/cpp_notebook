# Memo

## ENUM
-  used for better readability.

```cpp
#include <iostream>
using namespace std;

// Enum is used for better readability.
enum PEOPLE { PERSON_1, PERSON_2, PERSON_3 }; // Use instead of 0..2
enum REGION { REGION_1, REGION_2 };          // Use instead of 0..1

int main() {
     double sales[3][2];

     sales[PERSON_1][REGION_1] = 23.2;
     sales[PERSON_1][REGION_2] = 87.66;
     sales[PERSON_2][REGION_1] = 96.3;
     sales[PERSON_2][REGION_2] = 34.6;
     sales[PERSON_3][REGION_1] = 2;
     sales[PERSON_3][REGION_2] = 102.4;

    // ...

    return 0;
}
```

==

## Unified modeling languages (UML)

- List class members
