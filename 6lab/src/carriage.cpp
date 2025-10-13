#include "../include/carriage.h"
#include <format>
#include "../include/consts.h"
#include "../include/invalidException.h"


using namespace std;

Carriage::Carriage()
    : Transport(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP,
                CARRIAGE_REG_NUMBER) {}

double Carriage::calculateCost(double distance, double weight) const {
    if (weight > CARRIAGE_LOAD_CAP) {
        throw InvalidException(
            std::format("Carriage can't carry such a load! Capacity: {} kg, requested: {} kg",
                        static_cast<int>(CARRIAGE_LOAD_CAP), static_cast<int>(weight)));
    }
    return distance * CARRIAGE_COST_PER_KM * (weight / WEIGTH_UNIT) * NUMBER_OF_HORSES *
           CARRIAGE_HORSE_FACTOR;
}

double Carriage::calculatePassengerCost(double distance, int passengers) const {
    return distance * CARRIAGE_COST_PER_KM * passengers * CARRIAGE_PASSENGER_DISCOUNT;
}

const char* Carriage::getType() const { return "Carriage"; }
