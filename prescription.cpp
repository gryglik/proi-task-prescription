#include <stdexcept>
#include "prescription.h"

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
   this->status = States::in_preparation;
}

void Prescription::setStatus(const States &status)
{
   if(this->status <= status)
      this->status = status;
   else
      throw(std::runtime_error("Cannot change status."));
}