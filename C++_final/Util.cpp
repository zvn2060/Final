#include <vector>
#include <map>
#include <iomanip>
#include "LOG.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
#include "Polygon.hpp"

using namespace std;


float Math::toRadian(float angle) {
    return angle * 0.0174533f;  // 0.0174533 = pi / 180
}
float Math::toAngle(float radian) {
    return radian * 57.295755f;  // 57.295755 = 1 / 0.0174533
}
float Math::cos(float angle) {
    return std::cos(toRadian(angle));
}
float Math::sin(float angle) {
    return std::sin(toRadian(angle));
}
float Math::angleBetween(float x1, float y1, float x2, float y2) {
    return - toAngle(std::atan2(y2 - y1, x2 - x1)) + 90;
}
float Math::random(float a, float b) {
    std::uniform_real_distribution<float> dis(a, b);
    return dis(Math::ge);
}
float Math::abs(float x) {
    return x > 0 ? x : -x;
}
float Math::distanceBetween(Engine::Point& p1, Engine::Point& p2) {
    float dy = p1.y - p2.y;
    float dx = p1.x - p2.x;
    return std::sqrt(dx * dx + dy * dy);
}


bool Collision::circleOverlap(Engine::Point& p1, float r1, Engine::Point& p2, float r2) {
    return Math::distanceBetween(p1, p2) < r1 + r2;
}

bool Collision::outOfWorldBound(Engine::Point& p) {
    return p.x < MainScene::fieldX1 || p.x > MainScene::fieldX2 || p.y < MainScene::fieldY1 || p.y > MainScene::fieldY2;
}


bool Collision::overlap_circle_polygon(Engine::Point& c, float r, Polygon* polygon) {
    polygon->updateVertics();
    polygon->updateNorms();
    float c_mid;
    float c_max;
    float c_min;
    float p_max;
    float p_min;
    for (auto it = polygon->norms.begin(); it != polygon->norms.end(); it++) {
        polygon->getProjectedMinMax(&p_max, &p_min, *it);
        c_mid = c.projectLengthOnto(*it);
        c_min = c_mid - r;
        c_max = c_mid + r;
        if (c_min > p_max || p_min > c_max) return false;
    }
    return true;
}



json Util::readJsonData(const std::string& fileName) {
    std::ifstream fileInputStream;
    fileInputStream.open(fileName);
    json j;
    try {
        fileInputStream >> j;
    }
    catch (json::exception& e) {
        Engine::LOG(Engine::ERROR) << fileName << ": input stream to json failed, (1) the file doesn't exist (2) the other reasons \n";
    }
    fileInputStream.close();
    return j;
}

void Util::writeJsonData(const std::string& filename, const json& js){
    std::ofstream fileOutputStream;
    fileOutputStream.open(filename);
    fileOutputStream<<std::setw(4)<<js<<std::endl;
    fileOutputStream.close();
}

vector<vector< vector<map<string, float>> >> Util::readBulletData(const string& fileName) {
    json bulletData = Util::readJsonData(fileName);

    // rebuild bullet data to conform with C++ type;

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
                //cout << v << endl;
                map<string, float> v_t;
                // push all moving vector property
                for (auto it = v.begin(); it != v.end(); it++) {
                    if (it.value().is_number() || it.value().is_boolean()) {
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

vector<json> Util::readEnemyData(const std::string& fileName) {
    json enemyDataBundle = readJsonData(fileName);
    vector<json> enemyData;
    enemyData.reserve(enemyDataBundle.size());
    for (auto& enemy : enemyDataBundle) {
        enemyData.push_back(enemy);
    }
    return enemyData;
}