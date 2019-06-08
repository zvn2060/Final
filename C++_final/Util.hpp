#ifndef UTIL_HPP
#define UTIL_HPP
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include "Point.hpp"
#include "nlohmann/json.hpp"


using json = nlohmann::json;

namespace Math {
	float toRadian(float angle);
	float toAngle(float radian);
	float cos(float angle);
	float sin(float angle);
	float angleBetween(float x1, float y1, float x2, float y2);
	static std::random_device rd;
	static std::mt19937 ge(rd());
	float random(float a, float b);
	float abs(float x);
	
}

namespace Collision {
	bool circleOverlap(Engine::Point& p1, float r1, Engine::Point& p2, float r2);
	bool outOfWorldBound(Engine::Point& p);
}

namespace Util {
	json readJsonData(const std::string& fileName);
	void writeJsonData(const std::string& filename, const json& js);
	std::vector<std::vector< std::vector<std::map<std::string, float>> >> readBulletData(const std::string& fileName);
	std::vector<json> readEnemyData(const std::string& fileName);
}

#endif