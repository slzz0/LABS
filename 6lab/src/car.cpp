#include "../include/car.h"

#include <format>
#include <iostream>

#include "../include/consts.h"
#include "../include/invalidException.h"
#include "../include/transport.h"
#include "../include/utils.h"


using namespace std;

Car::Car() : Transport(CAR_SPEED_IN_KM, CAR_COST_PER_KM, CAR_LOAD_CAP, CAR_REG_NUMBER) {}

double Car::calculateCost(double distance, double weight) const {
    if (weight > CAR_LOAD_CAP) {
        throw InvalidException(
            std::format("Car can't carry such a load! Capacity: {} kg, requested: {} kg",
                        static_cast<int>(CAR_LOAD_CAP), static_cast<int>(weight)));
    }
    return distance * CAR_COST_PER_KM * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const {
    if (passengers > CAR_MAX_PASS) {
        throw InvalidException(
            std::format("Car can't carry that many passengers! Max: {}, requested: {}",
                        CAR_MAX_PASS, passengers));
    }

    return distance * CAR_COST_PER_KM * passengers;
}

const char* Car::getType() const { return "Car"; }
