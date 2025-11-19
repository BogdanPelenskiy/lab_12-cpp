#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    void normalize();

public:
    Time();
    Time(int h, int m, int s);
    ~Time() {}

    int toSeconds() const;
    bool operator>(const Time& other) const;
    Time& operator-=(int sec);

    friend std::ostream& operator<<(std::ostream& out, const Time& t);
    friend std::istream& operator>>(std::istream& in, Time& t);
};

#endif
