#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <csdtio>
#include <cstdlib>
using namespace std;

class Random {
public:
    Random() {
        random_device rd;
        seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd()};
        mt19937 eng = mt19937(seed);
        auto operator()(int a, int b) {
            uniform_int_distribution<int> dist(a, b);
            return dist(eng);
        }
    };
};

class Scribe {

};

class Canvas {
private:
    int length, witdh, ,
};

// Theory
// As Scribe changes, on a micro level, the Canvas object sends a messsage to the Scribe asking if there were any changes in its coordinates recently.
// The Scribe has the means to receive only this specific message, telling it that it needs to relay information about its progress and current position to ensure the Canvas on the screen is upto date with Scribes movements.
// After receiving the update, Canvas updates its map accodingly and signals to the Scribe that its awaiting the next move. 
// *** The scribe understands this to be the signal to continue its movements to reach its destination. 

// A simple two way interferaometer seems to be the basic virtual interface to use. Perhaps a multiplex for communicating actions without stepping over each others data. Perhaps threads may be usefulTO up tasks and make the system more efficient.

// Theory (revised)
// Scribe and Canvas objects NEED to be connected in some way
// This connection has to convey information regarding points on a grid (or 2 dimensional array)
// The Scribe should have simple information regarding its points on a grid determined by its (int)x and (int)y values
// The Scribe should change its location by modifying this information and conveying it to the Canvas object via the connection
// Therefore, the Canvas object can (in theory) have multiple Scribes. We can use multiple threads to run each Scribe object independent of each other, but not independent of the presence of the Canvas object.
// The Canvas object has different requirements for complexity dependent on the complexity of the Scribe.
// For example, if the Scribe only has the internal (x,y) information and nothing else, the Canvas object can keep a record of the Scribes movements by updating where the Scribe was and always displaying the Scribes current location with a symbol.
// ... Like with snake, the Scribe can have a head and a trail. When the info is delivered to the Canvas, the Canvas places the head character '*' at the location in the 2d array. However, when the info changes (lets say by its x value increasing by 1), the Canvas relays the change by marking all previous locations with a marker '\''. So if the Scribe was at one point at the 8,8 value of the array, that value will always contain '\'' unless the Scribe revisits the coordinate, in which the Canvas will again 'draw' the head character.
// Much of this version is dependent on the Canvas object to consistently and accurately read the value of a Scribe as it changes with every 'tick' of the clock.

// This could be very simple, however, lets say the Scribe draws a different trail from another Scribe:
// - The Scribe object would be instantiated with a given value '\''. But this character variable is modifiable during instantiation and via some method after instantiaton.
// - This would mean the Canvas would need additional complexity. Perhaps this could be done by creating a 2d array for each Scribe to move on based on the number of Scribes linked to the Canvas.
// - All of the 2d arrays could be 'added' together to form the picture you see.
// - Another way is to continue with the single array, but make the object 'gather' information from each Scribe through its internal coordinate system, but also through its given trail value and head value.
// - The Canvas would need a modified method for updating its coordanites. When it takes the info about a given Scribe, it would need to also take in the head value, to update the coordinate the Scribe sits on, and the trail value, to update the coordinates the Scribe has visited.
// - The trails could be differing in character and just replace another's trail whenever the coordinate is visited, meaning the information regarding the previous Scribe's location would be lost, or destroyed.
// - The trails could also be additive and gather general information about the number of times Scribes have visited