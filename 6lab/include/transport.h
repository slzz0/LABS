#pragma once
#include <string>

class Transport {
   private:
    double speedPerH;
    double costPerKm;
    double capacity;
    std::string registrationNumber;

   public:
    Transport(double speed, double cost, double cap, std::string regNum);
    virtual ~Transport() = default;

    virtual double calculateTime(double distance) const;
    virtual double calculateCost(double distance, double weight) const;
    virtual double calculatePassengerCost(double distance, int passengers) const;
    virtual void displayInfo() const;
    virtual const char* getType() const;
    std::string getRegistrationNumber() const { return registrationNumber; }
    void setRegistrationNumber(const std::string_view regNum);
    double getLoadCapacity() const { return capacity; }
    virtual int getMaxPassengers() const { return 1; }
};
