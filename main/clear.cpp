#include <iostream>
using namespace std;

#ifdef _WIN32 // Should check if the OS is windows.
    #define WINDOWS true
#endif // _WIN32 // For cross-system compatibility.

void cls() {
    if (getenv("windir") != NULL) {
        system("cls");
    } else {
        system("clear");
    }
}