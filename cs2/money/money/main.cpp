//
//  main.cpp
//  money
//
//  Created by Masatoshi Nishiguchi on 3/10/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


/**
 * An abstract class that represents money.
 */
class Money {
public:
  virtual bool isPaperBased()=0;
  virtual double getTotalValue()=0;
};


/**
 * Operator overload to compare Money objects.
 */
bool operator==( Money& lhs , Money& rhs) {
  return lhs.getTotalValue() == rhs.getTotalValue();
}


/**
 * Create the USDollars class.
 * Note its relationship to Money.
 */
class USDollars : public Money {
public:
  double denom;
  int howManyBills;
};


/**
 *
 */
class USCoins : public USDollars {
public:
  USCoins(double w);
  double getWeight();
private:
  double weight;
};

/**
*
*/
class MetalType {
public:
  string metalName;
  double proportion;

};

/**
 *
 */
class PreciousMetal : public Money {
public:
  MetalType *metals;

};

/**
 *
 */
class SilverBar: public PreciousMetal {
public:
  void setCurrentValue(double);
  double getCurrentValue();


};

/**
 *
 */
class MoneyHolder {
public:
  void addMoney( Money *moneyPtr );
  double getTotalValue();
private:
  Money **cash;
  int numberOfItems;
};

