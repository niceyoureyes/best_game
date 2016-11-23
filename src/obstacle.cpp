#include "Obstacle.h"

Obstacle::Obstacle(Box2D const & box, Point2D const & direction)
{
  SetParameters(box, direction);
  Logger::Instance() << "Constructor " << *this;
}
