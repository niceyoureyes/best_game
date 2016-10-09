#include <iostream>
#include <gtest/gtest.h>
#include "geometry.h"

using namespace std;

TEST(test, test)
{
    Point2D <double> a(0, 5), b(10, 10), c(-10, -2), d(-3, -8);
    Ray2D <double> r(Point2D<double>(0, 0), Point2D<double>(1, 1));
    Box2D<double> B1(a, b), B2(c, d);

    EXPECT_EQ(CrossRayBox(r, B1), 1);
    EXPECT_EQ(CrossRayBox(r, B2), 0);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
