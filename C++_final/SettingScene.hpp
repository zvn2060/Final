#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Image.hpp"
#include "Slider.hpp"
#include "TextButton.hpp"
#include "Fragment.hpp"


class SettingScene : public Engine::IScene{
private:
	Fragment* fragment;
	enum Tags{Audio, Language, Display};
	ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
	void ConstructUI();
	std::list<Engine::IObject*>* ConsLangTag();
	std::list<Engine::IObject*>* ConsDisplayTag();
	std::list <Engine::IObject*>* ConsAudioTag();
	void SetBGMValue( float value);
	void SetSFXValue(float value);
public:
	SettingScene() = default;
	void Initialize() override;
	void Onclick(int option);
	
};


#endif //SETTINGSCENE_HPP
