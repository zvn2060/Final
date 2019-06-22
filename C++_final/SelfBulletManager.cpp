#include "SelfBulletManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
void SelfBulletManager::init(MainScene* mainscene) {
	mainScene = mainscene;
	bulletPoolSize = 2000;
	for (int i = 0; i < this->bulletPoolSize; ++i) {
		this->bulletPool.emplace_back(mainscene);
	}
	
	bulletData = Util::parseBulletData("resources/data/selfbullet.json");
	
	firstDead = bulletPool.begin();
}

SelfBullet* SelfBulletManager::getFirstDead() {
	if (!firstDead->alive) {
		return &*firstDead;
	}
	auto prev = firstDead;
	next();
	while (firstDead != prev) {
		if (!firstDead->alive) {
			return &*firstDead;
		}
		next();
	}
	return nullptr;
}
void SelfBulletManager::next() {
	firstDead++;
	if (firstDead == bulletPool.end())
		firstDead = bulletPool.begin();
}

void SelfBulletManager::shot(Engine::Point& p, int bullet, int genre, int color, float aiming, float randomRange, float offset_x, float offset_y){
	float baseAngle = 0;
	if (aiming == 999) {
		baseAngle = Math::angleBetween(p.x, p.y, mainScene->fighter->position.x, mainScene->fighter->position.y);
	}
	else {
		baseAngle = aiming;
	}
	if (randomRange) {
		baseAngle += Math::random(-randomRange, randomRange);
	}
	
	SelfBullet* b;
	// for every bullet
	
	for (auto& ele_bullet : bulletData.at(bullet)) {
		
		b = getFirstDead();
		if (!b) {
			cout << "bulletPool not enough" << endl;
			return;
		}
		b->setGenre(genre, color);
		
		b->reset(p.x + offset_x, p.y + offset_y, ele_bullet, baseAngle);
	}

}

void SelfBulletManager::update(float deltaTime) {
	if (deltaTime < 3) {
		_update(deltaTime);
	}
	else{
		cout << "BulletMgr: update divided" << endl;
		_update(deltaTime / 2);
		_update(deltaTime / 2);
	}
}
void SelfBulletManager::_update(float deltaTime) {
	for (auto & i : bulletPool) {
		if (i.alive) {
			i.update(deltaTime);
		}
	}
}


void SelfBulletManager::draw() {
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