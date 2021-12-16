#include "ConsumerSharpener.h"


void ConsumerSharpener::Process(AsyncBuffer* buffer_straight_pins, AsyncBuffer* buffer_sharpened_pins, Generator* generator) {
    Pin next_pin;

    while (true) {
        next_pin = buffer_straight_pins->get();

        // Immitate pin sharpening.
        std::cout << "Pin " << next_pin.name << " rechived to sharpening" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        next_pin.is_sharpened = generator->isSuccessSharpened();
        buffer_sharpened_pins->push(next_pin);

        std::cout << "Pin " << next_pin.name << " it has been sharpened and is directed next" << std::endl;
    }
}
