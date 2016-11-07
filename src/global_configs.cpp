#include "Global_configs.h"

vector <TBullet> bulletConfigs;
vector <TGun> gunConfigs;
vector <TAlien> alienConfigs;

void InitConfig()
{
  bulletConfigs.push_back(TBullet{10, 10, 10, 1});
  gunConfigs.push_back(TGun{1, 0});
  alienConfigs.push_back(TAlien{100, 10, 50, 50, 0});
}
