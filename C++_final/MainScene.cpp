#include "MainScene.hpp"
#include "Image.hpp"

float MainScene::fieldX1 = 60.0f;
float MainScene::fieldX2 = 540.0f;
float MainScene::fieldY1 = 40.0f;
float MainScene::fieldY2 = 680.0f;

void MainScene::Initialize() {
    SetBackGround("background/play.png");
	this->fighter = new Fighter();
	this->bulletMgr = new BulletManager();
	this->enemyMgr = new EnemyManager();
	this->flag = new Flag();
	this->count = 0;

	this->bulletMgr->init(this);
	this->enemyMgr->init(this);

}

void MainScene::OnKeyDown(int keycode) {
	if (keycode == ALLEGRO_KEY_LEFT) {
		this->flag->setFlag(this->FLAG_KEY_LEFT);
		this->fighter->animation.play("move_left", false, 4);
		this->fighter->velocity.x = -this->fighter->velocity_normal;
	}
	if (keycode == ALLEGRO_KEY_RIGHT) {
		this->flag->setFlag(this->FLAG_KEY_RIGHT);
		this->fighter->animation.play("move_right", false, 4);
		this->fighter->velocity.x = this->fighter->velocity_normal;
	}
	if (keycode == ALLEGRO_KEY_DOWN) {
		this->flag->setFlag(this->FLAG_KEY_DOWN);
		this->fighter->velocity.y = this->fighter->velocity_normal;
	}
	if (keycode == ALLEGRO_KEY_UP) {
		this->flag->setFlag(this->FLAG_KEY_UP);
		this->fighter->velocity.y = -this->fighter->velocity_normal;
	}

	if (keycode == ALLEGRO_KEY_LSHIFT) {
		this->flag->setFlag(this->FLAG_KEY_SHIFT);
		this->fighter->animation_dot.play("show", false, 2);
		this->fighter->slow = true;
		
		Engine::Point p(300, 150);
		this->bulletMgr->shot(p, 0, 0, 4, true, 0, 0, 0, 0);
	}
}

void MainScene::OnKeyUp(int keycode) {
	if (keycode == ALLEGRO_KEY_LEFT) {
		this->flag->clearFlag(this->FLAG_KEY_LEFT);
		this->fighter->animation.play("stand", true, 4);
		this->fighter->velocity.x = 0;
		if (this->flag->isFlagSet(this->FLAG_KEY_RIGHT)) {
			this->fighter->animation.play("move_right", false, 4);
			this->fighter->velocity.x = this->fighter->velocity_normal;
		}
	}
	if (keycode == ALLEGRO_KEY_RIGHT) {
		this->flag->clearFlag(this->FLAG_KEY_RIGHT);
		this->fighter->animation.play("stand", true, 4);
		this->fighter->velocity.x = 0;
		if (this->flag->isFlagSet(this->FLAG_KEY_LEFT)) {
			this->fighter->animation.play("move_left", false, 4);
			this->fighter->velocity.x = -this->fighter->velocity_normal;
		}
	}
	if (keycode == ALLEGRO_KEY_DOWN) {
		this->flag->clearFlag(this->FLAG_KEY_DOWN);
		this->fighter->velocity.y = 0;
		if (this->flag->isFlagSet(this->FLAG_KEY_UP)) {
			this->fighter->velocity.y = -this->fighter->velocity_normal;
		}
	}
	if (keycode == ALLEGRO_KEY_UP) {
		this->flag->clearFlag(this->FLAG_KEY_UP);
		this->fighter->velocity.y = 0;
		if (this->flag->isFlagSet(this->FLAG_KEY_DOWN)) {
			this->fighter->velocity.y = this->fighter->velocity_normal;
		}
	}

	if (keycode == ALLEGRO_KEY_LSHIFT) {
		this->flag->clearFlag(this->FLAG_KEY_SHIFT);
		this->fighter->animation_dot.play("hidden");
		this->fighter->slow = false;
	}
}

void MainScene::Update(float deltaTime) {
	this->fighter->update(deltaTime);
	this->bulletMgr->update(deltaTime);
	this->enemyMgr->update(deltaTime);
	this->count++;
}
void MainScene::Draw() const {
	IScene::Draw();
	this->enemyMgr->draw();
	this->fighter->draw();
	this->bulletMgr->draw();
}

void MainScene::Terminate() {
	delete this->flag;
	this->fighter->~Fighter();
	this->bulletMgr->~BulletManager();
	IScene::Terminate();
}