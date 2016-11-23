#pragma once
#include "GameObject.h"
#include "Gun.h"

class Player : public GameObject
{
public:
  Player(Box2D const & box, Point2D const & direction, int const typeBeing);
private:
  Gun m_gun;
  int m_typeBeing;
  int m_hp;
  int m_ammo;
};
