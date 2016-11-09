#pragma once
#include "Point2D.h"
#include "Box2D.h"

class Ray2D
{
public:
  Ray2D() = default;
  Ray2D(Point2D const & origin, Point2D const & direction);
  Ray2D(Ray2D const & obj);
  Ray2D(Ray2D && obj);
  Ray2D & operator = (Ray2D && obj);
  Ray2D operator = (Ray2D const & obj);

  Point2D const & Origin() const;
  Point2D const & Direction() const;
  bool IntersectBox(Box2D const & box) const;
  void DirectVector(Point2D const & p1, Point2D const & p2);
  void Direct(Point2D const & origin, Point2D const & direction);
private:
  Point2D m_origin, m_direction;
};

std::ostream & operator << (std::ostream & os, Ray2D const & obj);
