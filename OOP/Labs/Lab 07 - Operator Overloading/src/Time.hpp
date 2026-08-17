#ifndef TIME_HPP
#define TIME_HPP

/// @brief Class representing a time of the day.
class Time {
public:

    // Time(3661) -> 01:01:01
    Time(const int seconds);

    // Time(2, 40, 10)  -> 02:40:10
    // Time(25, 10, 23) -> 01:10:23
    Time(const int hours, const int minutes, const int seconds);

    // Time(1, 20, 30) + Time(0, 50, 45) -> Time(2, 11, 15)
    Time operator+(const Time& other) const;
    // Time(1, 20, 30) + 3045 -> Time(2, 11, 15)
    Time operator+(const int other) const;

    // Time(2, 10, 0) - Time(1, 50, 0) -> 00:20:00
    Time operator-(const Time& other) const;
    // Time(1, 0, 0) - 90 -> 00:58:30
    Time operator-(const int other) const;

    // Time(1, 0, 0) == Time(1, 0, 0) -> true
    // Time(1, 0, 0) == Time(0, 59, 59) -> false
    bool operator==(const Time& other) const;
    // Time(1, 0, 0) == 3600 -> true
    // Time(1, 0, 0) == 3599 -> false
    bool operator==(const int other) const;

    // Time(1, 0, 0) != Time(0, 59, 59) -> true
    // Time(1, 0, 0) != Time(1, 0, 0) -> false
    bool operator!=(const Time& other) const;
    // Time(1, 0, 0) != 3599 -> true
    // Time(1, 0, 0) != 3600 -> false
    bool operator!=(const int other) const;

    // Time(1, 0, 0) < Time(2, 0, 0) -> true
    // Time(1, 0, 0) < Time(0, 59, 59) -> false
    bool operator<(const Time& other) const;
    // Time(1, 0, 0) < 7200 -> true
    // Time(1, 0, 0) < 3599 -> false
    bool operator<(const int other) const;

    // Time(2, 0, 0) > Time(1, 0, 0) -> true
    // Time(1, 0, 0) > Time(1, 0, 1) -> false
    bool operator>(const Time& other) const;
    // Time(2, 0, 0) > 3600 -> true
    // Time(1, 0, 0) > 3601 -> false
    bool operator>(const int other) const;

    void show() const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

private:

    int m_hours, m_minutes, m_seconds;
};

#endif  // TIME_HPP