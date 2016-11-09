#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
  Obstacle(Box2D const & box, Point2D const & direction);
private:

};
