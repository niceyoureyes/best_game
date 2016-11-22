#include "Space.h"

Space::Space(Box2D const & box, Point2D const & direction):
  m_player(Player(Box2D(Point2D(0, 0), Point2D(50, 50)), Point2D(0, 1), 0))
{
  SetParameters(box, direction);
  Logger::Instance() << "Constructor " << *this;
}
