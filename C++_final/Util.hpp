#ifndef UTIL_HPP
#define UTIL_HPP
#include <cmath>
#include "Point.hpp"

namespace Math {
	const float pi = 3.141592653589793;
	float toRadian(float angle) {
		return angle * pi / 180;
	}

	float cos(float angle) {
		return std::cos(toRadian(angle));
	}

	float sin(float angle) {
		return std::sin(toRadian(angle));
	}

}

namespace Collision {
	bool circleOverlap(Engine::Point p1, float r1, Engine::Point p2, float r2) {
		return (p1 - p2).Magnitude() < r1 + r2;
	}
}

#endif