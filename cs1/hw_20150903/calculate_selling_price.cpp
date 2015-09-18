//
//  calculate_selling_price.cpp
//  pp25-26, #18
//
//  Created by Masatoshi Nishiguchi on 9/4/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

double calcSellingPrice(double costPrice, bool isMarkedDown);

int main(int argc, const char * argv[]) {
    cout << calcSellingPrice(300.99, false) << endl;
    
    return 0;
}

// #18
double calcSellingPrice(double costPrice, bool isMarkedDown) {
    const double MARK_UP  = 0.8;  // to make a profit
    const double DISCOUNT = 0.1;

    double regularPrice = costPrice * (1.0 + MARK_UP);

    if (isMarkedDown) {
        return regularPrice * (1.0 - DISCOUNT);
    }
    else {
        return regularPrice;
    }
}
