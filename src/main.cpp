#include <iostream>
#include "Point2D.h"
#include "Box2D.h"
#include "Ray2D.h"
#include "alien.h"
#include "global_configs.h"
#include "memory"
using namespace std;
int main()
{
  std::unique_ptr<int> p(new int);
  *p = 10;
  cout << *p << endl;
  cout << "Hello\n";
  return 0;
}
