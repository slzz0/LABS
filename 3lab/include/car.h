#pragma once
#include "../include/consts.h"
#include "../include/transport.h"


class Car : public Transport {
   private:
    int maxPassengers = CAR_MAX_PASS;

   public:
    Car();
    double calculateCost(double distance, double weight) const override;
    double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
};