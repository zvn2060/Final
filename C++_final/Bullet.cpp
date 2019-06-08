
#include "Bullet.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include <allegro5/allegro_primitives.h>

Bullet::Bullet(Fighter* fighter) {
	this->setGenre(0, 0);
	this->position = Engine::Point(100, 100);
	this->count = 0;
	this->speed = 100;
	this->angle = 0;
	this->w = 0;
	this->ra = 0;
	this->raa = 0;
	this->alive = false;
	this->fighter = fighter;
	this->vIndex = 0;
	this->grazed = false;
}

void Bullet::setGenre(int genre, int color) {
	switch (genre) {
	case 0:
		this->bmp = Engine::Resources::GetInstance().GetBitmap("main/bullet0-" + to_string(color) + ".png");
		this->anchor = Engine::Point(0.45, 0.45);
		this->shape = SHAPE_CIRCLE;
		this->radius = 2;
		break;
	case 1:
		this->bmp = Engine::Resources::GetInstance().GetBitmap("main/bullet1-" + to_string(color) + ".png");
		this->anchor = Engine::Point(0.5, 0.5);
		this->shape = SHAPE_CIRCLE;
		this->radius = 4;
		break;
	case 2:
		break;
	default:
		break;
	}
	this->bitmapWidth = al_get_bitmap_width(bmp.get());
	this->bitmapHeight = al_get_bitmap_height(bmp.get());
}

void Bullet::reset(float x, float y, vector<map<string, float>>& v, float baseAngle) {
	this->alive = true;
	this->position.x = x;
	this->position.y = y;
	this->grazed = false;

	this->v = v;
	this->count = 0;
	this->changeMovingVector(0);

	this->angle += baseAngle;
}

bool Bullet::checkMovingVectorChange() {
	if (this->vIndex >= (int)this->v.size() - 1) {
		return false;
	}
	if (this->count >= this->v[vIndex + 1]["count"]) {
		return true;
	}
	return false;
}
void Bullet::changeMovingVector(int index) {
	//std::cout << "r: " << this->speed << " ra: " << this->ra << std::endl;
	if (this->v[index]["r"] == 999) {  // inheritance current speed
		this->speed = this->speed;
	}
	else {
		this->speed = this->v[index]["r"];
	}

	if (this->v[index]["toPlayer"]) {
		this->angle = Math::angleBetween(this->position.x, this->position.y, this->fighter->position.x, this->fighter->position.y);
	}
	else if(this->v[index]["angle"] == 999) {  // inheritance current angle
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

void Bullet::update(float deltaTime) {
	this->position.x += this->speed * Math::cos(this->angle - 90) * deltaTime;
	this->position.y += this->speed * (-Math::sin(this->angle - 90)) * deltaTime;
	this->speed += this->ra;
	this->ra += this->raa;
	this->angle += this->w;

	if (this->speed < 0) {
		speed = -speed;
		angle = -angle;
	}

	switch (this->shape) {
	case SHAPE_CIRCLE:
		if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->radius)) {
			this->fighter->reset();
		}
		if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->grazeRadius)) {
			this->fighter->graze++;
		}
		break;
	case SHAPE_POLYGON:
		break;
	default:
		break;
	}

	if (Collision::outOfWorldBound(this->position)) {
		this->alive = false;
	}
	if (this->checkMovingVectorChange())
		this->changeMovingVector(this->vIndex + 1);

	this->count++;
}

void Bullet::draw() {
	al_draw_rotated_bitmap(bmp.get(),
		anchor.x * bitmapWidth, anchor.y * bitmapHeight,
		position.x, position.y,
		Math::toRadian(-angle + 180), 0);
	// what the fuck is that allegro's rotating direction, which sees clockwise as positive angle, is different with cmath, which uses the coordinate view of real math

	// testing for discriminating the difference between position & anchor(image)
	al_draw_filled_circle(this->position.x, this->position.y, 1.5, al_map_rgb(10, 200, 10));
}