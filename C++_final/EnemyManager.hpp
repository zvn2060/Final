#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

#include <vector>
#include <set>
#include <string>
#include "nlohmann/json.hpp"
#include "Enemy.hpp"

using json = nlohmann::json;
using namespace std;

class EnemyManager {
private:
    MainScene* mainScene;
    vector<json> enemyData;
    int eIndex;
public:
    set<Enemy*> enemyArray;
    set<Enemy*> enemyArrayClear;  // enemies who ended their lifespan, need to be erased from enemyArray

    EnemyManager() {};
    ~EnemyManager() = default;
    void init(MainScene* main);

    void checkAndSpawnEnemy();

    void update(float deltaTime);
    void _update(float deltaTime);
    void draw();

};


#endif