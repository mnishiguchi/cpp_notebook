# FunThing2

## I. Make changes to the FunThing class.

### 1)  FunThing must now contain two purely virtual methods:
DONE

### 2) Create three subclasses of FunThing.  CrazySport and DomesticChore must be able to take as a constructor argument the number of players.  GenericThing must accept number of players and whether or not it is dangerous.

```cpp
// All instances of CrazySport considered dangerous.
CrazySport(numberOfPlayers)  

// All instances of DomesticChore are NOT dangerous
DomesticChore(numberOfPlayers) 
GenericThing(numberOfPlayers, isdangerous)
```

### 3) Overload the pre-increment and pre-decrement operators on FunThing.  When invoked, the funLevel should be increased or decreased as appropriate.

Create some instances of each and add to games. 


### 4) Add a meth to Games that will output the following 4 lines for each `FunThing` in the following way.  The output MUST be created via the stream-insertion operator.

FunThing: the name of the thing
Players: the number of players
Fun Level output
Last line

The Fun Level output must show the following text according to the funLevel:

```
It's super-fun if 8 or more
It's very fun if 7
It's ok fun if 3-6, inclusive
It's no fun if 0 - 2, inclusive
It's pretty boring if less than 0
```

For the last line 

If the FunThing is not dangerous, the last line should read:
It's fun for Everyone
otherwise, it should read
Be careful, it can be dangerous

### 5) Add a void method to Games called makeMoreFun().  This method must iterate all of the FunThings held in Games and increment each FunThing by 1.  This must be done by invoking the ++ operator on each method.

