#ifndef _Sleep_h
#define _Sleep_h

#pragma once

#include <iostream>
#include <thread>
#include <chrono>

class Sleep {
public:
    static void seconds(int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }
    static void milliseconds(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
    static void microseconds(int microseconds) {
        std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
    }
};

#endif