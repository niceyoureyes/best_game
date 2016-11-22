#include "Player.h"
#include "Global_configs.h"

Player::Player(Box2D const & box, Point2D const & direction, int const typeBeing): m_typeBeing(typeBeing)
{
  SetParameters(box, direction);
  Point2D point(Box().Width() / 2, Box().Width() / 2);
  m_gun = Gun(Box2D(point, point), Direction(), beingConfigs[m_typeBeing].typeGun);
  m_hp = beingConfigs[m_typeBeing].hp;
  Logger::Instance() << "Constructor " << *this;
}
