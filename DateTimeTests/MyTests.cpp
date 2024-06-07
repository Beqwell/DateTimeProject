#include "pch.h"
#include "Date.h"
#include "Time.h"
#include "DateTime.h"
#include <gtest/gtest.h>

TEST(TimeUnitTest, HourValidation) {
    Hour h1(15);
    EXPECT_NO_THROW(h1.validate());

    Hour h2(25);
    EXPECT_THROW(h2.validate(), std::invalid_argument);
}

TEST(MinuteTest, MinuteValidation) {
    Minute m1(30);
    EXPECT_NO_THROW(m1.validate());

    Minute m2(61);
    EXPECT_THROW(m2.validate(), std::invalid_argument);
}

TEST(SecondTest, SecondValidation) {
    Second s1(45);
    EXPECT_NO_THROW(s1.validate());

    Second s2(61);
    EXPECT_THROW(s2.validate(), std::invalid_argument);
}

TEST(DateTest, DateValidation) {
    Date d1(2024, 2, 29);
    EXPECT_TRUE(d1.isValid());

    Date d2(2024, 4, 31);
    EXPECT_FALSE(d2.isValid());
}

TEST(TimeTest, TimeValidation) {
    Time t1(Hour(12), Minute(30), Second(45));
    EXPECT_TRUE(t1.isValid());

    Time t2(Hour(12), Minute(61), Second(45));
    EXPECT_FALSE(t2.isValid());
}

TEST(DateTimeTest, DateTimeValidation) {
    DateTime dt1(Date(2024, 2, 29), Time(Hour(12), Minute(30), Second(45)));
    EXPECT_TRUE(dt1.isValid());

    DateTime dt2(Date(2024, 2, 30), Time(Hour(12), Minute(30), Second(45)));
    EXPECT_FALSE(dt2.isValid());
}
