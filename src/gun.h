#pragma once
#include "Ray2D.h"
#include "Bullet.h"
#include "GameObject.h"

class Gun : public GameObject
{
public:
  Gun() = default;
  Gun(Box2D const & box, Point2D const & direction, int const typeGun);
  Gun(Gun const & obj);
  Gun & operator = (Gun const & obj);

  int const & TypeGun() const;
  Bullet * Shot(Point2D const & alienPos);
private:
  int m_typeGun;
};
