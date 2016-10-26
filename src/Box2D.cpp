#include "Box2D.h"
#include <algorithm>

Box2D::Box2D(Point2D const & p1, Point2D const & p2)
{
  m_pointMin.x() = std::min(p1.x(), p2.x());
  m_pointMin.y() = std::min(p1.y(), p2.y());
  m_pointMax.x() = std::max(p1.x(), p2.x());
  m_pointMax.y() = std::max(p1.y(), p2.y());
}

Box2D::Box2D(Box2D const & obj)
{
  m_pointMin = obj.PointMin();
  m_pointMax = obj.PointMax();
}

Box2D::Box2D(Box2D && obj)
{
  std::swap(m_pointMin, obj.m_pointMin);
  std::swap(m_pointMax, obj.m_pointMax);
}

Box2D & Box2D::operator = (Box2D && obj)
{
  std::swap(m_pointMin, obj.m_pointMin);
  std::swap(m_pointMax, obj.m_pointMax);
  return *this;
}

Box2D Box2D::operator = (const Box2D & obj)
{
  if (&obj == this)
    return *this;
  m_pointMin = obj.PointMin();
  m_pointMax = obj.PointMax();
  return *this;
}

Point2D const & Box2D::PointMin() const { return m_pointMin; }

Point2D const & Box2D::PointMax() const { return m_pointMax; }

bool Box2D::IntersectBox(Box2D const & box)
{
  if (this->PointMax().x() < box.PointMin().x()) return 0;
  if (this->PointMax().y() < box.PointMin().y()) return 0;
  if (box.PointMax().x() < this->PointMin().x()) return 0;
  if (box.PointMax().y() < this->PointMin().y()) return 0;
  return 1;
}

double Box2D::DiagonalLength()
{
  return sqrt((this->PointMax().x() - this->PointMin().x()) * (this->PointMax().x() - this->PointMin().x()) +
              (this->PointMax().y() - this->PointMin().y()) * (this->PointMax().y() - this->PointMin().y()));
}

bool Box2D::PointInside(Point2D const & point)
{
  return this->PointMin().x() <= point.x() && point.x() <= this->PointMax().x() &&
      this->PointMin().y() <= point.y() && point.y() <= this->PointMax().y();
}

std::ostream & operator << (std::ostream & os, const Box2D & box)
{
  os << box.PointMin() << " " << box.PointMax();
  return os;
}
