#pragma once
#include <vector>
#include <algorithm>
#include "DateTime.h"

/**
 * @brief Class for operations on a list of DateTime objects.
 */
class ListOperations {
public:
    std::vector<DateTime> dateTimeList;

    /**
     * @brief Add a DateTime object to the list.
     * @param dt The DateTime object to add.
     */
    void addDateTime(const DateTime& dt) {
        dateTimeList.push_back(dt);
    }

    /**
     * @brief Sort the list by date.
     */
    void sortByDate() {
        std::sort(dateTimeList.begin(), dateTimeList.end(), [](const DateTime& a, const DateTime& b) {
            if (a.date.year != b.date.year) {
                return a.date.year < b.date.year;
            }
            if (a.date.month != b.date.month) {
                return a.date.month < b.date.month;
            }
            return a.date.day < b.date.day;
            });
    }

    /**
     * @brief Sort the list by time.
     */
    void sortByTime() {
        std::sort(dateTimeList.begin(), dateTimeList.end(), [](const DateTime& a, const DateTime& b) {
            if (a.time.hours.value != b.time.hours.value) {
                return a.time.hours.value < b.time.hours.value;
            }
            if (a.time.minutes.value != b.time.minutes.value) {
                return a.time.minutes.value < b.time.minutes.value;
            }
            return a.time.seconds.value < b.time.seconds.value;
            });
    }
};
