#include "Fighter.hpp"
#include "MainScene.hpp"

Fighter::Fighter() {
	this->position = Engine::Point(300, 600);
	this->anchor = Engine::Point(0.5, 0.5);
	this->velocity = Engine::Point(0, 0);
	this->radius = 2;
	this->grazeRadius = 10;
	this->graze = 0;
	this->animation = Animation();
	this->animation.add("stand", vector<string>{"main/reimu-1.png", "main/reimu-2.png", "main/reimu-3.png", "main/reimu-4.png", "main/reimu-5.png", "main/reimu-6.png", "main/reimu-7.png", "main/reimu-8.png"});
	this->animation.add("move_left", vector<string>{"main/reimu-9.png", "main/reimu-10.png", "main/reimu-11.png", "main/reimu-12.png", "main/reimu-13.png", "main/reimu-14.png", "main/reimu-15.png", "main/reimu-16.png"});
	this->animation.add("move_right", vector<string>{"main/reimu-17.png", "main/reimu-18.png", "main/reimu-19.png", "main/reimu-20.png", "main/reimu-21.png", "main/reimu-22.png", "main/reimu-23.png", "main/reimu-24.png"});
	this->animation.play("stand", true, 4);
	this->animation_dot = Animation();
	this->animation_dot.add("show", vector<string>{"main/slow_dot-1.png", "main/slow_dot-2.png", "main/slow_dot-3.png", "main/slow_dot-4.png"});
	this->animation_dot.add("hidden", vector<string>{"main/slow_dot-hidden.png"});
	this->animation_dot.play("hidden");

	this->reset();
}

void Fighter::reset() {
	this->position.x = 300;
	this->position.y = 600;
}

void Fighter::update(float deltaTime) {
	if (deltaTime < 3) {
		_update(deltaTime);
	}
	else {
		cout << "Fighter: update divided" << endl;
		_update(deltaTime / 2);
		_update(deltaTime / 2);
	}
}
void Fighter::_update(float deltaTime) {
	this->position.x += this->slow ? this->velocity.x * deltaTime * this->velocity_slow_normal_ratio : this->velocity.x * deltaTime;
	this->position.y += this->slow ? this->velocity.y * deltaTime * this->velocity_slow_normal_ratio : this->velocity.y * deltaTime;
	checkWorldBound();
}

void Fighter::checkWorldBound() {
	if (this->position.x < 60) this->position.x = 60;
	if (this->position.x > 540) this->position.x = 540;
	if (this->position.y < 40) this->position.y = 40;
	if (this->position.y > 680) this->position.y = 680;
}

void Fighter::draw() {
	this->animation.draw(this->position, this->anchor);
	this->animation_dot.draw(this->position, this->anchor);

	// testing for discriminating the difference between position & anchor(image)
	//al_draw_filled_circle(this->position.x, this->position.y, 1.5, al_map_rgb(10, 10, 240));
	al_draw_filled_circle(this->position.x, 40, 5, al_map_rgb(240, 240, 240));
	al_draw_filled_circle(this->position.x, 680, 5, al_map_rgb(240, 240, 240));
	al_draw_filled_circle(60, this->position.y, 5, al_map_rgb(240, 240, 240));
	al_draw_filled_circle(540, this->position.y, 5, al_map_rgb(240, 240, 240));
}