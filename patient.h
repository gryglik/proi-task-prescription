#include<string>

class Patient
{
private:
    std::string name;
    std::string surname;
    unsigned int birthYear;
public:
    Patient() = default;
    Patient(const std::string &name, const std::string &surname, unsigned int birthYear);

    const std::string& getName() const;
    const std::string& getSurname() const;
    unsigned int getBirthYear() const;

    const std::string print() const;
};