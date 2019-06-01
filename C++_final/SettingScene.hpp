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
	void ConstructUI();
public:
	SettingScene() = default;
	void Initialize() override;
	void Onclick(int option);
};


#endif //SETTINGSCENE_HPP
