#include "time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setTime(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

std::istream& operator>>(std::istream& in, Time& time) {
    std::cout << "Enter hours: ";
    in >> time.hours;
    std::cout << "Enter minutes: ";
    in >> time.minutes;
    std::cout << "Enter seconds: ";
    in >> time.seconds;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << time.hours << "h " << time.minutes << "m " << time.seconds << "s";
    return out;
}

Time Time::operator++() {
    seconds++;
    if (seconds == 60) {
        seconds = 0;
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hours++;
            if (hours == 24) {
                hours = 0;
            }
        }
    }
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

Time Time::operator--() {
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hours--;
            if (hours < 0) {
                hours = 23;
            }
        }
    }
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

bool Time::operator==(const Time& other) const {
    return (hours == other.hours) && (minutes == other.minutes) && (seconds == other.seconds);
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator>(const Time& other) const {
    if (hours > other.hours) {
        return true;
    }
    else if (hours == other.hours) {
        if (minutes > other.minutes) {
            return true;
        }
        else if (minutes == other.minutes) {
            return seconds > other.seconds;
        }
    }
    return false;
}

bool Time::operator<(const Time& other) const {
    return !(*this > other) && (*this != other);
}

int Time::operator[](int index) const {
    switch (index) {
    case 0:
        return hours;
    case 1:
        return minutes;
    case 2:
        return seconds;
    default:
        return -1;
    }
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time& Time::operator+=(const Time& other) {
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;

    if (seconds >= 60) {
        seconds -= 60;
        minutes++;
    }

    if (minutes >= 60) {
        minutes -= 60;
        hours++;
    }

    if (hours >= 24) {
        hours %= 24;
    }

    return *this;
}

Time& Time::operator-=(const Time& other) {
    hours -= other.hours;
    minutes -= other.minutes;
    seconds -= other.seconds;

    if (seconds < 0) {
        seconds += 60;
        minutes--;
    }

    if (minutes < 0) {
        minutes += 60;
        hours--;
    }

    if (hours < 0) {
        hours += 24;
    }

    return *this;
}

Time Time::operator()() const {
    return *this;
}