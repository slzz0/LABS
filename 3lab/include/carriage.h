#pragma once
#include "../include/transport.h"

class Carriage : public Transport {
   private:
    int numberOfHorses;

   public:
    Carriage();
    double calculateCost(double distance, double weight) const override;
    double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
};