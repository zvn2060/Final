#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Image.hpp"
#include "Slider.hpp"
#include "TextButton.hpp"
#include "Fragment.hpp"
#include "OptionSwitch.hpp"


class SettingScene : public Engine::IScene{
private:
    int halfh{};
    int halfw{};
	Fragment* fragment{};
	enum Tags{Audio, Language, Display};
	ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
	void ConstructUI();
	std::list<Engine::IObject*>* ConsLangTag();
	std::list<Engine::IObject*>* ConsDisplayTag();
	std::list <Engine::IObject*>* ConsAudioTag();
	Engine::OptionSwitch* btn;
	void SetBGMValue( float value);
	void SetSFXValue(float value);
public:
	SettingScene() = default;
	void Initialize() override;
	void SlideOnclick(int unit);
	void OnclickOption(int unit);
};


#endif //SETTINGSCENE_HPP
