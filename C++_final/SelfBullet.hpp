#ifndef SELFBULLET_HPP
#define SELFBULLET_HPP
#include <string>
#include <vector>
#include "Point.hpp"
#include "Fighter.hpp"
#include "Polygon.hpp"
class SelfBullet{
private:
	static int rotate;
	enum{ SHAPE_CIRCLE, SHAPE_POLYGON };
	static int hitscore[9];
public:
	shared_ptr<ALLEGRO_BITMAP> bmp;
	int bitmapWidth{}; // only for anchor
	int bitmapHeight{}; // only for anchor
	Engine::Point position = Engine::Point(100, 100);
	Engine::Point anchor;
	int count = 0;
	float speed = 100; // Speed
	float angle = 0; // Angle
	float w = 0;     // Angular Acceleration
	float ra = 0;    // Acceleration
	float raa = 0;   // Jerk
	// float wa;
	int shape{};
	float radius{};
	Polygon* polygon = nullptr;
	bool alive = false;
	vector<map<string, float>> v;
	int vIndex = 0;
	bool grazed = false;
	
	// link
	Fighter* fighter;
	MainScene* mainScene;
	
	explicit SelfBullet(MainScene*);
	~SelfBullet() = default;
	void setGenre(int genre, int color);
	void reset(float x, float y, vector<map<string, float>>& v, float baseAngle);
	bool checkMovingVectorChange();
	void changeMovingVector(int index);
	void update(float deltaTime);
	void draw();

};


#endif //SELFBULLET_HPP
