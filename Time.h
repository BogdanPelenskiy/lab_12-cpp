#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
int hours;
int minutes;
int seconds;

void normalize(); // нормалізація у межах 0–86399

public:
Time();
Time(int h, int m, int s);
~Time() {}

int toSeconds() const; // у секунди (0–86399)
int cyclicDistance() const; // мінімальна відстань до 0 за годинниковою логікою

bool operator>(const Time& other) const; // циклічне порівняння
Time& operator-=(int sec); // циклічне зменшення

friend std::ostream& operator<<(std::ostream& out, const Time& t);
friend std::istream& operator>>(std::istream& in, Time& t);
};

#endif
