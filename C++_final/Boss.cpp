#include "Boss.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include "MainScene.hpp"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>


map<string, int> Boss::movingVectorTypeMap = {
    { "random", RANDOM },
    { "linear", LINEAR },
    { "loop", LOOP }
};

Boss::Boss(const string& sprite, float hp, int timeLimit, vector<map<string, float>>& v, vector<map<string, float>>& s, vector<string>& dialogueA, vector<string>dialogueB, MainScene* mainScene)
    : Enemy(sprite, (mainScene->fieldX2 - mainScene->fieldX1) / 2, -100, hp, v, s, mainScene ){
    this->timeLimit = timeLimit;
    this->dialogueA = dialogueA;
    this->dialogueB = dialogueB;
    this->stopPoint = 99999;
    this->typeForEnemyManager_testing = 1;
}

void Boss::changeMovingVector(int index){
    if (this->v[index]["type"] == Boss::RANDOM) {
        float x = Math::random(this->v[index]["x1"], this->v[index]["x2"]);
        float y = Math::random(this->v[index]["y1"], this->v[index]["y2"]);
        Engine::Point p(x, y);
        this->speed = Math::distanceBetween(p, this->position) / (this->v[index]["interval"] / 60);
        this->angle = Math::angleBetween(this->position.x, this->position.y, x, y);
        this->stopPoint = this->v[index]["count"] + this->v[index]["interval"];
    }
    else if (this->v[index]["type"] == Boss::LINEAR) {
        float x = this->v[index]["x1"];
        float y = this->v[index]["y1"];
        Engine::Point p(x, y);
        this->speed = Math::distanceBetween(p, this->position) / (this->v[index]["interval"] / 60);
        this->angle = Math::angleBetween(this->position.x, this->position.y, x, y);
        this->stopPoint = this->v[index]["count"] + this->v[index]["interval"];
    }
    else if (this->v[index]["type"] == Boss::LOOP) {
        int toIndex = this->v[index]["index"];
        this->count = this->v[toIndex]["count"];
        this->changeMovingVector(toIndex);
        this->sIndex = -1;
        return;
    }
    this->vIndex = index;
}

void Boss::update(float deltaTime) {
    if (this->mainScene->flag->isFlagSet(mainScene->FLAG_BOSS_DIALOG) || this->mainScene->flag->isFlagSet(mainScene->FLAG_BOSS_MEET)) {
        if (this->mainScene->flag->isFlagSet(mainScene->FLAG_BOSS_MEET)) {
            this->position.y += 100 * deltaTime;
            if ((200 - this->position.y) <= 0) {
                this->mainScene->notifyBossMet();
                this->dialogueIndex = 0;
                this->mainScene->dialogue(this->dialogueA[dialogueIndex]);
            }
        }
        else {
            if (this->mainScene->flag->isFlagSet(mainScene->FLAG_KEY_DOWN)) {
                if (this->dialogueSkipCount == 0) {
                    this->dialogueIndex++;
                    this->dialogueSkipCount = 0;
                    if (this->dialogueIndex >= this->dialogueA.size()) {
                        this->mainScene->dialogue("");
                        this->mainScene->notifyBossDialogEnd();
                        this->changeMovingVector(0);
                    }
                    else {
                        this->mainScene->dialogue(this->dialogueA[dialogueIndex]);
                    }
                }
                this->dialogueSkipCount = (this->dialogueSkipCount + 1) % 16;
            }
            else {
                this->dialogueSkipCount = 0;
            }
        }
        return;
    }

    // update position, speed
    this->position.x += this->speed * Math::cos(this->angle - 90) * deltaTime;
    this->position.y += this->speed * (-Math::sin(this->angle - 90)) * deltaTime;
    this->speed += this->ra;
    this->ra += this->raa;
    if (this->speed < 0) {
        speed = -speed;
        angle = -angle;
    }

    // check collision
    if (Collision::circleOverlap(this->position, this->radius_fighter, this->mainScene->fighter->position, this->mainScene->fighter->radius)) {
        this->mainScene->fighter->reset();
    }
    if (this->checkMovingVectorChange()) {
        this->changeMovingVector(this->vIndex + 1);
    }
    if (this->checkShot()) {
        this->shot(this->sIndex + 1);
    }

    // count
    this->count++;
    this->time += 3;
    if (this->count >= this->stopPoint) {
        this->speed = 0;
        this->ra = 0;
        this->raa = 0;
    }
    if (this->time > this->timeLimit) {
        this->enemyMgr->enemyVanished.insert(this);

        // prepare to advance to next boss stage
    }

}

void Boss::draw() {
    al_draw_bitmap(bmp.get(), position.x - anchor.x * bitmapWidth, position.y - anchor.y * bitmapHeight, 0);

    if (this->mainScene->testMode) {
        al_draw_circle(this->position.x, this->position.y, this->radius_fighter, al_map_rgb(49, 42, 252), 2);
        al_draw_circle(this->position.x, this->position.y, this->radius_fighterBullet, al_map_rgb(252, 42, 42), 2);
    }
}