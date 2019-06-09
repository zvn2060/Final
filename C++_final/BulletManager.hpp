#ifndef BULLETMANAGER_HPP
#define BULLETMANAGER_HPP

#include <vector>
#include <string>
#include "Bullet.hpp"

class MainScene;
class Bullet;
using namespace std;

class BulletManager {
private:
	vector<Bullet> bulletPool;
	vector<Bullet>::iterator firstDead;
	MainScene* mainScene;
	int bulletPoolSize;
	vector< vector< vector<map<string, float>> > > bulletData;  // second vector's size = bullet quantity
public:
	BulletManager() {};
	~BulletManager() = default;
	void init(MainScene* main);

	Bullet* getFirstDead();
	void next();

	void shot(Engine::Point& p, int data, int genre, int color, float aiming, float randomRange, float offset_r, float offset_t);

	void update(float deltaTime);
	void _update(float deltaTime);
	void draw();

};


#endif