#include "SelfBullet.hpp"
#include "Util.hpp"
#include "Resources.hpp"
#include "MainScene.hpp"
#include "LOG.hpp"
#include <allegro5/allegro_primitives.h>

SelfBullet::SelfBullet(MainScene* mainScene):
fighter(mainScene->fighter),
mainScene(mainScene)
{}

void SelfBullet::setGenre(int genre, int color) {
	switch (genre) {
		case 0:
			bmp = Engine::Resources::GetInstance().GetBitmap("main/fighter_bullet-" + to_string(color) + ".png");
			shape = SHAPE_CIRCLE;
			radius = 4;
			break;
		default:
			string info = "shape of bullet " + to_string(genre) + "  is not supported yet ><";
			Engine::LOG(Engine::INFO) << info;
			// we will not re-assign it's bmp, and so it may still use the bullet0-0.png which is fetched by preload thread, and cause performance issue
			break;
	}
	// anchor should be (0.5, 0.5) to work with Polygon's separate-axis calculation
	anchor = Engine::Point(0.5, 0.5);
	bitmapWidth = al_get_bitmap_width(bmp.get());
	bitmapHeight = al_get_bitmap_height(bmp.get());
	
}

void SelfBullet::reset(float x, float y, vector<map<string, float>>& v, float baseAngle) {
	alive = true;
	position.x = x;
	position.y = y;
	if (v[0]["offset_r"]) {
		position.x += v[0]["offset_r"] * Math::cos(v[0]["offset_t"] - 90);
		position.y += v[0]["offset_r"] * -Math::sin(v[0]["offset_t"] - 90);
	}
	
	grazed = false;
	
	this->v = v;
	count = 0;
	changeMovingVector(0);
	
	angle += baseAngle;
}

bool SelfBullet::checkMovingVectorChange() {
	if (vIndex >= (int)v.size() - 1) {
		return false;
	}
	/*
	 * if (count >= v[vIndex + 1]["count"]) {
	 * return true;
	 * }
	 */
	
	return count >= v[vIndex + 1]["count"];
}
void SelfBullet::changeMovingVector(int index) {
	//std::cout << "r: " << speed << " ra: " << ra << std::endl;
	if (v[index]["r"] == 999) {  // inheritance current speed
		speed = speed;
	}
	else {
		speed = v[index]["r"];
	}
	
	if (v[index]["aiming"]) {
		angle = Math::angleBetween(position.x, position.y, fighter->position.x, fighter->position.y);
	}
	else if(v[index]["angle"] == 999) {  // inheritance current angle
		this->angle = angle;
	}
	else {
		angle = v[index]["angle"];
	}
	
	w = v[index]["w"];
	ra = v[index]["ra"];
	raa = v[index]["raa"];
	vIndex = index;
}

void SelfBullet::update(float deltaTime) {
	position.x += speed * Math::cos(angle - 90) * deltaTime;
	position.y += speed * (-Math::sin(angle - 90)) * deltaTime;
	speed += ra;
	ra += raa;
	angle += w;
	
	if (speed < 0) {
		speed = -speed;
		angle = -angle;
	}
	
	
	// collision check
	for(auto enemy : mainScene->enemyMgr->enemyArray) {
		if ( Math::distanceBetween( position, enemy->position ) < 80 ) {
			switch ( shape ) {
				case SHAPE_CIRCLE:
					if ( Collision::circleOverlap( position, radius, enemy->position, enemy->radius_fighterBullet) ) {
						enemy->hp -= 40;
						alive = false;
					}
					break;
				default:
					break;
			}
		}
	}
	
	if (Collision::outOfWorldBound(position)) {
		alive = false;
	}
	
	if (checkMovingVectorChange())
		changeMovingVector(vIndex + 1);
	
	count++;
}

void SelfBullet::draw() {
	al_draw_rotated_bitmap(bmp.get(),
						   anchor.x * bitmapWidth, anchor.y * bitmapHeight,
						   position.x, position.y,
						   Math::toRadian(-angle + 180), 0);
	// what the fuck is that allegro's rotating direction, which sees clockwise as positive angle, is different with cmath, which uses the coordinate view of real math
	
	
	if (mainScene->testMode) {
		if (shape == SHAPE_CIRCLE) {
			al_draw_circle(position.x, position.y, radius, al_map_rgb(49, 42, 252), 2);
			//al_draw_circle(position.x, position.y, radius + 1, al_map_rgb(252, 42, 42), 2);
		}
		else if (shape == SHAPE_POLYGON) {
			for (auto& it : polygon->vertex_real) {
				al_draw_filled_circle(it.x, it.y, 2, al_map_rgb(49, 42, 252));
			}
		}
	}
	
}
