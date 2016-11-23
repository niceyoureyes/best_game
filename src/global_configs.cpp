#include "Global_configs.h"

std::vector <TBullet> bulletConfigs;
std::vector <TGun> gunConfigs;
std::vector <TBeing> beingConfigs;

void InitConfig()
{
  bulletConfigs.push_back(TBullet{10, 10, 10, 1});
  bulletConfigs.push_back(TBullet{30, 5, 20, 50});
  gunConfigs.push_back(TGun{1, 0});
  beingConfigs.push_back(TBeing{100, 10, 50, 50, 0, 100});
}
