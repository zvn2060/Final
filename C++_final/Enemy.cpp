#include "Enemy.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include "MainScene.hpp"
#include <allegro5/allegro_primitives.h>

Enemy::Enemy(const string& sprite, float x, float y, float hp, vector<map<string, float>>& v, vector<map<string, float>>& s, MainScene* mainscene) {
    setSprite(sprite);
    position = Engine::Point(x + MainScene::fieldX1, y + MainScene::fieldY1);
    anchor = Engine::Point(0.5, 0.5);
    count = 0;
    this->v = v;
    this->s = s;
    sIndex = -1;
    changeMovingVector(0);
    radius_fighterBullet = bitmapWidth / 2;
    radius_fighter = 2;
    lifespan = 1000;
    this->hp = hp;
    mainScene = mainscene;
    enemyMgr = mainscene->enemyMgr;
}
void Enemy::setSprite(const string& fileName) {
    bmp = Engine::Resources::GetInstance().GetBitmap("main/" + fileName);
    bitmapWidth = al_get_bitmap_width(bmp.get());
    bitmapHeight = al_get_bitmap_height(bmp.get());
}

bool Enemy::checkMovingVectorChange() {
    if (vIndex >= (int)v.size() - 1) {
        return false;
    }
    return count >= v[vIndex + 1]["count"];
}
void Enemy::changeMovingVector(int index) {
    if (v[index]["r"] == 999) {  // inheritance current speed
        speed = speed;
    }
    else {
        speed = v[index]["r"];
    }

    if (v[index]["angle"] == 999) {  // inheritance current angle
        angle = angle;
    }
    else {
        angle = v[index]["angle"];
    }

    w = v[index]["w"];
    ra = v[index]["ra"];
    raa = v[index]["raa"];
    vIndex = index;
}

bool Enemy::checkShot() {
    if (sIndex >= (int)s.size() - 1) {
        return false;
    }
    return count >= s[sIndex + 1]["count"];
}

void Enemy::shot(int index) {
    map<string, float>& shot = s[index];
    mainScene->bulletMgr->shot(
        position, 
        shot["bullet"], 
        shot["genre"], 
        shot["color"], 
        shot["aiming"], 
        shot["random"],
        shot["offset_r"],
        shot["offset_t"]
    );
    sIndex = index;
}

void Enemy::update(float deltaTime) {
    position.x += speed * Math::cos(angle - 90) * deltaTime;
    position.y += speed * (-Math::sin(angle - 90)) * deltaTime;
    speed += ra;
    ra += raa;
    angle += w;

    if (speed < 0) {
        speed = -speed;
        angle = -angle;
    }

    if (Collision::circleOverlap(position, radius_fighter, mainScene->fighter->position, mainScene->fighter->radius)) {
        mainScene->fighter->reset();
    }
    
    if (checkMovingVectorChange()) {
        changeMovingVector(vIndex + 1);
    }
    if (checkShot()) {
        shot(sIndex + 1);
    }

    count++;
	
    if (count > lifespan ) {
        enemyMgr->enemyVanished.insert(this);
    }
}

void Enemy::draw() {
    al_draw_bitmap(bmp.get(), position.x - anchor.x * bitmapWidth, position.y - anchor.y * bitmapHeight, 0);

    if (mainScene->testMode) {
        al_draw_circle(position.x, position.y, radius_fighter, al_map_rgb(49, 42, 252), 2);
        al_draw_circle(position.x, position.y, radius_fighterBullet, al_map_rgb(252, 42, 42), 2);
    }
}