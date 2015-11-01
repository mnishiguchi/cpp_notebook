//
//  simple_triangles
//
//  Created by Masatoshi Nishiguchi on 11/1/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    const int NUM_ROWS = 10;

    cout << "\nPattern A" << endl;

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "+";
        }
        cout << endl;
    }

    cout << "\nPattern B" << endl;

    for (int i = NUM_ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}
