#include <vector>
#include <map>
#include <iomanip>
#include "LOG.hpp"
#include "Util.hpp"
#include "Polygon.hpp"
#include "MainScene.hpp"

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

vector<vector< vector<map<string, float>> >> Util::parseBulletData(const string& fileName) {
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
                    if ( (Util::movingVectorKeyword_bullet.find(it.key()) != Util::movingVectorKeyword_bullet.end()) &&
                        it.value().is_number() || it.value().is_boolean()) {
                        v_t[it.key()] = it.value();
                    }
                    else {
                        Engine::LOG(Engine::WARN) << "Util::parseBulletData(): not supported parameter type";
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

vector<Enemy*> Util::parseEnemyData(const std::string& fileName, MainScene* mainScene) {
    json enemyDataBundle = readJsonData(fileName);
    vector<Enemy*> enemyNotDebut;
    enemyNotDebut.reserve(enemyDataBundle.size());

    int index = 0;
    for (auto& ed : enemyDataBundle) {
        try {
            if (ed["bossStage"].is_null()) {
                enemyNotDebut.push_back(Util::parseEnemy(ed, mainScene));
            }
            else {
                enemyNotDebut.push_back(Util::parseBoss(ed, mainScene));
            }
        }
        catch (json::exception& e) {
            cout << "Util::parseEnemyData(): enemy index: " << index << " | create enemy failed" << endl;
        }

        index++;
    }
    return enemyNotDebut;
}

Enemy* Util::parseEnemy(json& ed, MainScene* mainScene) {
    vector<map<string, float>> vs;
    for (auto& v : ed["v"]) {
        map<string, float> v_t;
        // push all moving vector property
        for (auto it = v.begin(); it != v.end(); it++) {
            if ((Util::movingVectorKeyword_enemy.find(it.key()) != Util::movingVectorKeyword_enemy.end()) &&
                it.value().is_number()) {
                v_t[it.key()] = it.value();
            }
            else {
                Engine::LOG(Engine::WARN) << "Util::parseEnemy(): not supported parameter type";
            }
        }
        vs.push_back(v_t);
    }
    vector<map<string, float>> ss;
    for (auto& s : ed["s"]) {
        map<string, float> s_t;
        for (auto it = s.begin(); it != s.end(); it++) {
            if ((Util::shotDataKeyword.find(it.key()) != Util::shotDataKeyword.end()) &&
                it.value().is_number() || it.value().is_boolean()) {
                s_t[it.key()] = it.value();
            }
            else {
                Engine::LOG(Engine::WARN) << "Util::parseEnemy(): not supported parameter type";
            }
        }
        ss.push_back(s_t);
    }
    vector<int> items;
    for (auto& item : ed["items"]) {
        if (item.is_string() && 
            Util::itemMap.find(item) != itemMap.end()) {
            items.push_back(Util::itemMap[item]);
        }
        else {
            Engine::LOG(Engine::WARN) << "Util::parseEnemy(): not supported item type";
        }
    }

    return new Enemy(
        ed["count"].get<int>(),
        ed["sprite"].get<string>(),
        ed["x"].get<float>(),
        ed["y"].get<float>(),
        ed["hp"].get<float>(),
        items, vs, ss, mainScene
    );
}
Boss* Util::parseBoss(json& ed, MainScene* mainScene) {
    vector<map<string, float>> vs;
    for (auto& v : ed["v"]) {
        map<string, float> v_t;
        // push all moving vector property
        for (auto it = v.begin(); it != v.end(); it++) {
            if ((Util::movingVectorKeyword_boss.find(it.key()) != Util::movingVectorKeyword_boss.end()) &&
                it.value().is_number()) {
                v_t[it.key()] = it.value();
            }
            else if (it.value().is_string() && it.key() == "type") {
                v_t[it.key()] = Boss::movingVectorTypeMap[it.value()];
            }
            else {
                Engine::LOG(Engine::WARN) << "Util::parseBoss(): not supported parameter type";
            }
        }
        vs.push_back(v_t);
    }

    vector<map<string, float>> ss;
    for (auto& s : ed["s"]) {
        map<string, float> s_t;
        for (auto it = s.begin(); it != s.end(); it++) {
            if ((Util::shotDataKeyword.find(it.key()) != Util::shotDataKeyword.end()) &&
                it.value().is_number() || it.value().is_boolean()) {
                s_t[it.key()] = it.value();
            }
            else {
                Engine::LOG(Engine::WARN) << "Util::parseBoss(): not supported parameter type";
            }
        }
        ss.push_back(s_t);
    }
    vector<int> items;
    for (auto& item : ed["items"]) {
        if (item.is_string() &&
            Util::itemMap.find(item) != itemMap.end()) {
            items.push_back(Util::itemMap[item]);
        }
        else {
            Engine::LOG(Engine::WARN) << "Util::parseEnemy(): not supported item type";
        }
    }

    vector<string> dialogueA;
    if (!ed["dialogueA"].is_null()) {
        for (auto& dialogue : ed["dialogueA"]) {
            dialogueA.push_back(dialogue);
        }
    }

    vector<string> dialogueB;
    if (!ed["dialogueB"].is_null()) {
        for (auto& dialogue : ed["dialogueB"]) {
            dialogueB.push_back(dialogue);
        }
    }

    return new Boss(
        ed["count"].get<int>(),
        ed["sprite"].get<string>(),
        ed["hp"].get<float>(),
        ed["timeLimit"].get<int>(),
        items, vs, ss, dialogueA, dialogueB, mainScene
    );
}