#pragma once
#include <iostream>
#include "Pin.h"
#include "AsyncBuffer.h"
#include "Generator.h"

class ConsumerSharpener {
private:
    int delay;

public:
    void Process(AsyncBuffer* buffer_straight_pins, AsyncBuffer* buffer_sharpened_pins, Generator* generator);

    ConsumerSharpener(int delay = 4200) {
        this->delay = delay;
    }
};
