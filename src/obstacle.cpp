#include "Obstacle.h"

//std::ostream & operator << (std::ostream & os, const Obstacle & obstacle)
//{
//  os << "Obstacle";
//  return os;
//}

Obstacle::Obstacle(Box2D const & box, Point2D const & direction)
{
  SetParameters(box, direction);
  Logger::Instance() << "Constructor " << *this;
}
