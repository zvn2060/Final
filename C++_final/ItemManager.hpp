#ifndef ITEMMANAGER_HPP
#define ITEMMANAGER_HPP

#include <vector>
#include <string>
#include "Item.hpp"

using namespace std;

class ItemManager {
private:
    vector<Item> itemPool;
    vector<Item>::iterator firstDead;
    int itemPoolSize{};
    
    // link
    MainScene* mainScene{};
public:
    ItemManager() = default;
    ~ItemManager() = default;
    void init(MainScene* main);

    Item* getFirstDead();
    void next();

    void shot(Engine::Point& p, vector<int>& items);

    void update(float deltaTime);
    void draw();

};


#endif