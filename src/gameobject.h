#pragma once
#include "GameEntity.h"
#include "Box2D.h"

class GameObject : public GameEntity
{
public:
    void Move(Point2D const & point);
    void Scale(double factor);
private:
    Box2D box;
};
