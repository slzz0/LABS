#include "../include/transport.h"

#include "../include/consts.h"
#include "../include/invalidException.h"
#include "../include/utils.h"

Transport::Transport(double speed, double cost, double cap, std::string regNum)
    : speedPerH(speed), costPerKm(cost), capacity(cap), registrationNumber(std::move(regNum)) {}

double Transport::calculateTime(double distance) const { return distance / speedPerH; }

double Transport::calculateCost(double distance, double weight) const {
    if (weight > capacity) {
        throw InvalidException(
            "Load capacity exceeded! Capacity: " + std::to_string(static_cast<int>(capacity)) +
            " kg, requested: " + std::to_string(static_cast<int>(weight)) + " kg");
    }
    return distance * costPerKm * (weight / WEIGTH_UNIT);
}

double Transport::calculatePassengerCost(double distance, int passengers) const {
    return distance * passengers * costPerKm;
}

void Transport::displayInfo() const {
    std::cout << "Speed: " << speedPerH << " km/h" << "\n";
    std::cout << "Cost per km: " << costPerKm << " BYN" << "\n";
    std::cout << "Load capacity: " << capacity << " kg" << "\n";
    std::cout << "Registration: " << registrationNumber << "\n";
}

void Transport::setRegistrationNumber(const std::string& regNum) { registrationNumber = regNum; }

const char* Transport::getType() const { return "Transport vehicle"; }