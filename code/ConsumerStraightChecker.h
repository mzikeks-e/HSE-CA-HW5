#pragma once
#include <iostream>
#include "Pin.h"
#include "AsyncBuffer.h"
#include "Generator.h"

class ConsumerStraightChecker {
private:
    int delay;

public:
    void Process(AsyncBuffer* buffer_new_pins, AsyncBuffer* buffer_straight_pins);

    ConsumerStraightChecker(int delay = 2200) {
        this->delay = delay;
    }
};
