#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>
#include "Point.hpp"
#include "Fighter.hpp"

using namespace std;

class Item {
private:
public:
    shared_ptr<ALLEGRO_BITMAP> bmp;
    int bitmapWidth{}; // only for anchor
    int bitmapHeight{}; // only for anchor
    Engine::Point position = Engine::Point(100, 100);
    Engine::Point anchor;
    int count = 0;
    float speed; // Speed
    float ra = 5;    // Acceleration
    float angle = 0;
    float maxSpeed = 400;
    float radius{};
    bool alive = false;
    bool autoCollect = false;
    int type;

    // link
    Fighter* fighter;
    MainScene* mainScene;

    explicit Item(MainScene*);
    ~Item() = default;
    void setGenre(int genre);
    void reset(float x, float y);
    void update(float deltaTime);
    void draw();
};

#endif