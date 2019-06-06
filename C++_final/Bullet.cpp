
#include "Bullet.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include <allegro5/allegro_primitives.h>

Bullet::Bullet(Fighter* fighter) {
	this->setGenre(1, 6);  // TODO: this is hard coded
	this->position = Engine::Point(100, 100);
	this->count = 0;
	this->speed = 100;
	this->angle = 0;
	this->wa = 0;
	this->ra = 0;
	this->raa = 0;
	this->alive = false;
	this->fighter = fighter;
	this->vIndex = 0;
}

void Bullet::setGenre(int genre, int color) {
	switch (genre) {
	case 0:
		//this->setColor("main/bullet0", color);
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

void Bullet::reset(float x, float y, vector<map<string, float>> v) {
	this->alive = true;
	this->position.x = x;
	this->position.y = y;

	this->v = v;
	this->vIndex = 0;
	this->count = 0;
	this->speed = v[0]["r"];
	this->angle = v[0]["angle"];
	this->wa = v[0]["wa"];
	this->ra = v[0]["ra"];
	this->raa = v[0]["raa"];
}

bool Bullet::checkMovingVectorChange() {
	if (this->vIndex >= this->v.size() - 1) {
		return false;
	}
	if (this->count >= this->v[vIndex + 1]["count"]) {
		return true;
	}
	return false;
}
void Bullet::changeMovingVector(int index) {
	//std::cout << "r: " << this->speed << " ra: " << this->ra << std::endl;

	this->speed = this->v[index]["r"];
	this->angle = this->v[index]["angle"];
	this->wa = this->v[index]["wa"];
	this->ra = this->v[index]["ra"];
	this->raa = this->v[index]["raa"];
	this->vIndex = index;
}

void Bullet::update(float deltaTime) {
	this->position.x += this->speed * Math::cos(this->angle - 90) * deltaTime;
	this->position.y += this->speed * (-Math::sin(this->angle - 90)) * deltaTime;
	this->speed += this->ra;
	this->ra += this->raa;
	this->angle += this->wa;

	// TODO bullet is killed once out of world bound
	switch (this->shape) {
	case SHAPE_CIRCLE:
		if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->radius)) {
			this->fighter->reset();
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

void Bullet::draw() const {
	al_draw_rotated_bitmap(bmp.get(),
		anchor.x * bitmapWidth, anchor.y * bitmapHeight,
		position.x, position.y,
		Math::toRadian(-angle + 180), 0);
	// what the fuck is that allegro's rotating direction, which sees clockwise as positive angle, is different with cmath, which uses the coordinate view of real math

	// testing for discriminating the difference between position & anchor(image)
	al_draw_filled_circle(this->position.x, this->position.y, 1.5, al_map_rgb(10, 200, 10));
}