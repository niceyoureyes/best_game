#include "Gun.h"
#include "Global_configs.h"

Gun::Gun(Point2D const position, Point2D const direction, int const type_weapon, int const type_ammo):
  m_fire_position(position), m_direction(direction), m_type_weapon(type_weapon), m_ammo_type(type_ammo)
{
  m_hit_power = weapon_configs[type_weapon].hit_power * ammo_configs[type_ammo].hit_power;
  m_hit_impulse = weapon_configs[type_weapon].hit_impulse * ammo_configs[type_ammo].hit_impulse;
  m_speed = weapon_configs[type_weapon].speed * ammo_configs[type_ammo].speed;
  m_hit_type = weapon_configs[type_weapon].hit_type;
  m_rpm = weapon_configs[type_weapon].rpm;
}

Gun::Gun(Gun const & obj)
{
  m_fire_position = obj.m_fire_position;
  m_direction = obj.m_direction;
  m_type_weapon = obj.m_type_weapon;
  m_hit_power = obj.m_hit_power;
  m_hit_impulse = obj.m_hit_impulse;
  m_hit_type = obj.m_hit_type;
  m_speed = obj.m_speed;
  m_rpm = obj.m_rpm;
  m_ammo_type = obj.m_ammo_type;
}

Gun::Gun(Gun && obj)
{
  swap(m_fire_position, obj.m_fire_position);
  swap(m_direction, obj.m_direction);
  swap(m_type_weapon, obj.m_type_weapon);
  swap(m_hit_power, obj.m_hit_power);
  swap(m_hit_impulse, obj.m_hit_impulse);
  swap(m_hit_type, obj.m_hit_type);
  swap(m_speed, obj.m_speed);
  swap(m_rpm, obj.m_rpm);
  swap(m_ammo_type, obj.m_ammo_type);
}

Gun Gun::operator = (Gun const & obj)
{
  m_fire_position = obj.m_fire_position;
  m_direction = obj.m_direction;
  m_type_weapon = obj.m_type_weapon;
  m_hit_power = obj.m_hit_power;
  m_hit_impulse = obj.m_hit_impulse;
  m_hit_type = obj.m_hit_type;
  m_speed = obj.m_speed;
  m_rpm = obj.m_rpm;
  m_ammo_type = obj.m_ammo_type;
  return *this;
}

void Gun::SetTypeAmmo(int type)
{
  m_ammo_type = type;
  m_hit_power = weapon_configs[m_type_weapon].hit_power * ammo_configs[type].hit_power;
  m_hit_impulse = weapon_configs[m_type_weapon].hit_impulse * ammo_configs[type].hit_impulse;
  m_speed = weapon_configs[m_type_weapon].speed * ammo_configs[type].speed;
}

Bullet Gun::Shot(Point2D AlienPos)
{
  Ray2D bullet_orientation(AlienPos + m_fire_position, m_direction);
  return Bullet(bullet_orientation, m_speed, m_hit_power, m_hit_impulse, m_hit_type);
}
