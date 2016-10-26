#pragma once
#include "Ray2D.h"
class Bullet
{
public:
  Bullet(Ray2D const & orientation, double speed, double damage, double impulse, int hit_type);
  Bullet(Bullet const & obj);
  Bullet(Bullet && obj);
  Bullet operator = (Bullet const & obj);

  Ray2D & Orientation();
  Ray2D const & Orientation() const;
  double & Impulse();
  double const & Impulse() const;
  double const & GetDamage() const;
  int const & GetType() const;
private:
  Ray2D m_orientation;
  double m_damage;
  double m_speed;
  double m_impulse;
  int m_hit_type;
};
