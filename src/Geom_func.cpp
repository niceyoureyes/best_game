#include "Geom_func.h"
#include <cmath>

Point2D Vector(Point2D const & p1, Point2D const & p2)
{
  return p2 - p1;
}

double DotProduct(Point2D const & p1, Point2D const & p2)
{
  return p1.x() * p2.x() + p1.y() * p2.y();
}

double CrossProduct(Point2D const & p1, Point2D const & p2)
{
  return p1.x() * p2.y() - p1.y() * p2.x();
}

bool PointOnSegment(Point2D const & p, Point2D const & a, Point2D const & b)
{
  return abs(CrossProduct(Vector(p, a), Vector(p, b))) < EPS  &&
      DotProduct(Vector(p, a), Vector(p, b)) <= 0;
}

bool CrossSegments(Point2D const & p1, Point2D const & p2, Point2D const & p3, Point2D const & p4)
{
  return PointOnSegment(p1, p3, p4) || PointOnSegment(p2, p3, p4) ||
      PointOnSegment(p3, p1, p2) || PointOnSegment(p4, p1, p2) ||
      CrossProduct(Vector(p1, p2), Vector(p1, p3)) *
      CrossProduct(Vector(p1, p2), Vector(p1, p4)) < 0 &&
      CrossProduct(Vector(p3, p4), Vector(p3, p1)) *
      CrossProduct(Vector(p3, p4), Vector(p3, p2)) < 0;
}
