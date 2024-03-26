#include "patient.h"
#include <string>
#include <stdexcept>
#include <ctime>

Patient::Patient(const std::string &name, const std::string &surname, unsigned int birthYear)
{
    if(name.size() > 50 || !name.size())
        throw std::length_error("Name must consist of 1 to 50 chars.");

    if(surname.size() > 70 || !surname.size())
        throw std::length_error("Surname must consist of 1 to 70 chars.");

    if(birthYear < 1900)
        throw std::runtime_error("Birth Year must be equal or greater than 1900.");

    time_t now = std::time(0);
    unsigned int now_year = gmtime(&now)->tm_year + 1900;
    if(birthYear > now_year)
        throw std::runtime_error("Birth Year must be smaller or equal the current year");

    this->name = name;
    this->surname = surname;
    this->birthYear = birthYear;
}

const std::string& Patient::getName() const
{
    return this->name;
}

const std::string& Patient::getSurname() const
{
    return this->surname;
}

unsigned int Patient::getBirthYear() const
{
    return this->birthYear;
}

const std::string Patient::print() const
{
    return this->getName() + " " + this->getSurname() + " "
        + std::to_string(this->getBirthYear());
}