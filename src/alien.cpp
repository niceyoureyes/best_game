#include "Alien.h"
#include "Point2D.h"
#include "Global_configs.h"
#include "Box2D.h"

Alien::Alien(Box2D const & box, Point2D const & direction, int const typeAlien): m_typeAlien(typeAlien)
{
  SetParameters(box, direction);
  Point2D point(Box().Width() / 2, Box().Width() / 2);
  m_gun = Gun(Box2D(point, point), Direction(), alienConfigs[m_typeAlien].typeGun);
}

Alien::Alien(const Alien & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeAlien = obj.TypeAlien();
}

Alien Alien::operator = (const Alien & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeAlien = obj.TypeAlien();
  return *this;
}

int const & Alien::TypeAlien() const
{
  return m_typeAlien;
}

void Alien::Behavior()
{

}

void Alien::Shot()
{
  m_gun.Shot(Box().PointMin());
}
