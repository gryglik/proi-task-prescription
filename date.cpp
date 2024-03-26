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

unsigned int Date::getDay() const
{
    return this->day;
}

unsigned int Date::getMonth() const
{
    return this->month;
}

unsigned int Date::getYear() const
{
    return this->year;
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