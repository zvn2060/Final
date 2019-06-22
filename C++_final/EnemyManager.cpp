#include "EnemyManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
#include "LOG.hpp"

void EnemyManager::init(MainScene* mainScene) {
    this->mainScene = mainScene;
    this->enemyNotDebut = Util::parseEnemyData("resources/data/enemy.json", mainScene);
    this->eIndex = -1;
}

void EnemyManager::checkAndSpawnEnemy() {
    if (this->eIndex >= (int)this->enemyNotDebut.size() - 1) return;
    if (this->mainScene->count < this->enemyNotDebut[this->eIndex + 1]->debutCount) return;
    this->eIndex++;
    if (this->enemyNotDebut[this->eIndex]->typeForEnemyManager_testing == 0) {  // normal enemy
        this->enemyArray.insert(this->enemyNotDebut[this->eIndex]);
    }
    else if (this->enemyNotDebut[this->eIndex]->typeForEnemyManager_testing == 1) {  // boss
        this->enemyArray.insert(this->enemyNotDebut[this->eIndex]);
        this->mainScene->notifyBossStage();
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
        if (enemy->typeForEnemyManager_testing == 0) {
            enemy->update(deltaTime);
        }
        else if (enemy->typeForEnemyManager_testing == 1) {
            ((Boss*)enemy)->update(deltaTime);
        }
    }

    if (!this->enemyVanished.empty()) {
        for (auto& enemy : this->enemyVanished) {
        	delete enemy;
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