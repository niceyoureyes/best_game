#pragma once
#include "GameObject.h"
#include "Gun.h"

class Player : public GameObject
{
public:
  Player(Box2D const & box, Point2D const & direction, int const typePlayer);
private:
  Gun m_gun;
  int m_typePlayer;
};
