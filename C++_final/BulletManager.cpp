
#include "BulletManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
// to mutual include,
// (1) include BulletManager.hpp as before in MainScene.hpp,
// (2) "class MainScene;"       in BulletManager.hpp,
// (3) "#include MainScene.hpp" in BulletManager.cpp

#include <typeinfo>

using namespace std;

void BulletManager::init(MainScene* mainScene) {
	this->mainScene = mainScene;
	this->bulletPoolSize = 2000;
	this->bulletPool.push_back(Bullet(this->mainScene->fighter));
	for (int i = 0; i < this->bulletPoolSize; ++i) {
		this->bulletPool.push_back(Bullet(this->mainScene->fighter));
	}

	json bd = Util::readJsonData("resources/data/bullet.json");
	this->bulletData = Util::rebuildBulletData(bd);

	// TODO: change this hard coded to read data from json
	//this->bulletData.push_back(vector<vector<map<string, float>>>{
	//	{ // first bullet
	//		{ { "count", 0 }, { "r", 10 }, { "angle", 10 }, { "ra", 0 }, { "wa", 1 }, { "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{ // second bullet
	//		{ { "count", 0 },{ "r", 25 },{ "angle", -10 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{ // third bullet
	//		{ { "count", 0 },{ "r", 10 },{ "angle", 90 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{ // 4th bullet
	//		{ { "count", 0 },{ "r", 30 },{ "angle", 100 },{ "ra", 0 },{ "wa", 1 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{ // 5th bullet
	//		{ { "count", 0 },{ "r", 2 },{ "angle", -90 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//		{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 11 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 12 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 13 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 14 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	},
	//	{
	//		{ { "count", 0 },{ "r", 8 },{ "angle", 15 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
	//	{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
	//	}
	//});

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
	return NULL;
}
void BulletManager::next() {
	this->firstDead++;
	if (this->firstDead == this->bulletPool.end())
		this->firstDead = this->bulletPool.begin();
}

void BulletManager::shot(Engine::Point p, int data){
	// for every bullet
	for (vector<map<string, float>> bullet : bulletData[data]) {
		Bullet* b = getFirstDead();
		if (!b) {
			cout << "bulletPool not enough" << endl;
			return;
		}
		b->reset(p.x, p.y, bullet);
	}
}

void BulletManager::update(float deltaTime) {
	if (deltaTime < 3) {
		_update(deltaTime);
	}
	else if (deltaTime < 6) {
		_update(deltaTime / 2);
		_update(deltaTime / 2);
	}
	else if (deltaTime < 9) {
		_update(deltaTime / 3);
		_update(deltaTime / 3);
		_update(deltaTime / 3);
	}
	else if (deltaTime < 12) {
		_update(deltaTime / 4);
		_update(deltaTime / 4);
		_update(deltaTime / 4);
		_update(deltaTime / 4);
	}
	else if (deltaTime < 15) {
		_update(deltaTime / 5);
		_update(deltaTime / 5);
		_update(deltaTime / 5);
		_update(deltaTime / 5);
		_update(deltaTime / 5);
	}
	else {
		_update(deltaTime / 6);
		_update(deltaTime / 6);
		_update(deltaTime / 6);
		_update(deltaTime / 6);
		_update(deltaTime / 6);
		_update(deltaTime / 6);
	}
}
void BulletManager::_update(float deltaTime) {
	for (auto i = bulletPool.begin(); i != bulletPool.end(); i++) {
		if (i->alive) {
			i->update(deltaTime);
		}
	}
	//for (auto& b : this->bulletPool) {
	//	if (b.alive) {
	//		b.update(deltaTime);
	//	}
	//}
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