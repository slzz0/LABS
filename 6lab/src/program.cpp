#include "../include/program.h"

#include <iostream>

#include "../include/bicycle.h"
#include "../include/car.h"
#include "../include/carriage.h"
#include "../include/consts.h"
#include "../include/invalidException.h"
#include "../include/menu.h"
#include "../include/transport.h"
#include "../include/utils.h"

using namespace std;

Transport* createTransport() {
    while (true) {
        try {
            string regNumber;
            cout << "Enter registration number (digits and latin letters only): ";
            getline(cin, regNumber);
            validateString(regNumber, "Registration number");

            int choice;
            showTransportMenu();
            cout << "Enter ypur choice (1-4): ";
            choice = getNumber();

            Transport* transport = nullptr;

            switch (choice) {
                case 1:
                    transport = new Car;
                    break;
                case 2:
                    transport = new Bicycle;
                    break;
                case 3:
                    transport = new Carriage;
                    break;
                default:
                    cout << "Invalid choice!" << "\n";
                    cout << "Using car by default" << "\n";
                    transport = new Car;
                    break;
            }

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
    inputTransportationData(distance, weight, passengers);

    Transport *transport = createTransport();
    demonstrateTransport(transport, distance, weight, passengers);
    delete transport;
}