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
    return 0;
    //if(area>0 && area< TOLERENCE)
}
