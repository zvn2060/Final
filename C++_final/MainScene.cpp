#include "MainScene.hpp"
#include <cmath>
#include <thread>
#include <future>
#include "Image.hpp"
#include "LayoutHelper.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"

float MainScene::fieldX1 = 60.0f;
float MainScene::fieldX2 = 540.0f;
float MainScene::fieldY1 = 40.0f;
float MainScene::fieldY2 = 680.0f;

void MainScene::Initialize() {
	AudioHelper::PlayBGM("BGM/battle-1.ogg");
    SetBackGround("background/play.png");
    fighter = new Fighter(this);
    bulletMgr = new BulletManager();
    selfBulletManager = new SelfBulletManager();
    enemyMgr = new EnemyManager();
    itemMgr = new ItemManager();
    flag = new Flag();
    count = 0;

    loadCompleted = false;
    bitmapConvertCompleted = false;
    // Multithread
    //future<void> task = async(launch::async, &MainScene::preload, this);
    thread preloadThread(&MainScene::preload, this);
    preloadThread.detach();

    // original single thread
    //preload();

    bulletMgr->init(this);
    enemyMgr->init(this);
    selfBulletManager->init(this);
    itemMgr->init(this);
	ConstructUI();

}

void MainScene::ConstructUI(){
	label_record = new Engine::Label("ｒｅｃｏｒｄ　" + to_string(record), "FOT-SkipStd-B.otf", 30, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.15), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(label_record);
	
	label_score = new Engine::Label("Ｓｃｏｒｅ　　" + to_string(score), "FOT-SkipStd-B.otf", 30,fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.20), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(label_score);
	
	life = new Engine::Label("Ｌｉｆｅ　", "FOT-SkipStd-B.otf", 30, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.30), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(life);
	
	bomb = new Engine::Label("Ｂｏｍｂ　", "FOT-SkipStd-B.otf", 30, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.35), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(bomb);
	
	label_fps = new Engine::Label("fps: " + to_string(fps), "FOT-SkipStd-B.otf", 20, MainScene::fieldX2 + 5, MainScene::fieldY2 - 20, 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(label_fps);
    dialogueText = new Engine::Label("", "FOT-SkipStd-B.otf", 20, 100, 500, 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
    AddNewObject(dialogueText);
    /*
    Engine::Image * ptr =new Engine::Image("battle/1.png", fieldX1 - 15 , 3543-1300 - 23, fieldX2 - fieldX1 + 30, 0, 0, 1);
	AddNewObject(ptr);
	Engine::LOG(Engine::DEBUG)<<ptr->GetBitmapHeight();
	Engine::LOG(Engine::DEBUG)<<Engine::LayoutHelper::AlignBottom();
    */
    ground = new Animation();
    ground->addCircular(fieldX1 - 15, 0 ,fieldX2-fieldX1 + 30, Engine::LayoutHelper::AlignBottom(), "battle/1.png");
}

void MainScene::preload() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            Engine::Resources::GetInstance().LoadBitmap("main/bullet" + to_string(i) + "-" + to_string(j) + ".png");
        }
    }
    Engine::Resources::GetInstance().LoadBitmap("main/item-0.png");
    Engine::Resources::GetInstance().LoadBitmap("main/item-1.png");
    Engine::Resources::GetInstance().LoadBitmap("main/item-2.png");
    Engine::Resources::GetInstance().LoadBitmap("main/item-3.png");
    Engine::Resources::GetInstance().LoadBitmap("main/item-4.png");
    Engine::Resources::GetInstance().LoadBitmap("main/item-5.png");
    Engine::Resources::GetInstance().LoadBitmap("main/yousei_1.png");
    loadCompleted = true;
}

void MainScene::OnKeyDown(int keycode) {
    if (keycode == ALLEGRO_KEY_LEFT) {
        flag->setFlag(FLAG_KEY_LEFT);
        fighter->animation.play("move_left", false, 4);
        fighter->velocity.x = -fighter->velocity_normal;
    }
    if (keycode == ALLEGRO_KEY_RIGHT) {
        flag->setFlag(FLAG_KEY_RIGHT);
        fighter->animation.play("move_right", false, 4);
        fighter->velocity.x = fighter->velocity_normal;
    }
    if (keycode == ALLEGRO_KEY_DOWN) {
        flag->setFlag(FLAG_KEY_DOWN);
        fighter->velocity.y = fighter->velocity_normal;
    }
    if (keycode == ALLEGRO_KEY_UP) {
        flag->setFlag(FLAG_KEY_UP);
        fighter->velocity.y = -fighter->velocity_normal;
    }
    if(keycode == ALLEGRO_KEY_Z){
    	flag->setFlag(FLAG_KEY_Z);
    }

    if (keycode == ALLEGRO_KEY_LSHIFT) {
        flag->setFlag(FLAG_KEY_SHIFT);
        fighter->animation_dot.play("show", false, 2);
        fighter->slow = true;
    }

    if (keycode == ALLEGRO_KEY_TAB) {
        testMode = !testMode;
    }
}

void MainScene::OnKeyUp(int keycode) {
    if (keycode == ALLEGRO_KEY_LEFT) {
        flag->clearFlag(FLAG_KEY_LEFT);
        fighter->animation.play("stand", true, 4);
        fighter->velocity.x = 0;
        if (flag->isFlagSet(FLAG_KEY_RIGHT)) {
            fighter->animation.play("move_right", false, 4);
            fighter->velocity.x = fighter->velocity_normal;
        }
    }
    if (keycode == ALLEGRO_KEY_RIGHT) {
        flag->clearFlag(FLAG_KEY_RIGHT);
        fighter->animation.play("stand", true, 4);
        fighter->velocity.x = 0;
        if (flag->isFlagSet(FLAG_KEY_LEFT)) {
            fighter->animation.play("move_left", false, 4);
            fighter->velocity.x = -fighter->velocity_normal;
        }
    }
    if (keycode == ALLEGRO_KEY_DOWN) {
        flag->clearFlag(FLAG_KEY_DOWN);
        fighter->velocity.y = 0;
        if (flag->isFlagSet(FLAG_KEY_UP)) {
            fighter->velocity.y = -fighter->velocity_normal;
        }
    }
    if (keycode == ALLEGRO_KEY_UP) {
        flag->clearFlag(FLAG_KEY_UP);
        fighter->velocity.y = 0;
        if (flag->isFlagSet(FLAG_KEY_DOWN)) {
            fighter->velocity.y = fighter->velocity_normal;
        }
    }
	if(keycode == ALLEGRO_KEY_Z){
		flag->clearFlag(FLAG_KEY_Z);
	}
    if (keycode == ALLEGRO_KEY_LSHIFT) {
        flag->clearFlag(FLAG_KEY_SHIFT);
        fighter->animation_dot.play("hidden");
        fighter->slow = false;
    }
}

void MainScene::Update(float deltaTime) {
	
    if (count % 20 == 0) {
        fps = 1.0 / deltaTime;
        label_fps->Text = "fps: " + to_string(fps).substr(0, 5);
    }
    fighter->update(deltaTime);

    // deal with preload
    if (!loadCompleted || !bitmapConvertCompleted) {
        if (loadCompleted && !bitmapConvertCompleted) {
            Engine::Resources::GetInstance().convertBitmap(&bitmapConvertCompleted);
        }
        return;
    }

    if (flag->isFlagSet(FLAG_KEY_Z) && count % 10 == 0) {
    	AudioHelper::PlayAudio("fire.ogg");
        float x = fighter->position.x;
        float y = fighter->position.y - 30;
        Engine::Point p(x, y);
        selfBulletManager->shot(p, 0, 0, 0, false, 0, 0, 0);
    }

    bulletMgr->update(deltaTime);
    selfBulletManager->update(deltaTime);
    enemyMgr->update(deltaTime);
    itemMgr->update(deltaTime);

    if (!flag->isFlagSet(FLAG_BOSS_STAGE)) {
        count++;
    }
}
void MainScene::notifyBossStage() {
    flag->setFlag(FLAG_BOSS_STAGE);
    flag->setFlag(FLAG_BOSS_MEET);
}
void MainScene::notifyBossMet() {
    flag->clearFlag(FLAG_BOSS_MEET);
    flag->setFlag(FLAG_BOSS_DIALOG);
}
void MainScene::notifyBossDialogEnd() {
    flag->clearFlag(FLAG_BOSS_DIALOG);
    flag->setFlag(FLAG_BOSS_FIGHT);
}
void MainScene::notifyBossBeated() {
    flag->clearFlag(FLAG_BOSS_FIGHT);
    flag->clearFlag(FLAG_BOSS_STAGE);
}
void MainScene::dialogue(const string& text) {
    this->dialogueText->Text = text;
}

// this is called only when enemy is beated by fighter bullet
// otherwise, enemy can vanish due to it's lifetime
void MainScene::notifyEnemyVanished(Enemy* enemy) {
    SetScore(100);
    itemMgr->shot(enemy->position, enemy->items);
}
void MainScene::notifyItemCaught(Item* item) {
    switch (item->type) {
    case 0:  // score
        SetScore(1);
        break;
    case 1:  // power
    case 2:  // POWER
    case 3:  // Live
    default:
        break;
    }
}

void MainScene::Draw() const {
    IScene::Draw();
    ground->circular();
    enemyMgr->draw();
    fighter->draw();
    bulletMgr->draw();
    selfBulletManager->draw();
    itemMgr->draw();
}

void MainScene::Terminate() {
    delete flag;
    delete fighter;
    delete bulletMgr;
    delete selfBulletManager;
    IScene::Terminate();
}

void MainScene::SetScore(int delta_score){
	label_score->Text = "Ｓｃｏｒｅ　" + to_string(score += delta_score);
}
