/**
 * copy_example
 */

// #include <iostream>

// class Passenger {
// public:
//     string name;
// };

// class Bus {
// public:
//     Passenger* pas;

//     Bus(string name) {
//         this->name = name;
//     }


//     ~Bus() {
//         if (pas != NULL) {

//             delete pas;

//         }

//     }
// };


int main() {

    // We have two instances of Bus.
    Bus bolt;
    Bus metro;

    // Create a passenger to metro.
    metro.pas = new Passenger("Masatoshi");

    // Shallow copy - Both pointing to the same object.
    bolt = metro;

    //-------------------------------------------

    Bus busses[10];  // A constant pointer to
    Bus* d13;

    // We can assign an array to a pointer.
    d13 = busses;  // OK

    busses = d13;  // NG - busses is a constant pointer.

    // These are synonymous.
    d13[5]    = new Passenger;
    busses[5] = new Passenger;

    //-------------------------------------------

    Passenger* folks[12];  // An array of pointers.

    //-------------------------------------------

    return 0;
}
