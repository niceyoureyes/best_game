#include <iostream>
#include <gtest/gtest.h>
#include "Geom_func.h"
#include "Point2D.h"
#include "Box2D.h"
#include "Ray2D.h"

using namespace std;

TEST(TestPoints, test)
{
  Point2D a;
  EXPECT_EQ(a.x(), 0);
  EXPECT_EQ(a.y(), 0);
  Point2D b(1,2);
  EXPECT_EQ(b.x(), 1);
  EXPECT_EQ(b.y(), 2);
  a = b;
  EXPECT_EQ(a.x(), 1);
  EXPECT_EQ(a.y(), 2);
  Point2D c = Point2D (-5, 5);
  EXPECT_EQ(c.x(), -5);
  EXPECT_EQ(c.y(), 5);
  a = b + c;
  EXPECT_EQ(a.x(), -4);
  EXPECT_EQ(a.y(), 7);
  a = b - c;
  EXPECT_EQ(a.x(), 6);
  EXPECT_EQ(a.y(), -3);
  a *= 2;
  EXPECT_EQ(a.x(), 12);
  EXPECT_EQ(a.y(), -6);
  a = c * 2;
  EXPECT_EQ(a.x(), -10);
  EXPECT_EQ(a.y(), 10);
  a /= 4;
  EXPECT_EQ(a.x(), -2.5);
  EXPECT_EQ(a.y(), 2.5);

  Point2D d(6.9999999999, 0);
  Point2D e(7.0000000001, 0);
  EXPECT_EQ(e == d, true);

  a = b = c = Point2D (1, 2);
  a += b += c;
  EXPECT_EQ(c.x(), 1);
  EXPECT_EQ(c.y(), 2);
  EXPECT_EQ(b.x(), 2);
  EXPECT_EQ(b.y(), 4);
  EXPECT_EQ(a.x(), 3);
  EXPECT_EQ(a.y(), 6);

  a -= b -= c;
  EXPECT_EQ(b == c, true);
  EXPECT_EQ(a.x() , 2);
  EXPECT_EQ(a.y() , 4);
  EXPECT_EQ(a != c, true);
  a = a / 2;
  EXPECT_EQ(a != c, false);

  d = e = Point2D  (3, 4);
  EXPECT_EQ(d.Length(), 5);
  e = d.Norm();
  EXPECT_EQ(d.Length(), 5);
  EXPECT_EQ(e.x(), 3.0 / 5);
  EXPECT_EQ(e.y(), 4.0 / 5);
  EXPECT_EQ(e.Length(), 1);

  a = b;
  EXPECT_EQ(a == b, true);
  a = b * 2;
  EXPECT_EQ(a == b * 2, true);
}

TEST(TestBoxes, test)
{
  Box2D a(Point2D(-2, 1),Point2D(3, 3));
  EXPECT_EQ(Point2D(-2,1) == a.point1(), true);
  EXPECT_EQ(Point2D(3,3) == a.point2(), true);
  Box2D b = Box2D (Point2D(0,4),Point2D(3,0));
  EXPECT_EQ(b.point1() == Point2D (0,0), true);
  EXPECT_EQ(b.point2() == Point2D (3,4), true);
  a = b;
  EXPECT_EQ(a.point1() == Point2D (0,0), true);
  EXPECT_EQ(a.point2() == Point2D (3,4), true);
  a = Box2D(Point2D(-2, 1),Point2D(3, 3));
  EXPECT_EQ(Point2D(-2,1) == a.point1() && Point2D(3,3) == a.point2(), true);
}

TEST(CheckCrossBoxes, test)
{
  Point2D  a(0, 5), b(10, 10), c(-10, -2), d(-3, -8);
  Box2D B1(a, b), B2(c, d);
  EXPECT_EQ(CrossBoxes(B1, B2), 0);
  B1 = Box2D(Point2D(0, 0), Point2D(5, 6));
  B2 = Box2D(Point2D(2, 3), Point2D(8, 4));
  EXPECT_EQ(CrossBoxes(B1, B2), 1);
  B1 = Box2D(Point2D(0, 4), Point2D(20, 10));
  B2 = Box2D(Point2D(5, 2), Point2D(10, 50));
  EXPECT_EQ(CrossBoxes(B1, B2), 1);
}

TEST(CheckCrossRayBox, test)
{
  Point2D  a(0, 5), b(10, 10), c(-10, -2), d(-3, -8);
  Ray2D  r(Point2D(0, 0), Point2D(1, 1));
  Box2D B1(a, b), B2(c, d);
  EXPECT_EQ(CrossRayBox(r, B1), 1);
  EXPECT_EQ(CrossRayBox(r, B2), 0);

  B1 = Box2D(Point2D(0, 0), Point2D(3, 2));
  r = Ray2D(Point2D(0, -3), Point2D(0, 10));
  EXPECT_EQ(CrossRayBox(r, B1), 1);

  r = Ray2D(Point2D(-2, 2), Point2D(10, 0));
  EXPECT_EQ(CrossRayBox(r, B1), 1);
  r = Ray2D(Point2D(2, 1), Point2D(0, 0.5));
  EXPECT_EQ(CrossRayBox(r, B1), 1);
  r = Ray2D(Point2D(3, 2), Point2D(1, 1));
  EXPECT_EQ(CrossRayBox(r, B1), 1);
  r = Ray2D(Point2D(3, 1), Point2D(10, 0));
  EXPECT_EQ(CrossRayBox(r, B1), 1);

  B1 = Box2D(Point2D(-1, -1), Point2D(-3, -3));
  r = Ray2D(Point2D(0, 0), Point2D(-0.1, -0.1));
  EXPECT_EQ(CrossRayBox(r, B1), 1);
  r = Ray2D(Point2D(-2, -5), Point2D(0, 10));
  EXPECT_EQ(CrossRayBox(r, B1), 1);

  B1 = Box2D(Point2D(-2, 0), Point2D(2, 2));
  r = Ray2D(Point2D(0, 3), Point2D(0, 10));
  EXPECT_EQ(CrossRayBox(r, B1), 0);

  r = Ray2D(Point2D(-2, 3), Point2D(0, 10));
  EXPECT_EQ(CrossRayBox(r, B1), 0);

  r = Ray2D(Point2D(1, -2), Point2D(1, 1));
  EXPECT_EQ(CrossRayBox(r, B1), 0);

  r = Ray2D(Point2D(-1, -2), Point2D(3.0000000001, 2));
  EXPECT_EQ(CrossRayBox(r, B1), 1);
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
