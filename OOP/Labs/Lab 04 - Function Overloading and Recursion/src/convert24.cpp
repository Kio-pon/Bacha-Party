#include <iostream>
#include <string>

using namespace std;

// Write three overloaded versions of convert24 that convert given values of
// hours, minutes and/or seconds into a 24-hour "+days, HH:MM:SS" display.
// If hours and minutes are zero, call convert24(int seconds); if only hours
// is zero, call convert24(int minutes, int seconds); otherwise call
// convert24(int hours, int minutes, int seconds).

string zerofill(int time)
{
    // TODO: pad single-digit values with a leading zero, return as string
    return "";
}

void convert24(int seconds)
{
    // TODO: convert total seconds into days/hours/minutes/seconds and print
    // as "+D, HH:MM:SS" (or "HH:MM:SS" if no full day has elapsed)
}

void convert24(int minutes, int seconds)
{
    // TODO: convert to total seconds and delegate to convert24(int)
}

void convert24(int hours, int minutes, int seconds)
{
    // TODO: convert to total seconds and delegate to convert24(int)
}

int main()
{
    int hours, minutes, seconds;

    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;

    if (hours == 0 && minutes == 0)
    {
        convert24(seconds);
    }
    else if (hours == 0)
    {
        convert24(minutes, seconds);
    }
    else
    {
        convert24(hours, minutes, seconds);
    }

    return 0;
}
