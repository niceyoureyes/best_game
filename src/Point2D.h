#pragma once
#include <iostream>
class Point2D
{
public:
  #define EPS 0.000001
  Point2D() = default;
  Point2D(Point2D const & obj);
  Point2D(Point2D && obj);
  Point2D(double x, double y);
  // TODO: constructor initializer list
  double & x();
  double & y();
  double const & x() const;
  double const & y() const;
  Point2D operator + (Point2D const & obj) const;
  Point2D operator - (Point2D const & obj) const;
  Point2D operator += (Point2D const & obj);
  Point2D operator -= (Point2D const & obj);
  Point2D operator * (double const & val) const;
  Point2D operator / (double const & val) const;
  Point2D operator *= (double const & val);
  Point2D operator /= (double const & val);
  Point2D operator = (Point2D const & obj);
  Point2D & operator = (Point2D && obj);
  bool operator == (Point2D const & obj) const;
  bool operator != (Point2D const & obj) const;

  Point2D Normalize() const; // returns normalized vector
  double Length() const;
  Point2D Vector(Point2D const & point) const;

  static double DotProduct(Point2D const & p1, Point2D const & p2);
  static double CrossProduct(Point2D const & p1, Point2D const & p2);
  static bool PointOnSegment(Point2D const & p, Point2D const & a, Point2D const & b);
  static bool SegmentsIntersection(Point2D const & p1, Point2D const & p2, Point2D const & p3, Point2D const & p4);
private:
  double m_x = 0, m_y = 0;
};
std::ostream & operator << (std::ostream & os, Point2D const & obj);
