#include <iostream>
#include "Point2D.h"
#include "Box2D.h"
#include "Ray2D.h"
#include "alien.h"
#include "global_configs.h"
using namespace std;
int main()
{
  InitConfig();
  Alien al(Box2D(1, 1, 2, 2), Point2D(1, 1), 0);
  return 0;
}
