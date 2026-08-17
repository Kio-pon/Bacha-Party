#include "Time.hpp"

#include <iomanip>
#include <iostream>

// Exercise 1 [25 points]: implement the Time class declared in Time.hpp.
// See the header for the exact semantics/examples of each operator.
// Constraints: no <ctime>/<chrono>, integer arithmetic only, operands must
// not be mutated (except compound-assignment style methods, if any),
// subtraction assumes the first time is >= the second.

Time::Time(const int seconds)
{
    // TODO: normalize `seconds` into m_hours/m_minutes/m_seconds (wrap hours at 24)
}

Time::Time(const int hours, const int minutes, const int seconds)
    : Time(0)
{
    // TODO: delegate to Time(int) using the total seconds, like the
    // constructor delegation pattern shown in the header's comments
}

Time Time::operator+(const Time &other) const
{
    // TODO: add two Time values (as total seconds) and return a new Time
    return Time(0);
}

Time Time::operator+(const int other) const
{
    // TODO: add `other` seconds and return a new Time
    return Time(0);
}

Time Time::operator-(const Time &other) const
{
    // TODO: subtract other from this (as total seconds) and return a new Time
    return Time(0);
}

Time Time::operator-(const int other) const
{
    // TODO: subtract `other` seconds and return a new Time
    return Time(0);
}

bool Time::operator==(const Time &other) const
{
    // TODO: compare total seconds for equality
    return false;
}

bool Time::operator==(const int other) const
{
    // TODO: compare total seconds to `other`
    return false;
}

bool Time::operator!=(const Time &other) const
{
    // TODO: negate operator==
    return false;
}

bool Time::operator!=(const int other) const
{
    // TODO: negate operator==
    return false;
}

bool Time::operator<(const Time &other) const
{
    // TODO: compare total seconds
    return false;
}

bool Time::operator<(const int other) const
{
    // TODO: compare total seconds to `other`
    return false;
}

bool Time::operator>(const Time &other) const
{
    // TODO: compare total seconds
    return false;
}

bool Time::operator>(const int other) const
{
    // TODO: compare total seconds to `other`
    return false;
}

void Time::show() const
{
    // TODO: print as zero-padded HH:MM:SS
}

int Time::getHours() const { return m_hours; }

int Time::getMinutes() const { return m_minutes; }

int Time::getSeconds() const { return m_seconds; }
