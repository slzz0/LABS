#include "../include/car.h"

#include <iostream>
#include <format>

#include "../include/consts.h"
#include "../include/invalidException.h"
#include "../include/utils.h"
#include "../include/transport.h"

using namespace std;

Car::Car() : Transport(CAR_SPEED_IN_KM, CAR_COST_PER_KM, CAR_LOAD_CAP, CAR_REG_NUMBER) {}

#include <format>

double Car::calculateCost(double distance, double weight) const {
    if (weight > CAR_LOAD_CAP) {
        throw InvalidException(
            std::format(
                "Car can't carry such a load! Capacity: {} kg, requested: {} kg",
                static_cast<int>(CAR_LOAD_CAP),
                static_cast<int>(weight)
            )
        );
    }
    return distance * CAR_COST_PER_KM * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const {
    if (passengers > CAR_MAX_PASS) {
        throw InvalidException("Car can't carry that many passengers! Max: 5, requested: " +
                               to_string(passengers));
    }

    return distance * CAR_COST_PER_KM * passengers;
}

const char* Car::getType() const { return "Car"; }
