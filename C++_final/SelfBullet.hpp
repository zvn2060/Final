#ifndef SELFBULLET_HPP
#define SELFBULLET_HPP

#include "Bullet.hpp"

class SelfBullet : public Bullet{
public:
	explicit SelfBullet(MainScene* mainScene);
	void update(float deltaTime) override;
};


#endif //SELFBULLET_HPP
