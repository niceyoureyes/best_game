#include "Ray2D.h"
#include <iostream>

Ray2D::Ray2D(Point2D const &origin, Point2D const &direction) :m_origin(origin), m_direction(direction)
{
  m_direction = m_direction.Norm();
}

Ray2D::Ray2D(Ray2D const & obj) : m_origin(obj.m_origin), m_direction(obj.m_direction)
{
}

Ray2D::Ray2D(Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
}

Ray2D & Ray2D::operator=(Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
  return *this;
}

Ray2D Ray2D::operator =(const Ray2D &obj)
{
//  std::cout << "operator = " << std::endl;
  if (&obj == this)
    return *this;
  m_origin = obj.origin();
  m_direction = obj.direction();
  return *this;
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
