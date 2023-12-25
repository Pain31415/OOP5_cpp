#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:

    Date();
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDate(int day, int month, int year);

    friend std::istream& operator>>(std::istream& in, Date& date);
    friend std::ostream& operator<<(std::ostream& out, const Date& date);

    Date operator++();
    Date operator++(int);

    Date operator--();
    Date operator--(int);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;

    Date& operator=(const Date& other);

    Date& operator+=(int days);
    Date& operator-=(int days);

    Date operator()() const;
};

#endif // DATE_H