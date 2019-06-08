#ifndef BULLET_HPP
#define BULLET_HPP
#include <string>
#include <vector>
#include "Point.hpp"
#include "Fighter.hpp"

class Fighter;
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
	float w;     // Angular Acceleration
	float ra;    // Acceleration
	float raa;   // Jerk
	// float wa;
	int shape;
	float radius;
	bool alive;
	Fighter* fighter;
	vector<map<string, float>> v;
	int vIndex;
	bool grazed;

	explicit Bullet(Fighter* fighter);
	~Bullet() = default;;
	void setGenre(int genre, int color);
	void reset(float x, float y, vector<map<string, float>>& v, float baseAngle);
	bool checkMovingVectorChange();
	void changeMovingVector(int index);
	void update(float deltaTime);
	void draw();

};

#endif