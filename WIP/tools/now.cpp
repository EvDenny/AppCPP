#include <iostream> 
#include <ctime>
#include "now.hpp"
using namespace std;

Now::static void displayNow() {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    cout << "The current time is: " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;
}
