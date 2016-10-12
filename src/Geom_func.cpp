#include "Geom_func.h"
#include <cmath>

double &min(double &a, double &b)
{
  return (a < b ? a : b);
}

double &max(double &a, double &b)
{
  return (a > b ? a : b);
}

bool PointInBox(Point2D const &p, Box2D const &b)
{
  return b.point1().x() <= p.x() && p.x() <= b.point2().x() &&
      b.point1().y() <= p.y() && p.y() <= b.point2().y();
}

bool CrossBoxes(Box2D const &b1, Box2D const &b2)
{
  return (b1.point1().x() <= b2.point1().x() && b2.point1().x() <= b1.point2().x() ||
          b1.point1().x() <= b2.point2().x() && b2.point2().x() <= b1.point2().x() ||
          b2.point1().x() <= b1.point1().x() && b1.point1().x() <= b2.point2().x() ||
          b2.point1().x() <= b1.point2().x() && b1.point2().x() <= b2.point2().x()) &&
      (b1.point1().y() <= b2.point1().y() && b2.point1().y() <= b1.point2().y() ||
       b1.point1().y() <= b2.point2().y() && b2.point2().y() <= b1.point2().y() ||
       b2.point1().y() <= b1.point1().y() && b1.point1().y() <= b2.point2().y() ||
       b2.point1().y() <= b1.point2().y() && b1.point2().y() <= b2.point2().y());
}

double Length(Point2D const &p)
{
  return sqrt(p.x() * p.x() + p.y() * p.y());
}

double Length(Point2D const &p1, Point2D const &p2)
{
  return sqrt((p2.x() - p1.x()) * (p2.x() - p1.x()) + (p2.y() - p1.y()) * (p2.y() - p1.y()));
}

Point2D Vector(Point2D const &p1, Point2D const &p2)
{
  return p2 - p1;
}

double DotProduct(Point2D const &p1, Point2D const &p2)
{
  return p1.x() * p2.x() + p1.y() * p2.y();
}

double CrossProduct(Point2D const &p1, Point2D const &p2)
{
  return p1.x() * p2.y() - p1.y() * p2.x();
}

bool PointInSegment(Point2D const &p, Point2D const &a, Point2D const &b)
{
  return abs(CrossProduct(Vector(p, a), Vector(p, b))) < EPSI  &&
      DotProduct(Vector(p, a), Vector(p, b)) <= 0;
}

bool CrossSegments(Point2D const &p1, Point2D const &p2, Point2D const &p3, Point2D const &p4)
{
  return PointInSegment(p1, p3, p4) || PointInSegment(p2, p3, p4) ||
      PointInSegment(p3, p1, p2) || PointInSegment(p4, p1, p2) ||
      CrossProduct(Vector(p1, p2), Vector(p1, p3)) *
      CrossProduct(Vector(p1, p2), Vector(p1, p4)) < 0 &&
      CrossProduct(Vector(p3, p4), Vector(p3, p1)) *
      CrossProduct(Vector(p3, p4), Vector(p3, p2)) < 0;
}

bool CrossRayBox(Ray2D const &r, Box2D const &b)
{
  //TODO: change 100000 to smth else
  auto p1 = r.origin(), p2 = (r.origin() + r.direction() * 100000);
  return CrossSegments(p1, p2, b.point1(), Point2D(b.point1().x(), b.point2().y())) ||
      CrossSegments(p1, p2, b.point1(), Point2D(b.point2().x(), b.point1().y())) ||
      CrossSegments(p1, p2, b.point2(), Point2D(b.point1().x(), b.point2().y())) ||
      CrossSegments(p1, p2, b.point2(), Point2D(b.point2().x(), b.point1().y()));
}
