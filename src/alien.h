#pragma once
#include "Ray2D.h"
#include "Gun.h"
#include "GameObject.h"

class Alien : public GameObject
{
public:
  //Alien() = default;
  Alien(Box2D const & box, Point2D const & direction, int const typeAlien);
  Alien(Alien const & obj);
  Alien operator = (Alien const & obj);
  int const & TypeAlien() const;
  void Behavior();
  void Shot();
private:
  int m_typeAlien;
  Gun m_gun;
};
