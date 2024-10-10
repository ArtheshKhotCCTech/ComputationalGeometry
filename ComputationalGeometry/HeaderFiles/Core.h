#pragma once
#include<math.h>

#define TOLERENCE 0.0000001

enum class RELATIVE_POSITION {
	LEFT, RIGHT, BEHIND, BEYOND, BETWEEN, ORIGIN, DESTINATION
};

static bool isEqualD(double x, double y) {
	return fabs(x - y) < TOLERENCE;
}