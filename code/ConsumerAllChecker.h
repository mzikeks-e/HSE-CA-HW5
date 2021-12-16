#pragma once
#include <iostream>
#include "Pin.h"
#include "AsyncBuffer.h"
#include "Generator.h"

class ConsumerAllChecker {
private:
    int delay;

public:
    void Process(AsyncBuffer* buffer_sharpened_pins, AsyncBuffer* buffer_checked_pins);

    ConsumerAllChecker(int delay = 1500) {
        this->delay = delay;
    }
};
