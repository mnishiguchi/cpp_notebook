# Inheritance and Composition
- Two common ways to relate classes in a meaningful way
    + Inheritance ('is-a' relationship)
    + Composition (aggregation) ('has-a' relationship)
- https://www.thoughtworks.com/insights/blog/composition-vs-inheritance-how-choose

==

## Polymorphism
- 'is-a' relationship
- having many forms
- occurs when there is a hierarchy of classes and they are related by inheritance
- a call to a member function will cause a different function to be executed depending on the type of object that invokes the function

==

## Inheritance
- 
    + Single inheritance
        + derived from a single base class; 
    + Multiple inheritance
        + derived from more than one base class

```cpp
class className: memberAccessSpecifier baseClassName {

    // member list

};
```

### Base Access Specifier
- [Difference between private, public, and protected inheritance](http://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance)

```cpp
class A 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
```

### "super" in C++

- http://stackoverflow.com/a/180633/3837223

==

## Composition

- 'has-a' relationship
- one or more members of a class are objects of another class type.



