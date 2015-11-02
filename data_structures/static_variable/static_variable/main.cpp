//
//  main.cpp
//  static_variable
//
//  Created by Masatoshi Nishiguchi on 11/1/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

class Foo {
public:
    static int getInstanceCount();
    Foo();
    
private:
    static int count;
};

// Initialize the instance counter
int Foo::count = 0;

Foo::Foo() {
    count += 1;
}

int Foo::getInstanceCount() {
    return count;
}

int main() {
    cout << Foo::getInstanceCount() << endl;

    Foo f1;
    cout << Foo::getInstanceCount() << endl;
    
    Foo f2;
    cout << Foo::getInstanceCount() << endl;
    
    return 0;
}
