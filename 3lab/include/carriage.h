#pragma once
#include "../include/transport.h"

class Carriage : public Transport {
   private:
    int numberOfHorses;

   public:
    Carriage(double speed, double cost, double cap, int horses);
    double calculateCost(double distance, double weight) const override;
    double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
    void inputDetails() override;
};