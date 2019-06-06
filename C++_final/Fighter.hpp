#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <memory>
#include <map>
#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Flag.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Animation.hpp"

using namespace std;

class Fighter {
private:
public:
	Flag flag;
	Engine::Point position;
	Engine::Point anchor;
	Animation animation;
	Animation animation_dot;
	Engine::Point velocity;
	int radius;
	const float velocity_normal = 280;
	const float velocity_slow_normal_ratio = 0.464;
	//const float velocity_slow_normal_ratio = 0.05;  // for testing bullet's collision shape accurately
	bool slow = false;

	Fighter() {
		this->position = Engine::Point(250, 600);
		this->anchor = Engine::Point(0.5, 0.5);
		this->velocity = Engine::Point(0, 0);
		this->radius = 2;
		//map<string, vector<string>> animationMap = {
		//  { "stand", vector<string>{"main/reimu-1.png", "main/reimu-2.png", "main/reimu-3.png", "main/reimu-4.png", "main/reimu-5.png", "main/reimu-6.png", "main/reimu-7.png", "main/reimu-8.png"} },
		//  { "move_left", vector<string>{"main/reimu-9.png", "main/reimu-10.png", "main/reimu-11.png", "main/reimu-12.png", "main/reimu-13.png", "main/reimu-14.png", "main/reimu-15.png", "main/reimu-16.png"} },
		//  { "move_right", vector<string>{"main/reimu-17.png", "main/reimu-18.png", "main/reimu-19.png", "main/reimu-20.png", "main/reimu-21.png", "main/reimu-22.png", "main/reimu-23.png", "main/reimu-24.png"} }
		//};
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
	~Fighter() = default;

	void reset() {
		this->position.x = 250;
		this->position.y = 600;
	}

	void update(float& deltaTime) {
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
		else {
			_update(deltaTime / 4);
			_update(deltaTime / 4);
			_update(deltaTime / 4);
			_update(deltaTime / 4);
		}
	}
	void _update(float deltaTime) {
		this->position.x += this->slow ? this->velocity.x * deltaTime * this->velocity_slow_normal_ratio : this->velocity.x * deltaTime;
		this->position.y += this->slow ? this->velocity.y * deltaTime * this->velocity_slow_normal_ratio : this->velocity.y * deltaTime;
		checkWorldBound();
	}

	void checkWorldBound() {
		if (this->position.x > 440) this->position.x = 440;
		if (this->position.x < 40) this->position.x = 40;
		if (this->position.y > 680) this->position.y = 680;
		if (this->position.y < 40) this->position.y = 40;
	}
	void draw() {
		this->animation.draw(this->position, this->anchor);
		this->animation_dot.draw(this->position, this->anchor);

		// testing for discriminating the difference between position & anchor(image)
		al_draw_filled_circle(this->position.x, this->position.y, 1.5, al_map_rgb(10, 10, 240));
	}
};

#endif