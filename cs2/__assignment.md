# Games List Class -Lecture Project  

- Due Date: Wednesday, March 2, 2016 7:32 PM
- We will be going over this extensively in class!


In C++, dynamic arrays are a powerful structure that allow the creation of only what is needed as opposed to static array that can only allocate a fix number of elements.  We can use this dynamic to hold and process a collection of objects efficiently.

Create a class called Games that will dynamically hold instances of FunThing.  The class should contain at least a dynamic array of FunThing pointer called data; data must be a private class member.  Upon instantiation, this dynamic array should be set to NULL.  The Games class must have the ability to add FunThings by allocating a new instance of FunThing and adding that to the array.  The array should dynamically grow in capacity by a certain number of elements called chunk.  That chunk number of elements will be indicated by a private class member called chunk.

Further, the Games class must include methods to:

-Add a FunThing
-Report on the current number of elements it is holding
-Return whether or not a FunThing matching a name parameter exists in the collection.


So, a potential flow of adding a FunThing may go as follows:

An instance of Games is dynamically instantiated in main().

A FunThing is added.  Because this is the first FunThing, the add() method must allocate chunk number of elements.  Then, a new instance of FunThing must be allocated.  Finally, the pointer to the new instance is put to the data array.

A FunThing is added that overflows the current capacity.  The add() method must allocate the current capacity + chunk number of elements.
The old data must be moved into the new array (the old elements must not be recreated, just moved to the new array.
The old array must be destructed.
The new array becomes the new data.


The destructor for Games must properly deallocate everything that was created by the Games class.

We WILL be adding to this class in the future.
