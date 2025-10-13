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
    const char *getType() const override;
    int getMaxPassengers() const override { return CAR_MAX_PASS; }
};