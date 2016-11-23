#include "GameObject.h"

void GameObject::Move(Point2D const & point)
{
  m_box.Move(point);
}
void GameObject::SetSides(double const value)
{
  m_box.SetSides(value);
}

void GameObject::Direct(Point2D const & direction)
{
  m_direction = direction.Normalize();
}

void GameObject::SetParameters(Box2D const & box, Point2D const & direction)
{
  m_box = box;
  m_direction = direction.Normalize();
}

Box2D const & GameObject::Box() const
{
  return m_box;
}

Point2D const & GameObject::Direction() const
{
  return m_direction;
}
