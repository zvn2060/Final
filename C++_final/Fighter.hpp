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

class MainScene;
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
    float radius;
    float grazeRadius;
    int graze;
    const float velocity_normal = 280;
    const float velocity_slow_normal_ratio = 0.464;
    //const float velocity_slow_normal_ratio = 0.05;  // for testing bullet's collision shape accurately
    bool slow = false;

    // link
    MainScene* mainScene;

    Fighter(MainScene*);
    ~Fighter() = default;

    void reset();

    void update(float deltaTime);
    void _update(float deltaTime);

    void checkWorldBound();
    void draw();
};

#endif