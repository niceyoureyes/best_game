#pragma once

template <typename T>
class Point2D
{
public:
    Point2D() = default;
    Point2D(Point2D const &obj);
    Point2D(T _x, T _y);
    // TODO constructor initializer list
    T &x();
    T &y();
    T const &x() const;
    T const &y() const;
    Point2D operator + (Point2D const &obj) const;
    Point2D operator - (Point2D const &obj) const;
    Point2D operator += (Point2D const &obj);
    Point2D operator -= (Point2D const &obj);
    Point2D operator * (T const &val) const;
    Point2D operator / (T const &val) const;
    Point2D operator *= (T const &val);
    Point2D operator /= (T const &val);
    Point2D operator = (Point2D const &obj);
    bool operator == (Point2D const &obj) const;
    bool operator != (Point2D const &obj) const;
private:
    T m_x, m_y;
    T eps = 0.0001;
};

template <typename T>
class Box2D
{
public:
    Box2D(Point2D<T> p1, Point2D<T> p2)
    {
        point1.m_x = min(p1.m_x, p2.m_x);
        point1.m_y = min(p1.m_y, p2.m_y);
        point2.m_x = max(p1.m_x, p2.m_x);
        point2.m_y = max(p1.m_y, p2.m_y);
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
    return b.point1.m_x <= p.m_x && p.m_x <= b.point2.m_x &&
            b.point1.m_y <= p.m_y && p.m_y <= b.point2.m_y;
}

template <typename T>
bool CrossBoxes(Box2D<T> &b1, Box2D<T> &b2)
{
    return PointInBox(b1.point1, b2) || PointInBox(b1.point2, b2) ||
            PointInBox(Point2D<T>(b1.point1.m_x, b1.point2.m_y), b2) ||
            PointInBox(Point2D<T>(b1.point2.m_x, b1.point1.m_y), b2);
}

template <typename T>
bool CrossRayBox(Ray2D<T> &r, Box2D<T> &b)
{
    return 0;
}
