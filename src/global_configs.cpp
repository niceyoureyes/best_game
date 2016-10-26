#include "Global_configs.h"

vector <Ammo> ammo_configs;
vector <Weapon> weapon_configs;

void InitConfig()
{
  ammo_configs.push_back(Ammo{1, 10, 10});
  ammo_configs.push_back(Ammo{2, 20, 9});
  weapon_configs.push_back(Weapon{1, 1, 1, 1, 5});
}
