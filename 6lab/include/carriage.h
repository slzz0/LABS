#pragma once
#include "../include/consts.h"
#include "../include/transport.h"

class Carriage : public Transport {
   private:
    int numberOfHorses = NUMBER_OF_HORSES;

   public:
    Carriage();
    double calculateCost(double distance, double weight) const override;
    double calculatePassengerCost(double distance, int passengers) const override;
    const char *getType() const override;
    int getMaxPassengers() const override { return CAR_MAX_PASS; }
};