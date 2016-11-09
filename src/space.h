#pragma once
#include <list>
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Alien.h"
#include "Obstacle.h"
#include "Point2D.h"

class Space : public GameObject
{
public:
  Space(Box2D const & box, Point2D const & direction);
private:
  Player m_player;
  std::list <Alien> m_aliens;
  std::list <Bullet> m_bullets;
  std::list <Obstacle> m_obstacles;
};
