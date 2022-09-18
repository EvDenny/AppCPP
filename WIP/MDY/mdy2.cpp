#include <ctime>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int dd, mm, yyyy, day, month, year, dotw, hour, minute, second;

struct _time {
    int dd;
    int mm;
    int yyyy;
    int DOTW;
} input;

string weekdays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };
int monthDays[13]{ 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void hms(int hms) {
	if (hms < 10) {
		cout << "0" << to_string(hms);
	} else {
		cout << to_string(hms);
	}
}

class Calendar {
private:
    bool _continue = false;
    bool finish;
    int Today;
    int _count;
    bool future = false; 
    bool past = false;
public:
    Calendar(bool future = false, bool past = false, int _count = 0, int today = dotw, bool finish = false) : _count(_count), Today(today), finish(finish) { future; past; _continue; };
    inline bool getFuture() { return future; };
    inline bool getPast() { return past; };
    inline void setContinue(bool value) { _continue = value; };
    inline string returnDOTW(int value) { string val = weekdays[value]; return val; };
    inline int getDOTW() { return Today; };
    inline void setToday(int value) { Today = value; }
    inline void fToday() { Today++; if (Today > 6) { Today = 0; } };
    inline void pToday() { Today--; if (Today < 0) { Today = 6; } };
    inline void displayTime() { hms(hour); cout << ":"; hms(minute); cout << ":"; hms(second); cout << ":"; };
    inline void currentTime() { cout << "Today is " << returnDOTW(dotw) << ", " << month << " " << day << ", " << year << ". \n" << "The time is "; displayTime(); };
    inline int getCount() { return _count; };
    inline void count() { if (past) { dd--; Today--; if (Today<0) { setToday(6); } } else if (future) { dd++; Today++; if(Today>6) {setToday(0); } } _count++; };
    void check();
    void handleInput(int INPUT, int max, int min);
    void getInput();
    void prevMonth();
    void nextMonth();
    void nextYear();
    void prevYear();
    void mainloopForward();
    void mainloopBackward();
};

void Calendar::prevMonth() {
    if ((mm==3 && yyyy%4==0) && dd==1) {
        mm--;
        dd=monthDays[mm-2];
        _count++;
        pToday();
        check();
    } else if (dd==1 && mm != 1) {
        mm--;
        dd=monthDays[mm];
        _count++;
        pToday();
        check();
    };
}

void Calendar::nextMonth() { 
    if ((mm==2 && yyyy%4==0) && dd==monthDays[0]) {
        mm++; 
        dd=1;  
        _count++;
        fToday();
        check();
    } else if (dd==monthDays[mm] && mm!=12) { 
        mm++; 
        dd=1;
        _count++;
        fToday();
        check();
    }; 
}

void Calendar::prevYear() {
    if (mm==1 && dd==1) {
        mm = 12;
        dd = monthDays[mm];
        yyyy--;
        _count++;
        pToday();
        check();
    }
}

void Calendar::nextYear() { 
    if (mm==12 && dd==monthDays[mm]) { 
        mm = 1; 
        dd = 1; 
        yyyy++; 
        _count++;
        fToday();
        check(); 
    }; 
}

void Calendar::check() {
    if (mm == input.mm && input.dd == dd && input.yyyy == yyyy) {
        finish = true;
        if (past || future) {
            cout << "That day is " << _count << " days away!" << endl;
            cout << "It is a " << returnDOTW(Today) << "!" << endl;
            this_thread::sleep_for(chrono::milliseconds(2200));
            finish = true;
            exit(0);
        }
    }
    if (!past && !future) {
        if (input.mm >= mm && input.yyyy == yyyy) {
            if (input.mm == mm && input.dd > dd) {
                cout << "The date you entered is in the future!\n";
                future = true;
            } else if (input.mm == mm && input.dd < dd) {
                cout << "The date you entered is in the past!\n";
                past = true;
            } else {
                cout << "The date you entered is in the future!\n";
                future = true;
            }
        } else if (input.mm <= mm && input.yyyy == yyyy) {
            if (input.mm == mm && input.dd > dd) {
                cout << "The date you entered is in the future!\n";
                future = true;
            } else if (input.mm == mm && input.dd < dd) {
                cout << "The date you entered is in the past!\n";
                past = true;
            } else {
                cout << "The date you entered is in the past!\n";
                past = true;
            }
        } else if (input.yyyy > yyyy) {
            cout << "The date you entered is in the future!\n";
            future = true;
        } else if (input.yyyy < yyyy) {
            cout << "The date you entered is in the past!\n";
            past = true;
        }
    }
};

void Calendar::getInput() {
    cout << "Enter a date. It will tell you how many days away it is and that day of the week." << endl;
    int _yyyy;
    do{
        cin.clear();
        cout << "Enter a year (e.g. 2022):";
        cin >> _yyyy;
        handleInput(_yyyy, 12000, -10000);
    } while (!_continue);
    int _mm;
    do{
        cin.clear();
        cout << "Enter a month:";
        cin >> _mm;
        handleInput(_mm, 12, 1);
    } while (!_continue);
    int _dd;
    do {
        cin.clear();
        cout << "Enter a days:";
        cin >> _dd;
        if (_mm == 2 && _yyyy%4==0) {
            handleInput(_dd, monthDays[0], 1);
        } else {
            handleInput(_dd, monthDays[_mm], 1);
        }
    } while (!_continue);
    input.yyyy = _yyyy;
    input.mm = _mm;
    input.dd = _dd;
};

void Calendar::handleInput(int INPUT, int max, int min) {
    if (INPUT > max || INPUT < min) {
        setContinue(false);
        cout << "Please enter a value in the range " << min << " to " << max << endl;
    } else {
        setContinue(true);
    };
};

void Calendar::mainloopForward() {
    do {
        nextYear();
        nextMonth();
        if (!finish) {
            count();
            check();
        }
    } while (!finish);
}

void Calendar::mainloopBackward() {
    do {
        prevYear();
        prevMonth();
        count();
        check();
    } while (!finish);
}

int main() {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
    hour = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;
    dotw = now->tm_wday;
    dd = day;
    mm = month;
    yyyy = year;
    Calendar cal;
    cal.currentTime();
    cal.getInput();
    cal.check();
    if (cal.getFuture()) {
        cal.mainloopForward();
    } else if (cal.getPast()) {
        cal.mainloopBackward();
    }
    return 0;
}