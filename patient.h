#pragma once
#include <string>
#include "date.h"

class Patient
{
private:
    std::string name;
    std::string surname;
    Date birthDate;
public:
    Patient() = default;
    Patient(const std::string& name, const std::string& surname, const Date& birthDate);

    const std::string& getName() const {return this->name;}
    const std::string& getSurname() const {return this->surname;}
    const Date& getBirthDate() const {return this->birthDate;}

    const std::string print() const;
};