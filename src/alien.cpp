#include "Alien.h"
#include "Point2D.h"
#include "Global_configs.h"
#include "Box2D.h"
#include "Logger.h"

Alien::Alien(Box2D const & box, Point2D const & direction, int const typeBeing): m_typeBeing(typeBeing)
{
  SetParameters(box, direction);
  Point2D point(box.Width() / 2, box.Width() / 2);
  m_gun = Gun(Box2D(point, point), direction, beingConfigs[m_typeBeing].typeGun);
  m_hp = beingConfigs[m_typeBeing].hp;
  Logger::Instance() << "Constructor " << *this;
}

Alien::Alien(Alien const & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBeing = obj.TypeBeing();
  m_hp = beingConfigs[m_typeBeing].hp;
  Logger::Instance() << "Copy constructor " << *this;
}

Alien Alien::operator = (Alien const & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBeing = obj.TypeBeing();
  m_hp = beingConfigs[m_typeBeing].hp;
  Logger::Instance() << "Copy operator " << *this;
  return *this;
}

int const & Alien::TypeBeing() const
{
  return m_typeBeing;
}

void Alien::Shot()
{
  m_gun.Shot(Box().PointMin());
}

void Alien::SetOnHit(Alien::TOnHit const & onHit)
{
  *m_onHit = onHit;
}

void Alien::Hit(int const typeBullet)
{
  if (m_onHit != nullptr && (*m_onHit) != nullptr)
  {
    (*m_onHit)(typeBullet);
  }
  m_hp -= bulletConfigs[typeBullet].damage;
}
