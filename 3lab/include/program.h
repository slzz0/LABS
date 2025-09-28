#include "../include/transport.h"
#pragma once

void runProgram();
void inputCalculationData(double& distance, double& weight, int& passengers);
void printAllCalculations(const Transport* vehicle, double distance, double weight, int passengers);