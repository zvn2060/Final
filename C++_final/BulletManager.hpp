#ifndef BULLETMANAGER_HPP
#define BULLETMANAGER_HPP

#include <vector>
#include <string>
#include "Bullet.hpp"

class MainScene;

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
	void init(MainScene* main);

	Bullet* getFirstDead();
	void next();

	void shot(Engine::Point p, int data);// TODO: [int data] wiil be replaced with enemy's shot data

	void update(float deltaTime);
	void _update(float deltaTime);
	void draw();

};


#endif