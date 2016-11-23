#pragma once
#include <vector>
class TBullet
{
public:
  int damage;
  int speed;
  int width;
  int damageRadius;
};
class TGun
{
public:
  int rate; // per second
  int typeBullet;
};
class TBeing
{
public: // TODO: type of behavior
  int hp;
  int speed;
  int width;
  int height;
  int typeGun;
  int ammo;
};

void InitConfig();
extern std::vector <TBullet> bulletConfigs;
extern std::vector <TGun> gunConfigs;
extern std::vector <TBeing> beingConfigs;


