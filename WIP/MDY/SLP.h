#ifndef _SLP_H_
#define _SLP_H_

#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class SLP {
public:
	static void sec(int seconds) {
		std::this_thread::sleep_for(std::chrono::seconds(seconds));
	}
	static void msec(int milliseconds) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
	static void usec(int microseconds) {
		std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
	}
};

#endif