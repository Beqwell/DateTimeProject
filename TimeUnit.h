#pragma once
#include <stdexcept>

/**
 * @brief Base class representing a time unit.
 */
class TimeUnit {
public:
    int value;

    /**
     * @brief Constructor to initialize the time unit value.
     * @param v The value of the time unit.
     */
    TimeUnit(int v) : value(v) {}

    /**
     * @brief Validate the time unit value.
     * @throws std::invalid_argument if the value is invalid.
     */
    virtual void validate() const {
        if (value < 0) throw std::invalid_argument("Invalid value");
    }
};

/**
 * @brief Class representing an hour.
 */
class Hour : public TimeUnit {
public:
    /**
     * @brief Constructor to initialize the hour value.
     * @param h The value of the hour.
     */
    Hour(int h) : TimeUnit(h) {}

    /**
     * @brief Validate the hour value.
     * @throws std::invalid_argument if the value is invalid.
     */
    void validate() const override {
        if (value < 0 || value >= 24) throw std::invalid_argument("Invalid hour");
    }
};

/**
 * @brief Class representing a minute.
 */
class Minute : public TimeUnit {
public:
    /**
     * @brief Constructor to initialize the minute value.
     * @param m The value of the minute.
     */
    Minute(int m) : TimeUnit(m) {}

    /**
     * @brief Validate the minute value.
     * @throws std::invalid_argument if the value is invalid.
     */
    void validate() const override {
        if (value < 0 || value >= 60) throw std::invalid_argument("Invalid minute");
    }
};

/**
 * @brief Class representing a second.
 */
class Second : public TimeUnit {
public:
    /**
     * @brief Constructor to initialize the second value.
     * @param s The value of the second.
     */
    Second(int s) : TimeUnit(s) {}

    /**
     * @brief Validate the second value.
     * @throws std::invalid_argument if the value is invalid.
     */
    void validate() const override {
        if (value < 0 || value >= 60) throw std::invalid_argument("Invalid second");
    }
};
