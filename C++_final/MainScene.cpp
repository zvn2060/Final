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
    pauseOptionIndex = 0;
    isPaused = false;

	ConstructUI();

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
	
}

void MainScene::ConstructUI(){
	int font_size = 26;
	/*
	label_record = new Engine::Label(to_string(record), "FOT-SkipStd-B.otf", font_size, fieldX2 + 300, Engine::LayoutHelper::VerticalRatio(0.15), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(new Engine::Label("Ｒｅｃｏｒｄ", "FOT-SkipStd-B.otf", font_size, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.15), 0xf0, 0xf0, 0xf0, 0xff, 0, 0));
	AddNewObject(label_record);
	*/
	
	label_score = new Engine::Label(to_string(score), "FOT-SkipStd-B.otf", font_size,fieldX2 + 300, Engine::LayoutHelper::VerticalRatio(0.20), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(new Engine::Label("Ｓｃｏｒｅ", "FOT-SkipStd-B.otf", font_size,fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.20), 0xf0, 0xf0, 0xf0, 0xff, 0, 0));
	AddNewObject(label_score);
	
	label_life = new Engine::Label(to_string(fighter->hp), "FOT-SkipStd-B.otf", font_size, fieldX2 + 300, Engine::LayoutHelper::VerticalRatio(0.30), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(new Engine::Label("Ｌｉｆｅ", "FOT-SkipStd-B.otf", font_size, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.30), 0xf0, 0xf0, 0xf0, 0xff, 0, 0));
	AddNewObject(label_life);
	
	//label_bomb = new Engine::Label("Ｂｏｍｂ　", "FOT-SkipStd-B.otf", 30, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.35), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(new Engine::Label("Ｂｏｍｂ", "FOT-SkipStd-B.otf", font_size, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.35), 0xf0, 0xf0, 0xf0, 0xff, 0, 0));
	//AddNewObject(label_bomb);
	
	label_power = new Engine::Label(to_string(fighter->power) ,"FOT-SkipStd-B.otf", font_size, fieldX2 + 300, Engine::LayoutHelper::VerticalRatio(0.45), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(label_power);
	AddNewObject(new Engine::Label("Ｐｏｗｅｒ" ,"FOT-SkipStd-B.otf", font_size, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.45), 0xf0, 0xf0, 0xf0, 0xff, 0, 0));
	
    label_graze = new Engine::Label(to_string(fighter->graze) ,"FOT-SkipStd-B.otf", font_size, fieldX2 + 300, Engine::LayoutHelper::VerticalRatio(0.50), 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
    AddNewObject(label_graze);
	AddNewObject(new Engine::Label("Ｇｒａｚｅ", "FOT-SkipStd-B.otf", font_size, fieldX2 + 100, Engine::LayoutHelper::VerticalRatio(0.50), 0xf0, 0xf0, 0xf0, 0xff, 0, 0));
    
    label_fps = new Engine::Label("fps: " + to_string(fps), "FOT-SkipStd-B.otf", 20, MainScene::fieldX2 + 5, MainScene::fieldY2 - 20, 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
	AddNewObject(label_fps);
 
	dialogueText = new Engine::Label("", "FOT-SkipStd-B.otf", 20, 100, 500, 0xf0, 0xf0, 0xf0, 0xff, 0, 0);
    AddNewObject(dialogueText);

    label_pauseOption[0] = new Engine::Label("continue", "FOT-SkipStd-B.otf", 22, (MainScene::fieldX1 + fieldX2) / 2, 250, 0xf0, 0xf0, 0xf0, 0xff, 0.5, 0);
    label_pauseOption[1] = new Engine::Label("title", "FOT-SkipStd-B.otf", 22, (MainScene::fieldX1 + fieldX2) / 2, 300, 0xf0, 0xf0, 0xf0, 0x7f, 0.5, 0);
    
    img = new Engine::Image("battle/1.png", MainScene::fieldX1, MainScene::fieldY1, fieldX2 - fieldX1);
    img->Position.y = -1 * img->GetBitmapHeight() + Engine::LayoutHelper::AlignBottom() * 3.3;
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
    Engine::Resources::GetInstance().LoadBitmap("main/yousei_2.png");
    Engine::Resources::GetInstance().LoadBitmap("main/yousei_3.png");
    Engine::Resources::GetInstance().LoadBitmap("main/yousei_4.png");
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
        if (isPaused) {
            label_pauseOption[pauseOptionIndex]->ChangeColor(0xf0, 0xf0, 0xf0, 0x7f);
            pauseOptionIndex = (pauseOptionIndex + 1) % 2;
            label_pauseOption[pauseOptionIndex]->ChangeColor(0xf0, 0xf0, 0xf0, 0xff);
        }
        flag->setFlag(FLAG_KEY_DOWN);
        fighter->velocity.y = fighter->velocity_normal;
    }
    if (keycode == ALLEGRO_KEY_UP) {
        if (isPaused) {
            label_pauseOption[pauseOptionIndex]->ChangeColor(0xf0, 0xf0, 0xf0, 0x7f);
            pauseOptionIndex = (pauseOptionIndex - 1) % 2;
            if (pauseOptionIndex < 0) {
                pauseOptionIndex += 2;
            }
            label_pauseOption[pauseOptionIndex]->ChangeColor(0xf0, 0xf0, 0xf0, 0xff);
        }
        flag->setFlag(FLAG_KEY_UP);
        fighter->velocity.y = -fighter->velocity_normal;
    }
    if(keycode == ALLEGRO_KEY_Z){
        if (isPaused) {
            if (pauseOptionIndex == 0) {
                isPaused = false;
            }
            else if (pauseOptionIndex == 1) {
                Engine::GameEngine::GetInstance().ChangeScene("title");
            }
        }
    	flag->setFlag(FLAG_KEY_Z);
    }

    if (keycode == ALLEGRO_KEY_LSHIFT) {
        flag->setFlag(FLAG_KEY_SHIFT);
        fighter->animation_dot.play("show", false, 2);
        fighter->slow = true;
    }

    if (keycode == ALLEGRO_KEY_ESCAPE) {
        isPaused = !isPaused;
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
    if (isPaused) return;

	UpdateInfo();
    if (count % 20 == 0) {
        fps = 1.0 / deltaTime;
        label_fps->Text = "fps: " + to_string(fps).substr(0, 5);

        if (flag->isFlagSet(FLAG_BOSS_STAGE)) {
            count -= 20;  // -=
        }
    }
    fighter->update(deltaTime);

    // deal with preload
    if (!loadCompleted || !bitmapConvertCompleted) {
        if (loadCompleted && !bitmapConvertCompleted) {
            Engine::Resources::GetInstance().convertBitmap(&bitmapConvertCompleted);
        }
        return;
    }

    if (flag->isFlagSet(FLAG_KEY_Z) && count % 5 == 0) {
    	fighter->Shot(flag->isFlagSet(FLAG_KEY_SHIFT));
    }

    bulletMgr->update(deltaTime);
    selfBulletManager->update(deltaTime);
    enemyMgr->update(deltaTime);
    itemMgr->update(deltaTime);

    //if (!flag->isFlagSet(FLAG_BOSS_STAGE)) {
        count++;
    //}
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
void MainScene::notifyBossStageEnd() {
    flag->clearFlag(FLAG_BOSS_FIGHT);
    flag->clearFlag(FLAG_BOSS_STAGE);
}
void MainScene::dialogue(const string& text) {
    this->dialogueText->Text = text;
}

// this is called only when enemy is beated by fighter bullet
// otherwise, enemy can vanish due to it's lifetime
void MainScene::notifyEnemyVanished(Enemy* enemy) {
    score += static_cast<int>(enemy->maxhp);
    itemMgr->shot(enemy->position, enemy->items);
    AudioHelper::PlayAudio("se_enemy_vanish.wav");
}
void MainScene::notifyItemCaught(Item* item) {
    switch (item->type) {
    case 0:  // score
        score += static_cast<int>(pow(fieldY2 - fighter->position.y, 1.5));
        AudioHelper::PlayAudio("se_item00.wav");
        break;
    case 1:  // power
    	if(fighter->power++ > 128){
    		fighter->power = 128;
    		score += 10000;
            AudioHelper::PlayAudio("se_powerup.wav");
    	}else{
    		score += 10;
    	}
		break;
    case 2:  // POWER
    	if( (fighter->power += 8) > 128){
			fighter->power = 128;
			score += 40000;
            AudioHelper::PlayAudio("se_powerup.wav");
		}else{
			score += 10;
		}
		break;
    case 3:  // Live
    	if( (fighter->hp++) > 9){
    		fighter->hp = 9;
    	}
        AudioHelper::PlayAudio("se_powerup.wav");
    	break;
    default:
        break;
    }
}

void MainScene::notifyFighterExplosion() {
    this->fighter->reset();
    AudioHelper::PlayAudio("se_pldead00.wav");
}

void MainScene::Draw() const {
    IScene::Draw();
    img->Draw();
    img->Position.y += 3;
    if(img->Position.y >= 0){
		img->Position.y = -1 * img->GetBitmapHeight() + Engine::LayoutHelper::AlignBottom() * 3.3;
    }
    enemyMgr->draw();
    fighter->draw();
    bulletMgr->draw();
    selfBulletManager->draw();
    itemMgr->draw();

    dialogueText->Draw();
    if (isPaused) {
        label_pauseOption[0]->Draw();
        label_pauseOption[1]->Draw();
    }
}

void MainScene::Terminate() {
    delete flag;
    delete fighter;
    delete bulletMgr;
    delete selfBulletManager;
    delete img;
    IScene::Terminate();
}


void MainScene::UpdateInfo(){
	label_score->Text = to_string(score);
	label_score->Text = string( 8 - label_score->Text.size(), '0') + label_score->Text;
	
	label_life->Text = to_string(fighter->hp);
	label_graze->Text = to_string(fighter->graze);
	
	label_power->Text = to_string(fighter->power);
	
}
