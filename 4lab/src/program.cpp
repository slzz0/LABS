#include "../include/program.h"

#include <iostream>

#include "../include/ancestor.h"
#include "../include/grandson.h"
#include "../include/kid.h"
#include "../include/menu.h"
#include "../include/utils.h"


void Program::ensureFamilyCapacity() {
    size = std::max(size, 0);
    if (size + 1 >= capacity) {
        capacity *= 2;
        auto** newMembers = new Ancestor*[capacity];
        for (int i = 0; i < size; i++) {
            newMembers[i] = familyMembers[i];
        }
        delete[] familyMembers;
        familyMembers = newMembers;
    }
    size++;
}

void Program::addMember() {
    ensureFamilyCapacity();

    std::cout << "\n\t MENU" << "\n";
    std::cout << "1. Add Kid" << "\n";
    std::cout << "2. Add GrandSon" << "\n";
    std::cout << "Choose option: ";

    int opt = validation();

    auto* name = new char[100];
    std::cout << "Enter name: ";
    std::cin.getline(name, 100);

    if (myStrlen(name) == 0) {
        std::cout << "Error: Name cannot be empty!" << "\n";
        size--;
        return;
    }

    switch (opt) {
        case 1:
            familyMembers[size - 1] = new Kid(name);
            delete[] name;
            break;

        case 2: {
            auto* surName = new char[100];
            std::cout << "Enter surName: ";
            std::cin.getline(surName, 100);

            familyMembers[size - 1] = new Grandson(name, surName);
            delete[] name;
            delete[] surName;
            break;
        }

        default:
            delete[] name;
            size--;
            std::cout << "Error: Invalid option!!" << "\n";
            break;
    }
}

Program::~Program() { clear(); }

void Program::addFamilyMember() { addMember(); }

void Program::showAllMembers() const {
    if (size == 0) {
        std::cout << "No family members!" << "\n\n";
        return;
    }
    std::cout << "\n\tFAMILY MEMBERS" << "\n";
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". ";
        familyMembers[i]->print();
    }
}

void Program::clear() {
    for (int i = 0; i < size; i++) {
        delete familyMembers[i];
    }
    delete[] familyMembers;
    familyMembers = nullptr;
    size = capacity = 0;
}

void Program::start() {
    taskMenu();
    while (true) {
        std::cout << "\n\tMENU OPTIONS" << "\n";
        std::cout << "1. Add member" << "\n";
        std::cout << "2. Show members" << "\n";
        std::cout << "3. Exit" << "\n";
        std::cout << "Choose the option: ";

        int opt = validation();

        switch (opt) {
            case 1:
                addFamilyMember();
                break;
            case 2:
                showAllMembers();
                break;
            case 3:
                std::cout << "Exiting the program..." << "\n";
                return;
            default:
                std::cout << "Error: Invalid menu option!" << "\n";
                break;
        }
    }
}