# Unit testing
- https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks
- Testing a class can be done by creating a special program, sometimes known as a **testbench**, whose job is to thoroughly test the class.
- The process of creating and running a program that tests a specific item (or "unit"), such as a function or a class, is known as unit testing.
- Calling each function at least once is a minimal requirement of testing, but **does not guarantee correctness**.
- A class should be tested individually before being used in another program. When used in another program, class bugs may be harder to discover.
- A testbench may be in a separate file from the class, such as in file MyClassTest.cpp for a class MyClass.
- The testbench should be maintained for the lifetime of the class code, and run again (possibly updated first) whenever a change is made to the class.

### good practice
- Automatically check for correct execution rather than relying on a user reading program output
- Assert statements
- Keep each test independent from the previous case, as much as possible, so that problems are more readily detected

### code coverage
- A goal of testing is to achieve complete code coverage : all code is executed at least once
- Minimally for a class, every public function is called at least once
- But a line of code may work fine for some values yet fail on other values

### border cases
- Testing all possible values is simply impossible for nearly any class. Instead, some typical values and some border cases should be tested.
- Tests should include at least some typical values and some border cases, which for integers may include 0, large numbers, negative numbers, etc. 

### regression testing
- Running an existing testbench whenever code is changed is known as regression testing, due to checking whether the change caused the code to "regress", meaning to fail previously-passed test cases. 

== 

