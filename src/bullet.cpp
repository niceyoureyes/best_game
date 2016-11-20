#include "Bullet.h"
using namespace std;

//std::ostream & operator << (std::ostream & os, const Bullet & bullet)
//{
//  os << "Bullet";
//  return os;
//}

Bullet::Bullet(Box2D const & box, Point2D const & direction, int const typeBullet, int const owner):
  m_typeBullet(typeBullet), m_owner(owner)
{
  SetParameters(box, direction);
  Logger::Instance() << "Constructor " << *this;
}

Bullet::Bullet(const Bullet & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBullet = obj.TypeBullet();
  m_owner = obj.Owner();
  Logger::Instance() << "Copy constructor " << *this;
}

Bullet Bullet::operator = (const Bullet & obj)
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
