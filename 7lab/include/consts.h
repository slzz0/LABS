#pragma once

#include <array>
#include <iostream>

const int COUNT_OF_MONTH = 12;
const std::array<int, COUNT_OF_MONTH> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30,
                                                       31, 31, 30, 31, 30, 31};
const int LEAP_FEBRUARY_DAYS = 29;
const int FORMAT_DATE = 8;

const std::string FILE_WITH_PRODUCTS = "products.txt";