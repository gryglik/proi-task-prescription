#include <stdexcept>
#include "patient.h"

Patient::Patient(const std::string &name, const std::string &surname, const Date &birthDate)
{
    if(name.size() > 50 || !name.size())
        throw std::length_error("Name must consist of 1 to 50 chars.");

    if(surname.size() > 70 || !surname.size())
        throw std::length_error("Surname must consist of 1 to 70 chars.");

    if(birthDate < Date(1, 1, 1900))
        throw std::runtime_error("Birth date cannot be earlier that 01-01-1900.");

    if(birthDate > Date())
        throw std::runtime_error("Invalid birth date.");

    this->name = name;
    this->surname = surname;
    this->birthDate = birthDate;
}

const std::string Patient::print() const
{
    return this->getName() + " " + this->getSurname() + "\n"
        + this->getBirthDate().print();
}