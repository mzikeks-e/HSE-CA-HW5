#include "AsyncBuffer.h"

AsyncBuffer::AsyncBuffer() {
}

void AsyncBuffer::push(Pin pin) {
	std::lock_guard<std::mutex> guard(queue_mutex);
	if (queue.size() == max_size) {
		std::cout << "The buffer of the finished pins is filled, cleaning...";
		queue = std::queue<Pin>();
	}
	queue.push(pin);
	cv.notify_one();
}

Pin AsyncBuffer::get() {
	std::unique_lock<std::mutex> guard(notify);
	cv.wait(guard, [this] {return isNotEmpty(); });

	std::lock_guard<std::mutex> guard1(queue_mutex);
	Pin pin = queue.front();
	queue.pop();
	return pin;
}

bool AsyncBuffer::isNotEmpty() {
	std::lock_guard<std::mutex> guard(queue_mutex);
	bool is_empty = queue.empty();
	return !is_empty;
}