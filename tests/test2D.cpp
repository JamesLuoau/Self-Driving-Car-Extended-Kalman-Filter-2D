#include "gtest/gtest.h"
#include "../src/EntryPoint.h"

TEST(KalmanFilter, twoDimentionalTest) {
  int resutl1 = entryPoint2D();
  EXPECT_EQ(resutl1, 1);
};

