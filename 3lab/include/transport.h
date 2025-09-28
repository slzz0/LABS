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

    virtual double calculateTime(double distance) const;
    virtual double calculateCost(double distance, double weight) const;
    virtual double calculatePassengerCost(double distance, int passengers) const;
    virtual void displayInfo() const;
    virtual void inputDetails();
};
