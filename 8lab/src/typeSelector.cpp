#include "../include/program.h"

#include <iostream>

#include "../include/utils.h"

void runProgram() {
    int choice = 0;
    selectRingType();
    while (true) {
        std::cout << "\nPlease choose a ring type: ";
        choice = getValue<int>();

        switch (choice) {
            case 1: {
                Program<int> program;
                program.run();
                return;
            }
            case 2: {
                Program<long> program;
                program.run();
                return;
            }
            case 3: {
                Program<float> program;
                program.run();
                return;
            }
            case 4: {
                Program<double> program;
                program.run();
                return;
            }
            case 5: {
                Program<char> program;
                program.run();
                return;
            }
            case 6: {
                Program<std::string> program;
                program.run();
                return;
            }
            default:
                std::cout << "Error, invalid choice. Please try again." << "\n";
        }
    }
}