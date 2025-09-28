#include "../include/carriage.h"

#include "../include/consts.h"
#include "../include/utils.h"

using namespace std;

Carriage::Carriage() : Transport(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP), numberOfHorses(NUMBER_OF_HORSES) {}

double Carriage::calculateCost(double distance, double weight) const {
    return distance * getCostPerKm() * (weight / WEIGTH_UNIT) * numberOfHorses *
           CARRIAGE_HORSE_FACTOR;
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