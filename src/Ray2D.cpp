#include "Ray2D.h"
#include <iostream>

Ray2D::Ray2D(Point2D const & origin, Point2D const & direction) : m_origin(origin), m_direction(direction)
{
  m_direction = m_direction.Normalize();
}

Ray2D::Ray2D(Ray2D const & obj) : m_origin(obj.m_origin), m_direction(obj.m_direction)
{
  m_direction = m_direction.Normalize();
}

Ray2D::Ray2D(Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
  m_direction = m_direction.Normalize();
}

Ray2D & Ray2D::operator = (Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
  m_direction = m_direction.Normalize();
  return *this;
}

Ray2D Ray2D::operator = (Ray2D const & obj)
{
  if (&obj == this)
    return *this;
  m_origin = obj.Origin();
  m_direction = obj.Direction().Normalize();
  return *this;
}

Point2D const & Ray2D::Origin() const { return m_origin; }

Point2D const & Ray2D::Direction() const { return m_direction; }

bool Ray2D::IntersectBox(Box2D const & box) const
{
  //TODO: change 100000 to smth else
  auto p1 = this->Origin(), p2 = (this->Origin() + this->Direction() * 100000);
  return Point2D::SegmentsIntersection(p1, p2, box.PointMin(), Point2D(box.PointMin().x(), box.PointMax().y())) ||
      Point2D::SegmentsIntersection(p1, p2, box.PointMin(), Point2D(box.PointMax().x(), box.PointMin().y())) ||
      Point2D::SegmentsIntersection(p1, p2, box.PointMax(), Point2D(box.PointMin().x(), box.PointMax().y())) ||
      Point2D::SegmentsIntersection(p1, p2, box.PointMax(), Point2D(box.PointMax().x(), box.PointMin().y()));
}

void Ray2D::DirectVector(Point2D const & p1, Point2D const & p2)
{
  m_origin = p1;
  m_direction = (p2 - p1).Normalize();
}

void Ray2D::Direct(Point2D const & origin, Point2D const & direction)
{
  m_origin = origin;
  m_direction = direction.Normalize();
}

std::ostream & operator << (std::ostream & os, const Ray2D & obj)
{
  os << obj.Origin() << " " << obj.Direction();
  return os;
}
