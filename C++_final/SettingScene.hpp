#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Image.hpp"
#include "Slider.hpp"
#include "Flag.hpp"


class SettingScene : public Engine::IScene{
private:
	ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
	static const int btnNum = 4;
	Engine::Label* btn[btnNum];
	Flag* flag;
	const int FLAG_KEY_DOWN = 0x1;
	const int FLAG_KEY_UP = 0x2;
	int index;
	
	int count;
public:
	SettingScene() = default;
	void Initialize() override;
	void OnKeyDown(int keycode) override;
	void OnKeyUp(int keycode) override;
	void Update(float deltaTime) override;
	void Terminate() override {
		delete this->flag;
		IScene::Terminate();
	}
};


#endif //SETTINGSCENE_HPP
