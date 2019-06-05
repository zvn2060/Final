
#include "BulletManager.hpp"
#include "MainScene.hpp"
// to mutual include,
// (1) include BulletManager.hpp as before in MainScene.hpp,
// (2) "class MainScene;"       in BulletManager.hpp,
// (3) "#include MainScene.hpp" in BulletManager.cpp

using namespace std;

void BulletManager::init(MainScene* mainScene) {
	this->mainScene = mainScene;
	this->bulletPoolSize = 10;
	this->bulletPool.push_back(Bullet(this->mainScene->fighter));
	for (int i = 0; i < this->bulletPoolSize; ++i) {
		this->bulletPool.push_back(Bullet(this->mainScene->fighter));
	}

	// TODO: change this hard coded to read data from json
	this->bulletData.push_back(vector<vector<map<string, float>>>{
		{ // first bullet
			{ { "count", 0 }, { "r", 25 }, { "angle", 10 }, { "ra", 0 }, { "wa", 0 }, { "raa", 0 } },
			{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
		},
		{ // second bullet
			{ { "count", 0 },{ "r", 25 },{ "angle", -10 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } },
			{ { "count", 50 },{ "r", 0 },{ "angle", 0 },{ "ra", 0 },{ "wa", 0 },{ "raa", 0 } }
		}
	});

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
	for (auto& b : this->bulletPool) {
		if (b.alive) {
			b.update(deltaTime);
		}
	}
}

void BulletManager::draw() {
	for (auto b : this->bulletPool) {
		if (b.alive) {
			b.draw();
		}
	}
}