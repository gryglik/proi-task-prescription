#include <ctime>
#include <string>
#include <stdexcept>
#include "date.h"

Date::Date()
{
    time_t now = std::time(0);

    this->day = gmtime(&now)->tm_mday;
    this->month = gmtime(&now)->tm_mon + 1;
    this->year = gmtime(&now)->tm_year + 1900;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    if(!day || !month || !year || month > 12 || year < 1900 || year > 9999
        || (month == 2 && day > (28 + (year % 4 == 0)))
        || (month <= 7 && day > (30 + month % 2))
        || (month >= 8 && day > (31 - month % 2))
    )
        throw(std::runtime_error("Invalid date."));

    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const std::string &date)
{
    if (date.size() != 10
        || ! ('0' <= date[0] <= '9')
        || ! ('0' <= date[1] <= '9')
        || date[2] != '-'
        || ! ('0' <= date[3] <= '9')
        || ! ('0' <= date[4] <= '9')
        || date[5] != '-'
        || ! ('0' <= date[6] <= '9')
        || ! ('0' <= date[7] <= '9')
        || ! ('0' <= date[8] <= '9')
        || ! ('0' <= date[9] <= '9'))
        throw (std::runtime_error("Invalid date format"));
    unsigned int day = 10 * (date[0] - '0') + (date[1] - '0');
    unsigned int month = 10 * (date[3] - '0') + (date[4] - '0');
    unsigned int year = 1000 * (date[6] - '0') + 100 * (date[7] - '0')
        + 10 * (date[8] - '0') + (date[9] - '0');
    *this = Date(day, month, year);
}

bool Date::operator==(const Date& date) const
{
    return this->getYear() == date.getYear()
        && this->getMonth() == date.getMonth()
        && this->getDay() == date.getDay();
}

bool Date::operator!=(const Date& date) const
{
    return ! (*this == date);
}

bool Date::operator>(const Date& date) const
{
    if(this->getYear() > date.getYear())
        return true;
    else if(this->getYear() == date.getYear()
            && this->getMonth() > date.getMonth())
        return true;
    else if(this->getYear() == date.getYear()
            && this->getMonth() == date.getMonth()
            && this->getDay() > date.getDay())
        return true;
    return false;
}

bool Date::operator>=(const Date& date) const
{
    return *this > date || *this == date;
}

bool Date::operator<(const Date& date) const
{
    return ! (*this >= date);
}

bool Date::operator<=(const Date& date) const
{
    return ! (*this > date);
}

std::string Date::print() const
{
    std::string day = std::to_string(this->getDay());
    if(day.size() == 1)
        day = "0" + day;
    std::string month = std::to_string(this->getMonth());
    if(month.size() == 1)
        month = "0" + month;
    std::string year = std::to_string(this->getYear());

    return day + "-" + month + "-" + year;
}