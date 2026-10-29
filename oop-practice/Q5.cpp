#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    void getTime()
    {
        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;
    }

    Time operator+(Time t)
    {
        Time result;

        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes;
        result.hours = hours + t.hours;

        if (result.seconds >= 60)
        {
            result.seconds = result.seconds - 60;
            result.minutes++;
        }

        if (result.minutes >= 60)
        {
            result.minutes = result.minutes - 60;
            result.hours++;
        }

        return result;
    }

    Time operator-(Time t)
    {
        Time result;

        int totalSeconds1;
        int totalSeconds2;
        int difference;

        totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        totalSeconds2 = t.hours * 3600 + t.minutes * 60 + t.seconds;

        difference = totalSeconds1 - totalSeconds2;

        if (difference < 0)
        {
            difference = -difference;
        }

        result.hours = difference / 3600;
        difference = difference % 3600;

        result.minutes = difference / 60;
        result.seconds = difference % 60;

        return result;
    }

    Time operator++()
    {
        seconds++;

        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
        }

        if (minutes == 60)
        {
            minutes = 0;
            hours++;
        }

        return *this;
    }

    void display()
    {
        cout << setfill('0') << setw(2) << hours << ":";
        cout << setfill('0') << setw(2) << minutes << ":";
        cout << setfill('0') << setw(2) << seconds << endl;
    }
};

int main()
{
    Time time1, time2, sum, difference;

    cout << "Enter first time:" << endl;
    time1.getTime();

    cout << "\nEnter second time:" << endl;
    time2.getTime();

    sum = time1 + time2;
    difference = time1 - time2;

    cout << "\nFirst Time: ";
    time1.display();

    cout << "Second Time: ";
    time2.display();

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    ++time1;

    cout << "First Time after increment: ";
    time1.display();

    return 0;
}