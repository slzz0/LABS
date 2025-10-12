#include "../include/carriage.h"
#include "../include/invalidException.h"
#include "../include/consts.h"
#include "../include/utils.h"
#include <iostream>

using namespace std;

Carriage::Carriage() : Transport(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP, CARRIAGE_REG_NUMBER) {}

double Carriage::calculateCost(double distance, double weight) const
{
    if (weight > CARRIAGE_LOAD_CAP)
    {
        throw InvalidException(
            "Carriage can't carry such a load! Capacity: " + 
            to_string(static_cast<int>(CARRIAGE_LOAD_CAP)) + 
            " kg, requested: " + 
            to_string(static_cast<int>(weight)) + 
            " kg"
        );
    }
    return distance * CARRIAGE_COST_PER_KM * (weight / WEIGTH_UNIT) * NUMBER_OF_HORSES * CARRIAGE_HORSE_FACTOR;
}

double Carriage::calculatePassengerCost(double distance, int passengers) const
{
    return distance * CARRIAGE_COST_PER_KM * passengers * CARRIAGE_PASSENGER_DISCOUNT;
}

const char *Carriage::getType() const { return "Carriage"; }

