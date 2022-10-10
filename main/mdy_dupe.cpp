// #include <ctime>
// #include <string>
// #include <iostream>
// #include <thread>
// #include <chrono>
// #include "mdy.h"
// #include "clear.h"
// using namespace std;

// class User {
// private:    
//     int dd, mm, yyyy, day, month, year, dotw, hour, minute, second;
// public:
//     inline int getDD() { return dd; }
//     inline int getMM() { return mm; }
//     inline int getYYYY() { return yyyy; }
//     inline int getDay() { return day; }
//     inline int getMonth() { return month; }
//     inline int getYear() { return year; }
//     inline int getDOTW() { return dotw; }
//     inline int getHour() { return hour; }
//     inline int getMinute() { return minute; }
//     inline int getSecond() { return second; }
//     inline void setDD(int value) { dd = value; }
//     inline void setMM(int value) { mm = value; }
//     inline void setYYYY(int value) { yyyy = value; }
//     inline void setDay(int value) { day = value; }
//     inline void setMonth(int value) { month = value; }
//     inline void setYear(int value) { year = value; }
//     inline void setDOTW(int value) { dotw = value; }
//     inline void setHour(int value) { hour = value; }
//     inline void setMinute(int value) { minute = value; }
//     inline void setSecond(int value) { second = value; }
// };

// User INPUT;

// struct _time
//     {
//     int dd;
//     int mm;
//     int yyyy;
//     int DOTW;
//     } input;

// string weekdays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };
// int monthDays[13]{ 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// void hms(int hms)
//     {
//     if (hms < 10)
//         {
//         cout << "0" << to_string(hms);
//         }
//     else
//         {
//         cout << to_string(hms);
//         }
//     }

// class Calendar
//     {
//     private:
//         bool _continue = false;
//         bool finish = false;
//         int Today;
//         int _count;
//         bool future = false;
//         bool past = false;
//     public:
//         Calendar(bool future = false, bool past = false, int _count = 0, int today = INPUT.getDOTW(), bool finish = false) : _count(_count), Today(today), finish(finish) { this->future = future; this->past = past; this->_continue = _continue; };
//         inline bool getFuture() { return future; };
//         inline bool getPast() { return past; };
//         inline bool getFinish() { return finish; };
//         inline void setFinish(bool value) { finish = value; };
//         inline void setContinue(bool value) { _continue = value; };
//         inline string returnDOTW(int value) { string val = weekdays[value]; return val; };
//         inline int getDOTW() { return Today; };
//         inline void setToday(int value) { Today = value; }
//         inline void fToday() { Today++; if (Today > 6) { Today = 0; } };
//         inline void pToday() { Today--; if (Today < 0) { Today = 6; } };
//         inline void displayTime() { hms(INPUT.getHour()); cout << ":"; hms(INPUT.getMinute()); cout << ":"; hms(INPUT.getSecond()); };
//         inline void currentTime() { cout << "Today is " << returnDOTW(INPUT.getDOTW()) << ", " << INPUT.getMonth() << " " << INPUT.getDay() << ", " << INPUT.getYear() << ". \n" << "The time is "; displayTime(); cout << endl; };
//         inline int getCount() { return _count; };
//         inline void count() { int DD = INPUT.getDD(); if (past) { INPUT.setDD(DD--); Today--; if (Today < 0) { setToday(6); } } else if (future) { INPUT.setDD(DD++); Today++; if (Today > 6) { setToday(0); } } _count++; };
//         inline void Future() { cout << "The date you entered is in the future!\n"; future = true; };
//         inline void Past() { cout << "The date you entered is in the past!\n"; past = true; };
//         inline bool leapDay(int month, int year) { return (month == 2 && year % 4 == 0); };
//         int Input(int input, string question, int max, int min, int max2 = 31, bool value = false);
//         void handleInput(int _input, int max, int min);
//         void getInput();
//         void checkInput();
//         void checkFinish();
//         void prevMonth();
//         void nextMonth();
//         void nextYear();
//         void prevYear();
//         void mainloopForward();
//         void mainloopBackward();
//     };

// void Calendar::prevMonth()
//     {
//     if ((INPUT.getMM() == 3 && INPUT.getYYYY() % 4 == 0) && INPUT.getDD() == 1)
//         {
//         int _mm = INPUT.getMM();
//         INPUT.setMM(_mm--);
//         INPUT.setDD(monthDays[INPUT.getMM() - 2]);
//         _count++;
//         pToday();
//         checkFinish();
//         }
//     else if (INPUT.getDD() == 1 && INPUT.getMM() != 1)
//         {
//         int _mm = INPUT.getMM();
//         INPUT.setMM(_mm--);
//         INPUT.setDD(monthDays[INPUT.getMM()]);
//         _count++;
//         pToday();
//         checkFinish();
//         };
//     }

// void Calendar::nextMonth()
//     {
//     if (INPUT.getMM() == 2 && INPUT.getYYYY() % 4 == 0)
//         {
//         if (INPUT.getDD() == monthDays[0])
//             {
//             int _mm = INPUT.getMM();
//             INPUT.setMM(_mm++);
//             INPUT.setDD(1);
//             _count++;
//             fToday();
//             checkFinish();
//             }
//         }
//     else if (INPUT.getDD() == monthDays[INPUT.getMM()] && INPUT.getMM() != 12)
//         {
//         int _mm = INPUT.getMM();
//         INPUT.setMM(_mm++);
//         INPUT.setDD(1);
//         _count++;
//         fToday();
//         checkFinish();
//         };
//     }

// void Calendar::prevYear()
//     {
//     if (INPUT.getMM() == 1 && INPUT.getDD() == 1)
//         {
//         INPUT.setMM(12);
//         INPUT.setDD(monthDays[INPUT.getMM()]);;
//         int _yyyy = INPUT.getYYYY();
//         INPUT.setYYYY(_yyyy--);
//         _count++;
//         pToday();
//         checkFinish();
//         }
//     }

// void Calendar::nextYear()
//     {
//     if (INPUT.getMM() == 12 && INPUT.getDD() == monthDays[INPUT.getMM()])
//         {
//         INPUT.setMM(1);
//         INPUT.setDD(1);
//         int _yyyy = INPUT.getYYYY();
//         _yyyy += 1;
//         INPUT.setYYYY(_yyyy);
//         _count++;
//         fToday();
//         checkFinish();
//         };
//     }

// void Calendar::checkFinish()
//     {
//     if (INPUT.getMM() == input.mm && input.dd == INPUT.getDD() && input.yyyy == INPUT.getYYYY())
//         {
//         setFinish(true);
//         if (past || future)
//             {
//             cout << "That day is " << _count << " days away!" << endl;
//             if (getFuture()) {
//                 cout << "It will be a " << returnDOTW(Today) << "!" << endl;
//             } else if (getPast()) {
//                 cout << "It was a " << returnDOTW(Today) << endl;
//             }
//             this_thread::sleep_for(chrono::milliseconds(800));
//             setFinish(true);
//             }
//         }
//     }

// void Calendar::checkInput() {
//     if (input.yyyy != INPUT.getYYYY()) {
//         if (input.yyyy > INPUT.getYYYY()) {
//             Future();
//         } else if (input.yyyy < INPUT.getYYYY()) {
//             Past();
//         }
//     } else if (input.yyyy == INPUT.getYYYY()) {
//         if (input.mm != INPUT.getMM()) {
//             if (input.mm > INPUT.getMM()) {
//                 Future();
//             } else if (input.mm < INPUT.getMM()) {
//                 Past();
//             }
//         } else if (input.mm == INPUT.getMM()) {
//             if (input.dd != INPUT.getDD()) {
//                 if (input.dd > INPUT.getDD()) {
//                     Future();
//                 } else if (input.dd < INPUT.getDD()) {
//                     Past();
//                 }
//             } else if (input.dd == INPUT.getDD()) {
//                     checkFinish();
//                 }
//             }
//         }
//     }

// int Calendar::Input(int input, string question, int max, int min, int max2, bool value)
//     {
//     do
//         {
//         cin.clear();
//         cout << question;
//         cin >> input;
//         if (value)
//             {
//             handleInput(input, max2, min);
//             }
//         else
//             {
//             handleInput(input, max, min);
//             }
//         }
//     while (!_continue);
//         return input;
//     }

// void Calendar::getInput()
//     {
//     cout << "Enter a date. It will tell you how many days away it is and that day of the week." << endl;
//     int _yyyy, _mm, _dd;
//     input.yyyy = Calendar::Input(_yyyy, "Enter a year (e.g. 2022): ", 12000, -10000);
//     input.mm = Calendar::Input(_mm, "Enter a month: ", 12, 1);
//     input.dd = Input(_dd, "Enter a day: ", monthDays[input.mm], 1, monthDays[0], leapDay(input.mm, input.yyyy));
//     };

// void Calendar::handleInput(int _input, int max, int min)
//     {
//     if (_input > max || _input < min)
//         {
//         setContinue(false);
//         cout << "Please enter a value in the range " << min << " to " << max << endl;
//         }
//     else
//         {
//         setContinue(true);
//         };
//     };

// void Calendar::mainloopForward()
//     {
//     do
//         {
//         nextYear();
//         nextMonth();
//         if (!getFinish())
//             {
//             count();
//             checkFinish();
//             }
//         }
//     while (!getFinish());
//     };

// void Calendar::mainloopBackward()
//     {
//     do
//         {
//         prevYear();
//         prevMonth();
//         count();
//         checkFinish();
//         }
//     while (!getFinish());
//     };

// void CalendarTool() {
//     // User INPUT;
//     time_t t = time(0);
//     struct tm* now = localtime(&t);
//     INPUT.setDay(now->tm_mday);
//     INPUT.setMonth(now->tm_mon + 1);
//     INPUT.setYear(now->tm_year + 1900);
//     INPUT.setHour(now->tm_hour);
//     INPUT.setMinute(now->tm_min);
//     INPUT.setSecond(now->tm_sec);
//     INPUT.setDOTW(now->tm_wday);
//     bool done = false;
//     do 
//     {
//         INPUT.setDD(INPUT.getDay());
//         INPUT.setMM(INPUT.getMonth());
//         INPUT.setYYYY(INPUT.getYear());
//         Calendar cal;
//         cal.currentTime();
//         cal.getInput();
//         cal.checkInput();
//         if (cal.getFuture())
//             {
//             cal.mainloopForward();
//             }
//         else if (cal.getPast())
//             {
//             cal.mainloopBackward();
//             }
//         this_thread::sleep_for(chrono::milliseconds(800));
//         bool endswitch = false;
//         do {
//             cout << "Press 1 to continue or 2 to use again." << std::endl;
//             int input;
//             cin >> input;
//             switch (input) {
//                 case 1:
//                     endswitch = true;
//                     done = true;
//                     break;
//                 case 2:
//                     endswitch = true;
//                     done = false;
//                     break;
//                 default:
//                     endswitch = false;
//                     cout << "Invalid input. Please try again..." << std::endl;
//                     break;
//                 }
//             cls();
//         } while (endswitch = false);
//     } while (!done);
// }