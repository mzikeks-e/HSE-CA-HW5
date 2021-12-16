#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "Pin.h"
#include "AsyncBuffer.h"
#include "Generator.h"
#include "ConsumerAllChecker.h"
#include "ConsumerSharpener.h"
#include "ConsumerStraightChecker.h"
#include "Machine.h"


int getNextIntInRange(std::string message, std::string error, int from, int to) {
    int input = from;
    do {
        std::cout << message << std::endl;
        try {
            std::cin >> input;
            if (!std::cin || input < from || input > to) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                throw 1;
            }
            break;
        }
        catch (int) {
            std::cout << error << std::endl;
        }
    } while (true);
    return input;
}


int main() {
    Generator generator = Generator();

    // Buffer for pins from Machine.
    AsyncBuffer buffer_new_pins;

    // Buffer for pins, complited ConsumerStraightChecker.
    AsyncBuffer buffer_straight_pins;

    // Buffer for pins, complited ConsumerSharpener.
    AsyncBuffer buffer_sharpened_pins;

    // Buffer for pins, complited ConsumerAllChecker.
    AsyncBuffer buffer_checked_pins;


    ConsumerStraightChecker consumer_straight_checker(getNextIntInRange(
        "Enter time (miliseconds) for execution one operation for first worker (straight checker)",
        "Error! Input should be integer from 100 to 100000",
        100, 100 * 1000
    ));
    ConsumerSharpener consumer_sharpener(getNextIntInRange(
        "Enter time (miliseconds) for execution one operation for second worker (sharper)",
        "Error! Input should be integer from 100 to 100000",
         100, 100 * 1000
    ));

    ConsumerAllChecker consumer_all_checker(getNextIntInRange(
        "Enter time (miliseconds) for execution one operation for third worker (final checker)",
        "Error! Input should be integer from 100 to 100000",
        100, 100 * 1000
    ));;

    Machine machine1(getNextIntInRange(
        "Enter the production time of one blank for the first machine (miliseconds)",
        "Error! Input should be integer from 100 to 500000",
        100, 500 * 1000), "gen1");
    Machine machine2(getNextIntInRange(
        "Enter the production time of one blank for the first machine (miliseconds)",
        "Error! Input should be integer from 100 to 500000",
        100, 500 * 1000), "gen2");
 

    std::thread prod1_thread(&Machine::Process, &machine1, &buffer_new_pins, &generator);
    std::thread prod2_thread(&Machine::Process, &machine2, &buffer_new_pins, &generator);

    std::thread cons1_thread(&ConsumerStraightChecker::Process, &consumer_straight_checker, &buffer_new_pins, &buffer_straight_pins);
    std::thread cons2_thread(&ConsumerSharpener::Process, &consumer_sharpener, &buffer_straight_pins, &buffer_sharpened_pins, &generator);
    std::thread cons3_thread(&ConsumerAllChecker::Process, &consumer_all_checker, &buffer_sharpened_pins, &buffer_checked_pins);
    

    prod1_thread.join();
    prod2_thread.join();
    cons1_thread.join();
    cons2_thread.join();
    cons3_thread.join();

    return 0;
}


