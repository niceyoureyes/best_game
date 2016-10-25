#pragma once
#include <vector>
using namespace std;
// ниже представлены характеристики и конфигурации...
// патроны
class Ammo
{
public:
  double hit_power;
  double hit_impulse;
  double speed;
};
// оружие
class Weapon
{
public:
  double hit_power;
  double hit_impulse;
  double speed;
  double hit_type;
  double rpm;
};

void InitConfig();
vector <Ammo> extern ammo_configs;
vector <Weapon> extern weapon_configs;


