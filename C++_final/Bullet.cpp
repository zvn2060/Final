
#include "Bullet.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include "MainScene.hpp"
#include "LOG.hpp"
#include <allegro5/allegro_primitives.h>
#include "AudioHelper.hpp"


Bullet::Bullet(MainScene* mainScene):fighter(mainScene->fighter), mainScene(mainScene){
    //this->setGenre(0, 0);  // this will make main thread contends mutex with preload thread, so we will not do this initialization

    // anchor should be (0.5, 0.5) to work with Polygon's separate-axis calculation
    this->anchor = Engine::Point(0.5, 0.5);

    this->polygonDB[2] = new Polygon(this, {
        Engine::Point(-3, 4), Engine::Point(-3, -4), Engine::Point(3, -4), Engine::Point(3, 4)
        });
    this->polygonDB[3] = new Polygon(this, {
        Engine::Point(0, 3), Engine::Point(-2.5, 0), Engine::Point(-4, -4), Engine::Point(4, -4), Engine::Point(2.5, 0)
        });
    this->polygonDB[6] = new Polygon(this, {
        Engine::Point(0, 4), Engine::Point(-2, 2), Engine::Point(-2, -2), Engine::Point(0, -4), Engine::Point(2, -2), Engine::Point(2, 2)
        });
    this->polygonDB[7] = new Polygon(this, {
        Engine::Point(0, 6), Engine::Point(-2, 4), Engine::Point(-2, -5), Engine::Point(2, -5), Engine::Point(2, 4)
        });
    this->polygonDB[8] = new Polygon(this, {
        Engine::Point(0, 6), Engine::Point(-2.5, 0), Engine::Point(-2, -7), Engine::Point(2, -7), Engine::Point(2.5, 0)
        });
    this->polygonDB[9] = new Polygon(this, {
        Engine::Point(-0.5, 4), Engine::Point(-2, 2), Engine::Point(-2, -2.5), Engine::Point(-0.5, -5), Engine::Point(1, -2.5), Engine::Point(1, 2)
        });
}

void Bullet::setGenre(int genre, int color) {
    switch (genre) {
    case 0:
        this->shape = SHAPE_CIRCLE;
        this->radius = 2;
        break;
    case 1:
        this->shape = SHAPE_CIRCLE;
        this->radius = 4;
        break;
    case 4:
        this->shape = SHAPE_CIRCLE;
        this->radius = 5;
        break;
    case 5:
        this->shape = SHAPE_CIRCLE;
        this->radius = 9;
        break;
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        this->shape = SHAPE_POLYGON;
        this->radius = 10;
        this->polygon = this->polygonDB[genre];
        //this->polygon = new Polygon(this, {
        //    Engine::Point(-0.5, 4), Engine::Point(-2, 2), Engine::Point(-2, -2.5), Engine::Point(-0.5, -5), Engine::Point(1, -2.5), Engine::Point(1, 2)
        //    });
        break;
    default:
        string info = "shape of bullet " + to_string(genre) + "  is not supported yet ><";
        Engine::LOG(Engine::INFO) << info;
        // we will not re-assign it's bmp, and so it may still use the bullet0-0.png which is fetched by preload thread, and cause performance issue
        break;
    }
    string fileName = "main/bullet" + to_string(genre) + "-" + to_string(color) + ".png";
    this->bmp = Engine::Resources::GetInstance().GetBitmap(fileName);

    // approach 1: get dimension from Util's map, png should be loaded by Util first
    //this->bitmapWidth = Util::getPngWidth(fileName);
    //this->bitmapHeight = Util::getPngHeight(fileName);

    // approach 2: from allegro library directly
    this->bitmapWidth = al_get_bitmap_width(this->bmp.get());
    this->bitmapHeight = al_get_bitmap_height(this->bmp.get());
}

void Bullet::reset(float x, float y, vector<map<string, float>>& v, float baseAngle) {
    this->alive = true;
    this->position.x = x;
    this->position.y = y;
    if (v[0]["offset_r"]) {
        this->position.x += v[0]["offset_r"] * Math::cos(v[0]["offset_t"] - 90);
        this->position.y += v[0]["offset_r"] * -Math::sin(v[0]["offset_t"] - 90);
    }
    
    this->grazed = false;

    this->v = v;
    this->count = 0;

    this->angle = 0;
    this->changeMovingVector(0);

    this->angle += baseAngle;
}

bool Bullet::checkMovingVectorChange() {
    if (this->vIndex >= (int)this->v.size() - 1) {
        return false;
    }
    /*
     * if (this->count >= this->v[vIndex + 1]["count"]) {
     * return true;
     * }
     */

    return this->count >= this->v[vIndex + 1]["count"];
}
void Bullet::changeMovingVector(int index) {
    //std::cout << "r: " << this->speed << " ra: " << this->ra << std::endl;
    if (this->v[index]["r"] == 999) {  // inheritance current speed
        this->speed = this->speed;
    }
    else {
        this->speed = this->v[index]["r"];
    }

    if (this->v[index]["aiming"]) {
        this->angle = Math::angleBetween(this->position.x, this->position.y, this->fighter->position.x, this->fighter->position.y);
    }
    //else {
        if(this->v[index]["angle"] == 999) {  // inheritance current angle
            this->angle = this->angle;
        }
        else {
            this->angle += this->v[index]["angle"];
        }
    //}
    if (this->v[index]["random"]) {
        float randomRange = this->v[index]["random"];
        this->angle += Math::random(-randomRange, randomRange);
    }

    this->w = this->v[index]["w"];
    this->ra = this->v[index]["ra"];
    this->raa = this->v[index]["raa"];
    this->vIndex = index;
}

void Bullet::update(float deltaTime) {
    this->position.x += this->speed * Math::cos(this->angle - 90) * deltaTime;
    this->position.y += this->speed * (-Math::sin(this->angle - 90)) * deltaTime;
    this->speed += this->ra;
    this->ra += this->raa;
    this->angle += this->w;

    if (this->speed < 0) {
        speed = -speed;
        angle = -angle;
    }


    // collision check
    if (Math::distanceBetween(this->position, this->fighter->position) < 80) {
        switch (this->shape) {
        case SHAPE_CIRCLE:
            if (!this->grazed) {
                if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->grazeRadius)) {
                    this->fighter->graze++;
                    mainScene->score += 500;
                    this->grazed = true;
                    AudioHelper::PlayAudio("se_graze.wav");
                }
            }
            if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->radius) && !this->fighter->invincible) {
                this->mainScene->notifyFighterExplosion();
            }
            break;
        case SHAPE_POLYGON:
            if (!this->grazed) {
                if (Collision::circleOverlap(this->position, this->radius, this->fighter->position, this->fighter->grazeRadius)) {
                    this->fighter->graze++;
					mainScene->score += 500;
                    this->grazed = true;
                    AudioHelper::PlayAudio("se_graze.wav");
                }
            }
            if (Collision::overlap_circle_polygon(this->fighter->position, this->fighter->radius, this->polygon) && !this->fighter->invincible) {
                this->mainScene->notifyFighterExplosion();
            }
            break;
        default:
            break;
        }
    }

    if (Collision::outOfWorldBound(this->position)) {
        this->alive = false;
    }
    if (this->checkMovingVectorChange())
        this->changeMovingVector(this->vIndex + 1);

    this->count++;
}

void Bullet::draw() {
    al_draw_rotated_bitmap(bmp.get(),
        anchor.x * bitmapWidth, anchor.y * bitmapHeight,
        position.x, position.y,
        Math::toRadian(-angle + 180), 0);
    // what the fuck is that allegro's rotating direction, which sees clockwise as positive angle, is different with cmath, which uses the coordinate view of real math


    if (this->mainScene->testMode) {
        if (this->shape == SHAPE_CIRCLE) {
            al_draw_circle(this->position.x, this->position.y, this->radius, al_map_rgb(49, 42, 252), 2);
            //al_draw_circle(this->position.x, this->position.y, this->radius + 1, al_map_rgb(252, 42, 42), 2);
        }
        else if (this->shape == SHAPE_POLYGON) {
            for (auto& it : this->polygon->vertex_real) {
                al_draw_filled_circle(it.x, it.y, 2, al_map_rgb(49, 42, 252));
            }
            //al_draw_circle(this->position.x, this->position.y, this->radius, al_map_rgb(42, 252, 49), 2);
        }
    }

}