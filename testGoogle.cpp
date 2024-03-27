#include <ctime>
#include <stdexcept>
#include <gtest/gtest.h>
#include "prescription.h"


TEST(DateTest, create_default)
{
    Date date = Date();
    std::time_t today = std::time(0);

    ASSERT_EQ(date.getDay(), gmtime(&today)->tm_mday);
    ASSERT_EQ(date.getMonth(), gmtime(&today)->tm_mon + 1);
    ASSERT_EQ(date.getYear(), gmtime(&today)->tm_year + 1900);
}

TEST(DateTest, print)
{
    Date date1 = Date(30, 3, 2004);
    Date date2 = Date(9, 12, 2004);
    Date date3 = Date(9, 9, 2004);
    ASSERT_EQ(date1.print(), "30-03-2004");
    ASSERT_EQ(date2.print(), "09-12-2004");
    ASSERT_EQ(date3.print(), "09-09-2004");
}

TEST(DateTest, create_custom_typical)
{
    Date date = Date(30, 3, 2004);
    ASSERT_EQ(date.getDay(), 30);
    ASSERT_EQ(date.getMonth(), 3);
    ASSERT_EQ(date.getYear(), 2004);
}

TEST(DateTest, create_custom_last_days_of_months)
{
    Date date1 = Date(31, 1, 2004);
    ASSERT_EQ(date1.print(), "31-01-2004");

    Date date2 = Date(31, 3, 2004);
    ASSERT_EQ(date2.print(), "31-03-2004");

    Date date3 = Date(30, 4, 2004);
    ASSERT_EQ(date3.print(), "30-04-2004");

    Date date4 = Date(31, 5, 2004);
    ASSERT_EQ(date4.print(), "31-05-2004");

    Date date5 = Date(30, 6, 2004);
    ASSERT_EQ(date5.print(), "30-06-2004");

    Date date6 = Date(31, 7, 2004);
    ASSERT_EQ(date6.print(), "31-07-2004");

    Date date7 = Date(31, 8, 2004);
    ASSERT_EQ(date7.print(), "31-08-2004");

    Date date8 = Date(30, 9, 2004);
    ASSERT_EQ(date8.print(), "30-09-2004");

    Date date9 = Date(31, 10, 2004);
    ASSERT_EQ(date9.print(), "31-10-2004");

    Date date10 = Date(30, 11, 2004);
    ASSERT_EQ(date10.print(), "30-11-2004");

    Date date11 = Date(31, 12, 2004);
    ASSERT_EQ(date11.print(), "31-12-2004");
}

TEST(DateTest, create_custom_last_day_of_february)
{
    Date date1 = Date(29, 2, 2004);
    Date date2 = Date(28, 2, 2005);
    ASSERT_EQ(date1.print(), "29-02-2004");
    ASSERT_EQ(date2.print(), "28-02-2005");
}

TEST(DateTest, create_invalid_day)
{
    EXPECT_THROW(Date(0, 1, 2010), std::runtime_error);
    EXPECT_THROW(Date(0, 6, 2010), std::runtime_error);
    EXPECT_THROW(Date(32, 1, 2010), std::runtime_error);
    EXPECT_THROW(Date(29, 2, 2010), std::runtime_error);
    EXPECT_THROW(Date(30, 2, 2012), std::runtime_error);
    EXPECT_THROW(Date(32, 3, 2010), std::runtime_error);
    EXPECT_THROW(Date(31, 4, 2010), std::runtime_error);
    EXPECT_THROW(Date(32, 5, 2010), std::runtime_error);
    EXPECT_THROW(Date(31, 6, 2010), std::runtime_error);
    EXPECT_THROW(Date(32, 7, 2010), std::runtime_error);
    EXPECT_THROW(Date(32, 8, 2010), std::runtime_error);
    EXPECT_THROW(Date(31, 9, 2010), std::runtime_error);
    EXPECT_THROW(Date(32, 9, 2010), std::runtime_error);
    EXPECT_THROW(Date(31, 11, 2010), std::runtime_error);
}

TEST(DateTest, create_invalid_month)
{
    EXPECT_THROW(Date(23, 0, 2010), std::runtime_error);
    EXPECT_THROW(Date(23, 13, 2010), std::runtime_error);
}

TEST(DateTest, create_invalid_year)
{
    EXPECT_THROW(Date(23, 11, 1899), std::runtime_error);
    EXPECT_THROW(Date(23, 11, 10000), std::runtime_error);
}

TEST(DateTest, create_from_string)
{
    Date date1 = Date("12-03-2024");
    ASSERT_EQ(date1.print(), "12-03-2024");
}

TEST(DateTest, create_from_string_invalid)
{
    ASSERT_THROW(Date("10/12/2004"), std::runtime_error);
    ASSERT_THROW(Date("3-3-2004"), std::runtime_error);
}

TEST(DateTest, operator_comprasion_equality)
{
    ASSERT_EQ(Date(23, 11, 2004) == Date(23, 11, 2004), true);
    ASSERT_EQ(Date(23, 11, 2004) == Date(22, 11, 2004), false);

    ASSERT_EQ(Date(23, 11, 2004) != Date(23, 11, 2004), false);
    ASSERT_EQ(Date(23, 11, 2004) != Date(22, 11, 2004), true);
}

TEST(DateTest, operator_comprasion_greater)
{
    ASSERT_EQ(Date(23, 11, 2004) > Date(22, 11, 2004), true);
    ASSERT_EQ(Date(22, 12, 2004) > Date(22, 11, 2004), true);
    ASSERT_EQ(Date(22, 11, 2005) > Date(22, 11, 2004), true);

    ASSERT_EQ(Date(30, 12, 2000) > Date(1, 1, 2004), false);
    ASSERT_EQ(Date(30, 3, 2004) > Date(26, 3, 2024), false);
}

TEST(DateTest, operator_comprasion_greater_or_equal)
{
    ASSERT_EQ(Date(23, 11, 2004) >= Date(22, 11, 2004), true);
    ASSERT_EQ(Date(23, 11, 2004) >= Date(23, 11, 2004), true);
    ASSERT_EQ(Date(23, 11, 2004) >= Date(23, 12, 2004), false);
}

TEST(DateTest, operator_comprasion_less)
{
    ASSERT_EQ(Date(22, 11, 2004) < Date(23, 11, 2004), true);
    ASSERT_EQ(Date(22, 11, 2004) < Date(22, 12, 2004), true);
    ASSERT_EQ(Date(22, 11, 2004) < Date(22, 11, 2005), true);

    ASSERT_EQ(Date(22, 11, 2004) < Date(22, 11, 2004), false);
    ASSERT_EQ(Date(21, 11, 2005) < Date(22, 11, 2004), false);
}

TEST(DateTest, operator_comprasion_less_or_equal)
{
    ASSERT_EQ(Date(22, 11, 2004) <= Date(23, 11, 2004), true);
    ASSERT_EQ(Date(23, 11, 2004) <= Date(23, 11, 2004), true);
    ASSERT_EQ(Date(23, 12, 2004) <= Date(23, 11, 2004), false);
}

TEST(PatientTest, create_patient_typical)
{
    Patient patient = Patient("Andrzej", "Kawka", Date(30, 3, 2004));
    ASSERT_EQ(patient.getName(), "Andrzej");
    ASSERT_EQ(patient.getSurname(), "Kawka");
    ASSERT_EQ(patient.getBirthDate(), Date(30, 3, 2004));
}

TEST(PatientTest, create_empty_name_or_surname)
{
    EXPECT_THROW(Patient("", "Kawka", Date(30, 3, 2004)), std::length_error);
    EXPECT_THROW(Patient("Andrzej", "", Date(30, 3, 2004)), std::length_error);
}

TEST(PatientTest, create_too_long_name_or_surname)
{
    EXPECT_THROW(
        Patient("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
                "Kawka", Date(30, 3, 2004)),
        std::length_error);
    EXPECT_THROW(
        Patient("Andrzej",
                "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
                Date(30, 3, 2004)),
        std::length_error);
}

TEST(PatientTest, create_invalid_birth_date)
{
    Date today;
    EXPECT_THROW(Patient("Andrzej", "Kawka", Date(30, 3, 1899)), std::runtime_error);
    EXPECT_THROW(Patient("Andrzej", "Kawka", Date(30, 3, today.getYear() + 1)),
        std::runtime_error);
}

TEST(PatientTest, print)
{
    Patient patient = Patient("Andrzej", "Kawka", Date(30, 3, 2004));
    ASSERT_EQ(patient.print(), "Andrzej Kawka\n30-03-2004");
}

TEST(PrescriptionTest, create_typical)
{
    Date today = Date();
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(23, 12, today.getYear() + 1));

    ASSERT_EQ(prescription.getPatient().getName(), "Andrzej");
    ASSERT_EQ(prescription.getExpiryDate(), Date(23, 12, today.getYear() + 1));
    ASSERT_EQ(prescription.getIssueDate(), Date());
    ASSERT_EQ(prescription.getStatus(), States::in_preparation);
}

TEST(PrescriptionTest, create_typical_past_issue_date)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024),
        Date(23, 3, 2024));

    ASSERT_EQ(prescription.getPatient().getName(), "Andrzej");
    ASSERT_EQ(prescription.getExpiryDate(), Date(26, 4, 2024));
    ASSERT_EQ(prescription.getIssueDate(), Date(23, 3, 2024));
    ASSERT_EQ(prescription.getStatus(), States::in_preparation);
    ASSERT_EQ(prescription.getCount(), 0);
}

TEST(PrescriptionTest, create_passed_expiry_date)
{
    Patient patient = Patient("Andrzej", "Kawka", Date(30, 3, 2004));
    EXPECT_THROW(Prescription(patient, Date(25, 3, 2024)), std::runtime_error);
    EXPECT_THROW(Prescription(patient, Date(21, 3, 2024)), std::runtime_error);
    EXPECT_THROW(Prescription(patient, Date(21, 3, 2024),
        Date(22, 3, 2024)), std::runtime_error);
}

TEST(PrescriptionTest, create_future_issue_date)
{
    Date today = Date();
    Patient patient = Patient("Andrzej", "Kawka", Date(30, 3, 2004));
    EXPECT_THROW(Prescription(
            patient,
            Date(25, 4, today.getYear() + 1),
            Date(22, 4, today.getYear() + 1)),
        std::runtime_error);
}

TEST(PrescriptionTest, setStatus_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024),
        Date(23, 3, 2024));

    ASSERT_EQ(prescription.getStatus(), States::in_preparation);

    prescription.setStatus(States::issued);
    ASSERT_EQ(prescription.getStatus(), States::issued);

    prescription.setStatus(States::partly_realised);
    ASSERT_EQ(prescription.getStatus(), States::partly_realised);

    prescription.setStatus(States::realised);
    ASSERT_EQ(prescription.getStatus(), States::realised);
}

TEST(PrescriptionTest, setStatus_invalid)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024),
        Date(23, 3, 2024));

    prescription.setStatus(States::issued);
    ASSERT_EQ(prescription.getStatus(), States::issued);
    EXPECT_THROW(prescription.setStatus(States::in_preparation), std::runtime_error);
    ASSERT_EQ(prescription.getStatus(), States::issued);

    prescription.setStatus(States::partly_realised);
    ASSERT_EQ(prescription.getStatus(), States::partly_realised);
    EXPECT_THROW(prescription.setStatus(States::in_preparation), std::runtime_error);
    EXPECT_THROW(prescription.setStatus(States::issued), std::runtime_error);
    ASSERT_EQ(prescription.getStatus(), States::partly_realised);

    prescription.setStatus(States::realised);
    ASSERT_EQ(prescription.getStatus(), States::realised);
    EXPECT_THROW(prescription.setStatus(States::in_preparation), std::runtime_error);
    EXPECT_THROW(prescription.setStatus(States::issued), std::runtime_error);
    EXPECT_THROW(prescription.setStatus(States::partly_realised), std::runtime_error);
    ASSERT_EQ(prescription.getStatus(), States::realised);
}

TEST(PrescriptionTest, getCount_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    ASSERT_EQ(prescription.getCount(), 0);
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.getCount(), 1);
    prescription.add("Xanax, 0,25 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.getCount(), 2);
}

TEST(PrescriptionTest, search_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.search("Clatra, 20 mg, tabletki, 30 szt."), true);
    ASSERT_EQ(prescription.search("Izotziaja, 0,5 mg/g, żel, 20 g"), false);
}


TEST(PrescriptionTest, add_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.getCount(), 1);
    ASSERT_EQ(prescription.search("Clatra, 20 mg, tabletki, 30 szt."), true);
}

TEST(PrescriptionTest, add_empty_medicine)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    EXPECT_THROW(prescription.add(""), std::runtime_error);
}

TEST(PrescriptionTest, add_existing_medicine)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    EXPECT_THROW(prescription.add("Clatra, 20 mg, tabletki, 30 szt."),
        std::runtime_error);
}

TEST(PrescriptionTest, modify_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,25 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.getCount(), 2);
    prescription.modify("Xanax, 0,25 mg, tabletki, 30 szt.", "Xanax, 0,50 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.search("Xanax, 0,50 mg, tabletki, 30 szt."), true);
    ASSERT_EQ(prescription.search("Xanax, 0,25 mg, tabletki, 30 szt."), false);
}

TEST(PrescriptionTest, modify_no_existing)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,25 mg, tabletki, 30 szt.");
    EXPECT_THROW(prescription.modify("Clatra 20 mg", "Clatra 40 mg"), std::runtime_error);
}

TEST(PrescriptionTest, modify_to_empty_too_long_medicine)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    prescription.add("Clatra, 40 mg, tabletki, 30 szt.");
    EXPECT_THROW(prescription.modify("Clatra, 20 mg, tabletki, 30 szt.", ""), std::runtime_error);
    EXPECT_THROW(prescription.modify("Clatra, 20 mg, tabletki, 30 szt.", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"),
        std::runtime_error);
}

TEST(PrescriptionTest, remove_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,25 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,50 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 1,00 mg, tabletki, 30 szt.");
    prescription.remove("Xanax, 0,25 mg, tabletki, 30 szt.");
    ASSERT_EQ(prescription.getCount(), 3);
    ASSERT_EQ(prescription.search("Xanax, 0,25 mg, tabletki, 30 szt."), false);
}

TEST(PrescriptionTest, remove_not_existing)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,25 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,50 mg, tabletki, 30 szt.");
    EXPECT_THROW(prescription.remove("Clatra, 30mg"), std::runtime_error);
}

TEST(PrescriptionTest, printMedicines_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra");
    prescription.add("Xanax");
    prescription.add("Bilagra");
    ASSERT_EQ(prescription.printMedicines(), "Clatra\nXanax\nBilagra");
}


TEST(PrescriptionTest, printMedicines_empty)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    ASSERT_EQ(prescription.printMedicines(), "");
}

TEST(PrescriptionTest, print_typical)
{
    Prescription prescription = Prescription(
        Patient("Andrzej", "Kawka", Date(30, 3, 2004)),
        Date(26, 4, 2024));
    prescription.add("Clatra, 20 mg, tabletki, 30 szt.");
    prescription.add("Xanax, 0,25 mg, tabletki, 30 szt.");
    std::string expected_output = ""
    "[ PATIENT ]\n"
    "Andrzej Kawka\n"
    "30-03-2004\n"
    "\n"
    "[ MEDICINES ]\n"
    "Clatra, 20 mg, tabletki, 30 szt.\n"
    "Xanax, 0,25 mg, tabletki, 30 szt.\n"
    "\n"
    "[ STATUS ] realised\n"
    "\n"
    "[ ISSUE DATE ] 27-03-2024\n"
    "\n"
    "[ EXPIRY DATE ] 26-04-2024";
    ASSERT_EQ(prescription.print(), expected_output);
}
