
#include "BulletManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
// to mutual include,
// (1) include BulletManager.hpp as before in MainScene.hpp,
// (2) "class MainScene;"       in BulletManager.hpp,
// (3) "#include MainScene.hpp" in BulletManager.cpp

#include <typeinfo>

void BulletManager::init(MainScene* mainScene) {
	this->mainScene = mainScene;
	this->bulletPoolSize = 2000;
	this->bulletPool.emplace_back(this->mainScene->fighter);
	for (int i = 0; i < this->bulletPoolSize; ++i) {
		this->bulletPool.emplace_back(this->mainScene->fighter);
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
	return nullptr;
}
void BulletManager::next() {
	this->firstDead++;
	if (this->firstDead == this->bulletPool.end())
		this->firstDead = this->bulletPool.begin();
}

void BulletManager::shot(Engine::Point& p, int bullet, int genre, int color, bool aiming, float randomRange, float randomRangeForEach, float offset_r, float offset_t){
	float baseAngle = 0;
	if (aiming) {
		baseAngle = Math::angleBetween(p.x, p.y, this->mainScene->fighter->position.x, this->mainScene->fighter->position.y);
	}
	if (randomRange) {
		baseAngle += Math::random(-randomRange, randomRange);
	}

	// for every bullet
	for (vector<map<string, float>>& bullet : bulletData[bullet]) {
		Bullet* b = getFirstDead();
		if (!b) {
			cout << "bulletPool not enough" << endl;
			return;
		}
		b->setGenre(genre, color);

		if (randomRangeForEach) {
			baseAngle += Math::random(-randomRangeForEach, randomRangeForEach);
		}
		b->reset(p.x + offset_r * Math::cos(offset_t - 90), p.y + offset_r * -Math::sin(offset_t - 90), bullet, baseAngle);
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
	for (auto & i : bulletPool) {
		if (i.alive) {
			i.update(deltaTime);
		}
	}
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