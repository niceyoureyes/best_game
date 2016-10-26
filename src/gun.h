#pragma once
#include "Ray2D.h"
#include "Bullet.h"
using namespace std;
class Gun
{
public:
  Gun() = default;
  Gun(Point2D const position, Point2D const direction, int const type_weapon, int const type_ammo);
  Gun(Gun const & obj);
  Gun(Gun && obj);
  Gun operator = (Gun const & obj);

  void SetTypeAmmo(int type);
  Bullet Shot(Point2D AlienPos);
private:
  Point2D m_fire_position;
  Point2D m_direction;

  double m_hit_power;
  double m_hit_impulse;
  double m_hit_type;
  double m_speed;

  double m_rpm;

  int m_ammo_type;
  int m_type_weapon;
};
