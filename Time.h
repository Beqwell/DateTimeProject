#pragma once
#include "TimeUnit.h"

/**
 * @brief Structure representing a time.
 */
struct Time {
    Hour hours;
    Minute minutes;
    Second seconds;

    /**
     * @brief Constructor to initialize the time.
     * @param h The hours.
     * @param m The minutes.
     * @param s The seconds.
     */
    Time(Hour h, Minute m, Second s) : hours(h), minutes(m), seconds(s) {}

    /**
     * @brief Validate the time.
     * @return true if the time is valid, false otherwise.
     */
    bool isValid() const {
        try {
            hours.validate();
            minutes.validate();
            seconds.validate();
            return true;
        }
        catch (const std::invalid_argument&) {
            return false;
        }
    }
};
