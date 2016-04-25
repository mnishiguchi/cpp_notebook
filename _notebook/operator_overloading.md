# [Operator overloading](http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm)
- `std::string` comes with preconfigured operators
    + [relational operators (string)](http://www.cplusplus.com/reference/string/string/operators/)
    + [std::string::compare](http://www.cplusplus.com/reference/string/string/compare/)

==

Basic syntax.
```cpp
// Overloaded < operator
bool operator>( const Z& rhs ) {
    return val > rhs.val;
}

// How to use
// `z1.operator>( z2 )` or simply `z1 > z2`
```

Member operator overload and non-member operator overload.
```cpp
class Z {
public:
  int val;

  // Member Operator Overload
  bool operator<( const Z& rhs ) {
      return val < rhs.val;
  }
  bool operator>( const Z& rhs ) {
      return val > rhs.val;
  }
  bool operator==( const Z& rhs ) {
      return val == rhs.val;
  }
  bool operator!=( const Z& rhs ) {
      return ! operator==( rhs );
  }

}; // end class Z


// Non-member Operator Overload
// http://en.cppreference.com/w/cpp/language/operators
// IMPORTANT: operator>> and operator<< as non-member functions
ostream& operator<<( ostream& os, const Z& obj ) {
    return os << "The val is: " << obj.val;
}


// Non-member Operator Overload
bool operator==( Class_A& lhs, Class_B& rhs ) {
    return lhs.val == rhs.val;
}


int main() {
    Z z1, z2;

    z1.val = 11;
    z2.val = 99;

    //========================//

    cout << z1 << endl;

    //========================//


    if ( z1 == z2 ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //========================//

    return 0;
}
```

Three patterns to compare objects.
```cpp
    // Pattern 1
    // Compare objects using the overloaded operator.
    if ( z1 > z2 ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //------------------------//

    // Pattern 2
    // Compare objects by one of their members.
    if ( z1.val > z2.val ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }

    //------------------------//

    // Pattern 3
    if ( z1.operator>( z2 ) ) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }
```

==

## [overloading ++ for both pre and post increment](http://stackoverflow.com/a/15244185/3837223)
- [Increment/decrement operators](http://en.cppreference.com/w/cpp/language/operator_incdec)

```cpp
// prefix
CSample& operator++()
{
  // implement increment logic on this instance, return reference to it.
  return *this;
}
```

```cpp
// prefix
CSample& operator++()
{
  // implement increment logic on this instance, return reference to it.
  return *this;
}
```

==

## Overloading Square Bracket [] Operator
- http://www.cplusplus.com/forum/general/62240/

==

## [Comparing objects and inheritance](http://stackoverflow.com/a/2825479/3837223)

```cpp
class Base // Base is an abstract class
{
    virtual bool equals(const Base& b) = 0;
};

class A : public Base
{
    virtual bool equals(const Base& base)
    {
        if (const A* a = dynamic_cast<const A*>(&base))
        {
            // Return true iff this and a are equal.
        }
        return false;
    }
};

class B : public Base
{
    virtual bool equals(const Base& base)
    {
        if (const B* b = dynamic_cast<const B*>(&base))
        {
            // Return true iff this and b are equal.
        }
        return false;
    }
};
```

```cpp
bool GenericThing::operator<( const FunThing& _other ) {

    // Run-time casting.
    // http://stackoverflow.com/a/2825479/3837223
    const GenericThing* other = dynamic_cast<const GenericThing*>( &_other );

    printf("Called from GenericThing\n");

    if ( funLevel != other->getFunLevel() ) {
        return funLevel < other->getFunLevel();

    } else if ( dangerous != other->dangerous ) {
        return dangerous < other->dangerous;

    } else if ( numberOfPlayers != other->numberOfPlayers ) {
        return numberOfPlayers > other->numberOfPlayers;
    }

    return thingName < other->getThingName();
}
```

== 

## [The friend funcitons](http://www.cplusplus.com/doc/tutorial/inheritance/)

- Allow a non-member function access private members outside of the class.
- A friend class in C++ can access the "private" and "protected" members of the class in which it is declared as a friend.
