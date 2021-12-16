#include "Machine.h"

Machine::Machine(int delay, std::string name) {
    this->delay = delay;
    this->name = name;
}

void Machine::Process(AsyncBuffer* buffer_new_pins, Generator* generator) {
    Pin next_bin;

    while (true) {
        // Immitate pin produsing.
        std::cout << "Machine " << name << " starts pin production " << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        next_bin = generator->getNewPin(name, n++);
        buffer_new_pins->push(next_bin);

        std::cout << "Machine " << name << " produced a pin " << next_bin.name << " and directed it next" << std::endl;
    }
}