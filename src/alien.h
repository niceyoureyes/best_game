#pragma once
#include "Ray2D.h"
#include "gun.h"

class Alien
{
public:
  Alien(double hp, Ray2D orientation, double speed, int weapon_type, int ammo_type);
  void Behavior();
  void Shot();
private:
  double m_hp;
  Ray2D m_orientation;
  double m_speed;

  Gun m_gun;
  int m_count_ammo;
};
