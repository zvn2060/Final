#include "MainScene.hpp"
#include <cmath>
#include <thread>
#include <future>
#include "Image.hpp"

float MainScene::fieldX1 = 60.0f;
float MainScene::fieldX2 = 540.0f;
float MainScene::fieldY1 = 40.0f;
float MainScene::fieldY2 = 680.0f;

void MainScene::Initialize() {

    IScene::SetBackGround("background/play.png");
    this->fighter = new Fighter(this);
    this->bulletMgr = new BulletManager();
    this->enemyMgr = new EnemyManager();
    this->flag = new Flag();
    this->count = 0;


    this->loadCompleted = false;
    this->bitmapConvertCompleted = false;
    // Multithread
    //future<void> task = async(launch::async, &MainScene::preload, this);
    //thread preloadThread(&MainScene::preload, this);
    //preloadThread.detach();

    // original single thread
    preload();

    this->bulletMgr->init(this);
    this->enemyMgr->init(this);

    label_fps = new Engine::Label("fps: 0", "FOT-SkipStd-B.otf", 20, this->fieldX2 + 5, this->fieldY2 - 20, 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
    AddNewObject(label_fps);

}
void MainScene::preload() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            Engine::Resources::GetInstance().LoadBitmap("main/bullet" + to_string(i) + "-" + to_string(j) + ".png");
        }
    }
    Engine::Resources::GetInstance().LoadBitmap("main/yousei_1.png");
    this->loadCompleted = true;
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
        
        if (!this->testSeparateAcis) {
            Engine::Point p(300, 300);
            this->bulletMgr->shot(p, 3, 2, 0, false, 0, 0, 0);
            p.y = 350;
            this->bulletMgr->shot(p, 3, 3, 0, false, 0, 0, 0);
            //this->testSeparateAcis = true;
        }
        else {

        }

    }

    if (keycode == ALLEGRO_KEY_TAB) {
        this->testMode = !this->testMode;
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
    if (this->count % 20 == 0) {
        //cout << deltaTime << endl;
        string s = "fps: " + to_string(1.0 / deltaTime);
        label_fps->Text = s.substr(0, 10);
    }
    this->fighter->update(deltaTime);

    // deal with preload
    if (!this->loadCompleted || !this->bitmapConvertCompleted) {
        if (this->loadCompleted && !this->bitmapConvertCompleted) {
            Engine::Resources::GetInstance().convertBitmap(&this->bitmapConvertCompleted);
        }
        return;
    }

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