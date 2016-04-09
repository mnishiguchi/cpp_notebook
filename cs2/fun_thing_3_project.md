# FunThing 3 Project  
Due Date: Saturday, April 16, 2016

---DONE---

Create a new class that extends FunThing called BoardGame.  BoardGame will contain 1 purely virtual method called getRules() that will return a VERY SHORT (50 characters or less) string of the basic rules of the game.  Also make a method called setRules() as a setter for BoardGame rules.  

Make two classes that extend BoardGame called TwoPlayerBG and MultiPlayerBG.

All BoardGame will output ONLY their rules when a left-shift operator is applied.  This is far different than the output for FunThing.


Instantiate at least two instances of TwoPlayerBG and MultiPlayerBG.  Appropriately add each instance to the following vector:

vector<FunThing*> v_boardGames;

---TODO---

Correctly iterate v_boardGames and << appropriately to output through the left-shift operator.  Your loop must be coded in such a way that it will work for any number of vector elements.

## Hints and rules.

I am purposely leaving the design up to you.  Make sure you understand the requirements and come up with an appropriate, efficient design.

You are NOT allowed to change the design of FunThing.  From previous assignments, your FunThing must contain a <<, -- and ++ overload as well as the two purely virtual methods.

All TwoPlayerBG instances will always have two and exactly two players.  All BoardGame instances are not considered dangerous.

You MUST use the declaration of v_boardGames as given.

BoardGame MUST inherit from FunThing.  TwoPlayerBG and MultiPlayerBG must extend from BoardGame.

You only need to make three classes, but if you can defend a reason to use more, I will consider it.

I realize your previous submissions may have errors.  You should make every effort to correct your previous classes before doing this.  If you have trouble, I can post a starter set of code.

Note, your are NOT using the Games class for this assignment.

## Rubrik
Creation of BoardGame with a purely virtual method. 10 pts.
Objects well-designed according to rules and instructions. 20 pts.
Objects properly instantiated and populated with rules. 10 pts.
Objects properly added to v_boardGames. 10 pts.
V_boardGames properly iterated and displayed.  10 pts.
Documentation, comments, and structure. 10 pts.
