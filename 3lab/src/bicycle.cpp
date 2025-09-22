#include "../include/bicycle.h"
#include "../include/consts.h"
#include "../include/utils.h"

using namespace std;

Bicycle::Bicycle(double speed, double cost, double cap) : Transport(speed, cost, cap) {}

double Bicycle::calculatePassengerCost(double distance, int passengers) const {
    passengers = validatePassengers(passengers, 1);  
    return distance * getCostPerKm() * passengers;
}

double Bicycle::calculateCost(double distance, double weight) const {
    weight = validateWeight(weight, getCapacity());  
    return distance * getCostPerKm() * (1 + weight / BICYCLE_WEIGHT_FACTOR);
}

void Bicycle::displayInfo() const {
    cout << "Type: Bicycle" << "\n";
    Transport::displayInfo();
    cout << "======" << "\n";
}