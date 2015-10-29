# Data structures - Extra Credit 1

Due: Sunday, November 22, 2015

Implement a function called getAgeAppropriate() that will accept the head pointer to a linked list of VGameNode and a minimum age both as parameters.  This is the same VGameNode used in previous examples.  The function must traverse the linked list and return a linked list head pointer to a new linked list that contains VGameNodes whose minimum age is less than or equal to the passed-in parameter.  If no games are less than or equal to the passed in minimum age parameter, the function must return NULL.  You should note a few things:

The ONLY class you need for this is VGameNode.
The new linked list returned must not interfere with the passed-in linked list, therefore you must create new nodes and you should consider implementing a copy constructor.
