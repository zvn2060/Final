#ifndef UTIL_HPP
#define UTIL_HPP
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <set>
#include <map>
#include "Point.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "nlohmann/json.hpp"

class Polygon;
class MainScene;

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
    float distanceBetween(Engine::Point& p1, Engine::Point& p2);
    
}

namespace Collision {
    bool circleOverlap(Engine::Point& p1, float r1, Engine::Point& p2, float r2);
    bool outOfWorldBound(Engine::Point& p);
    bool overlap_circle_polygon(Engine::Point& c, float r, Polygon* polygon);
}

namespace Util {
    json readJsonData(const std::string& fileName);
    void writeJsonData(const std::string& filename, const json& js);

    static std::set<std::string> movingVectorKeyword_bullet = { "count", "r", "aiming", "angle", "ra", "w", "raa", "offset_r", "offset_t" };
    static std::set<std::string> movingVectorKeyword_enemy = { "count", "r", "angle", "ra", "w", "raa" };
    static std::set<std::string> movingVectorKeyword_boss = { "count", "type", "x1", "x2", "y1", "y2", "index", "interval" };
    static std::set<std::string> shotDataKeyword = { "count", "genre", "color", "bullet", "aiming", "angle", "random", "offset_r", "offset_t" };
    static std::map<string, int> itemMap = {
        {"s", 0},
        {"p", 1},
        {"P", 2},
        {"L", 3}
    };
    std::vector<std::vector< std::vector<std::map<std::string, float>> >> parseBulletData(const std::string& fileName);
    std::vector<Enemy*> parseEnemyData(const std::string& fileName, MainScene* mainScene);
    Enemy* parseEnemy(json&, MainScene*);
    Boss* parseBoss(json&, MainScene*);


    // work with MainScene::preload()
    // build fileName -> bitmapDimension map to skip al_get_bitmap_width() when Bullet::setGenre()
    void loadBitmap(const string& fileName);
    int getPngWidth(const string& fileName);
    int getPngHeight(const string& fileName);
    static std::map<string, int> bitmapWidthMap;
    static std::map<string, int> bitmapHeightMap;
}

#endif