#include "../include/car.h"

#include "../include/consts.h"
#include "../include/utils.h"

using namespace std;

Car::Car(double speed, double cost, double cap, int maxPass)
    : Transport(speed, cost, cap), maxPassengers(maxPass) {}

double Car::calculateCost(double distance, double weight) const {
    weight = validateWeight(weight, getCapacity());
    return distance * getCostPerKm() * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const {
    passengers = validatePassengers(passengers, maxPassengers);
    return distance * getCostPerKm() * passengers;
}

void Car::displayInfo() const {
    cout << "Type: Car" << "\n";
    Transport::displayInfo();
    cout << "Max number of passengers: " << maxPassengers << "\n";
    cout << "=====================" << "\n";
}

void Car::inputDetails() {
    Transport::inputDetails();
    cout << "Enter max number of passengers: ";
    maxPassengers = validation();
}