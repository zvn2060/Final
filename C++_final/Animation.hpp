#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include "Point.hpp"
#include <map>
#include <vector>
#include <string>

using namespace std;

class Animation {
private:
  vector<shared_ptr<ALLEGRO_BITMAP>> bmps;
  map<string, vector<shared_ptr<ALLEGRO_BITMAP>> > bmps_all;
  int frame;
  int count;
  int framerate;
  bool loop;
public:
  Animation() {
	this->bmps.push_back( Engine::Resources::GetInstance().GetBitmap("main/animation_not_loaded.png") );

	this->frame = 0;
	this->count = 0;
	this->framerate = 4;
	this->loop = true;
  }
  ~Animation() {

  }
  void play(std::string name, bool loop = false, int framerate = 4) {
	this->frame = 0;
	this->count = 0;
	this->bmps = this->bmps_all[name];
	this->loop = loop;
	this->framerate = framerate;
  }
  void draw(Engine::Point position, Engine::Point anchor) {
	al_draw_bitmap(this->bmps[this->frame].get(),
	  position.x - anchor.x * al_get_bitmap_width(bmps[this->frame].get()),
	  position.y - anchor.y * al_get_bitmap_height(bmps[this->frame].get()),
	  0);

	this->count = (this->count + 1) % this->framerate;
	if (this->count == 0) {
	  this->frame++;
	  if (this->frame >= this->bmps.size()) {
		if (this->loop) {
		  this->frame = 0;
		}
		else {
		  this->frame = this->bmps.size() - 1;
		}
	  }
	}

  }

  void add(string animationName, vector<string> files) {
	for (vector<string>::iterator file = files.begin(); file != files.end(); file++) {
	  this->bmps_all[animationName].push_back(Engine::Resources::GetInstance().GetBitmap(*file));
	}
  }
};

#endif