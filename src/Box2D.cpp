#include "Box2D.h"
#include <algorithm>

Box2D::Box2D(Point2D const &p1, Point2D const &p2)
{
  m_point1.x() = std::min(p1.x(), p2.x());
  m_point1.y() = std::min(p1.y(), p2.y());
  m_point2.x() = std::max(p1.x(), p2.x());
  m_point2.y() = std::max(p1.y(), p2.y());
}

Box2D::Box2D(Box2D const &obj) {
  m_point1 = obj.point1();
  m_point2 = obj.point2();
}

Box2D::Box2D(Box2D && obj)
{
  std::swap(m_point1, obj.m_point1);
  std::swap(m_point2, obj.m_point2);
}

Box2D & Box2D::operator=(Box2D && obj)
{
  std::swap(m_point1, obj.m_point1);
  std::swap(m_point2, obj.m_point2);
  return *this;
}

Box2D Box2D::operator =(const Box2D &obj)
{
//  std::cout << "operator = " << std::endl;
  if (&obj == this)
    return *this;
  m_point1 = obj.point1();
  m_point2 = obj.point2();
  return *this;
}

Point2D & Box2D::point1() { return m_point1; }

Point2D const & Box2D::point1() const { return m_point1; }

Point2D & Box2D::point2() { return m_point2; }

Point2D const & Box2D::point2() const { return m_point2; }

std::ostream &operator <<(std::ostream &os, const Box2D &box)
{
  os << box.point1() << " " << box.point2();
  return os;
}
