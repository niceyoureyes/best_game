#include "bullet.h"
using namespace std;

Bullet::Bullet(Ray2D const & orientation, double speed, double damage, double impulse, int hit_type):m_damage(damage), m_impulse(impulse), m_hit_type(hit_type), m_orientation(orientation), m_speed(speed) {}

Bullet::Bullet(const Bullet & obj)
{
  m_orientation = obj.m_orientation;
  m_speed = obj.m_speed;
  m_damage = obj.m_damage;
  m_impulse = obj.m_impulse;
  m_hit_type = obj.m_hit_type;
}

Bullet::Bullet(Bullet && obj)
{
  swap(m_orientation, obj.m_orientation);
  swap(m_speed, obj.m_speed);
  swap(m_damage, obj.m_damage);
  swap(m_impulse, obj.m_impulse);
  swap(m_hit_type, obj.m_hit_type);
}

Bullet Bullet::operator=(const Bullet & obj)
{
  m_orientation = obj.m_orientation;
  m_speed = obj.m_speed;
  m_damage = obj.m_damage;
  m_impulse = obj.m_impulse;
  m_hit_type = obj.m_hit_type;
  return *this;
}

Ray2D & Bullet::Orientation()
{
  return m_orientation;
}

const Ray2D & Bullet::Orientation() const
{
  return m_orientation;
}

double & Bullet::Impulse()
{
  return m_impulse;
}

const double & Bullet::Impulse() const
{
  return m_impulse;
}

const double & Bullet::GetDamage() const
{
  return m_damage;
}

const int & Bullet::GetType() const
{
  return m_hit_type;
}
