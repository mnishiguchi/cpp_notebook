//
//  main.cpp
//  _14_hard_drive_storage_capacity
//
//  In computer memory, 1KB is equal to 1024 bytes.
//  So the actual storage on a 40GB hard drive is approximately 37.25GB.
//
//  Prompts the user to enter the size of the hard drive specified by the manufacturer.
//  Outputs the actual storage capacity of the hard drive.
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {

    const int KB_IN_BYTES = 1024;                // 2^10 bytes
    const int MB_IN_BYTES = 1024 * KB_IN_BYTES;  // 2^20 bytes
    const int GB_IN_BYTES = 1024 * MB_IN_BYTES;  // 2^30 bytes
    
    double manufacturerGB;
    double manufacturerBytes;
    double actualGB;
    
    // Input
    cout << "Enter the GB size specified by the manufacturer: ";
    cin >> manufacturerGB;
    
    // Convert manufacturerGB into bytes
    manufacturerBytes = manufacturerGB * 1000 * 1000 * 1000;
    
    // Calculate the actual GB
    actualGB = manufacturerBytes / GB_IN_BYTES;
    
    // Output
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "The actual size of the hard drive: " << actualGB << "GB" << endl;
    
    return 0;
}
