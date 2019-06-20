#include "EnemyManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
#include "LOG.hpp"


set<string> EnemyManager::movingVectorKeyword = { "count", "r", "angle", "ra", "w", "raa" };
set<string> EnemyManager::movingVectorKeyword_boss = { "count", "type", "x1", "x2", "y1", "y2", "index", "interval" };
set<string> EnemyManager::shotDataKeyword = { "count", "genre", "color", "bullet", "aiming", "angle", "random", "offset_r", "offset_t" };


void EnemyManager::init(MainScene* mainScene) {
    this->mainScene = mainScene;
    this->enemyData = Util::readEnemyData("resources/data/enemy.json");
    this->eIndex = 3;
}

void EnemyManager::checkAndSpawnEnemy() {
    if (this->eIndex >= (int)this->enemyData.size() - 1) return;
    if (!(this->mainScene->count >= this->enemyData[this->eIndex + 1]["count"].get<int>())) return;
    this->eIndex++;
    try {
        json& ed = this->enemyData[this->eIndex];

        if (!ed["bossStage"].is_null()) {
            this->bossStage(ed);
            return;
        }

        vector<map<string, float>> vs;
        for (auto& v : ed["v"]) {
            map<string, float> v_t;
            // push all moving vector property
            for (auto it = v.begin(); it != v.end(); it++) {
                if ((EnemyManager::movingVectorKeyword.find(it.key()) != EnemyManager::movingVectorKeyword.end()) && 
                    it.value().is_number()) {
                    v_t[it.key()] = it.value();
                }
                else {
                    Engine::LOG(Engine::WARN) << "EnemyManager.checkAndSpawnEnemy(): not supported parameter type";
                }
            }
            vs.push_back(v_t);
        }
        vector<map<string, float>> ss;
        for (auto& s : ed["s"]) {
            map<string, float> s_t;
            for (auto it = s.begin(); it != s.end(); it++) {
                if ((EnemyManager::shotDataKeyword.find(it.key()) != EnemyManager::shotDataKeyword.end()) && 
                    it.value().is_number() || it.value().is_boolean()) {
                    s_t[it.key()] = it.value();
                }
                else {
                    Engine::LOG(Engine::WARN) << "EnemyManager.checkAndSpawnEnemy(): not supported parameter type";
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

void EnemyManager::bossStage(json& ed) {
    vector<map<string, float>> vs;
    for (auto& v : ed["v"]) {
        map<string, float> v_t;
        // push all moving vector property
        for (auto it = v.begin(); it != v.end(); it++) {
            if ((EnemyManager::movingVectorKeyword_boss.find(it.key()) != EnemyManager::movingVectorKeyword_boss.end()) &&
                it.value().is_number()) {
                v_t[it.key()] = it.value();
            }
            else if (it.value().is_string() && it.key() == "type") {
                v_t[it.key()] = Boss::movingVectorTypeMap[it.value()];
            }
            else {
                Engine::LOG(Engine::WARN) << "EnemyManager.bossStage(): not supported parameter type";
            }
        }
        vs.push_back(v_t);
    }

    vector<map<string, float>> ss;
    for (auto& s : ed["s"]) {
        map<string, float> s_t;
        for (auto it = s.begin(); it != s.end(); it++) {
            if ((EnemyManager::shotDataKeyword.find(it.key()) != EnemyManager::shotDataKeyword.end()) &&
                it.value().is_number() || it.value().is_boolean()) {
                s_t[it.key()] = it.value();
            }
            else {
                Engine::LOG(Engine::WARN) << "EnemyManager.bossStage(): not supported parameter type";
            }
        }
        ss.push_back(s_t);
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

    this->boss = new Boss(
        ed["sprite"].get<string>(),
        ed["hp"].get<float>(),
        ed["timeLimit"].get<int>(),
        vs,
        ss,
        dialogueA,
        dialogueB,
        this->mainScene
    );

    this->mainScene->notifyBossStage();
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
    if (this->boss) {
        this->boss->update(deltaTime);
    }

    if (!this->enemyVanished.empty()) {
        for (auto& enemy : this->enemyVanished) {
            enemy->~Enemy();
            this->enemyArray.erase(enemy);

            if (enemy->typeForEnemyManager_testing == 1) {  // boss
                this->boss = nullptr;
            }
        }
        this->enemyVanished.clear();
    }
}

void EnemyManager::draw() {
    for (auto& enemy : this->enemyArray) {
        enemy->draw();
    }
    if (this->boss) {
        this->boss->draw();
    }
}