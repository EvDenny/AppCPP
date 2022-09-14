#ifndef _NOW_HPP_
#define _NOW_HPP_

#include <string>

class Now {
private:
    std::string time;
    int hour;
    int minute;
    int seconds
public:
    Now(){
        time_t t = time(0);
        struct tm *now = localtime(&t); 
        this->time = time;
        this->hour = now->tm_hour;
        this->minute = now->tm_min;
        this->seconds = now->tm_sec;
    };
    std::string getTime();
    void setTime(std::string time);
    int getHour();
    int getMinute();
    int getSeconds();
    std::string makeStr();
    void display();
};

#endif