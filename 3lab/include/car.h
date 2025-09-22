#pragma once
#include "../include/transport.h"

class Car : public Transport {
   private:
    int maxPassengers;

   public:
    Car(double speed, double cost, double cap, int maxPass);
    double calculateCost(double distance, double weight) const override;
    double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
    void inputDetails() override;
};