#pragma once

/**
 * @brief Class for date validation.
 */
class DateValidator {
public:
    /**
     * @brief Check if a year is a leap year.
     * @param year The year to check.
     * @return true if the year is a leap year, false otherwise.
     */
    static bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    /**
     * @brief Validate a date.
     * @param year The year.
     * @param month The month.
     * @param day The day.
     * @return true if the date is valid, false otherwise.
     */
    static bool isValidDate(int year, int month, int day) {
        if (year < 0 || month < 1 || month > 12 || day < 1)
            return false;

        const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int maxDays = daysInMonth[month];

        if (month == 2 && isLeapYear(year))
            maxDays = 29;

        return (day <= maxDays);
    }
};
