#pragma once

class Date
{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);

    bool operator==(const Date& date) const;
    bool operator!=(const Date& date) const;
    bool operator>(const Date& date) const;
    bool operator>=(const Date& date) const;
    bool operator<(const Date& date) const;
    bool operator<=(const Date& date) const;

    unsigned int getDay() const {return this->day;}
    unsigned int getMonth() const {return this->month;};
    unsigned int getYear() const {return this->year;};

    std::string print() const;
};