#pragma once
#include "Point2D.h"

class Ray2D
{
public:
  Ray2D(Point2D const &origin, Point2D const &direction);
  Point2D &origin();
  Point2D const &origin() const;
  Point2D &direction();
  Point2D const &direction() const;
private:
  Point2D m_origin, m_direction;
};

std::ostream &operator << (std::ostream &os, Ray2D const &obj);
