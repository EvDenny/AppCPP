#ifndef _today_h
#define _today_h

#include <bits/stdc++.h>
#include <string>

using namespace std;

string dw[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
string months[13] = { "NULL", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
string m_abv[13] = { "NULL", "Jan.", "Feb.", "Mar.", "Apr.", "May", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec.   " };
int daysM[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Today
{
public:
    int d;
    int m;
    int y;
    int hour;
    int minute;
    int dotw;
    string DOTW;
    string month;
} today;    

class Input {
public:
    int mm;
    int dd;
    int yyyy;
    int dotw;
    string DotW = dw[dotw];
    string Month = months[mm];
};

#endif