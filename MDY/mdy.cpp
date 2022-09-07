#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <ctime>
#include <thread>
#include "today.h"

using namespace std;

int long mm;
int long dd;
int long yyyy;
int long dotw;
string DOTW;
string month;

bool _past = false;
bool _future = false;
int pastfuture = 0;

int * tdp = &today.d;
int * tmp = &today.m;
int * typ = &today.y;
int * thp = &today.hour;
int * tminp = &today.minute;
int * twp = &today.dotw;
string * TWP = &today.DOTW;
string * TMP = &today.month;

int _count;
int cm, cd, cy, cw;

bool equals = false;

void cvars() {
    cm = *tmp;
    cd = *tdp;
    cy = *typ;
    cw = *twp;
};

void mdy() {
inputmonth:
    cout << "Input month (1-12): ";
    cin >> mm;
    if (mm < 1 || mm > 12) {
        cout << "Error! Please input a valid month.\n";
        goto inputmonth;
    }
    else
        cout << "";
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
    dd31:
        cout << "Input day (1-31): ";
        cin >> dd;
        if (dd > 31 || dd < 1) {
            cout << "Error! Please input a valid day\n";
            goto dd31;
        }
        else
            cout << "";
    }
    else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    dd30:
        cout << "Input day (1-30): ";
        cin >> dd;
        if (dd > 30 || dd < 1) {
            cout << "Error! Please input a valid day.\n";
            goto dd30;
        }
        else
            cout << "";
    }
    else if (mm == 2) {
    dd29:
        cout << "Input day (1-28/29): ";
        cin >> dd;
        if (dd > 29 || dd < 1) {
            cout << "Error! Please input a valid day.\n";
            goto dd29;
        }
        else
            cout << "";
    }
getyear:
    cout << "Input year (e.g. 2022): ";
    cin >> yyyy;
    if  (yyyy > 20000) {
        cout << "Come on... Give me a reasonable year: ";
        cin >> yyyy;
    } else if (yyyy < 0) {
        cout << "We don't talk about times Before Christ...\n";
        goto getyear;
    } else if (mm == 2 && yyyy % 4 != 0 && dd == 29) {
        cout << "Error! The date you entered doesn't exist.\nFebruary only has 29 days on leap years (when yyyy is divisible by 4).\n";
        goto inputmonth;
    } else
        cout << "";
};

void PastFuture() {
    if (today.y < yyyy) {
        cout << "The date you entered is in the FUTURE.\n";
        _future = true;
    }
    else if (today.y > yyyy) {
        cout << "The date you entered is in the PAST.\n";
        _past = true;
    } 
    else if (today.y == yyyy) {
        if (mm > today.m && dd > today.d) {
            cout << "The date you entered is in the FUTURE.\n";
            _future = true;
        } 
        else if (mm < today.m && dd < today.d) {
            cout << "The date you entered is in the PAST.\n";
            _past = true;
        } 
        else if (mm == today.m) {
            if (today.d < dd) {
                cout << "The date you entered is in the FUTURE.\n";
                _future = true;
            } 
            else if (today.d > dd) {
                cout << "The date you entered is in the PAST.\n";
                _past = true;
            } 
            else if (today.d == dd) {
                cout << "The date you entered is today...\n";
            }
        }
    } else {
        cout << "ERROR: Date invalid.";
    }
    if (pastfuture == 1)
        _future = true;
    else if (pastfuture == -1)
        _past = true;
}

void checkCount() {
    if (cd == dd && cm == mm && cy == yyyy) {
        cout << mm << "/" << dd << "/" << yyyy << " is " << _count << " days away." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "That day is a " << dw[cw] << ".\n";
        equals = true;
    }
    if (equals == true)
        return;
};

void countpp(){
    _count++;
    if (cw != 6)
        cw++;
    else if (cw == 6)
        cw = 0;
};

void countppback(){
    ++_count;
    if (cw != 0)
        cw--;
    else if (cw == 0)
        cw = 6;
};

void nextDay() {
    cd++;
    countpp();
    checkCount();
};

void prevDay() {
    --cd;
    countppback();
    checkCount();
}

void nextMonth() {
    cm++;
    cd = 1;
    countpp();
    checkCount();
};

void prevMonth() {
    --cm;
    cd = daysM[cm];
    countppback();
    checkCount();
}

void prevYear() {
    cm = 12;
    cd = daysM[cm];
    --cy;
    countppback();
    checkCount();
}

void nextYear() {
    cy++;
    cm = 1;
    cd = 1;
    countpp();
    checkCount();
};

void genCountBack() {
    for (int i = cd; i > 1; i--) {
        prevDay(); };
    if (cm == 1) {
        prevYear();
    } else if (cm > 1) {
        prevMonth(); };
}

void genCount() {
    for (int i = cd; i < daysM[cm]; i++) {
        nextDay(); };
    if (cm == 12) {
        nextYear();
    } else if (cm < 12) {
        nextMonth(); };
}

void flyCountBack() {
    for (int i = daysM[0]; i > 1; i--) {
        prevDay(); };
    prevMonth();
}

void flyCount() {
    for (int i = cd; i < daysM[0]; i++) {
        nextDay(); };
    nextMonth();
}

void countPast() {
    checkCount();
    if (equals == true)
        return;
    do {
        flyCountBack();
        if (equals == true)
            return;
        genCountBack();
        if (equals == true)
            return;
    } while (true);
    if (equals == true)
        return;
}

void countPast2() {
    checkCount();
    if (equals == true)
        return;
next:
    if (cm == 2 && cy%4 == 0) {
        flyCountBack(); 
        if (equals == true)
            return;
        };
    genCountBack();
    if (equals == true)
        return;
    goto next;
};

void countFuture() {
    checkCount();
    if (equals == true)
        return;
next:
    if (cm == 2 && cy%4 == 0) {
        flyCount(); 
        if (equals == true)
            return;
        };
    genCount();
    if (equals == true)
        return;
    goto next;
};

void boolfp() {
    if (_future == true) 
        countFuture();
    else if (_past == true)
        countPast2();
    else
        return;
};

int main() {
    _count = 0; 
    time_t t = time(0);
    tm * now = localtime(&t);
    today.y = now->tm_year + 1900;
    today.m = now->tm_mon + 1;
    today.d = now->tm_mday;
    today.hour = now->tm_hour;
    today.minute = now->tm_min;
    today.dotw = now->tm_wday;
    today.DOTW = dw[today.dotw];
    today.month = months[today.m];
    cout << "Today is " << today.DOTW << ", " << today.month << " " << today.d << ", " << today.y << ".\n";
    if (today.hour < 12 && today.hour > 0 && today.minute < 10) {
        cout << "Good Morning. The time is " << today.hour << ":" << "0" << today.minute << " AM.\n";
    } else if (today.hour < 12 && today.hour > 0 && today.minute > 10) {
        cout << "Good Morning. The time is " << today.hour << ":" << today.minute << " AM.\n";
    } else if (today.hour == 12 && today.minute < 10) {
        cout << "Good Noon. The time is " << today.hour << ":" << "0" << today.minute << " PM.\n";
    } else if (today.hour == 12 && today.minute > 10) {
        cout << "It's high noon... The time is " << today.hour << ":" << today.minute << " PM.\n";
    } else if (today.hour == 0 && today.minute < 10) {
        cout << "Spooky! It's midnight. The time is " << (today.hour + 12) << ":" << "0" << today.minute << " AM.\n";
    } else if (today.hour == 0 && today.minute > 10) {
        cout << "Spooky! It's midnight. The time is " << (today.hour + 12) << ":" << today.minute << " AM.\n";
    } else if (today.hour > 12 && today.minute < 10) {
        cout << "Good Afternoon. The time is " << (today.hour - 12) << ":" << "0" << today.minute << " PM.\n";
    } else if (today.hour > 12 && today.minute > 10) {
        cout << "Good Afternoon. The time is " << (today.hour - 12) << ":" << today.minute << " PM.\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mdy();
    std::this_thread::sleep_for(std::chrono::seconds(1/2));
    cout << "You entered: " << mm << "/" << dd << "/" << yyyy << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    PastFuture();
    std::this_thread::sleep_for(std::chrono::milliseconds(1250));
    cvars();
    boolfp();
    return 0;
}
