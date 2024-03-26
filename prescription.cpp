#include <stdexcept>
#include "prescription.h"

Prescription::Prescription(const Patient& patient, const Date& expiryDate,
   const Date& issueDate)
{
   if(expiryDate < issueDate)
      throw(std::runtime_error(
         "The expiration date must be earlier than the issuance date."));

   this->patient = patient;
   this->issueDate = issueDate;
   this->expiryDate = expiryDate;
   this->status = States::in_preparation;
}

const Patient& Prescription::getPatient() const
{
   return this->patient;
}

const Date& Prescription::getIssueDate() const
{
   return this->issueDate;
}

const Date& Prescription::getExpiryDate() const
{
   return this->expiryDate;
}

const States& Prescription::getStatus() const
{
   return this->status;
}

void Prescription::setStatus(const States &status)
{
   if(this->status <= status)
      this->status = status;
   else
      throw(std::runtime_error("Cannot change status."));
}