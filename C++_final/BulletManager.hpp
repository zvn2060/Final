#ifndef BULLETMANAGER_HPP
#define BULLETMANAGER_HPP

#include <vector>
#include <string>
#include "Bullet.hpp"

using namespace std;

class BulletManager {
private:
    vector<Bullet> bulletPool;
    vector<Bullet>::iterator firstDead;
    int bulletPoolSize{};
    vector< vector< vector< map<string, float> > > > bulletData;  // second vector's size = bullet quantity
    
    // link
    MainScene* mainScene{};
public:
    BulletManager() = default;
    ~BulletManager() = default;
    void init(MainScene* main);

    Bullet* getFirstDead();
    void next();

    void shot(Engine::Point& p, int data, int genre, int color, float aiming, float angle, float randomRange, float offset_r, float offset_t);

    void update(float deltaTime);
    void _update(float deltaTime);
    void draw();

};


#endif