#include "../include/program.h"

#include <iostream>

#include "../include/bicycle.h"
#include "../include/car.h"
#include "../include/carriage.h"
#include "../include/invalidException.h"
#include "../include/menu.h"
#include "../include/transport.h"
#include "../include/utils.h"

using namespace std;

Transport* createTransport() {
    while (true) {
        try {
            int choice;
            showTransportMenu();
            cout << "Enter your choice (1-4): ";
            choice = getNumber();

            Transport* transport = nullptr;

            switch (choice) {
                case 1:
                    std::cout << "\n\tYou have selected: Car";
                    transport = new Car;
                    break;
                case 2:
                std::cout << "\n\tYou have selected: Bicycle";
                    transport = new Bicycle;
                    break;
                case 3:
                std::cout << "\n\tYou have selected: Carriage";
                    transport = new Carriage;
                    break;
                default:
                    cout << "Invalid choice!" << "\n";
                    cout << "Using car by default" << "\n";
                    transport = new Car;
                    break;
            }

            string regNumber;
            cout << "\nEnter registration number (digits and latin letters only): ";
            getline(cin, regNumber);
            validateString(regNumber, "Registration number");

            transport->setRegistrationNumber(regNumber);
            return transport;
        } catch (const InvalidException& e) {
            cout << "Error: " << e.what() << "\n";
            cout << "Please try again.\n" << "\n";
        }
    }
}

void runProgram() {
    double distance = 0;
    double weight = 0;
    int passengers = 0;
    Transport *transport = createTransport();
    inputTransportationData(transport, distance, weight, passengers);

    demonstrateTransport(transport, distance, weight, passengers);
    delete transport;
}