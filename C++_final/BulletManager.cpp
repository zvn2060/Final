
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