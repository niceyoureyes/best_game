#pragma once
#include "stdafx.h"

double &min(double &a, double &b);
double &max(double &a, double &b);
bool PointInBox(Point2D const &p, Box2D const &b);
bool CrossBoxes(Box2D const &b1, Box2D const &b2);
bool CrossRayBox(Ray2D const &r, Box2D const &b);
double Length(Point2D const &p);
double Length(Point2D const &p1, Point2D const &p2);
Point2D Vector(Point2D const &p1, Point2D const &p2);
double DotProduct(Point2D const &p1, Point2D const &p2);
double CrossProduct(Point2D const &p1, Point2D const &p2);
bool PointInSegment(Point2D const &p, Point2D const &a, Point2D const &b);
bool CrossSegments(Point2D const &p1, Point2D const &p2, Point2D const &p3, Point2D const &p4);
