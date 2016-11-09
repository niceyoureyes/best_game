#pragma once
#include "Ray2D.h"
#include "Gun.h"
#include "GameObject.h"

class Alien : public GameObject
{
public:
  Alien(Box2D const & box, Point2D const & direction, int const typeBeing);
  Alien(Alien const & obj);
  Alien operator = (Alien const & obj);
  int const & TypeBeing() const;
  void Behavior();
  void Shot();
private:
  int m_typeBeing;
  Gun m_gun;
  int m_hp;
};
