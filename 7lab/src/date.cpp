#include "../include/date.h"

#include <iostream>

#include "../include/consts.h"
#include "../include/utils.h"

Date::Date(int inputDay, int inputMonth, int inputYear)
    : day(inputDay), month(inputMonth), year(inputYear) {}

bool Date::isLeapYear() const { return (year % 4 == 0); }

int Date::getDaysInMonth() const {
    if (month == 2 && isLeapYear()) {
        return LEAP_FEBRUARY_DAYS;
    }

    return DAYS_IN_MONTH[month - 1];
}

void Date::showInvalidDataException(const std::string& date, const std::exception& excep) {
    std::cout << "Incorrect date format: " << excep.what() << " | input: " << date << "\n";
}

void Date::validateAndSet(const std::string& date) {
    try {
        if (date.length() != FORMAT_DATE) {
            throw std::invalid_argument("Invalid format of date (dd.mm.yy)");
        }
        if (date[2] != '.' && date[5] != '.') {
            throw std::invalid_argument("Invalid format: dd.mm.yy with dots between");
        }
        int dayValue = std::stoi(date.substr(0, 2));
        int monthValue = std::stoi(date.substr(3, 2));
        int yearValue = std::stoi(date.substr(6, 2));

        if (!isDigits(date, 0, 2) || !isDigits(date, 3, 2) || !isDigits(date, 6, 2)) {
            throw std::invalid_argument("Day, months and years must contain only digits");
        }
        if (monthValue < 1 || monthValue > COUNT_OF_MONTH) {
            throw std::invalid_argument("Month out of range (1-12)");
        }
        Date value(dayValue, monthValue, yearValue);
        *this = value;
    } 
    catch (const std::invalid_argument& excep) {
        showInvalidDataException(date, excep);
    } 
    catch (const std::out_of_range& excep) {
        showInvalidDataException(date, excep);
    }
}

void Date::inputDate() {
    std::string date;
    while (true) {
        date = getValue<std::string>("Enter the date with format dd.mm.yy: ");
        
        try {
            validateAndSet(date);
            break;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << ". Please try again.\n";
        }
    }
}