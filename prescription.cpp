#include <stdexcept>
#include "prescription.h"

inline void Prescription::validateMedicine(const std::string &medicine) const
{
   if (! medicine.size() || medicine.size() > 100)
      throw (std::runtime_error("Medicine name must consist of 1 - 100 chars."));
}

Prescription::Prescription(const Patient& patient, const Date& expiryDate,
   const Date& issueDate)
{
   if(expiryDate < issueDate)
      throw(std::runtime_error(
         "The expiration date must be earlier than the issuance date."));

   if(issueDate > Date())
      throw(std::runtime_error(
         "Cannot create prescription with future issuance date."));

   this->patient = patient;
   this->issueDate = issueDate;
   this->expiryDate = expiryDate;
}

void Prescription::setStatus(const States &status)
{
   if(this->status <= status)
      this->status = status;
   else
      throw(std::runtime_error("Cannot change status."));
}

bool Prescription::search(const std::string &medicine)
{
   for (unsigned int i = 0; i < this->medicines.size(); i++)
      if (medicine == medicines[i])
      {
         this->lastSearch = i;
         return true;
      }
   this->lastSearch = -1;
   return false;
}

void Prescription::add(const std::string &medicine)
{
   validateMedicine(medicine);
   if (this->search(medicine))
      throw (std::runtime_error("Medicine: '" + medicine + "' already in the prescription."));
   this->medicines.push_back(medicine);
}

void Prescription::modify(const std::string& medicine,
   const std::string& new_medicine)
{
   this->validateMedicine(new_medicine);
   if (! this->search(medicine))
      throw (std::runtime_error("Medicine not in the prescription."));
   this->medicines[lastSearch] = new_medicine;
}

void Prescription::remove(const std::string& medicine)
{
   if (! this->search(medicine))
      throw (std::runtime_error("Medicine not in the prescription."));
   this->medicines.erase(medicines.begin() + this->lastSearch);
}

std::string Prescription::printMedicines() const
{
   std::string medicinesString = "";
   for (unsigned int i=0; i < this->getCount() - 1; i++)
      medicinesString += this->medicines[i] + "\n" ;
   medicinesString += medicines[this->getCount() - 1];
   return medicinesString;
}

std::string Prescription::print() const
{
   return ">--- PATIENT:\n"
      + this->getPatient().print()
      + "\n\n>--- MEDICINES:\n"
      + this->printMedicines()
      + "\n\n>--- STATUS:\n"
      + "\n\n>--- ISSUE DATE:\n"
      + this->getIssueDate().print()
      + "\n>--- EXPIRY DATE:\n"
      + this->getExpiryDate().print();
}