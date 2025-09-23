#include "../include/utils.h"

#include <iostream>

#include "../include/transport.h"

using namespace std;

int validation() {
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

        if (number < 0) {
            std::cout << "Please enter a non-negative number: ";
            continue;
        }

        return number;
    }
}

int validatePassengers(int passengers, int maxPassengers) {
    while (passengers > maxPassengers || passengers < 0) {
        if (passengers > maxPassengers) {
            cout << "Cannot carry more than " << maxPassengers << " passengers!\n";
        } else {
            cout << "Number of passengers cannot be negative!\n";
        }
        cout << "Enter number of passengers (0-" << maxPassengers << "): ";
        passengers = validation();
    }
    return passengers;
}

double validateWeight(double weight, double maxCapacity) {
    while (weight > maxCapacity || weight < 0) {
        if (weight > maxCapacity) {
            cout << "Cannot carry more than " << maxCapacity << " kg!\n";
        } else {
            cout << "Weight cannot be negative!\n";
        }
        cout << "Enter cargo weight (0-" << maxCapacity << " kg): ";
        weight = validation();
    }
    return weight;
}