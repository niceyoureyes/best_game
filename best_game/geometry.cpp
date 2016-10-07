//#include "geometry.h"

//template <typename T>
//Point2D<T>::Point2D(const Point2D<T> &obj) : m_x(obj.m_x), m_y(obj.m_y) {}

//template <typename T>
//Point2D<T>::Point2D(T _x, T _y){
//   m_x = _x; m_y = _y;
//}

//template <typename T>
//T &Point2D<T>::x(){return m_x;}

//template <typename T>
//T &Point2D<T>::y(){return m_y;}

//template <typename T>
//T const &Point2D<T>::x() const {return m_x;}

//template <typename T>
//T const &Point2D<T>::y() const {return m_y;}

//template <typename T>
//Point2D<T> Point2D<T>::operator +(const Point2D<T> &obj) const
//{
//    return Point2D(m_x + obj.x(), m_y + obj.y());
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator - (const Point2D<T> &obj) const
//{
//    return Point2D(m_x - obj.x(), m_y - obj.y());
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator +=(const Point2D<T> &obj)
//{
//    m_x += obj.x();
//    m_y += obj.y();
//    return *this;
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator -=(const Point2D<T> &obj)
//{
//    m_x -= obj.x();
//    m_y -= obj.y();
//    return *this;
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator *(const T &val) const
//{
//    return Point2D(m_x * val, m_y * val);
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator / (const T &val) const
//{
//    //TODO exception
//    return Point2D(m_x / val, m_y / val);
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator *=(const T &val)
//{
//    m_x *= val;
//    m_y *= val;
//    return *this;
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator /=(const T &val)
//{
//    //TODO exception
//    m_x /= val;
//    m_y /= val;
//    return *this;
//}

//template <typename T>
//Point2D<T> Point2D<T>::operator =(const Point2D<T> &obj)
//{
//    if(&obj == this)
//        return *this;
//    m_x = obj.x();
//    m_y = obj.y();
//    return *this;
//}

//template <typename T>
//bool Point2D<T>::operator ==(const Point2D<T> &obj) const
//{
//    return abs(m_x - obj.x()) < eps && abs(m_y - obj.y()) < eps;
//}

//template <typename T>
//bool Point2D<T>::operator !=(const Point2D<T> &obj) const
//{
//    return !operator ==(*this,obj);
//}

//template <typename T>
//std::ostream &operator <<(std::ostream &os, const Point2D<T> &obj)
//{
//    os << "Point2D{" << obj.x() << ", " << obj.y() << "}" << std::endl;
//    return os;
//}


//template <typename T>
//Box2D<T>::Box2D(Point2D<T> p1, Point2D<T> p2)
//{
//    point1.m_x = min(p1.m_x, p2.m_x);
//    point1.m_y = min(p1.m_y, p2.m_y);
//    point2.m_x = max(p1.m_x, p2.m_x);
//    point2.m_y = max(p1.m_y, p2.m_y);
//}

//template <typename T>
//std::ostream &operator <<(std::ostream &os, const Box2D<T> &box)
//{
//    os << "Left-down "; // << box.point1 << "   Right-up" << box.point2 << std::endl;
//    return os;
//}

//template <typename T>
//Ray2D<T>::Ray2D(Point2D<T> _origin, Point2D<T> _direction):origin(_origin), direction(_direction){}

//template <typename T>
//bool PointInBox(Point2D<T> &p, Box2D<T> &b)
//{
//    return b.point1.m_x <= p.m_x && p.m_x <= b.point2.m_x &&
//            b.point1.m_y <= p.m_y && p.m_y <= b.point2.m_y;
//}

//template <typename T>
//bool CrossBoxes(Box2D<T> &b1, Box2D<T> &b2)
//{
//    return PointInBox(b1.point1, b2) || PointInBox(b1.point2, b2) ||
//            PointInBox(Point2D<T>(b1.point1.m_x, b1.point2.m_y), b2) ||
//            PointInBox(Point2D<T>(b1.point2.m_x, b1.point1.m_y), b2);
//}

//template <typename T>
//bool CrossRayBox(Ray2D<T> &r, Box2D<T> &b)
//{
//    return 0;
//}
