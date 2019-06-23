#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP

#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Flag.hpp"
#include "Fighter.hpp"
#include "BulletManager.hpp"
#include "EnemyManager.hpp"
#include "SelfBulletManager.hpp"
#include "ItemManager.hpp"


class MainScene : public Engine::IScene {
	friend Bullet;
	friend SelfBullet;
	friend Boss;
	friend EnemyManager;
private:
	int cnt = 0;

	Engine::Label* label_fps;
    float fps{};
    Engine::Label* label_record;
    int record{};
    Engine::Label* label_score;
    int score{};
    Engine::Label* label_life;
    Engine::Label* label_bomb;
    Engine::Label* label_power;
    Engine::Label* label_graze;
    Engine::Image* dialogueBG;
    Engine::Label* dialogueText;
    Engine::Label* bossTimeLimit;
    Engine::Image* img;
	
	Flag * flag;
	const int FLAG_KEY_LEFT = 0x1;
	const int FLAG_KEY_RIGHT = 0x2;
	const int FLAG_KEY_DOWN = 0x4;
	const int FLAG_KEY_UP = 0x8;
	const int FLAG_KEY_SHIFT = 0x10;
	const int FLAG_KEY_Z = 0x20;
	const int FLAG_BOSS_STAGE = 0x40;
	const int FLAG_BOSS_MEET = 0x80;
	const int FLAG_BOSS_DIALOG = 0x100;
	const int FLAG_BOSS_FIGHT = 0x200;
	
	void ConstructUI();
public:

    bool isPaused = false;
    bool fighterFail = false;
    int pauseOptionIndex = 0;
    Engine::Label* label_pauseOption[2];

    int count;
    Fighter* fighter;
    BulletManager* bulletMgr;
    SelfBulletManager* selfBulletManager;
    EnemyManager* enemyMgr;
    ItemManager* itemMgr;

    static float fieldX1;
    static float fieldX2;
    static float fieldY1;
    static float fieldY2;

    bool testMode = false;

    bool loadCompleted;
    bool bitmapConvertCompleted;
    void preload();
    explicit MainScene() = default;
    void Initialize() override;
    void OnKeyDown(int keycode) override;
    void OnKeyUp(int keycode) override;
    void Update(float deltaTime) override;
    void notifyBossStage();
    void notifyBossMet();
    void notifyBossDialogEnd();
    void notifyBossStageEnd();
    void dialogue(const string& text);
    void notifyEnemyVanished(Enemy* enemy);
    void notifyItemCaught(Item* item);
    void notifyFighterExplosion();

    void Draw() const override;
    void Terminate() override;
    void UpdateInfo();
};


#endif