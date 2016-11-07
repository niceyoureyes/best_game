#pragma once
#include <vector>
using namespace std;
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
class TAlien
{
public: // TODO: type of behavior
  int hp;
  int speed;
  int width;
  int height;
  int typeGun;
};

void InitConfig();
vector <TBullet> extern bulletConfigs;
vector <TGun> extern gunConfigs;
vector <TAlien> extern alienConfigs;


