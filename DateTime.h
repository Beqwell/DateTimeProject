#pragma once
#include "Date.h"
#include "Time.h"

/**
 * @brief Structure representing a date and time.
 */
struct DateTime {
    Date date;
    Time time;

    /**
     * @brief Constructor to initialize the date and time.
     * @param d The date.
     * @param t The time.
     */
    DateTime(Date d, Time t) : date(d), time(t) {}

    /**
     * @brief Validate the date and time.
     * @return true if the date and time are valid, false otherwise.
     */
    bool isValid() const {
        return date.isValid() && time.isValid();
    }

    /**
     * @brief Add time difference to the current date and time.
     * @param diff The time difference.
     */
    void addTimeDifference(const Time& diff) {
        time.seconds.value += diff.seconds.value;
        time.minutes.value += diff.minutes.value;
        time.hours.value += diff.hours.value;

        if (time.seconds.value >= 60) {
            time.seconds.value -= 60;
            time.minutes.value++;
        }

        if (time.minutes.value >= 60) {
            time.minutes.value -= 60;
            time.hours.value++;
        }

        if (time.hours.value >= 24) {
            time.hours.value -= 24;
            date.day++;
        }

        while (!date.isValid()) {
            int daysInMonth = 31;

            if (date.month == 2) {
                daysInMonth = DateValidator::isLeapYear(date.year) ? 29 : 28;
            }
            else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
                daysInMonth = 30;
            }

            if (date.day > daysInMonth) {
                date.day -= daysInMonth;
                date.month++;

                if (date.month > 12) {
                    date.month = 1;
                    date.year++;
                }
            }
        }
    }

    /**
     * @brief Calculate the day of the week for the date.
     * @return The day of the week (0 = Sunday, 6 = Saturday).
     */
    int calculateDayOfWeek() const {
        int day = date.day;
        int month = date.month;
        int year = date.year;

        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;

        int dayOfWeek = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

        dayOfWeek = (dayOfWeek + 7) % 7;

        return dayOfWeek;
    }

    /**
     * @brief Calculate the time difference between two DateTime objects.
     * @param other The other DateTime object.
     * @return The time difference.
     */
    Time calculateTimeDifference(const DateTime& other) const {
        int totalSeconds1 = date.day * 24 * 3600 + time.hours.value * 3600 + time.minutes.value * 60 + time.seconds.value;
        int totalSeconds2 = other.date.day * 24 * 3600 + other.time.hours.value * 3600 + other.time.minutes.value * 60 +
            other.time.seconds.value;

        int diffSeconds = totalSeconds2 - totalSeconds1;

        int diffHours = diffSeconds / 3600;
        int diffMinutes = (diffSeconds % 3600) / 60;
        int diffSecs = diffSeconds % 60;

        return Time(Hour(diffHours), Minute(diffMinutes), Second(diffSecs));
    }
};
