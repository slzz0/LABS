#include "../include/carriage.h"

#include "../include/consts.h"
#include "../include/utils.h"

using namespace std;

Carriage::Carriage() : Transport(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP) {}

double Carriage::calculateCost(double distance, double weight) const {
    return distance * CARRIAGE_COST_PER_KM * (weight / WEIGTH_UNIT) * NUMBER_OF_HORSES *
           CARRIAGE_HORSE_FACTOR;
}

double Carriage::calculatePassengerCost(double distance, int passengers) const {
    return distance * CARRIAGE_COST_PER_KM * passengers * CARRIAGE_PASSENGER_DISCOUNT;
}

void Carriage::displayInfo() const {
    cout << "Type: Carriage" << "\n";
    Transport::displayInfo();
    cout << "Number of horses: " << numberOfHorses << "\n";
    cout << "======================" << "\n";
}
