#include "../headers/program.h"

#include "../headers/matrix.h"
#include "../headers/menu.h"
#include "../headers/utilits.h"

using namespace std;

void runProgram() {
    Matrix matrix;
    int choice;

    taskMenu();

    while (true) {
        cout << "\nSelect a task MENU option: ";
        choice = validInt();

        switch (choice) {
            case 1:
                matrix.inputMatrix();
                break;
            case 2:
                matrix.printMatrix();
                break;
            case 3: {
                cout << "Enter the number you want to multiply your matrix by: ";
                int num = validInt();
                matrix.multiplyByNumber(num);
                break;
            }
            case 4:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "Error you have selected an incorrect MENU option" << endl;
                break;
        }
    }
}
