class Date
{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);

    bool operator==(const Date& date) const;
    bool operator!=(const Date& date) const;
    bool operator>(const Date& date) const;
    bool operator>=(const Date& date) const;
    bool operator<(const Date& date) const;
    bool operator<=(const Date& date) const;

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    std::string print() const;
};