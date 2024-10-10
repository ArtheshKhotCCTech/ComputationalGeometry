#include "GeoUtils.h"

double jmk::areaTriangle2D(const Point2D& a, const Point2D& b, const Point2D& c)
{
    auto AB = b - a;
    auto BC = c - b;

    auto result = crossProduct2D(AB, BC);

    return result/2;
}

int jmk::orientation2D(const Point2D& a, const Point2D& b, const Point2D& c)
{
    auto area = areaTriangle2D(a, b, c);
    if (area > 0 && area < TOLERENCE)
        area = 0;

    if (area < 0 && -(area) < TOLERENCE)
        area = 0;

    Vector2f ab = b - a;
    Vector2f ac = a - c;

    if (area > 0)
        return LEFT;

    if (area < 0)
        return RIGHT;

    if ((ab[X] * ac[X] < 0) || (ab[Y] * ac[Y] < 0))
        return BEHIND;

    if (ab.magnitude() < ac.magnitude())
        return BEYOND;

    if (a == c)
        return ORIGIN;

    if()
}
