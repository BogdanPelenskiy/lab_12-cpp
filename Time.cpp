#include "Time.h"

static const int DAY = 86400; // кількість секунд у добі

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
normalize();
}

int Time::toSeconds() const {
return hours * 3600 + minutes * 60 + seconds;
}

// нормалізація циклічного часу
void Time::normalize() {
int total = toSeconds();
total = ((total % DAY) + DAY) % DAY; // завжди у межах 0–86399

hours = total / 3600;
total %= 3600;
minutes = total / 60;
seconds = total % 60;
}

// циклічна "відстань" від 00:00:00
int Time::cyclicDistance() const {
int t = toSeconds();
return std::min(t, DAY - t);
}

// циклічне порівняння
bool Time::operator>(const Time& other) const {
return this->cyclicDistance() > other.cyclicDistance();
}

// циклічне віднімання
Time& Time::operator-=(int sec) {
int total = toSeconds();
total = ((total - sec) % DAY + DAY) % DAY;
hours = total / 3600;
total %= 3600;
minutes = total / 60;
seconds = total % 60;

return *this;
}

// виведення
std::ostream& operator<<(std::ostream& out, const Time& t) {
out << (t.hours < 10 ? "0" : "") << t.hours << ":"
<< (t.minutes < 10 ? "0" : "") << t.minutes << ":"
<< (t.seconds < 10 ? "0" : "") << t.seconds;
return out;
}

// введення з валідацією
std::istream& operator>>(std::istream& in, Time& t) {
while (true) {
std::cout << "Введіть години: ";
if (in >> t.hours && t.hours >= 0 && t.hours < 24) break;
std::cout << "❌ Помилка! Години 0–23.\n";
in.clear();
in.ignore(10000, '\n');
}

while (true) {
std::cout << "Введіть хвилини: ";
if (in >> t.minutes && t.minutes >= 0 && t.minutes < 60) break;
std::cout << "❌ Помилка! Хвилини 0–59.\n";
in.clear();
in.ignore(10000, '\n');
}

while (true) {
std::cout << "Введіть секунди: ";
if (in >> t.seconds && t.seconds >= 0 && t.seconds < 60) break;
std::cout << "❌ Помилка! Секунди 0–59.\n";
in.clear();
in.ignore(10000, '\n');
}

t.normalize();
return in;
}
