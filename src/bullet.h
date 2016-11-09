#pragma once
#include "Ray2D.h"
#include "GameObject.h"

class Bullet : public GameObject
{
public:
  Bullet(Box2D const & box, Point2D const & direction, int const typeBullet, int owner);
  Bullet(Bullet const & obj);
  Bullet operator = (Bullet const & obj);
  int const & TypeBullet() const;
  int const & Owner() const;
private:
  int m_typeBullet;
  int m_owner;
};
