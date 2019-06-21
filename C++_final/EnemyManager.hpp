#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

#include <vector>
#include <set>
#include <string>
#include "nlohmann/json.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"

using json = nlohmann::json;
using namespace std;

class EnemyManager {
private:
    vector<json> enemyData;
    int eIndex;

    // link
    MainScene* mainScene;
public:
    vector<Enemy*> enemyNotDebut;
    vector<Boss*> bossNotDebut;
    set<Enemy*> enemyArray;
    set<Enemy*> enemyVanished;  // enemies who ended their lifespan, need to be erased from enemyArray


    static set<string> movingVectorKeyword;
    static set<string> movingVectorKeyword_boss;
    static set<string> shotDataKeyword;

    EnemyManager() = default;
    ~EnemyManager() = default;
    void init(MainScene* mainScene);

    void checkAndSpawnEnemy();

    void update(float deltaTime);
    void _update(float deltaTime);
    void draw();

};


#endif