#pragma once
#include "Point2D.h"
#include "Box2D.h"
#include "Ray2D.h"

Point2D Vector(Point2D const & p1, Point2D const & p2);
double DotProduct(Point2D const & p1, Point2D const & p2);
double CrossProduct(Point2D const & p1, Point2D const & p2);
bool PointOnSegment(Point2D const & p, Point2D const & a, Point2D const & b);
bool CrossSegments(Point2D const & p1, Point2D const & p2, Point2D const & p3, Point2D const & p4);
