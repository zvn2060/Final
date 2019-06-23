#include "Fighter.hpp"
#include "MainScene.hpp"
#include "AudioHelper.hpp"

Fighter::Fighter(MainScene* mainScene) {

    animation = Animation();
    animation.add("stand", vector<string>{"main/reimu-1.png", "main/reimu-2.png", "main/reimu-3.png", "main/reimu-4.png", "main/reimu-5.png", "main/reimu-6.png", "main/reimu-7.png", "main/reimu-8.png"});
    animation.add("move_left", vector<string>{"main/reimu-9.png", "main/reimu-10.png", "main/reimu-11.png", "main/reimu-12.png", "main/reimu-13.png", "main/reimu-14.png", "main/reimu-15.png", "main/reimu-16.png"});
    animation.add("move_right", vector<string>{"main/reimu-17.png", "main/reimu-18.png", "main/reimu-19.png", "main/reimu-20.png", "main/reimu-21.png", "main/reimu-22.png", "main/reimu-23.png", "main/reimu-24.png"});
    animation.play("stand", true, 4);
    animation_dot = Animation();
    animation_dot.add("show", vector<string>{"main/slow_dot-1.png", "main/slow_dot-2.png", "main/slow_dot-3.png", "main/slow_dot-4.png"});
    animation_dot.add("hidden", vector<string>{"main/slow_dot-hidden.png"});
    animation_dot.play("hidden");

    this->mainScene = mainScene;
    reset();
    this->hp = 3;
}

void Fighter::reset() {
	hp--;
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

    if (this->mainScene->testMode) {
        al_draw_circle(this->position.x, this->position.y, this->radius, al_map_rgb(49, 42, 252), 2);
        al_draw_circle(this->position.x, this->position.y, this->grazeRadius, al_map_rgb(42, 252, 49), 2);
        al_draw_filled_circle(this->position.x, 40, 5, al_map_rgb(240, 240, 240));
        al_draw_filled_circle(this->position.x, 680, 5, al_map_rgb(240, 240, 240));
        al_draw_filled_circle(60, this->position.y, 5, al_map_rgb(240, 240, 240));
        al_draw_filled_circle(540, this->position.y, 5, al_map_rgb(240, 240, 240));
    }
}

void Fighter::Shot(bool shift ){
	AudioHelper::PlayAudio("fire.ogg");
	
	if(!shift) {
	
	} else {
	
	}
}
