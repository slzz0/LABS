#pragma once
#include <iostream>

#include "../include/algorithm.h"
#include "../include/exceptions.h"
#include "../include/ring.h"
#include "../include/utils.h"
#include "../include/menu.h"

template <typename T>
class Program {
    Ring<T> ring;
    Algorithm<T> algorithm;

    void createRing();
    void addRingElement();
    void removeRingElement();
    void showRing();
    void sortRing();
    void searchRingElement();
    void clearRing();
    void demonstrateAlgorithms();

   public:
    Program();
    void run();
};

template <typename T>
Program<T>::Program() {}

template <typename T>
void Program<T>::createRing() {
    if (!ring.empty()) {
        std::cout << "Error, ring is already created!" << "\n";
        return;
    }

    std::cout << "Enter number of elements: ";
    auto count = getValue<size_t>();

    for (size_t i = 0; i < count; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        T value = getValue<T>();
        ring.pushBack(value);
    }
}

template <typename T>
void Program<T>::addRingElement() {
    std::cout << "Enter value to add: ";
    auto value = getValue<T>();

    int opt = 0;
    showAddMenu();

    while (true) {
        std::cout << "Please enter the add menu option: ";
        opt = getValue<int>();

        switch (opt) {
            case 1:
                ring.pushFront(value);
                std::cout << "Element added to front!" << "\n";
                return;
            case 2:
                ring.pushBack(value);
                std::cout << "Element added to back!" << "\n";
                return;
            default:
                std::cout << "Invalid choice, please try again!" << "\n";
        }
    }
}   

template <typename T>
void Program<T>::removeRingElement() {
    if (ring.empty()) {
        std::cout << "Error, ring is empty" << "\n";
        return;
    }

    int opt = 0;
    showRemoveMenu();

    while (true) {
        std::cout << "Please enter the remove menu option: ";
        opt = getValue<int>();

        switch (opt) {
            case 1:
                ring.popFront();
                std::cout << "Front element removed!" << "\n";
                return;
            case 2:
                ring.popBack();
                std::cout << "Back element removed!" << "\n";
                return;
            default:
                std::cout << "Wrong choice, please try again!" << "\n";
        }
    }
}

template <typename T>
void Program<T>::showRing() {
    if (ring.empty()) {
        std::cout << "Ring is empty." << "\n";
        return;
    }

    std::cout << "Ring elements: ";

    auto it = ring.begin();
    for (size_t i = 0; i < ring.getSize(); i++) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}

template <typename T>
void Program<T>::sortRing() {
    if (ring.empty()) {
        std::cout << "Error, ring is empty." << "\n";
        return;
        std::cout << "The ring was sorting" << "\n";
    }

    try {
        algorithm.sort(ring);
    } catch (const RingException& e) {
        std::cout << "Sorting error: " << e.what() << "\n";
    }
}

template <typename T>
void Program<T>::searchRingElement() {
    if (ring.empty()) {
        std::cout << "Error, ring is empty." << "\n";
        return;
    }

    std::cout << "Enter value to search: ";
    auto value = getValue<T>();

    try {
        if (algorithm.find(ring, value)) {
            std::cout << "Element found!" << "\n";
        } else {
            std::cout << "Element not found." << "\n";
        }
    } catch (const RingException& e) {
        std::cout << "Search error: " << e.what() << "\n";
    }
}

template <typename T>
void Program<T>::clearRing() {
    if (ring.empty()) {
        std::cout << "Ring is already empty" << "\n";
        return;
    }

    ring.clear();
}

template <typename T>
void Program<T>::run() {
    int opt = 0;

    while (true) {
        showMenu();
        std::cout << "\nPlease enter menu option: ";
        opt = getValue<int>();

        switch (opt) {
            case 1:
                createRing();
                break;
            case 2:
                addRingElement();
                break;
            case 3:
                removeRingElement();
                break;
            case 4:
                showRing();
                break;
            case 5:
                sortRing();
                break;
            case 6:
                searchRingElement();
                break;
            case 7:
                clearRing();
                break;

            case 9:
                std::cout << "End the program..." << "\n";
                return;
            default:
                std::cout << "Invalid option. Try again." << "\n";
        }
    }
}