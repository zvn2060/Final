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
    set<Enemy*> enemyArray;
    set<Enemy*> enemyVanished;  // enemies who ended their lifespan, need to be erased from enemyArray
    Boss* boss;


    static set<string> movingVectorKeyword;
    static set<string> movingVectorKeyword_boss;
    static set<string> shotDataKeyword;

    EnemyManager() = default;
    ~EnemyManager() = default;
    void init(MainScene* main);

    void checkAndSpawnEnemy();
    
    void bossStage(json& ed);

    void update(float deltaTime);
    void _update(float deltaTime);
    void draw();

};


#endif