#pragma once
#include "Point.h"

namespace jmk {
	double areaTriangle2D(const Point2D& a, const Point2D& b, const Point2D& c);
	int orientation2D(const Point2D& a, const Point2D& b, const Point2D& c);
}