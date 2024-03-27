#include <iostream>
#include <string>
#include "prescription.h"

int main(int argc, char* argv[])
{

    Patient patient = Patient(argv[1], argv[2], Date(argv[3]));

    Date expiryDate = Date(argv[4]);

    Date issueDate = Date();
    if (std::string(argv[5]) != "today")
        issueDate = Date(argv[5]);

    Prescription prescription = Prescription(patient, expiryDate, issueDate);
    for (int i = 6; i < (argc - 1); i++)
        prescription.add(argv[i]);
    if (std::string(argv[argc - 1]) == "in_preparation")
        prescription.setStatus(States::in_preparation);
    else if (std::string(argv[argc - 1]) == "issued")
        prescription.setStatus(States::issued);
    else if (std::string(argv[argc - 1]) == "partly_realised")
        prescription.setStatus(States::partly_realised);
    else if (std::string(argv[argc - 1]) == "realised")
        prescription.setStatus(States::realised);
    else
        throw (std::runtime_error("incorrect status"));

    std::cout << prescription.print();
}