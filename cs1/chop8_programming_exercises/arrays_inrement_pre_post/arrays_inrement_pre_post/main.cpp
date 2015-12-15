//
//  arrays_inrement_pre_post
//
//  Created by Masatoshi Nishiguchi on 12/8/15.
//  Copyright © 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    
    int values[] = { 2, 6, 10, 14 };
    
    What does each of the following display?
    A)  cout <<   values[ 2 ];     // 10
    B)  cout << ++values[ 0 ];     // 3
    C)  cout <<   values[ 1 ]++;   // 7
    D)  x = 2;
    cout <<   values[ ++x ];   // 14
    
    std::cout << "Hello, World!\n";
    return 0;
}
