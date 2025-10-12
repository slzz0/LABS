#include "../include/utils.h"
#include "../include/invalidException.h"

#include <iostream>

void inputTransportationData(double& distance, double& weight, int& passengers) {
    while (true) {
        try {
            std::cout << "  Enter Transportation Data  " << "\n";

            std::cout << "Enter distance (km): ";
            distance = getNumber();

            if (distance <= 0) throw InvalidException("Distance must be positive");

            std::cout << "Enter cargo weight (kg): ";
            weight = getNumber();

            if (weight < 0) throw InvalidException("Weight cannot be negative");

            std::cout << "Enter number of passengers (km): ";
            passengers = getNumber();
            if (passengers < 0) throw InvalidException("Number of passengers cannot be negative");

            std::cout << "\n";
            return;
        } catch (const InvalidException& e) {
            std::cout << "Input error: " << e.what() << "\n";
            std::cout << "Please re-enter all transportation data.\n" << "\n";
        }
    }
}

int getNumber() {
    int number;

    while (true) {
        if (!(std::cin >> number)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please enter a valid number: ";
            continue;
        }

        if (std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please enter only numbers without characters: ";
            continue;
        }

        return number;
    }
}

void demonstrateTransport(const Transport* transport, double distance, double weight,
                          int passengers) {
    std::cout << "\n\n\t Calculation for  " << transport->getType() << " " << "\n";
    transport->displayInfo();

    double time = transport->calculateTime(distance);
    std::cout << "Transportation time for " << distance << " km: " << time << " hours ("
              << time * 60 << " minutes)"
              << "\n";

    try {
        double cost = transport->calculateCost(distance, weight);
        std::cout << "Transportation cost for " << weight << " kg: " << cost << " BYN" << "\n";
    } catch (const InvalidException& e) {
        std::cout << "Error calculating cargo cost: " << e.what() << "\n";
    }

    try {
        double passengerCost = transport->calculatePassengerCost(distance, passengers);
        std::cout << "Transportation cost for " << passengers << " passengers: " << passengerCost
                  << " BYN" << "\n";
    } catch (const InvalidException& e) {
        std::cout << "Error calculating passenger cost: " << e.what() << "\n";
    }
}

void validateString(const std::string& input, const std::string& fieldName) {
    if (input.empty()) {
        throw InvalidException(input, "Field cannot be empty");
    }

    for (char character : input) {
        if (isspace(static_cast<unsigned char>(character))) {
            throw InvalidException(input, "Must not contain spaces or whitespace characters");
        }
        if (!isdigit(character) && (character < 'a' || character > 'z') &&
            (character < 'A' || character > 'Z')) {
            throw InvalidException(
                input, "Must contain only digits (0-9) and latin letters (a-z, A-Z)");
        }
    }
}