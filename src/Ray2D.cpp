#include "Ray2D.h"
#include <iostream>

Ray2D::Ray2D(Point2D const &origin, Point2D const &direction) :m_origin(origin), m_direction(direction)
{
  m_direction = m_direction.Norm();
}

Point2D &Ray2D::origin() { return m_origin; }

Point2D const &Ray2D::origin() const { return m_origin; }

Point2D &Ray2D::direction() { return m_direction; }

Point2D const &Ray2D::direction() const { return m_direction; }

std::ostream &operator <<(std::ostream &os, const Ray2D &obj)
{
  os << obj.origin() << " " << obj.direction();
  return os;
}
