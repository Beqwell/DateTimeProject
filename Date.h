#pragma once
#include "DateValidator.h"

/**
 * @brief Structure representing a date.
 */
struct Date {
    int year;
    int month;
    int day;

    /**
     * @brief Constructor to initialize the date.
     * @param y The year.
     * @param m The month.
     * @param d The day.
     */
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    /**
     * @brief Validate the date.
     * @return true if the date is valid, false otherwise.
     */
    bool isValid() const {
        return DateValidator::isValidDate(year, month, day);
    }
};
