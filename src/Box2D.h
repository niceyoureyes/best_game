#pragma once
#include <iostream>
#include "Point2D.h"

class Box2D
{
public:
  Box2D(Point2D const & p1, Point2D const & p2);
  Box2D(Box2D const & obj);
  Box2D(Box2D && obj);
  Box2D & operator = (Box2D && obj);
  Box2D operator = (Box2D const & obj);
  Point2D const & PointMin() const;
  Point2D const & PointMax() const;
  bool IntersectBox(Box2D const & box);
  double DiagonalLength();
  bool PointInside(Point2D const & point);
private:
  Point2D m_pointMin, m_pointMax;
};
std::ostream & operator << (std::ostream & os, Box2D const & box);
