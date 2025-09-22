#include "../include/program.h"
#include "../include/bicycle.h"
#include "../include/car.h"
#include "../include/carriage.h"
#include "../include/menu.h"
#include "../include/transport.h"
#include "../include/utils.h"

using namespace std;

void calculateAndPrintTime(const Transport* vehicle) {
    cout << "Enter distance (km): ";
    double distance = validation();
    double time = vehicle->calculateTime(distance);
    cout << "Transportation time: " << time << " hours" << endl;
}

void calculateAndPrintPassengerCost(const Transport* vehicle) {
    cout << "Enter distance (km): ";
    double distance = validation();
    cout << "Enter number of passengers: ";
    int passengers = validation();
    double cost = vehicle->calculatePassengerCost(distance, passengers);
    if (cost >= 0) {
        cout << "Passenger cost: " << cost << " BYN" << endl;
    }
}

void calculateAndPrintCargoCost(const Transport* vehicle) {
    cout << "Enter distance (km): ";
    double distance = validation();
    cout << "Enter cargo weight (kg): ";
    double weight = validation();
    double cost = vehicle->calculateCost(distance, weight);
    if (cost >= 0) {
        cout << "Cargo cost: " << cost << " BYN" << endl;
    }
}

void runProgram() {
    Car car(0, 0, 0, 0);
    Bicycle bicycle(0, 0, 0);
    Carriage carriage(0, 0, 0, 0);

    Transport* currentVehicle = nullptr;
    int choice;

    taskMenu();

    while (true) {
        showTransportMenu();
        cout << "Select a transport type: ";
        choice = validation();

        switch (choice) {
            case 1:
                currentVehicle = &car;
                cout << "Selected: Car" << endl;
                currentVehicle->inputDetails();  
                break;
            case 2:
                currentVehicle = &bicycle;
                cout << "Selected: Bicycle" << endl;
                currentVehicle->inputDetails();  
                break;
            case 3:
                currentVehicle = &carriage;
                cout << "Selected: Carriage" << endl;
                currentVehicle->inputDetails();  
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "Error: you have selected an incorrect option" << endl;
                continue;
        }

        bool backToTransport = false;
        while (!backToTransport && currentVehicle != nullptr) {
            showCalculationMenu();
            cout << "Select a calculation option: ";
            int calcChoice = validation();

            switch (calcChoice) {
                case 1:
                    calculateAndPrintTime(currentVehicle);
                    break;
                case 2:
                    calculateAndPrintPassengerCost(currentVehicle);
                    break;
                case 3:
                    calculateAndPrintCargoCost(currentVehicle);
                    break;
                case 4:
                    currentVehicle->displayInfo();
                    break;
                case 5:
                    backToTransport = true;
                    break;
                default:
                    cout << "Error: you have selected an incorrect option" << endl;
                    break;
            }
        }
    }
}