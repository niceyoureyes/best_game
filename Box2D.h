#pragma once
#include "stdafx.h"
#include <iostream>

class Box2D
{
public:
	Box2D(Point2D const &p1, Point2D const &p2);
	Box2D(Box2D const &obj);
	Point2D & point1();
	Point2D & point2();
	Point2D const & point1() const;
	Point2D const & point2() const;
private:
	Point2D m_point1, m_point2;
};
std::ostream &operator << (std::ostream &os, Box2D const &box);