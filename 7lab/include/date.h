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
    friend std::ostream &operator<<(std::ostream &ostm, const Date &date)
{
    ostm << std::setw(2) << std::setfill('0') << date.day << '.' 
         << std::setw(2) << std::setfill('0') << date.month << '.'
         << date.year;
    return ostm;
}

friend std::istream &operator>>(std::istream &istm, Date &date)
{
    char dot1, dot2;
    istm >> date.day >> dot1 >> date.month >> dot2 >> date.year;
    
    // Проверка корректности разделителей
    if (dot1 != '.' || dot2 != '.') {
        istm.setstate(std::ios::failbit);
    }
    
    return istm;
}
    void validateAndSet(const std::string &date);
    void inputDate();
    int getYear() const {return year;}
};
