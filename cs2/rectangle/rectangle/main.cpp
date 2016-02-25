//
//  main.cpp
//  rectangle
//
//  Created by Masatoshi Nishiguchi on 2/25/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

// C.Ch13 Templates and Overloading.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;


//Exmple 13-3
//p. 876 - 879
class rectangleType {
public:
  void setDimension(double l, double w);
  //Function to set the length and width of the rectangle.
  //Postcondition: length = l; width = w;
    double getLength() const;
    //Function to return the length of the rectangle.
    //Postcondition: The value of length is returned.
    double getWidth() const;
    //Function to return the width of the rectangle.
    //Postcondition: The value of width is returned.
    double area() const;
    //Function to return the area of the rectangle.
    //Postcondition: The area of the rectangle is
    // calculated and returned.
    double perimeter() const;
    //Function to return the perimeter of the rectangle.
    //Postcondition: The perimeter of the rectangle is
    // calculated and returned.
    void print() const;
    //Function to output the length and width of
    //the rectangle.
    rectangleType();
    //Default constructor
    //Postcondition: length = 0; width = 0;
    rectangleType(double l, double w);
    //Constructor with parameters
    //Postcondition: length = l; width = w;

private:
  double length;
  double width;
};



void rectangleType::setDimension(double l, double w)
{
  if (l >= 0) length = l; else length = 0;
  if (w >= 0) width = w; else width = 0;
}
double rectangleType::getLength() const { return length; }
double rectangleType::getWidth()const { return width; }
double rectangleType::area() const { return length * width; }
double rectangleType::perimeter() const { return 2 * (length + width); }
void rectangleType::print() const { cout << "Length = " << length << "; Width = " << width; }
rectangleType::rectangleType(double l, double w) { setDimension(l, w); }
rectangleType::rectangleType() { length = 0; width = 0; }


// ---
// Utility functions
// ---

void rectangleFriend(rectangleType recFriendObject)
{
  cout << "recFriendObject area: "
    << recFriendObject.area()
    << endl;


  //=================================//
  // recFriendObject.length = recFriendObject.length + 5;
  // recFriendObject.width = recFriendObject.width + 5;
  double l = recFriendObject.getLength() + 5;
  double w = recFriendObject.getWidth() + 5;
  recFriendObject.setDimension(l, w);
  //=================================//


  cout << "After increasing length and width by 5 units "
    << "each, \n recFriendObject area: "
    << recFriendObject.area()
    << endl;
}
class boxType : public rectangleType
{
public:
  void setDimension(double l, double w, double h);
  double getHeight()const;
  double area() const;
  double volume() const;
  void print() const;
  boxType(double l = 0, double w = 0, double h = 0); //Constructor with default parameters
private:
double height;
};

int main()
{ //Line 6
  rectangleType myYard(25, 18); //Line 7
  cout << fixed << showpoint << setprecision(2); //Line 8
  cout << "myYard area: " <<
    myYard.area()
    << endl; //Line 9
  cout << "Passing object myYard to the friend "
    << "function rectangleFriend."
    << endl; //Line 10
  rectangleFriend(myYard); //Line 11















  /*


  */
  system("pause");
    return 0;
}
