#include <ctime>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include "mdy.h"
#include "clear.h"
using namespace std;

int dd, mm, yyyy, day, month, year, dotw, hour, minute, second;

struct _time
    {
    int dd;
    int mm;
    int yyyy;
    int DOTW;
    } input;

string weekdays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };
int monthDays[13]{ 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void hms(int hms)
    {
    if (hms < 10)
        {
        cout << "0" << to_string(hms);
        }
    else
        {
        cout << to_string(hms);
        }
    }

class Calendar
    {
    private:
        bool _continue = false;
        bool finish = false;
        int Today;
        int _count;
        bool future = false;
        bool past = false;
    public:
        Calendar(bool future = false, bool past = false, int _count = 0, int today = dotw, bool finish = false) : _count(_count), Today(today), finish(finish) { this->future = future; this->past = past; this->_continue = _continue; };
        inline bool getFuture() { return future; };
        inline bool getPast() { return past; };
        inline bool getFinish() { return finish; };
        inline void setFinish(bool value) { finish = value; };
        inline void setContinue(bool value) { _continue = value; };
        inline string returnDOTW(int value) { string val = weekdays[value]; return val; };
        inline int getDOTW() { return Today; };
        inline void setToday(int value) { Today = value; }
        inline void fToday() { Today++; if (Today > 6) { Today = 0; } };
        inline void pToday() { Today--; if (Today < 0) { Today = 6; } };
        inline void displayTime() { hms(hour); cout << ":"; hms(minute); cout << ":"; hms(second); cout << ":"; };
        inline void currentTime() { cout << "Today is " << returnDOTW(dotw) << ", " << month << " " << day << ", " << year << ". \n" << "The time is "; displayTime(); };
        inline int getCount() { return _count; };
        inline void count() { if (past) { dd--; Today--; if (Today < 0) { setToday(6); } } else if (future) { dd++; Today++; if (Today > 6) { setToday(0); } } _count++; };
        inline void Future() { cout << "The date you entered is in the future!\n"; future = true; };
        inline void Past() { cout << "The date you entered is in the past!\n"; past = true; };
        inline bool leapDay(int month, int year) { return (month == 2 && year % 4 == 0); };
        int Input(int input, string question, int max, int min, int max2 = 31, bool value = false);
        void handleInput(int INPUT, int max, int min);
        void getInput();
        void checkInput();
        void checkFinish();
        void prevMonth();
        void nextMonth();
        void nextYear();
        void prevYear();
        void mainloopForward();
        void mainloopBackward();
    };

void Calendar::prevMonth()
    {
    if ((mm == 3 && yyyy % 4 == 0) && dd == 1)
        {
        mm--;
        dd = monthDays[mm - 2];
        _count++;
        pToday();
        checkFinish();
        }
    else if (dd == 1 && mm != 1)
        {
        mm--;
        dd = monthDays[mm];
        _count++;
        pToday();
        checkFinish();
        };
    }

void Calendar::nextMonth()
    {
    if (mm == 2 && yyyy % 4 == 0)
        {
        if (dd == monthDays[0])
            {
            mm++;
            dd = 1;
            _count++;
            fToday();
            checkFinish();
            }
        }
    else if (dd == monthDays[mm] && mm != 12)
        {
        mm++;
        dd = 1;
        _count++;
        fToday();
        checkFinish();
        };
    }

void Calendar::prevYear()
    {
    if (mm == 1 && dd == 1)
        {
        mm = 12;
        dd = monthDays[mm];
        yyyy--;
        _count++;
        pToday();
        checkFinish();
        }
    }

void Calendar::nextYear()
    {
    if (mm == 12 && dd == monthDays[mm])
        {
        mm = 1;
        dd = 1;
        yyyy++;
        _count++;
        fToday();
        checkFinish();
        };
    }

void Calendar::checkFinish()
    {
    if (mm == input.mm && input.dd == dd && input.yyyy == yyyy)
        {
        setFinish(true);
        if (past || future)
            {
            cout << "That day is " << _count << " days away!" << endl;
            if (getFuture()) {
                cout << "It will be a " << returnDOTW(Today) << "!" << endl;
            } else if (getPast()) {
                cout << "It was a " << returnDOTW(Today) << endl;
            }
            this_thread::sleep_for(chrono::milliseconds(800));
            setFinish(true);
            }
        }
    }

void Calendar::checkInput() {
    if (input.yyyy != yyyy) {
        if (input.yyyy > yyyy) {
            Future();
        } else if (input.yyyy < yyyy) {
            Past();
        }
    } else if (input.yyyy == yyyy) {
        if (input.mm != mm) {
            if (input.mm > mm) {
                Future();
            } else if (input.mm < mm) {
                Past();
            }
        } else if (input.mm == mm) {
            if (input.dd != dd) {
                if (input.dd > dd) {
                    Future();
                } else if (input.dd < dd) {
                    Past();
                }
            } else if (input.dd == dd) {
                    checkFinish();
                }
            }
        }
    }

int Calendar::Input(int input, string question, int max, int min, int max2, bool value)
    {
    do
        {
        cin.clear();
        cout << question;
        cin >> input;
        if (value)
            {
            handleInput(input, max2, min);
            }
        else
            {
            handleInput(input, max, min);
            }
        }
    while (!_continue);
        return input;
    }

void Calendar::getInput()
    {
    cout << "Enter a date. It will tell you how many days away it is and that day of the week." << endl;
    int _yyyy, _mm, _dd;
    input.yyyy = Calendar::Input(_yyyy, "Enter a year (e.g. 2022):", 12000, -10000);
    input.mm = Calendar::Input(_mm, "Enter a month:", 12, 1);
    input.dd = Input(_dd, "Enter a day:", monthDays[input.mm], 1, monthDays[0], leapDay(input.mm, input.yyyy));
    };

void Calendar::handleInput(int INPUT, int max, int min)
    {
    if (INPUT > max || INPUT < min)
        {
        setContinue(false);
        cout << "Please enter a value in the range " << min << " to " << max << endl;
        }
    else
        {
        setContinue(true);
        };
    };

void Calendar::mainloopForward()
    {
    do
        {
        nextYear();
        nextMonth();
        if (!getFinish())
            {
            count();
            checkFinish();
            }
        }
    while (!getFinish());
    };

void Calendar::mainloopBackward()
    {
    do
        {
        prevYear();
        prevMonth();
        count();
        checkFinish();
        }
    while (!getFinish());
    };

void CalendarTool() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
    hour = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;
    dotw = now->tm_wday;
    bool done = false;
    do 
    {
        dd = day;
        mm = month;
        yyyy = year;
        Calendar cal;
        cal.currentTime();
        cal.getInput();
        cal.checkInput();
        if (cal.getFuture())
            {
            cal.mainloopForward();
            }
        else if (cal.getPast())
            {
            cal.mainloopBackward();
            }
        this_thread::sleep_for(chrono::milliseconds(800));
        bool endswitch = false;
        do {
            cout << "Press 1 to continue or 2 to use again." << std::endl;
            int input;
            cin >> input;
            switch (input) {
                case 1:
                    endswitch = true;
                    done = true;
                    break;
                case 2:
                    endswitch = true;
                    done = false;
                    break;
                default:
                    endswitch = false;
                    cout << "Invalid input. Please try again..." << std::endl;
                    break;
                }
            cls();
        } while (endswitch = false);
    } while (!done);
}