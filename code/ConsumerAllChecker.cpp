#include "ConsumerAllChecker.h"

void ConsumerAllChecker::Process(AsyncBuffer* buffer_sharpened_pins, AsyncBuffer* buffer_checked_pins) {
    Pin next_pin;

    while (true) {
        next_pin = buffer_sharpened_pins->get();

        // Immitate pin checking.
        std::cout << "Pin " << next_pin.name << " received for final inspection" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        if (next_pin.is_sharpened && next_pin.is_straight) {
            next_pin.all_correct = true;
            buffer_checked_pins->push(next_pin);

            std::cout << "Pin " << next_pin.name << " passed the final inspection and sent to the warehouse" << std::endl;
        }
        else {
            std::cout << "Pin " << next_pin.name << " did not pass the final check" << std::endl;
        }
    }
}