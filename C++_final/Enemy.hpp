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
    int bitmapWidth;
    int bitmapHeight; // only for anchor
    Engine::Point position;
    Engine::Point anchor;
    int count;
    float speed; // Speed
    float angle; // Angle
    float w;     // Angular Acceleration
    float ra;    // Acceleration
    float raa;   // Jerk
                 // float wa;
    float radius_fighterBullet;
    float radius_fighter;
    MainScene* mainScene;
    vector<map<string, float>> v;
    vector<map<string, float>> s;
    vector<string> item;
    int vIndex;
    int sIndex;
    int lifespan;
    float hp;
    EnemyManager* enemyMgr;

    explicit Enemy(const string& sprite, float x, float y, float hp,
        vector<map<string, float>>& v, vector<map<string, float>>& s,
        MainScene* mainScene, EnemyManager* em);
    ~Enemy() = default;;
    void setSprite(const string& fileName);
    bool checkMovingVectorChange();
    void changeMovingVector(int index);
    bool checkShot();
    void shot(int index);
    void update(float deltaTime);
    void draw();

};

#endif