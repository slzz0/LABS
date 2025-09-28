#include "../include/program.h"

#include "../include/bicycle.h"
#include "../include/car.h"
#include "../include/carriage.h"
#include "../include/consts.h"
#include "../include/menu.h"
#include "../include/transport.h"
#include "../include/utils.h"

using namespace std;

void inputCalculationData(double& distance, double& weight, int& passengers) {
    cout << "Enter distance (km): ";
    distance = validation();
    
    cout << "Enter cargo weight (kg): ";
    weight = validation();
    
    cout << "Enter number of passengers: ";
    passengers = validation();
}

void printAllCalculations(const Transport* vehicle, double distance, double weight, int passengers) {
    cout << "\n=== Results ===" << endl;
    cout << "Transportation time: " << vehicle->calculateTime(distance) << " hours" << endl;
    cout << "Cargo cost: " << vehicle->calculateCost(distance, weight) << " BYN" << endl;
    cout << "Passenger cost: " << vehicle->calculatePassengerCost(distance, passengers) << " BYN" << endl;
    cout << "==================" << endl;
}

void runProgram() {
    Car car;
    Bicycle bicycle;
    Carriage carriage;

    const Transport* currentVehicle = nullptr;
    int choice;
    double distance;
    double weight;
    int passengers;

    taskMenu();

    while (true) {
        showTransportMenu();
        cout << "Enter your choice (1-3): ";
        choice = validation();

        switch (choice) {
            case 1:
                currentVehicle = &car;
                cout << "Selected: Car" << endl;
                currentVehicle->displayInfo();
                
                cout << "Enter distance (km): ";
                distance = validation();
                
                cout << "Enter cargo weight (kg): ";
                weight = validation();
                weight = validateWeight(weight, CAR_LOAD_CAP);
                
                cout << "Enter number of passengers: ";
                passengers = validation();
                passengers = validatePassengers(passengers, CAR_MAX_PASS);
                
                printAllCalculations(currentVehicle, distance, weight, passengers);
                break;

            case 2:
                currentVehicle = &bicycle;
                cout << "Selected: Bicycle" << endl;
                currentVehicle->displayInfo();
                
                cout << "Enter distance (km): ";
                distance = validation();
                
                cout << "Enter cargo weight (kg): ";
                weight = validation();
                weight = validateWeight(weight, BICYCLE_LOAD_CAP); 
                
                cout << "Enter number of passengers: ";
                passengers = validation();
                passengers = validatePassengers(passengers, 1);
                
                printAllCalculations(currentVehicle, distance, weight, passengers);
                break;

            case 3:
                currentVehicle = &carriage;
                cout << "Selected: Carriage" << endl;
                currentVehicle->displayInfo();
                
                cout << "Enter distance (km): ";
                distance = validation();
                
                cout << "Enter cargo weight (kg): ";
                weight = validation();
                weight = validateWeight(weight, CARRIAGE_LOAD_CAP); 
                
                cout << "Enter number of passengers: ";
                passengers = validation();
                
                printAllCalculations(currentVehicle, distance, weight, passengers);
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "Error: you have selected an incorrect option" << endl;
                continue;
        }
    }
}