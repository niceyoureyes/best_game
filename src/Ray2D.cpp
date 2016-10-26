#include "Ray2D.h"
#include "Geom_func.h"
#include <iostream>

Ray2D::Ray2D(Point2D const & origin, Point2D const & direction) : m_origin(origin), m_direction(direction)
{
  m_direction = m_direction.Norm();
}

Ray2D::Ray2D(Ray2D const & obj) : m_origin(obj.m_origin), m_direction(obj.m_direction) {}

Ray2D::Ray2D(Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
}

Ray2D & Ray2D::operator = (Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
  return *this;
}

Ray2D Ray2D::operator = (const Ray2D & obj)
{
  if (&obj == this)
    return *this;
  m_origin = obj.origin();
  m_direction = obj.direction();
  return *this;
}

Point2D & Ray2D::origin() { return m_origin; }

Point2D const & Ray2D::origin() const { return m_origin; }

Point2D & Ray2D::direction() { return m_direction; }

Point2D const & Ray2D::direction() const { return m_direction; }

bool Ray2D::IntersectBox(Box2D const & box)
{
  //TODO: change 100000 to smth else
  auto p1 = this->origin(), p2 = (this->origin() + this->direction() * 100000);
  return CrossSegments(p1, p2, box.PointMin(), Point2D(box.PointMin().x(), box.PointMax().y())) ||
      CrossSegments(p1, p2, box.PointMin(), Point2D(box.PointMax().x(), box.PointMin().y())) ||
      CrossSegments(p1, p2, box.PointMax(), Point2D(box.PointMin().x(), box.PointMax().y())) ||
      CrossSegments(p1, p2, box.PointMax(), Point2D(box.PointMax().x(), box.PointMin().y()));
}

std::ostream & operator << (std::ostream & os, const Ray2D & obj)
{
  os << obj.origin() << " " << obj.direction();
  return os;
}
