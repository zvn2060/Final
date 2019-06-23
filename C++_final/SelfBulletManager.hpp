#ifndef SELFBULLETMANAGER_HPP
#define SELFBULLETMANAGER_HPP

#include "SelfBullet.hpp"
class MainScene;

class SelfBulletManager{
private:
	vector<SelfBullet> bulletPool;
	vector<SelfBullet>::iterator firstDead;
	int bulletPoolSize{};
	vector< vector< vector< map<string, float> > > > bulletData;  // second vector's size = bullet quantity
	
	// link
	MainScene* mainScene{};
public:
	SelfBulletManager() = default;
	~SelfBulletManager() = default;
	void init(MainScene* main);
	
	SelfBullet* getFirstDead();
	void next();
	
	void shot(Engine::Point& p, int bullet, int genre, int color, float angle, float offset_x, float offset_y);
	
	void update(float deltaTime);
	void _update(float deltaTime);
	void draw();
	
};
#endif //SELFBULLETMANAGER_HPP
