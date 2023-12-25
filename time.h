#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int hours, int minutes, int seconds);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void setTime(int hours, int minutes, int seconds);

    friend std::istream& operator>>(std::istream& in, Time& time);
    friend std::ostream& operator<<(std::ostream& out, const Time& time);

    Time operator++();         // Префіксний інкремент
    Time operator++(int);      // Постфіксний інкремент

    Time operator--();         // Префіксний декремент
    Time operator--(int);      // Постфіксний декремент

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;

    int operator[](int index) const;

    Time& operator=(const Time& other);

    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);

    Time operator()() const;
};

#endif // TIME_H