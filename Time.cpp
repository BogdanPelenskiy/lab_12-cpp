#include "Time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::normalize() {
    int total = toSeconds();
    if (total < 0) total = 0;

    hours = total / 3600;
    total %= 3600;
    minutes = total / 60;
    seconds = total % 60;
}

bool Time::operator>(const Time& other) const {
    return this->toSeconds() > other.toSeconds();
}

Time& Time::operator-=(int sec) {
    int total = toSeconds() - sec;
    if (total < 0) total = 0;

    hours = total / 3600;
    total %= 3600;
    minutes = total / 60;
    seconds = total % 60;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds;
    return out;
}

std::istream& operator>>(std::istream& in, Time& t) {
    while (true) {
        std::cout << "Введіть години: ";
        if (in >> t.hours && t.hours >= 0) break;
        std::cout << "❌ Помилка! Години мають бути цілим невід’ємним числом.\n";
        in.clear();
        in.ignore(10000, '\n');
    }

    while (true) {
        std::cout << "Введіть хвилини: ";
        if (in >> t.minutes && t.minutes >= 0 && t.minutes < 60) break;
        std::cout << "❌ Помилка! Хвилини мають бути в межах 0–59.\n";
        in.clear();
        in.ignore(10000, '\n');
    }

    while (true) {
        std::cout << "Введіть секунди: ";
        if (in >> t.seconds && t.seconds >= 0 && t.seconds < 60) break;
        std::cout << "❌ Помилка! Секунди мають бути в межах 0–59.\n";
        in.clear();
        in.ignore(10000, '\n');
    }

    t.normalize();
    return in;
}
