#include "EnemyManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"

void EnemyManager::init(MainScene* mainScene) {
    this->mainScene = mainScene;
    this->enemyData = Util::readEnemyData("resources/data/enemy.json");
    this->eIndex = -1;
}

void EnemyManager::checkAndSpawnEnemy() {
    if (this->eIndex >= (int)this->enemyData.size() - 1) return;
    if (!(this->mainScene->count >= this->enemyData[this->eIndex + 1]["count"].get<int>())) return;
    this->eIndex++;
    try {
        json& ed = this->enemyData[this->eIndex];

        vector<map<string, float>> vs;
        for (auto& v : ed["v"]) {
            map<string, float> v_t;
            // push all moving vector property
            for (auto it = v.begin(); it != v.end(); it++) {
                if (it.value().is_number()) {
                    v_t[it.key()] = it.value();
                }
            }
            vs.push_back(v_t);
        }
        vector<map<string, float>> ss;
        for (auto& s : ed["s"]) {
            map<string, float> s_t;
            for (auto it = s.begin(); it != s.end(); it++) {
                if (it.value().is_number() || it.value().is_boolean()) {
                    s_t[it.key()] = it.value();
                }
            }
            ss.push_back(s_t);
        }

        this->enemyArray.insert(new Enemy(
            ed["sprite"].get<string>(),
            ed["x"].get<float>(),
            ed["y"].get<float>(),
            ed["hp"].get<float>(),
            vs,
            ss,
            this->mainScene
        ));
    }
    catch (json::exception& e) {
        cout << "enemy index: " << this->eIndex << " | create enemy failed" << endl;
    }
}

void EnemyManager::update(float deltaTime) {
    if (deltaTime < 3) {
        _update(deltaTime);
    }
    else {
        cout << "EnemyMgr: update divided" << endl;
        _update(deltaTime / 2);
        _update(deltaTime / 2);
    }

    this->checkAndSpawnEnemy();
}
void EnemyManager::_update(float deltaTime) {
    for (auto& enemy : this->enemyArray) {
        enemy->update(deltaTime);
    }

    if (!this->enemyVanished.empty()) {
        for (auto& enemy : this->enemyVanished) {
            enemy->~Enemy();
            this->enemyArray.erase(enemy);
        }
        this->enemyVanished.clear();
    }
}

void EnemyManager::draw() {
    for (auto& enemy : this->enemyArray) {
        enemy->draw();
    }
}