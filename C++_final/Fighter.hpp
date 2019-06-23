#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <memory>
#include <map>
#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <nlohmann/json.hpp>
#include "Point.hpp"
#include "Resources.hpp"
#include "Animation.hpp"

class MainScene;
using namespace std;
using json = nlohmann::json;
class Fighter {
private:
	json Power{};
public:
    Engine::Point position = Engine::Point(300, 600);
    Engine::Point anchor = Engine::Point(0.5, 0.5);
    Animation animation;
    Animation animation_dot;
    
    int hp = 3;
    int power = 0;
    
    Engine::Point velocity = Engine::Point(0, 0);
    float radius = 2;
    float grazeRadius = 16;
    int graze = 0;
    const float velocity_normal = 280;
    const float velocity_slow_normal_ratio = 0.464;
    //const float velocity_slow_normal_ratio = 0.05;  // for testing bullet's collision shape accurately
    bool slow = false;

    bool invincible = false;
    int invincibleCount;
    void enterInvincible();

    // link
    MainScene* mainScene;

    explicit Fighter(MainScene*);
    ~Fighter() = default;

    void reset();

    void update(float deltaTime);
    void _update(float deltaTime);

    void checkWorldBound();
    void draw();
    void Shot(bool shift);
    int GetPowerLevel();
};

#endif