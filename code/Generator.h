#pragma once
#include <ctime>
#include <random>
#include <string>
#include "Pin.h"

class Generator {
public:
    Generator();

    Pin getNewPin(std::string name, int n);

    bool isSuccessSharpened();
};
