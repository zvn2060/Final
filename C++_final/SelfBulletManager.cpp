#include "SelfBulletManager.hpp"
#include "Util.hpp"
#include "MainScene.hpp"
void SelfBulletManager::init(MainScene* mainscene) {
	mainScene = mainscene;
	bulletPoolSize = 2000;
	bulletPool.emplace_back(mainscene);
	for (int i = 0; i < this->bulletPoolSize; ++i) {
		this->bulletPool.emplace_back(mainscene);
	}
	
	bulletData = Util::readBulletData("resources/data/selfbullet.json");
	
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

void SelfBulletManager::shot(Engine::Point& p, int bullet, int genre, int color, float aiming, float randomRange, float offset_r, float offset_t){
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
		
		if (offset_r) {
			b->reset(p.x + offset_r * Math::cos(offset_t - 90), p.y + offset_r * -Math::sin(offset_t - 90), ele_bullet, baseAngle);
		}
		else {
			b->reset(p.x, p.y, ele_bullet, baseAngle);
		}
		
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