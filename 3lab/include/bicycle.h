#pragma once
#include "../include/transport.h"

class Bicycle : public Transport {
   public:
    Bicycle();
    double calculateCost(double distance, double weight) const override;
    double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
};