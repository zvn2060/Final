#include <vector>
#include <map>
#include "LOG.hpp"
#include "Util.hpp"

using namespace std;


float Math::toRadian(float angle) {
	return angle * 0.0174533f; // 0.0174533 = pi / 180
}

float Math::cos(float angle) {
	return std::cos(toRadian(angle));
}

float Math::sin(float angle) {
	return std::sin(toRadian(angle));
}

bool Collision::circleOverlap(Engine::Point p1, float r1, Engine::Point p2, float r2) {
	return (p1 - p2).Magnitude() < r1 + r2;
}

bool Collision::outOfWorldBound(Engine::Point p) {
	return p.x < 40 || p.x > 440 || p.y < 40 || p.y > 680;
}

json Util::readJsonData(std::string fileName) {
	std::ifstream fileInputStream;
	fileInputStream.open(fileName);
	json j;
	fileInputStream >> j;
	return j;
}
vector<vector< vector<map<string, float>> >> Util::rebuildBulletData(json bulletData) {
	vector<vector< vector<map<string, float>> >> bulletData_t;
	bulletData_t.reserve(bulletData.size());

	// push all bullets
	for (auto& bullets : bulletData) {
		vector<vector<map<string, float>>> bullets_t;
		bullets_t.reserve(bullets.size());

		// push all bullet
		for (auto& bullet : bullets) {
			vector<map<string, float>> bullet_t;
			bullet_t.reserve(bullet.size());

			// push all moving vector
			for (auto& v : bullet) {
				cout << v << endl;
				map<string, float> v_t;
				// push all moving vector property
				for (auto it = v.begin(); it != v.end(); it++) {
					if (it.value().is_number()) {
						v_t[it.key()] = it.value();
					}
					else {
						Engine::LOG(Engine::WARN) << "only float value is supported now. Value in map without key will be 0";
					}
				}

				bullet_t.push_back(v_t);
			}

			bullets_t.push_back(bullet_t);
		}

		bulletData_t.push_back(bullets_t);
	}
	return bulletData_t;
}