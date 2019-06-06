//#ifndef UTIL_HPP
//#define UTIL_HPP
#include <cmath>
#include <iostream>
#include <fstream>
#include "Point.hpp"
#include "nlohmann/json.hpp"


using json = nlohmann::json;

namespace Math {
	float toRadian(float angle);
	float cos(float angle);
	float sin(float angle);

}

namespace Collision {
	bool circleOverlap(Engine::Point p1, float r1, Engine::Point p2, float r2);
	bool outOfWorldBound(Engine::Point p);
}

namespace Util {
	json readJsonData(std::string fileName);
	std::vector<std::vector< std::vector<std::map<std::string, float>> >> readBulletData(std::string fileName);
}

//#endif