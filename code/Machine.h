#pragma once
#include <iostream>
#include "Pin.h"
#include "AsyncBuffer.h"
#include "Generator.h"

class Machine {
private:
    int delay;
    std::string name;
    int n = 0;

public:
    Machine(int delay, std::string name);

    void Process(AsyncBuffer* buffer_new_pins, Generator* generator);
};
