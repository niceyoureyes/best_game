
template <typename T>
std::ostream &operator <<(std::ostream &os, const Ray2D<T> &obj)
{
	os << obj.origin() << " " << obj.direction();
	return os;
}

template <typename T>
Ray2D<T>::Ray2D(Point2D<T> const &origin, Point2D<T> const &direction) :m_origin(origin), m_direction(direction)
{
	m_direction = m_direction.Norm();
}

template <typename T>
Point2D<T> &Ray2D<T>::origin() { return m_origin; }

template <typename T>
Point2D<T> const &Ray2D<T>::origin() const { return m_origin; }

template <typename T>
Point2D<T> &Ray2D<T>::direction() { return m_direction; }

template <typename T>
Point2D<T> const &Ray2D<T>::direction() const { return m_direction; }

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