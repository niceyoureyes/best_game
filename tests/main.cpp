#include <iostream>
#include <gtest/gtest.h>
#include "Point2D.h"
#include "Box2D.h"
#include "Ray2D.h"
#include "alien.h"
#include "global_configs.h"
#include "player.h"
#include "factory.h"

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
  e = d.Normalize();
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
  EXPECT_EQ(Point2D(-2,1) == a.PointMin(), true);
  EXPECT_EQ(Point2D(3,3) == a.PointMax(), true);
  Box2D b = Box2D (Point2D(0,4),Point2D(3,0));
  EXPECT_EQ(b.PointMin() == Point2D (0,0), true);
  EXPECT_EQ(b.PointMax() == Point2D (3,4), true);
  a = b;
  EXPECT_EQ(a.PointMin() == Point2D (0,0), true);
  EXPECT_EQ(a.PointMax() == Point2D (3,4), true);
  a = Box2D(Point2D(-2, 1),Point2D(3, 3));
  EXPECT_EQ(Point2D(-2,1) == a.PointMin() && Point2D(3,3) == a.PointMax(), true);
}

TEST(CheckCrossBoxes, test)
{
  Point2D  a(0, 5), b(10, 10), c(-10, -2), d(-3, -8);
  Box2D B1(a, b), B2(c, d);
  EXPECT_EQ(B1.IntersectBox(B2), 0);
  B1 = Box2D(Point2D(0, 0), Point2D(5, 6));
  B2 = Box2D(Point2D(2, 3), Point2D(8, 4));
  EXPECT_EQ(B1.IntersectBox(B2), 1);
  B1 = Box2D(Point2D(0, 4), Point2D(20, 10));
  B2 = Box2D(Point2D(5, 2), Point2D(10, 50));
  EXPECT_EQ(B1.IntersectBox(B2), 1);
}

TEST(CheckCrossRayBox, test)
{
  Point2D  a(0, 5), b(10, 10), c(-10, -2), d(-3, -8);
  Ray2D  r(Point2D(0, 0), Point2D(1, 1));
  Box2D B1(a, b), B2(c, d);
  EXPECT_EQ(r.IntersectBox(B1), 1);
  EXPECT_EQ(r.IntersectBox(B2), 0);

  B1 = Box2D(Point2D(0, 0), Point2D(3, 2));
  r = Ray2D(Point2D(0, -3), Point2D(0, 10));
  EXPECT_EQ(r.IntersectBox(B1), 1);

  r = Ray2D(Point2D(-2, 2), Point2D(10, 0));
  EXPECT_EQ(r.IntersectBox(B1), 1);
  r = Ray2D(Point2D(2, 1), Point2D(0, 0.5));
  EXPECT_EQ(r.IntersectBox(B1), 1);
  r = Ray2D(Point2D(3, 2), Point2D(1, 1));
  EXPECT_EQ(r.IntersectBox(B1), 1);
  r = Ray2D(Point2D(3, 1), Point2D(10, 0));
  EXPECT_EQ(r.IntersectBox(B1), 1);

  B1 = Box2D(Point2D(-1, -1), Point2D(-3, -3));
  r = Ray2D(Point2D(0, 0), Point2D(-0.1, -0.1));
  EXPECT_EQ(r.IntersectBox(B1), 1);
  r = Ray2D(Point2D(-2, -5), Point2D(0, 10));
  EXPECT_EQ(r.IntersectBox(B1), 1);

  B1 = Box2D(Point2D(-2, 0), Point2D(2, 2));
  r = Ray2D(Point2D(0, 3), Point2D(0, 10));
  EXPECT_EQ(r.IntersectBox(B1), 0);

  r = Ray2D(Point2D(-2, 3), Point2D(0, 10));
  EXPECT_EQ(r.IntersectBox(B1), 0);

  r = Ray2D(Point2D(1, -2), Point2D(1, 1));
  EXPECT_EQ(r.IntersectBox(B1), 0);

  r = Ray2D(Point2D(-1, -2), Point2D(3.0000000001, 2));
  EXPECT_EQ(r.IntersectBox(B1), 0);
}

TEST(exceptionTest, test)
{
  Point2D a(0,0);
  ASSERT_THROW(a.Normalize(), invalid_argument);
  Point2D b(4, 8);
  Point2D c(1, 1);
  ASSERT_THROW(c = b / 0, invalid_argument);
  ASSERT_THROW(c /= 0, invalid_argument);
}

TEST(hierarchy, test)
{
  InitConfig();
  Box2D box1(400, 400, 600, 600);
  Point2D dir1(0, 1);
  Point2D dir2(1, 2);
  Alien al(box1, dir1, 0);
  Point2D place(1000, 1200);

  EXPECT_EQ(al.Box().PointMin(), Point2D(400, 400));
  EXPECT_EQ(al.Box().PointMax(), Point2D(600, 600));
  EXPECT_EQ(al.Box(), box1);

  EXPECT_EQ(al.Direction(), dir1);
  EXPECT_EQ(al.TypeBeing(), 0);

  al.Move(place);

  EXPECT_EQ(al.Box().PointMin(), place);
  EXPECT_EQ(al.Box().PointMax(), place + Point2D(200, 200));
  EXPECT_EQ(al.Box(), Box2D(1000, 1200, 1200, 1400));

  al.SetSides(100);

  EXPECT_EQ(al.Box(), Box2D(1000, 1200, 1100, 1300));

  al.SetParameters(box1, dir2);

  EXPECT_EQ(al.Box(), box1);
  EXPECT_EQ(al.Direction(), dir2.Normalize());

  al.Direct(dir1 * 100);

  EXPECT_EQ(al.Direction(), dir1);


  Bullet bul1(box1, dir1, 0, 0);
  EXPECT_EQ(bul1.Box(), box1);
  EXPECT_EQ(bul1.Direction(), dir1);
  EXPECT_EQ(bul1.TypeBullet(), 0);
  EXPECT_EQ(bul1.Owner(), 0);

  Gun gun1(box1, dir1, 0);
  EXPECT_EQ(gun1.Box(), box1);
  EXPECT_EQ(gun1.Direction(), dir1);
  EXPECT_EQ(gun1.TypeGun(), 0);

  Player pl1(box1, dir2, 0);
  EXPECT_EQ(pl1.Box(), box1);
  EXPECT_EQ(pl1.Direction(), dir2.Normalize());
}

TEST(factory, test){
  InitConfig();
  auto gun = Factory::Create<Gun>(Box2D(100, 100, 200, 200), Point2D(0, 1), 0);
  EXPECT_EQ(gun->Box(), Box2D(100, 100, 200, 200));
  EXPECT_EQ(gun->Direction(), Point2D(0, 1));
  EXPECT_EQ(gun->TypeGun(), 0);
}

TEST(observer, test)
{
  InitConfig();
  auto al1 = Factory::Create<Alien>(Box2D(0, 0, 50, 50), Point2D(0, 1), 0);
  auto al2 = Factory::Create<Alien>(Box2D(100, 0, 50, 50), Point2D(0, 1), 0);
  Alien::TOnHit onHit([] (int const typeBullet)
  {
      Logger::Instance() << "Bullet hit the alien with " << bulletConfigs[typeBullet].damage << " damage\n";
  });
  al1->SetOnHit(onHit);
  al2->SetOnHit(onHit);
  al1->Hit(0);
  al2->Hit(1);
}

int main(int argc, char * argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
