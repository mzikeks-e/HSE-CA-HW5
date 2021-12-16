#pragma once
#include<string>

class Pin {
public:
    bool is_straight = false;
    bool is_sharpened = false;
    bool all_correct = false;
    std::string name;


    Pin(bool is_straight, std::string);

    Pin();
};
