#ifndef __SLEEP_H__
#define __SLEEP_H__

#pragma once

#include <iostream>
#include <thread>
#include <chrono>

class Sleep {
public:
    inline static void seconds(int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }
    inline static void milliseconds(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
    inline static void microseconds(int microseconds) {
        std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
    }
};

#endif // __SLEEP_H__