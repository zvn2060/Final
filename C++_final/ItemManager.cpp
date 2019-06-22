
#include "ItemManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"

void ItemManager::init(MainScene* mainscene) {
    mainScene = mainscene;
    itemPoolSize = 150;
    for (int i = 0; i < itemPoolSize; ++i) {
        itemPool.emplace_back(mainscene);
    }

    firstDead = itemPool.begin();
}

Item* ItemManager::getFirstDead() {
    if (!firstDead->alive) {
        return &*firstDead;
    }

    auto prev = firstDead;
    next();
    while (firstDead != prev) {
        if (!firstDead->alive) {
            return &*firstDead;
        }
        next();
    }
    return nullptr;
}
void ItemManager::next() {
    firstDead++;
    if (firstDead == itemPool.end())
        firstDead = itemPool.begin();
}

void ItemManager::shot(Engine::Point& p, vector<int>& items) {
    Item* item;
    // for every bullet
    for (int genre : items) {
        item = getFirstDead();
        if (!item) {
            cout << "itemPool not enough" << endl;
            return;
        }
        item->setGenre(genre);
        item->reset(Math::random(p.x - 35, p.x + 35), Math::random(p.y - 35, p.y + 35));
    }
}

void ItemManager::update(float deltaTime) {
    if (deltaTime < 3) {
        for (auto & i : itemPool) {
            if (i.alive) {
                i.update(deltaTime);
            }
        }
    }
    else {
        cout << "itemMgr: deltaTime > 3" << endl;
    }
}


void ItemManager::draw() {
    for (auto& item : itemPool) {
        if (item.alive) {
            item.draw();
        }
    }
}