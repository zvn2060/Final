#include <memory>
#include <map>
#include <vector>
#include <string>
#include <allegro5/allegro.h>
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

  Fighter() {
	this->position = Engine::Point(250, 600);
	this->anchor = Engine::Point(0.5, 0.5);
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
  }
  ~Fighter() {

  }

  void init() {  // reset
	this->position.x = 250;
	this->position.y = 600;
  }

  void draw() {
	this->animation.draw(this->position, this->anchor);
	this->animation_dot.draw(this->position, this->anchor);
  }
  void update() {
	
  }
};