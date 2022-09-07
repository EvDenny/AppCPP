#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	cin.clear();
	time_t t = time(0);
	tm *tm = localtime(&t);
	char *tim = asctime(localtime((&t)));
	int year = tm->tm_year + 1900;
	int month = tm->tm_mon + 1;
	int day = tm->tm_mday;
	int hour = tm->tm_hour;
	int minute = tm->tm_min;
	int second = tm->tm_sec;
	cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
	cout << tim << endl;
	std::cout << "       ___/--\\___       " << std::endl;
	std::cout << "     _/    12    \\_     " << std::endl;
	std::cout << "   _/ 11   |     1 \\_   " << std::endl;
	std::cout << "  /        |         \\  " << std::endl;
	std::cout << " | 10      ||       2 | " << std::endl;
	std::cout << "/          ||          \\" << std::endl;
	std::cout << "| 9        o         3 |" << std::endl;
	std::cout << "\\                      /" << std::endl;
	std::cout << " |  8              4  | " << std::endl;
	std::cout << "  \\_                _/  " << std::endl;
	std::cout << "    \\_ 7        5 _/    " << std::endl;
	std::cout << "      \\___ 6. ___/      " << std::endl;
	std::cout << "          \\--/          " << std::endl;
	std::cout << "                       " << std::endl;
	return 0;
}


