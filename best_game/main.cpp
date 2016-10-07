#include <iostream>
#include "geometry.h"

using namespace std;

int main()
{
    Point2D <double> a(0, 5), b(10, 10), c(-10, -2), d(-3, -8);
    Ray2D <double> r(Point2D<double>(0, 0), Point2D<double>(1, 1));
    Box2D<double> B1(a, b), B2(c, d);
    cout << CrossRayBox(r, B1) << endl;
    cout << CrossRayBox(r, B2) << endl;
    cout << r << endl;
    cout << B1 << endl;
    cout << B2 << endl;

    cout << "easy peasy lemon squeezy!" << endl;
    return 0;
}
