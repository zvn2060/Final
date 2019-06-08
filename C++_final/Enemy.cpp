#include "Enemy.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include "MainScene.hpp"
#include <allegro5/allegro_primitives.h>

Enemy::Enemy(string sprite, float x, float y, float hp, vector<map<string, float>>& v, vector<map<string, float>>& s, MainScene* mainScene, EnemyManager* em) {
	this->setSprite(sprite);
	this->position = Engine::Point(x + MainScene::fieldX1, y + MainScene::fieldY1);
	this->anchor = Engine::Point(0.5, 0.5);
	this->count = 0;
	this->v = v;
	this->s = s;
	this->sIndex = -1;
	this->changeMovingVector(0);
	this->mainScene = mainScene;
	this->radius_fighterBullet = this->bitmapWidth;
	this->radius_fighter = 2;
	this->lifespan = 1000;
	this->hp = hp;
	this->enemyMgr = em;
}
void Enemy::setSprite(string fileName) {
	this->bmp = Engine::Resources::GetInstance().GetBitmap("main/" + fileName);
	this->bitmapWidth = al_get_bitmap_width(bmp.get());
	this->bitmapHeight = al_get_bitmap_height(bmp.get());
}

bool Enemy::checkMovingVectorChange() {
	if (this->vIndex >= (int)this->v.size() - 1) {
		return false;
	}
	if (this->count >= this->v[vIndex + 1]["count"]) {
		return true;
	}
	return false;
}
void Enemy::changeMovingVector(int index) {
	if (this->v[index]["r"] == 999) {  // inheritance current speed
		this->speed = this->speed;
	}
	else {
		this->speed = this->v[index]["r"];
	}

	if (this->v[index]["angle"] == 999) {  // inheritance current angle
		this->angle = this->angle;
	}
	else {
		this->angle = this->v[index]["angle"];
	}

	this->w = this->v[index]["w"];
	this->ra = this->v[index]["ra"];
	this->raa = this->v[index]["raa"];
	this->vIndex = index;
}

bool Enemy::checkShot() {
	if (this->sIndex >= (int)this->s.size() - 1) {
		return false;
	}
	if (this->count >= this->s[sIndex + 1]["count"]) {
		return true;
	}
	return false;
}

void Enemy::shot(int index) {
	map<string, float>* shot = &this->s[index];
	this->mainScene->bulletMgr->shot(this->position, 
		(*shot)["bullet"], 
		(*shot)["genre"], 
		(*shot)["color"], 
		(*shot)["aiming"], 
		(*shot)["rr"], 
		(*shot)["re"],
		(*shot)["offset_r"],
		(*shot)["offset_t"]
	);
	this->sIndex = index;
}

void Enemy::update(float deltaTime) {
	this->position.x += this->speed * Math::cos(this->angle - 90) * deltaTime;
	this->position.y += this->speed * (-Math::sin(this->angle - 90)) * deltaTime;
	this->speed += this->ra;
	this->ra += this->raa;
	this->angle += this->w;

	if (this->speed < 0) {
		speed = -speed;
		angle = -angle;
	}

	if (Collision::circleOverlap(this->position, this->radius_fighter, this->mainScene->fighter->position, this->mainScene->fighter->radius)) {
		this->mainScene->fighter->reset();
	}
	if (this->checkMovingVectorChange()) {
		this->changeMovingVector(this->vIndex + 1);
	}
	if (this->checkShot()) {
		this->shot(this->sIndex + 1);
	}

	this->count++;
	if (this->count > this->lifespan) {
		this->enemyMgr->enemyArrayClear.insert(this);
	}
}

void Enemy::draw() {
	al_draw_bitmap(bmp.get(), position.x - anchor.x * bitmapWidth, position.y - anchor.y * bitmapHeight, 0);
}