#pragma once
#include "Ray2D.h"
#include "Gun.h"
#include "GameObject.h"
#include <functional>

class Alien : public GameObject
{
public:
  using TOnHit = std::function<void(int const)>;
  Alien() = default;
  Alien(Box2D const & box, Point2D const & direction, int const typeBeing);
  Alien(Alien const & obj);
  Alien operator = (Alien const & obj);
  int const & TypeBeing() const;
  void Shot();
  void SetOnHit(TOnHit const & onHit);
  void Hit(int const typeBullet);
private:
  int m_typeBeing;
  Gun m_gun;
  int m_hp;
  TOnHit * m_onHit;
};
