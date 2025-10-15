#pragma once
#include <iomanip>
#include <iostream>
#include <string>

class Date {
   private:
    int day = 0;
    int month = 0;
    int year = 0;

    Date(int day, int month, int year);
    void showInvalidDataException(const std::string& date, const std::exception& excep);
    int getDaysInMonth() const;
    bool isLeapYear() const;

   public:
    Date() = default;
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << std::setw(2) << date.day << '.' << std::setw(2) << date.month << '.' << date.year;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Date& date) {
        std::string line;

        if (std::getline(is, line, '.')) {
            date.day = std::stoi(line);
        }

        if (std::getline(is, line, '.')) {
            date.month = std::stoi(line);
        }

        if (std::getline(is, line, ' ')) {
            date.year = std::stoi(line);
        }

        return is;
    }
    void validateAndSet(const std::string& date);
    void inputDate();
    int getYear() const { return year; }
};
