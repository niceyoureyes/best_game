#include "geometry.h"


template <typename T>
Point2D<T>::Point2D(const Point2D<T> & obj) : m_x(obj.m_x), m_y(obj.m_y) {}

template <typename T>
Point2D<T>::Point2D(T _x, T _y) : m_x(_x), m_y(_y) {}

template <typename T>
T & Point2D<T>::x(){return m_x;}

template <typename T>
T & Point2D<T>::y(){return m_y;}

template <typename T>
T const & Point2D<T>::x() const {return m_x;}

template <typename T>
T const & Point2D<T>::y() const {return m_y;}

template <typename T>
Point2D<T> Point2D<T>::operator +(const Point2D<T> &obj) const
{
    return Point2D(m_x + obj.x(), m_y + obj.y());
}

