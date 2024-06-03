#pragma once
#include "TimeUnit.h"

/**
 * @brief Factory class for creating time objects.
 */
class TimeFactory {
public:
    /**
     * @brief Create an Hour object.
     * @param value The hour value.
     * @return Hour object.
     */
    static Hour createHour(int value) {
        return Hour(value);
    }

    /**
     * @brief Create a Minute object.
     * @param value The minute value.
     * @return Minute object.
     */
    static Minute createMinute(int value) {
        return Minute(value);
    }

    /**
     * @brief Create a Second object.
     * @param value The second value.
     * @return Second object.
     */
    static Second createSecond(int value) {
        return Second(value);
    }
};
