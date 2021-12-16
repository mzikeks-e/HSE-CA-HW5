#include "Generator.h"

Pin Generator::getNewPin(std::string name, int n) {
    // The probability of getting a curved Pin is about 30%
    return Pin(rand() % 1000 > 300, name + "_pin" + std::to_string(n));
}

Generator::Generator() {
    std::srand(std::time(nullptr));
}

bool Generator::isSuccessSharpened() {
    // The probability of getting a successfully sharpened Pin is about 90%.
    return rand() % 1000 > 100;
}