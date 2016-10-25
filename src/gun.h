#pragma once
#include "Ray2D.h"
#include "bullet.h"
using namespace std;
class Gun
{
public:
  Gun() = default;
  Gun(Point2D position, Point2D direction, int type_weapon, int type_ammo);
  Gun(Gun & obj);
  Gun(Gun && obj);
  Gun operator=(Gun & obj);

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
