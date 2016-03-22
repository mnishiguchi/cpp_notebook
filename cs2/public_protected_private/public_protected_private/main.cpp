//
//  public_protected_private
//
//  Created by Masatoshi Nishiguchi on 3/10/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Destination {
public:
  string name;
protected:
  int rating;
private:
  double cost;
};

class Planet : public Destination {
public:
  void doIt() {
    name   = "Masatoshi";
    rating = 10;
    // cost   = 9;   // Cannot access a private member of its superclass.
  }
};

int main() {

  Destination dest;

  cout << "name:   " << dest.name << endl;
  // cout << "rating: " << dest.rating << endl;  // Cannot access a protected member.
  // cout << "cost:   " << dest.cost   << endl;  // Cannot access a private member.

  return 0;
}
