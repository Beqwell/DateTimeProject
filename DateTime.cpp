#include <iostream>
#include <windows.h>
#include "DateTime.h"
#include "ListOperations.h"
#include "TimeFactory.h"

using namespace std;

/**
 * @brief Main function.
 * @return 0 on success.
 */
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ListOperations listOps;

    cout << "Enter dates and times. Enter '0 0 0' for date and time to finish." << endl;

    while (true) {
        Date date(1, 0, 0);
        Time time(TimeFactory::createHour(0), TimeFactory::createMinute(1), TimeFactory::createSecond(0));
        DateTime dateTime(date, time);

        cout << "Enter day and month (DD MM): ";
        cin >> dateTime.date.day >> dateTime.date.month;

        if (dateTime.date.day == 0 && dateTime.date.month == 0) {
            cout << "Input finished." << endl;
            break;
        }

        if (dateTime.date.month < 1 || dateTime.date.month > 12) {
            cout << "Invalid month. Please enter a valid month (1-12) and try again." << endl;
            continue;
        }

        const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int maxDays = daysInMonth[dateTime.date.month];

        if (dateTime.date.month == 2 && DateValidator::isLeapYear(dateTime.date.year))
            maxDays = 29;

        if (dateTime.date.day < 1 || dateTime.date.day > maxDays) {
            cout << "Invalid day. Please enter a valid day (1-" << maxDays << ") for the selected month and try again." << endl;
            continue;
        }

        cout << "Enter year (YYYY): ";
        cin >> dateTime.date.year;

        cout << "Enter time (HH MM SS): ";
        cin >> dateTime.time.hours.value >> dateTime.time.minutes.value >> dateTime.time.seconds.value;

        try {
            dateTime.time.hours.validate();
            dateTime.time.minutes.validate();
            dateTime.time.seconds.validate();
        }
        catch (const std::invalid_argument& e) {
            cout << "Invalid time. " << e.what() << " Please enter a valid time and try again." << endl;
            continue;
        }

        if (dateTime.date.day == 0 && dateTime.date.month == 0 && dateTime.date.year == 0 &&
            dateTime.time.hours.value == 0 && dateTime.time.minutes.value == 0 && dateTime.time.seconds.value == 0) {
            cout << "Input finished." << endl;
            break;
        }

        if (!dateTime.isValid()) {
            cout << "Invalid date or time. Please enter a valid date and time and try again." << endl;
            continue;
        }

        int dayOfWeek = dateTime.calculateDayOfWeek();
        const char* daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        cout << "Day of the week: " << daysOfWeek[dayOfWeek] << endl;

        listOps.addDateTime(dateTime);
    }

    listOps.sortByDate();

    cout << "Sorted by date:" << endl;
    for (const auto& dt : listOps.dateTimeList) {
        cout << dt.date.day << "-" << dt.date.month << "-" << dt.date.year << " ";
        cout << dt.time.hours.value << ":" << dt.time.minutes.value << ":" << dt.time.seconds.value << endl;
    }

    listOps.sortByTime();

    cout << "Sorted by time:" << endl;
    for (const auto& dt : listOps.dateTimeList) {
        cout << dt.date.day << "-" << dt.date.month << "-" << dt.date.year << " ";
        cout << dt.time.hours.value << ":" << dt.time.minutes.value << ":" << dt.time.seconds.value << endl;
    }

    return 0;
}
