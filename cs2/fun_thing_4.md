# FunThing 4
Sunday, May 1, 2016

Note, the Games, BoardGame (or any of its subclasses) classes are NOT needed.

## Specs
### Data files
- Read data from provided file
- Create any number of GenericThing, CrazySport, and DomesticChore instances.
- Each row must make a new instance of one of these three classes.
- Each class must add a pointer to the instance to a single STL object of your choice.
- Before choosing an STL, note that you will need to find the "greatest" and the "least" FunThing in all of these.
- Also note that whatever STL you use, all objects added are added as FunThing pointers.  So, for instance, if you choose to add your items to a vector, your STL must be declared as something like: `vector<FunThing*> vThings;`

### Comparing FunThing instances (overload `>` operator on FunThing)
NOTE: Assume that all the items are unique.
1. **greater funLevel** - A FunThing is greater than another if it's fun level is larger.  
2. **dangerous is greater** - If two FunThing's have the same funLevel, then the one that is dangerous is greater.
3. **lesser number of players** - Should they have equal values for both of these, the one with the LESSER number of players is considered greater.  
4. **ASCII value of thingName** - if all these values are the same, use the alphabetical order of the thing name to determine which is "greater". 

### Methodology
We have gone over several ways to find a greatest and a least in a collection.  Some of the STL objects can assist in this requirement,
some better than others.  I am leaving the methodology up to you, but the STL is there to help in common requirements such as this.
I recommend that you review the different options and somehow use an STL object to help you here.

**std::max_element and std::min_element**
 -http://www.cplusplus.com/reference/algorithm/max_element/

### RUBRIK
- Overload the greater-than operator correctly at the FunThing level.  15 pts

- Load all of the data in the correct subclasses correctly into an STL. 15 pts.

- Write a FUNCTION that will accept the STL container you have selected and two pointers to FunThing. 15 pts
- The function must return void and all parameters must be passed-by-ref.
- The function must correctly assign the "greatest" and the "least" to the passed-in pointers.

- Test that the code works by following the example below: 10 pts

```
vector<FunThing*> vC;  //You may choose a different contain than vector

//Open the file and load the data into vC
//close the file

FunThing *high, *low;

getHighLowThings(vC, high, low);  //Note, these 3 parameters are all passed by reference.

//Output the results that were stuffed into high and low pointers
```

- General logic, style, comments, and documentation.  10 pts.


EXTRA CREDIT
Write a function called getHighest() that will return nothing, but will fill a vector with x highest FunThing's contained in a supplied STL container.  A string exception must be thrown if the number of highest elements sought (x) is greater than the number of elements in the container or if that number is less-than 1.
So, in the code below, highestThings will be filled with the top 4 things from vC.  Ensure you are prepared to catch any exceptions thrown by getHighest().

```
vector<FunThing*> vC;  //You may choose a different contain than vector
vector<FunThing*> highestThings;


getHighest(vC, highestThings, 4);
```

//Iterate highestThings to see the results

-----------------------------------------------------------------------------

Use this code to help in the file processing

```
int main()
{

    
    ifstream thingsFile;

    char tType[5], tName[30]; //, line[70];
    char funLev[4], numPlay[4], dangerous[2];

    string s_tType, s_dangerous;

    thingsFile.open("C:/funthingfile.txt");

    FunThing* ft=NULL;
    
    while(!thingsFile.eof())
    {

        thingsFile.getline(tType,5, ',');
        s_tType=tType;
        
        thingsFile.getline(tName,30, ',');
        thingsFile.getline(funLev,30, ',');
        thingsFile.getline(numPlay,4, ',');
        thingsFile.getline(dangerous,30, '\n');
        s_dangerous = dangerous;
        

        //set ft = to one of the following
        if(s_tType == "GT")
            //instantiate GenericThing
            ft = new GenericThing(atoi(funLev), tName, atoi(numPlay), (dangerous == "1"));
        else if(s_tType == "CS")
        {
            //instantiate CrazySport
        }
        else if(s_tType == "DC")
        {
            //instantiate DomesticChore
        }
        else

            continue;


        //Add ft to your STL object

    }


    thingsFile.close();
```
