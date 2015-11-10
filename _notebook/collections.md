# Collections
- [Standard Containers](http://www.cplusplus.com/reference/stl/)

## Static Map as Class Member in C++
http://stackoverflow.com/questions/19336236/static-map-as-class-member-in-c

## Printing all the keys and values of a map

```cpp
static void printDictionary() {
    for(auto it = aDictionary.cbegin(); it != aDictionary.cend(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}
```
or
```cpp
static void printDictionary() {
    for (auto it : aDictionary) {
        cout << it.first << " " << it.second << endl;
    }
}
```
