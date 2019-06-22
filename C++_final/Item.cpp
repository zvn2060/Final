#include "Item.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include "MainScene.hpp"
#include "LOG.hpp"
#include <allegro5/allegro_primitives.h>


Item::Item(MainScene* mainScene) :fighter(mainScene->fighter), mainScene(mainScene) {
    this->anchor = Engine::Point(0.5, 0.5);

}

void Item::setGenre(int genre) {
    this->bmp = Engine::Resources::GetInstance().GetBitmap("main/item-" + to_string(genre) + ".png");
    this->bitmapWidth = al_get_bitmap_width(bmp.get());
    this->bitmapHeight = al_get_bitmap_height(bmp.get());
    this->radius = this->bitmapWidth / 2;
    this->type = genre;

}

void Item::reset(float x, float y) {
    this->alive = true;
    this->position.x = x;
    this->position.y = y;
    this->speed = -200;
    this->count = 0;
    this->autoCollect = false;
}


void Item::update(float deltaTime) {
    if (!this->autoCollect) {
        this->position.y += this->speed * deltaTime;
        this->speed += this->ra;
        if (this->speed >= this->maxSpeed) {
            this->speed = this->maxSpeed;
        }
        if (this->fighter->position.y < 200) {
            this->autoCollect = true;
        }
    }
    else {
        this->angle = Math::angleBetween(this->position.x, this->position.y, this->fighter->position.x, this->fighter->position.y);
        this->position.x += 600 * Math::cos(this->angle - 90) * deltaTime;
        this->position.y += 600 * (-Math::sin(this->angle - 90)) * deltaTime;
    }


    // collision check
    if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->grazeRadius)) {
        // catch item
        this->mainScene->notifyItemCaught(this);
        this->alive = false;
    }

    this->count++;
    if (this->count > 300) {
        this->alive = false;
    }
}

void Item::draw() {
    al_draw_bitmap(bmp.get(), position.x - anchor.x * bitmapWidth, position.y - anchor.y * bitmapHeight, 0);

    if (this->mainScene->testMode) {
        al_draw_circle(this->position.x, this->position.y, this->radius, al_map_rgb(49, 42, 252), 2);
    }

}