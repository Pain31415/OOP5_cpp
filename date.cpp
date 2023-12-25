#include "date.h"


Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

std::istream& operator>>(std::istream& in, Date& date) {
    std::cout << "Enter day: ";
    in >> date.day;
    std::cout << "Enter month: ";
    in >> date.month;
    std::cout << "Enter year: ";
    in >> date.year;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.day << "." << date.month << "." << date.year;
    return out;
}

Date Date::operator++() {
    // Префіксний інкремент
    day++;
    if (day > 31) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int) {
    // Постфіксний інкремент
    Date temp = *this;
    ++(*this);
    return temp;
}

Date Date::operator--() {
    // Префіксний декремент
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}

Date Date::operator--(int) {
    // Постфіксний декремент
    Date temp = *this;
    --(*this);
    return temp;
}

bool Date::operator==(const Date& other) const {
    return (day == other.day) && (month == other.month) && (year == other.year);
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator>(const Date& other) const {
    if (year > other.year) {
        return true;
    }
    else if (year == other.year) {
        if (month > other.month) {
            return true;
        }
        else if (month == other.month) {
            return day > other.day;
        }
    }
    return false;
}

bool Date::operator<(const Date& other) const {
    return !(*this > other) && (*this != other);
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

Date& Date::operator+=(int days) {
    for (int i = 0; i < days; ++i) {
        ++(*this);
    }
    return *this;
}

Date& Date::operator-=(int days) {
    for (int i = 0; i < days; ++i) {
        --(*this);
    }
    return *this;
}

Date Date::operator()() const {
    return *this;
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    default:
        return -1;
    }
}