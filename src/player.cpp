#include "Player.h"
#include "Global_configs.h"

Player::Player(Box2D const & box, Point2D const & direction, int const typePlayer): m_typePlayer(typePlayer)
{
  SetParameters(box, direction);
  Point2D point(Box().Width() / 2, Box().Width() / 2);
  m_gun = Gun(Box2D(point, point), Direction(), alienConfigs[m_typePlayer].typeGun);
}
