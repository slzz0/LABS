#include "../include/carriage.h"
#include "../include/utils.h"
#include "../include/consts.h"


using namespace std;

Carriage::Carriage(double speed, double cost, double cap, int horses)
    : Transport(speed, cost, cap), numberOfHorses(horses) {}

double Carriage::calculateCost(double distance, double weight) const {
    weight = validateWeight(weight, getCapacity());
    return distance * getCostPerKm() * (weight / WEIGTH_UNIT) * numberOfHorses * CARRIAGE_HORSE_FACTOR;
}

double Carriage::calculatePassengerCost(double distance, int passengers) const {
    return distance * getCostPerKm() * passengers * CARRIAGE_PASSENGER_DISCOUNT;
}

void Carriage::displayInfo() const {
    cout << "Type: Carriage" << "\n";
    Transport::displayInfo();
    cout << "Number of horses: " << numberOfHorses << "\n";
    cout << "======================" << "\n";
}

void Carriage::inputDetails() {
    Transport::inputDetails();
    cout << "Enter number of horses: ";
    numberOfHorses = validation();
}