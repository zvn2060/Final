#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Image.hpp"
#include "Slider.hpp"

class SettingScene : public Engine::IScene{
public:
	SettingScene() = default;
	void Initialize() override;
};


#endif //SETTINGSCENE_HPP
