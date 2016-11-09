#include "Bullet.h"
using namespace std;

Bullet::Bullet(Box2D const & box, Point2D const & direction, int const typeBullet, int owner):
  m_typeBullet(typeBullet), m_owner(owner)
{
  SetParameters(Box(), Direction());
}

Bullet::Bullet(const Bullet & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
  m_owner = obj.Owner();
}

Bullet Bullet::operator = (const Bullet & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
  m_owner = obj.Owner();
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
