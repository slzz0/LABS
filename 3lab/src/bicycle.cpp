#include "../include/bicycle.h"

#include "../include/consts.h"
#include "../include/utils.h"

using namespace std;

Bicycle::Bicycle() : Transport(BICYCLE_SPEED_IN_KM, BICYCLE_COST_PER_KM, BICYCLE_LOAD_CAP) {}   

double Bicycle::calculatePassengerCost(double distance, int passengers) const {
    return distance * getCostPerKm() * passengers;
}

double Bicycle::calculateCost(double distance, double weight) const {
    return distance * getCostPerKm() * (1 + weight / BICYCLE_WEIGHT_FACTOR);
}

void Bicycle::displayInfo() const {
    cout << "Type: Bicycle" << "\n";
    Transport::displayInfo();
    cout << "Max passengers: 1" << "\n";
    cout << "======" << "\n";
}
