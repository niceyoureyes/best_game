#pragma once
#include <iostream>
#define EPS 0.000001
class Point2D
{
public:
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

  Point2D Norm() const; // returns normalized vector
  double Length() const;
private:
  double m_x = 0, m_y = 0;
};
std::ostream & operator << (std::ostream & os, Point2D const & obj);