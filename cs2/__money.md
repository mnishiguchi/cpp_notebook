# Money

```
Money < PrecMetal < Silver
      < USDollar  < USCoin
MetalType
MoneyHolder
```


Create the Money class.
Note which two methods are purely virtual and what that means.

Implement the == method for Money as a non-member overload.  
It should compare the relative values for getTotalValue() for lhs and rhs.

bool operator==( Money& lhs , Money& rhs)

 

Create the USDollars class.  Note its relationship to Money.

 

Make the MoneyHolder class.  Implement the addMoney method.  Note the parameter type.  MoneyHolder's addMoney method should dynamically hold any number of Moneys very similar to the Games class holding FunThing.  You should NOT delete any pointer elements held except the Money ** itself.

Instantiate a MoneyHolder pointer dynamically and call it wallet.

Add some USDollars to wallet.

Implement the getTotalValue() in MoneyHolder.  This method simply iterates every Money and accumulates the total as reported by getTotalValue().  Call the method with the added Money.  Is the value as expected?

Implement the USCoins class.  Note its relationship to USDollars and what that means.

Now, add a mixture of USDollars and USCoins to wallet.  Wallet is now able to process two different class types, USDollars and USCoins, why?

 

Implement MetalType and PreciousMetal, noting their relationship to each other and other classes.  Note that PreciousMetal can consist of more than 1 MetalType.

  

Create SilverBar.  Note that silver bars' value tend to fluctuate and may have a differeing notion of getTotalValue().  An instance of SilverBar should return its getCurrentValue() as the getTotalValue().

 

Implement a pre- or post ++ operator on SilverBar so the the following code (assuming pre) is valid:
SilverBar valueBrick;  //Your constructor may be different
//Add any code needed to properly setup valueBrick

++valueBrick;  //Should be able to apply this operator.

The ++ operator on SilverBar should increment its currentValue by 1.
