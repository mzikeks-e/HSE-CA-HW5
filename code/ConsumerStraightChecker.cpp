#include "ConsumerStraightChecker.h"

void ConsumerStraightChecker::Process(AsyncBuffer* buffer_new_pins, AsyncBuffer* buffer_straight_pins) {
    Pin next_pin;

    while (true) {
        next_pin = buffer_new_pins->get();

        // Immitate straight checking.
        std::cout << "Pin " << next_pin.name << " received a straight check" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        if (next_pin.is_straight) {
            buffer_straight_pins->push(next_pin);
            std::cout << "Pin " << next_pin.name << " passed the straight check and is directed next" << std::endl;
        }
        else {
            std::cout << "Pin " << next_pin.name << " failed straight check" << std::endl;
        }
    }
}
