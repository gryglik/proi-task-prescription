#pragma once
#include <vector>
#include <string>
#include "date.h"
#include "patient.h"

enum class States : short {in_preparation, issued, partly_realised, realised};

class Prescription
{
private:
    Patient patient;
    Date issueDate;
    Date expiryDate;
    States status = States::in_preparation;
    std::vector<std::string> medicines;

    int lastSearch = -1;
    inline void validateMedicine(const std::string& medicine) const;

public:
    Prescription(const Patient& patient, const Date& expiryDate,
        const Date& issueDate=Date());

    const Patient& getPatient() const {return this->patient;}
    const Date& getIssueDate() const {return this->issueDate;}
    const Date& getExpiryDate() const {return this->expiryDate;}
    const States& getStatus() const {return this->status;}
    unsigned int getCount() const {return this->medicines.size();}

    void setStatus(const States &status);

    bool search(const std::string& medicine);
    void add(const std::string& medicine);
    void modify(const std::string& medicine, const std::string& new_medicine);
    void remove(const std::string& medicine);

    std::string printMedicines() const;
    std::string print() const;
};
