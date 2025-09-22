#include "../include/transport.h"
#include "../include/utils.h"
#include "../include/consts.h"

#include <iostream>

using namespace std;

Transport::Transport(double speed, double cost, double cap)
    : speedPerH(speed), costPerKm(cost), capacity(cap) {}

double Transport::calculateTime(double distance) const { return distance / speedPerH; }

double Transport::calculateCost(double distance, double weight) const {
    weight = validateWeight(weight, capacity);  
    return distance * costPerKm * (weight / WEIGTH_UNIT);
}

double Transport::calculatePassengerCost(double distance, int passengers) const {
    return distance * costPerKm * passengers;
}

void Transport::displayInfo() const {
    cout << "Speed: " << speedPerH << " km/h" << "\n";
    cout << "Cost per km: " << costPerKm << " BYN" << "\n";
    cout << "Load capacity: " << capacity << " kg" << "\n";
}

void Transport::inputDetails(){
    cout << "Enter speed (km/h): ";
    speedPerH = validation();
    cout << "Enter cost per km (BYN): ";
    costPerKm = validation();
    cout << "Enter load capacity (kg): ";
    capacity = validation();
}