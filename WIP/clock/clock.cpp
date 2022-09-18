#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

void hms(int hms) {
	if (hms < 10) {
		cout << "0" << hms;
	} else {
		cout << hms;
	}
}

int main () {
	time_t t = time(0);
	tm *tm = localtime(&t);
	int year = tm->tm_year + 1900;
	int month = tm->tm_mon + 1;
	int day = tm->tm_mday;
	int hour = tm->tm_hour;
	int minute = tm->tm_min;
	int second = tm->tm_sec;
	cout << year << "-" << month << "-" << day << " ";
	hms(hour); cout << ":";
	hms(minute); cout << ":";
	hms(second); cout << endl;
	return 0;
}