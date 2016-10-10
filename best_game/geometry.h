#pragma once
#include <iostream>

#define EPS 0.000001

///Point2D
template <typename T>
class Point2D
{
public:
    Point2D() = default;
    Point2D(Point2D<T> const &obj);
    Point2D(T x, T y);
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

    Point2D Norm() const; // return normalized vector
    T Length() const;
private:
    T m_x = 0, m_y = 0;
};
template <typename T>
std::ostream &operator << (std::ostream &os, Point2D<T> const &obj);

///Box2D
template <typename T>
class Box2D
{
public:
    Box2D(Point2D<T> const &p1, Point2D<T> const &p2);
    Box2D(Box2D<T> const &obj);
    Point2D<T> &point1();
    Point2D<T> &point2();
    Point2D<T> const &point1() const;
    Point2D<T> const &point2() const;
private:
    Point2D<T> m_point1, m_point2;
};
template <typename T>
std::ostream &operator << (std::ostream &os, Box2D<T> const &box);

///Ray2D
template <typename T>
class Ray2D
{
public:
    Ray2D(Point2D<T> const &origin, Point2D<T> const &direction);
    Point2D<T> &origin();
    Point2D<T> const &origin() const;
    Point2D<T> &direction();
    Point2D<T> const &direction() const;
private:
    Point2D<T> m_origin, m_direction;
};
template <typename T>
std::ostream &operator << (std::ostream &os, Ray2D<T> const &obj);

///Other
template <typename T>
T &min(T &a, T &b)
{
    return (a < b ? a : b);
}
template <typename T>
T &max(T &a, T &b)
{
    return (a > b ? a : b);
}

template <typename T>
bool PointInBox(Point2D<T> const &p, Box2D<T> const &b);

template <typename T>
bool CrossBoxes(Box2D<T> const &b1, Box2D<T> const &b2);

template <typename T>
bool CrossRayBox(Ray2D<T> const &r, Box2D<T> const &b);

template <typename T>
T Length(Point2D<T> const &p);

template <typename T>
T Length(Point2D<T> const &p1, Point2D<T> const &p2);

template <typename T>
Point2D<T> Vector(Point2D<T> const &p1, Point2D<T> const &p2);

template <typename T>
T DotProduct(Point2D<T> const &p1, Point2D<T> const &p2);

template <typename T>
T CrossProduct(Point2D<T> const &p1, Point2D<T> const &p2);

template <typename T>
bool PointInSegment(Point2D<T> const &p, Point2D<T> const &a, Point2D<T> const &b);

template <typename T>
bool CrossSegments(Point2D<T> const &p1, Point2D<T> const &p2, Point2D<T> const &p3, Point2D<T> const &p4);

///Point2D
template <typename T>
Point2D<T>::Point2D(const Point2D<T> &obj) : m_x(obj.m_x), m_y(obj.m_y) {}

template <typename T>
Point2D<T>::Point2D(T x, T y){
   m_x = x; m_y = y;
}

template <typename T>
T &Point2D<T>::x(){return m_x;}

template <typename T>
T &Point2D<T>::y(){return m_y;}

template <typename T>
T const &Point2D<T>::x() const {return m_x;}

template <typename T>
T const &Point2D<T>::y() const {return m_y;}

template <typename T>
Point2D<T> Point2D<T>::operator +(const Point2D<T> &obj) const
{
    return Point2D(m_x + obj.x(), m_y + obj.y());
}

template <typename T>
Point2D<T> Point2D<T>::operator - (const Point2D<T> &obj) const
{
    return Point2D(m_x - obj.x(), m_y - obj.y());
}

template <typename T>
Point2D<T> Point2D<T>::operator +=(const Point2D<T> &obj)
{
    m_x += obj.x();
    m_y += obj.y();
    return *this;
}

template <typename T>
Point2D<T> Point2D<T>::operator -=(const Point2D<T> &obj)
{
    m_x -= obj.x();
    m_y -= obj.y();
    return *this;
}

template <typename T>
Point2D<T> Point2D<T>::operator *(const T &val) const
{
    return Point2D(m_x * val, m_y * val);
}

template <typename T>
Point2D<T> Point2D<T>::operator / (const T &val) const
{
    //TODO exception
    return Point2D(m_x / val, m_y / val);
}

template <typename T>
Point2D<T> Point2D<T>::operator *=(const T &val)
{
    m_x *= val;
    m_y *= val;
    return *this;
}

template <typename T>
Point2D<T> Point2D<T>::operator /=(const T &val)
{
    //TODO exception
    m_x /= val;
    m_y /= val;
    return *this;
}

template <typename T>
Point2D<T> Point2D<T>::operator =(const Point2D<T> &obj)
{
    if(&obj == this)
        return *this;
    m_x = obj.x();
    m_y = obj.y();
    return *this;
}

template <typename T>
bool Point2D<T>::operator ==(const Point2D<T> &obj) const
{
    return abs(m_x - obj.x()) <= EPS && abs(m_y - obj.y()) <= EPS;
}

template <typename T>
bool Point2D<T>::operator !=(const Point2D<T> &obj) const
{
    return !(*this == obj);
}

template <typename T>
Point2D<T> Point2D<T>::Norm() const
{
    return *this / this->Length();
}

template <typename T>
T Point2D<T>::Length() const
{
    return sqrt(x() * x() + y() * y());
}

template <typename T>
std::ostream &operator <<(std::ostream &os, const Point2D<T> &obj)
{
    os << "Point2D{" << obj.x() << ", " << obj.y() << "}";
    return os;
}

///Box2D
template <typename T>
Box2D<T>::Box2D(Point2D<T> const &p1, Point2D<T> const &p2)
{
    m_point1.x() = min(p1.x(), p2.x());
    m_point1.y() = min(p1.y(), p2.y());
    m_point2.x() = max(p1.x(), p2.x());
    m_point2.y() = max(p1.y(), p2.y());
}

template <typename T>
Box2D<T>::Box2D(Box2D<T> const &obj) : {
    point1 = obj.point1();
    point2 = obj.point2();
}

template <typename T>
std::ostream &operator <<(std::ostream &os, const Box2D<T> &box)
{
    os << box.point1() << " " << box.point2();
    return os;
}

template <typename T>
std::ostream &operator <<(std::ostream &os, const Ray2D<T> &obj)
{
    os << obj.origin() << " " << obj.direction();
    return os;
}

template <typename T>
Ray2D<T>::Ray2D(Point2D<T> const &origin, Point2D<T> const &direction):m_origin(origin), m_direction(direction)
{
    m_direction = m_direction.Norm();
}

template <typename T>
Point2D<T> &Ray2D<T>::origin() {return m_origin;}

template <typename T>
Point2D<T> const &Ray2D<T>::origin() const {return m_origin;}

template <typename T>
Point2D<T> &Ray2D<T>::direction() {return m_direction;}

template <typename T>
Point2D<T> const &Ray2D<T>::direction() const {return m_direction;}

template <typename T>
Point2D<T> &Box2D<T>::point1() {return m_point1;}

template <typename T>
Point2D<T> const &Box2D<T>::point1() const {return m_point1;}

template <typename T>
Point2D<T> &Box2D<T>::point2() {return m_point2;}

template <typename T>
Point2D<T> const &Box2D<T>::point2() const {return m_point2;}

///Other

template <typename T>
bool PointInBox(Point2D<T> const &p, Box2D<T> const &b)
{
    return b.point1().x() <= p.x() && p.x() <= b.point2().x() &&
            b.point1().y() <= p.y() && p.y() <= b.point2().y();
}

template <typename T>
bool CrossBoxes(Box2D<T> const &b1, Box2D<T> const &b2)
{
    return (b1.point1().x() <= b2.point1().x() && b2.point1().x() <= b1.point2().x() ||
            b1.point1().x() <= b2.point2().x() && b2.point2().x() <= b1.point2().x() ||
            b2.point1().x() <= b1.point1().x() && b1.point1().x() <= b2.point2().x() ||
            b2.point1().x() <= b1.point2().x() && b1.point2().x() <= b2.point2().x()) &&
            (b1.point1().y() <= b2.point1().y() && b2.point1().y() <= b1.point2().y() ||
             b1.point1().y() <= b2.point2().y() && b2.point2().y() <= b1.point2().y() ||
             b2.point1().y() <= b1.point1().y() && b1.point1().y() <= b2.point2().y() ||
             b2.point1().y() <= b1.point2().y() && b1.point2().y() <= b2.point2().y());
}

template <typename T>
T Length(Point2D<T> const &p)
{
    return sqrt(p.x() * p.x() + p.y() * p.y());
}

template <typename T>
T Length(Point2D<T> const &p1, Point2D<T> const &p2)
{
    return sqrt((p2.x() - p1.x()) * (p2.x() - p1.x()) + (p2.y() - p1.y()) * (p2.y() - p1.y()));
}

template <typename T>
Point2D<T> Vector(Point2D<T> const &p1, Point2D<T> const &p2)
{
    return p2 - p1;
}

template <typename T>
T DotProduct(Point2D<T> const &p1, Point2D<T> const &p2)
{
    return p1.x() * p2.x() + p1.y() * p2.y();
}

template <typename T>
T CrossProduct(Point2D<T> const &p1, Point2D<T> const &p2)
{
    return p1.x() * p2.y() - p1.y() * p2.x();
}

template <typename T>
bool PointInSegment(Point2D<T> const &p, Point2D<T> const &a, Point2D<T> const &b)
{
    return abs(CrossProduct(Vector(p, a), Vector(p, b))) < EPS  &&
            DotProduct(Vector(p, a), Vector(p, b)) <= 0;
}

template <typename T>
bool CrossSegments(Point2D<T> const &p1, Point2D<T> const &p2, Point2D<T> const &p3, Point2D<T> const &p4)
{
    return PointInSegment(p1, p3, p4) || PointInSegment(p2, p3, p4) ||
            PointInSegment(p3, p1, p2) || PointInSegment(p4, p1, p2) ||
            CrossProduct(Vector(p1, p2), Vector(p1, p3)) *
            CrossProduct(Vector(p1, p2), Vector(p1, p4)) < 0 &&
            CrossProduct(Vector(p3, p4), Vector(p3, p1)) *
            CrossProduct(Vector(p3, p4), Vector(p3, p2)) < 0;
}

template <typename T>
bool CrossRayBox(Ray2D<T> const &r, Box2D<T> const &b)
{
    //TODO: change 100000 to smth else
    auto p1 = r.origin(), p2 = (r.origin() + r.direction() * 100000);
    return CrossSegments(p1, p2, b.point1(), Point2D<T>(b.point1().x(), b.point2().y())) ||
            CrossSegments(p1, p2, b.point1(), Point2D<T>(b.point2().x(), b.point1().y())) ||
            CrossSegments(p1, p2, b.point2(), Point2D<T>(b.point1().x(), b.point2().y())) ||
            CrossSegments(p1, p2, b.point2(), Point2D<T>(b.point2().x(), b.point1().y()));
}
