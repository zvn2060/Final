#include "SelfBullet.hpp"
#include "MainScene.hpp"

SelfBullet::SelfBullet( MainScene * mainScene ) : Bullet( mainScene ){

}

void SelfBullet::update( float deltaTime ){
	this->position.x += this->speed * Math::cos(this->angle - 90) * deltaTime;
	this->position.y += this->speed * (-Math::sin(this->angle - 90)) * deltaTime;
	this->speed += this->ra;
	this->ra += this->raa;
	this->angle += this->w;
	
	if (this->speed < 0) {
		speed = -speed;
		angle = -angle;
	}
	
	
	// collision check
	for(auto it : Bullet::mainScene->enemyMgr->enemyArray){
		if(it->position % position <= it->radius_fighter){
			it->hp--;
		}
	}
	
	if (Math::distanceBetween(this->position, this->fighter->position) < 80) {
	
	}
	
	if (Collision::outOfWorldBound(this->position)) {
		this->alive = false;
	}
	if (this->checkMovingVectorChange())
		this->changeMovingVector(this->vIndex + 1);
	
	this->count++;
}
