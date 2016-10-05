#pragma once

template <typename T>
class Point2D
{
public:
    Point2D(T _x, T _y) : x(_x), y(_y){}
private:
    T x, y;
};
template <typename T>
class Box2D
{
public:
    Box2D(Point2D<T> p1, Point2D<T> p2)
    {
        point1.x = min(p1.x, p2.x);
        point1.y = min(p1.y, p2.y);
        point2.x = max(p1.x, p2.x);
        point2.y = max(p1.y, p2.y);
    }

    Point2D<T> point1, point2;
};
template <typename T>
class Ray2D
{
public:
    Point2D<T> origin, direction;
};

template <typename T>
bool PointInBox(Point2D<T> &p, Box2D<T> &b)
{
    return b.point1.x <= p.x && p.x <= b.point2.x &&
            b.point1.y <= p.y && p.y <= b.point2.y;
}

template <typename T>
bool CrossBoxes(Box2D<T> &b1, Box2D<T> &b2)
{
    return PointInBox(b1.point1, b2) || PointInBox(b1.point2, b2) ||
            PointInBox(Point2D<T>(b1.point1.x, b1.point2.y), b2) ||
            PointInBox(Point2D<T>(b1.point2.x, b1.point1.y), b2);
}

template <typename T>
bool CrossRayBox(Ray2D<T> &r, Box2D<T> &b)
{
    return 0;
}
