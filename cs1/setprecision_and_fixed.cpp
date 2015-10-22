//
//  setprecision_and_fixed.cpp
//  20151020_lec
//
//  Created by Masatoshi Nishiguchi on 10/20/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // Without `fixed`
    cout << setw(6) << showpoint << setprecision(2) << 215.0 << endl;

    // With `fixed`
    cout << fixed;
    cout << setw(6) << showpoint << setprecision(2) << 215.0 << endl;

    return 0;
}
