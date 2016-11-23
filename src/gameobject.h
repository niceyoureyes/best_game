#pragma once
#include "GameEntity.h"
#include "Box2D.h"
#include "Ray2D.h"

class GameObject : public GameEntity
{
public:
  void Move(Point2D const & point);
  void SetSides(double const value); // change side length
  void Direct(Point2D const & direction);
  void SetParameters(Box2D const & box, Point2D const & direction);

  Box2D const & Box() const;
  Point2D const & Direction() const;
private:
  Box2D m_box;
  Point2D m_direction;
};
