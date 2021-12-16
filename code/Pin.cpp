#include "Pin.h"


Pin::Pin(bool is_straight, std::string name) {
    this->is_straight = is_straight;
    this->name = name;
}

Pin::Pin() {}
