#include "gtest/gtest.h"
#include "../src/test.h"
#include "../src/kalman_filter_1d.h"

TEST(TestTest, FirstTest) {
    EXPECT_EQ(true, test());
};

TEST(KalmanFilter, oneDimentionalTest) {
  kalman_1d();
};

