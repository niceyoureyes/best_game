#pragma once
#include <iostream>
#include "Point2D.h"

class Box2D
{
public:
  Box2D() = default;
  Box2D(Point2D const & p1, Point2D const & p2);
  Box2D(double const p1x, double const p1y, double const p2x, double const p2y);
  Box2D(Box2D const & obj);
  Box2D(Box2D && obj);
  Box2D & operator = (Box2D && obj);
  Box2D operator = (Box2D const & obj);

  bool operator == (Box2D const & obj) const;
  Point2D const & PointMin() const;
  Point2D const & PointMax() const;
  bool IntersectBox(Box2D const & box);
  double DiagonalLength();
  bool PointInside(Point2D const & point);
  void Move(Point2D const & point);
  void SetWidth(double const value);
  void SetHeight(double const value);
  void SetSides(double const value);

  double Width() const;
  double Heigth() const;
private:
  Point2D m_pointMin, m_pointMax;
};
std::ostream & operator << (std::ostream & os, Box2D const & box);
