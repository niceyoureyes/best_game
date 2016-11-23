#include "Bullet.h"
using namespace std;

Bullet::Bullet(Box2D const & box, Point2D const & direction, int const typeBullet, int const owner):
  m_typeBullet(typeBullet), m_owner(owner)
{
  SetParameters(box, direction);
  Logger::Instance() << "Constructor " << *this;
}

Bullet::Bullet(Bullet const & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
  m_owner = obj.Owner();
  Logger::Instance() << "Copy constructor " << *this;
}

Bullet Bullet::operator = (Bullet const & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
  m_owner = obj.Owner();
  Logger::Instance() << "Copy operator " << *this;
  return *this;
}

int const & Bullet::TypeBullet() const
{
  return m_typeBullet;
}

int const & Bullet::Owner() const
{
  return m_owner;
}
