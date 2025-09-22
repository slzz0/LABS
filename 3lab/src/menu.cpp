#include "../include/menu.h"
#include <iostream>
using namespace std;

void taskMenu() {
    cout << "\n\t\t\tTASK" << endl;
    cout << "Create a base class 'Vehicle' and derived classes 'Car', 'Bicycle', 'Carriage'."
              << endl;
    cout << "Calculate the time and cost of transporting passengers and goods by each vehicle."
              << endl;
}

void showTransportMenu() {
    cout << "\n\t=== SELECT TRANSPORT TYPE ===" << endl;
    cout << "1. Car" << endl;
    cout << "2. Bicycle" << endl;
    cout << "3. Carriage" << endl;
    cout << "4. End the program..." << endl;
    cout << "========================================================" << endl;
}

void showCalculationMenu() {
    cout << "\n\t=== SELECT CALCULATION ===" << endl;
    cout << "1. Calculate Transportation Time" << endl;
    cout << "2. Calculate Passenger Cost" << endl;
    cout << "3. Calculate Cargo Cost" << endl;
    cout << "4. Display Vehicle Information" << endl;
    cout << "5. Back to Transport Selection" << endl;
    cout << "========================================================" << endl;
}