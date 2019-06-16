
#include "BulletManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
// to mutual include,
// (1) include BulletManager.hpp as before in MainScene.hpp,
// (2) "class MainScene;"       in BulletManager.hpp,
// (3) "#include MainScene.hpp" in BulletManager.cpp

#include <typeinfo>

void BulletManager::init(MainScene* mainScene) {
    this->mainScene = mainScene;
    this->bulletPoolSize = 2000;
    this->bulletPool.emplace_back(mainScene);
    for (int i = 0; i < this->bulletPoolSize; ++i) {
        this->bulletPool.emplace_back(mainScene);
    }

    this->bulletData = Util::readBulletData("resources/data/bullet.json");

    this->firstDead = this->bulletPool.begin();
}

Bullet* BulletManager::getFirstDead() {
    if (!(*this->firstDead).alive) {
        return &*this->firstDead;
    }

    auto prev = this->firstDead;
    next();
    while (this->firstDead != prev) {
        if (!(*this->firstDead).alive) {
            return &*this->firstDead;
        }
        next();
    }
    return nullptr;
}
void BulletManager::next() {
    this->firstDead++;
    if (this->firstDead == this->bulletPool.end())
        this->firstDead = this->bulletPool.begin();
}

void BulletManager::shot(Engine::Point& p, int bullet, int genre, int color, float aiming, float randomRange, float offset_r, float offset_t){
    float baseAngle = 0;
    if (aiming == 999) {
        baseAngle = Math::angleBetween(p.x, p.y, this->mainScene->fighter->position.x, this->mainScene->fighter->position.y);
    }
    else {
        baseAngle = aiming;
    }
    if (randomRange) {
        baseAngle += Math::random(-randomRange, randomRange);
    }

    Bullet* b;
    // for every bullet
    for (vector<map<string, float>>& ele_bullet : bulletData[bullet]) {
        b = getFirstDead();
        if (!b) {
            cout << "bulletPool not enough" << endl;
            return;
        }
        b->setGenre(genre, color);

        if (offset_r) {
            b->reset(p.x + offset_r * Math::cos(offset_t - 90), p.y + offset_r * -Math::sin(offset_t - 90), ele_bullet, baseAngle);
        }
        else {
            b->reset(p.x, p.y, ele_bullet, baseAngle);
        }
    }
}

void BulletManager::update(float deltaTime) {
    if (deltaTime < 3) {
        _update(deltaTime);
    }
    else{
        cout << "BulletMgr: update divided" << endl;
        _update(deltaTime / 2);
        _update(deltaTime / 2);
    }
}
void BulletManager::_update(float deltaTime) {
    for (auto & i : bulletPool) {
        if (i.alive) {
            i.update(deltaTime);
        }
    }
}


void BulletManager::draw() {
    //for (auto b : this->bulletPool) {
    //	if (b.alive) {
    //		b.draw();
    //	}
    //}
    for (auto& b : this->bulletPool) {
        if (b.alive) {
            b.draw();
        }
    }
}