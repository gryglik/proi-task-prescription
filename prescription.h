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
    States status;
    std::vector<std::string> medicines;
public:
    Prescription(const Patient& patient, const Date& expiryDate,
        const Date& issueDate=Date());

    const Patient& getPatient() const {return this->patient;}
    const Date& getIssueDate() const {return this->issueDate;}
    const Date& getExpiryDate() const {return this->expiryDate;}
    const States& getStatus() const {return this->status;}

    void setStatus(const States &status);

    bool search(const std::string& medicine) const;
    bool add(const std::string& medicine);
    bool modify(const std::string& medicine, const std::string& new_medicine);
    bool remove(const std::string& medicine);
    unsigned int count() const;

    std::string print(const Prescription& prescription) const;
};
