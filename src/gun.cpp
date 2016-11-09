#include "Gun.h"
#include "Global_configs.h"

Gun::Gun(Box2D const & box, Point2D const & direction, int const typeGun): m_typeGun(typeGun)
{
  SetParameters(box, direction);
}

Gun::Gun(Gun const & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeGun = obj.TypeGun();
}

Gun Gun::operator = (Gun const & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeGun = obj.TypeGun();
  return *this;
}

int const & Gun::TypeGun() const
{
  return m_typeGun;
}

Bullet Gun::Shot(Point2D const & alienPos)
{
  int width = bulletConfigs[gunConfigs[m_typeGun].typeBullet].width;
  Point2D pwidth(width, width);
  Box2D box(alienPos + Box().PointMin() - pwidth / 2, alienPos + Box().PointMin() + pwidth / 2);
  return Bullet(box, Direction(), gunConfigs[m_typeGun].typeBullet, 1);
}
