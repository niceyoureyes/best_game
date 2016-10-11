#include "Point2D.h"

Point2D::Point2D(const Point2D &obj) : m_x(obj.m_x), m_y(obj.m_y) {}

Point2D::Point2D(double  _x, double  _y) : m_x(_x), m_y(_y) {}

double  &Point2D::x() { return m_x; }

double  &Point2D::y() { return m_y; }

double  const &Point2D::x() const { return m_x; }

double  const &Point2D::y() const { return m_y; }

Point2D Point2D::operator +(const Point2D &obj) const
{
	return Point2D(m_x + obj.x(), m_y + obj.y());
}

Point2D Point2D::operator - (const Point2D &obj) const
{
	return Point2D(m_x - obj.x(), m_y - obj.y());
}

Point2D Point2D::operator +=(const Point2D &obj)
{
	m_x += obj.x();
	m_y += obj.y();
	return *this;
}

Point2D Point2D::operator -=(const Point2D &obj)
{
	m_x -= obj.x();
	m_y -= obj.y();
	return *this;
}

Point2D Point2D::operator *(const double &val) const
{
	return Point2D(m_x * val, m_y * val);
}

Point2D Point2D::operator / (const double  &val) const
{
	//TODO exception
	return Point2D(m_x / val, m_y / val);
}

Point2D Point2D::operator *=(const double  &val)
{
	m_x *= val;
	m_y *= val;
	return *this;
}

Point2D Point2D::operator /=(const double  &val)
{
	// TODO exception
	m_x /= val;
	m_y /= val;
	return *this;
}

Point2D Point2D::operator =(const Point2D &obj)
{
	if (&obj == this)
		return *this;
	m_x = obj.x();
	m_y = obj.y();
	return *this;
}

bool Point2D  ::operator ==(const Point2D &obj) const
{
	return (abs(m_x - obj.x()) < EPS) && (abs(m_y - obj.y()) < EPS);
}

bool Point2D::operator !=(const Point2D &obj) const
{
	return !(*this == obj);
}

Point2D Point2D::Norm() const
{
	return *this / this->Length();
}

double Point2D::Length() const
{
	return sqrt(x() * x() + y() * y());
}

std::ostream &operator <<(std::ostream &os, const Point2D &obj)
{
	os << "Point2D{" << obj.x() << ", " << obj.y() << "}" << std::endl;
	return os;
}