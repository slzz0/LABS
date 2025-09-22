#pragma once
#include <iostream>

class Transport {
   private:
    double speedPerH;
    double costPerKm;
    double capacity;

   public:
    Transport(double speed, double cost, double cap);
    virtual ~Transport() = default;

    double getCostPerKm() const { return costPerKm; }
    double getCapacity() const { return capacity; }
    double getSpeed() const { return speedPerH; }

    virtual double calculateTime(double distance) const;
    virtual double calculateCost(double distance, double weight) const;
    virtual double calculatePassengerCost(double distance, int passengers) const;
    virtual void displayInfo() const;
    virtual void inputDetails();
};
