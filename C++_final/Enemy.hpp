#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include "Point.hpp"
#include "Fighter.hpp"

class MainScene;
class EnemyManager;
using namespace std;

class Enemy {
private:
public:
    shared_ptr<ALLEGRO_BITMAP> bmp;
    int bitmapWidth{};
    int bitmapHeight{}; // only for anchor
    Engine::Point position;
    Engine::Point anchor;
    int debutCount;
    int count;
    float speed{}; // Speed
    float angle{}; // Angle
    float w{};     // Angular Acceleration
    float ra{};    // Acceleration
    float raa{};   // Jerk
                 // float wa;
    float radius_fighterBullet;
    float radius_fighter;
    vector<map<string, float>> v;
    vector<map<string, float>> s;
    vector<int> items;
    int vIndex{};
    int sIndex;
    int lifespan;
    float hp;
    int typeForEnemyManager_testing;

    // link
    MainScene* mainScene;
    EnemyManager* enemyMgr;

    explicit Enemy(int debutCount, const string& sprite, float x, float y, float hp,
        vector<int>& items, vector<map<string, float>>& v, vector<map<string, float>>& s,
        MainScene*);
    virtual ~Enemy() = default;
    void setSprite(const string& fileName);
    bool checkMovingVectorChange();
	
	virtual void changeMovingVector(int index);
    bool checkShot();
    void shot(int index);
	
	virtual void update(float deltaTime);
	
	virtual void draw();

};

#endif