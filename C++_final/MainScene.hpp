#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP

#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Flag.hpp"
#include "Fighter.hpp"
#include "Bullet.hpp"
#include "BulletManager.hpp"

class MainScene : public Engine::IScene {
private:
	ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
	Flag* flag;
	const int FLAG_KEY_LEFT    = 0x1;
	const int FLAG_KEY_RIGHT   = 0x2;
	const int FLAG_KEY_DOWN    = 0x4;
	const int FLAG_KEY_UP      = 0x8;
	const int FLAG_KEY_SHIFT   = 0x10;

	int count;
public:

	Fighter* fighter;
	BulletManager* bulletMgr;

	explicit MainScene() = default;
	void Initialize() override;

	void OnKeyDown(int keycode) override;
	void OnKeyUp(int keycode) override;

	void Update(float deltaTime) override;

	void Draw() const override;

	void Terminate() override;

};

#endif