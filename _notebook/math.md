# math functions

- has about 20 math operations available for floating-point values
- `#include <cmath>`
- [doc](http://www.cplusplus.com/reference/cmath/)

```cpp
#include <iostream>
#include <cmath>
using namespace std;

// ...

double sideSquare = 0.0;
double areaSquare = 49.0;

sideSquare = sqrt(areaSquare);

```

## trig functions

- Value representing an angle expressed in radians.
- One radian is equivalent to 180/PI degrees.
- [doc](http://www.cplusplus.com/reference/cmath/cos/)
```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    double param, result;
    param = 60.0;
    
    result =  cos(param * M_PI / 180.0);
    printf("The cosine of %.1f degrees is %f.\n", param, result );
    
    return 0;
}
```

==
