#ifndef BULLET_HPP
#define BULLET_HPP
#include <string>
#include "Point.hpp"
#include "Image.hpp"
#include "Fighter.hpp"

using namespace std;

class Bullet {
private:
	enum{ SHAPE_CIRCLE, SHAPE_POLYGON };
public:
	shared_ptr<ALLEGRO_BITMAP> bmp;
	int bitmapWidth;  // only for anchor
	int bitmapHeight; // only for anchor
	Engine::Point position;
	Engine::Point anchor;
	int count;
	float speed; // Speed
	float angle; // Angle
	float wa;    // Angular Acceleration
	float ra;    // Acceleration
	float raa;   // Jerk
	// float waa;
	int shape;
	float radius;
	bool alive;
	Fighter* fighter;
	vector<map<string, float>> v;
	int vIndex;

	Bullet(Fighter* fighter);
	~Bullet() {};
	//void setColor(string genre, int color);
	void setGenre(int genre, int color);
	void reset(float x, float y, vector<map<string, float>> v);
	void update(float deltaTime);
	void draw() const;

};

#endif