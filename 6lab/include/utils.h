#include "../include/transport.h"
#pragma once

int getNumber();
void inputTransportationData(double &distance, double &weight, int &passengers);
void demonstrateTransport(const Transport *transport, double distance, double weight, int passengers);
void validateString(const std::string &input, const std::string_view fieldName);
