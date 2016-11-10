#include "Point2D.h"
#include <cmath>

Point2D::Point2D(const Point2D & obj) : m_x(obj.m_x), m_y(obj.m_y) {}

Point2D::Point2D(Point2D && obj)
{
  std::swap(obj.m_x, m_x);
  std::swap(obj.m_y, m_y);
}

Point2D::Point2D(double _x, double _y) : m_x(_x), m_y(_y) {}

double & Point2D::x() { return m_x; }

double & Point2D::y() { return m_y; }

double const & Point2D::x() const { return m_x; }

double const & Point2D::y() const { return m_y; }

Point2D Point2D::operator + (const Point2D & obj) const
{
  return Point2D(m_x + obj.x(), m_y + obj.y());
}

Point2D Point2D::operator - (const Point2D & obj) const
{
  return Point2D(m_x - obj.x(), m_y - obj.y());
}

Point2D Point2D::operator += (const Point2D & obj)
{
  m_x += obj.x();
  m_y += obj.y();
  return *this;
}

Point2D Point2D::operator -= (const Point2D & obj)
{
  m_x -= obj.x();
  m_y -= obj.y();
  return *this;
}

Point2D Point2D::operator * (const double & val) const
{
  return Point2D(m_x * val, m_y * val);
}

Point2D Point2D::operator / (const double  & val) const
{
  if(val == 0)
    throw new std::invalid_argument("Error! Divizion by zero!");
  return Point2D(m_x / val, m_y / val);
}

Point2D Point2D::operator *= (const double  & val)
{
  m_x *= val;
  m_y *= val;
  return *this;
}

Point2D Point2D::operator /= (const double  & val)
{
  if(val == 0)
    throw new std::invalid_argument("Error! Divizion by zero!");
  m_x /= val;
  m_y /= val;
  return *this;
}

Point2D Point2D::operator = (const Point2D & obj)
{
  if (&obj == this)
    return * this;
  m_x = obj.x();
  m_y = obj.y();
  return *this;
}

Point2D & Point2D::operator = (Point2D && obj)
{
  std::swap(m_x, obj.m_x);
  std::swap(m_y, obj.m_y);
  return *this;
}

bool Point2D::operator == (const Point2D & obj) const
{
  return (abs(m_x - obj.x()) < EPS) && (abs(m_y - obj.y()) < EPS);
}

bool Point2D::operator != (const Point2D & obj) const
{
  return !(*this == obj);
}

Point2D Point2D::Normalize() const
{
  if(this->Length() == 0)
    throw new std::invalid_argument("Error! Vector length is zero!");
  return *this / this->Length();
}

double Point2D::Length() const
{
  return sqrt(x() * x() + y() * y());
}

Point2D Point2D::Vector(Point2D const & point) const
{
  return point - *this;
}

std::ostream & operator << (std::ostream & os, const Point2D & obj)
{
  os << "Point2D{" << obj.x() << ", " << obj.y() << "}" << std::endl;
  return os;
}

double Point2D::DotProduct(Point2D const & p1, Point2D const & p2)
{
  return p1.x() * p2.x() + p1.y() * p2.y();
}

double Point2D::CrossProduct(Point2D const & p1, Point2D const & p2)
{
  return p1.x() * p2.y() - p1.y() * p2.x();
}

bool Point2D::PointOnSegment(Point2D const & p, Point2D const & a, Point2D const & b)
{
  return abs(CrossProduct(p.Vector(a), p.Vector(b))) < EPS  &&
      DotProduct(p.Vector(a), p.Vector(b)) <= 0;
}

bool Point2D::SegmentsIntersection(Point2D const & p1, Point2D const & p2, Point2D const & p3, Point2D const & p4)
{
  return PointOnSegment(p1, p3, p4) || PointOnSegment(p2, p3, p4) ||
      PointOnSegment(p3, p1, p2) || PointOnSegment(p4, p1, p2) ||
      CrossProduct(p1.Vector(p2), p1.Vector(p3)) *
      CrossProduct(p1.Vector(p2), p1.Vector(p4)) < 0 &&
      CrossProduct(p3.Vector(p4), p3.Vector(p1)) *
      CrossProduct(p3.Vector(p4), p3.Vector(p2)) < 0;
}
