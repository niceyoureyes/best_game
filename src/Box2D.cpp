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

Box2D::Box2D(double const p1x, double const p1y, double const p2x, double const p2y)
{
  m_pointMin.x() = std::min(p1x, p2x);
  m_pointMin.y() = std::min(p1y, p2y);
  m_pointMax.x() = std::max(p1x, p2x);
  m_pointMax.y() = std::max(p1y, p2y);
}

Box2D & Box2D::operator = (Box2D && obj)
{
  std::swap(m_pointMin, obj.m_pointMin);
  std::swap(m_pointMax, obj.m_pointMax);
  return *this;
}

Box2D Box2D::operator = (Box2D const & obj)
{
  if (&obj == this)
    return *this;
  m_pointMin = obj.PointMin();
  m_pointMax = obj.PointMax();
  return *this;
}

bool Box2D::operator ==(Box2D const & obj) const
{
  return obj.PointMin() == m_pointMin && obj.PointMax() == m_pointMax;
}

Point2D const & Box2D::PointMin() const { return m_pointMin; }

Point2D const & Box2D::PointMax() const { return m_pointMax; }

bool Box2D::IntersectBox(Box2D const & box)
{
  if (this->PointMax().x() < box.PointMin().x()) return false;
  if (this->PointMax().y() < box.PointMin().y()) return false;
  if (box.PointMax().x() < this->PointMin().x()) return false;
  if (box.PointMax().y() < this->PointMin().y()) return false;
  return true;
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

void Box2D::Move(Point2D const & point)
{
  Point2D dp = m_pointMax - m_pointMin;
  m_pointMin = point;
  m_pointMax = point + dp;
}

void Box2D::SetWidth(double const value)
{
  m_pointMax.x() = this->PointMin().x() + value;
}

void Box2D::SetHeight(double const value)
{
  m_pointMax.y() = this->PointMin().y() + value;
}

void Box2D::SetSides(double const value)
{
  SetWidth(value);
  SetHeight(value);
}

double Box2D::Width() const
{
  return m_pointMax.x() - m_pointMin.x();
}

double Box2D::Heigth() const
{
  return m_pointMax.y() - m_pointMin.y();
}

std::ostream & operator << (std::ostream & os, const Box2D & box)
{
  os << box.PointMin() << " " << box.PointMax();
  return os;
}
