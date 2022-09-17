#include <iostream>
#include <string>
#include <tuple>
#include <ctime>
#include <time.h>
using namespace std;

time_t t = time(0)  ;
struct tm *Now = localtime(&t);

int main() {
    cout << Now->tm_hour;
    return 0;
}