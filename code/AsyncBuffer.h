#pragma once

#include <queue>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <mutex>
#include <condition_variable>
#include "Pin.h"

class AsyncBuffer {
private:
	std::queue<Pin> queue;
	std::mutex queue_mutex;
	std::mutex notify;
	std::condition_variable cv;
	int max_size = 100000;
public:
	AsyncBuffer();

	void push(Pin pin);

	Pin get();

	bool isNotEmpty();
};

