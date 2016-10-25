#include "alien.h"

Alien::Alien(double hp, Ray2D orientation, double speed, int weapon_type, int ammo_type):m_hp(hp), m_orientation(orientation), m_speed(speed)
{
  m_gun = (Point2D(0,0), Point2D(0, 1), weapon_type, ammo_type); m_count_ammo = 30;
}

void Alien::Behavior()
{

}

void Alien::Shot()
{
  m_count_ammo--;
  m_gun.Shot(m_orientation.origin());
}
