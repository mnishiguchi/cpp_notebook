//
//  main.cpp
//  fill_characters
//
//  Created by Masatoshi Nishiguchi on 11/3/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    char  fill = '*';
    
    do {
        cout << endl;
        cout << fill << fill << fill << endl;
        cout << fill << fill << fill << endl;
        cout << fill << fill << fill << endl;
        cout << "Enter char (q to quit): ";
        cin  >> fill;
    } while (fill != 'q');
    
    return 0;
}
