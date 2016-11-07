#include "Bullet.h"
using namespace std;

Bullet::Bullet(Box2D const & box, Point2D const & direction, int const typeBullet): m_typeBullet(typeBullet)
{
  SetParameters(Box(), Direction());
}

Bullet::Bullet(const Bullet & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
}

Bullet Bullet::operator = (const Bullet & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
  return *this;
}

 int const & Bullet::TypeBullet() const
 {
   return m_typeBullet;
 }
