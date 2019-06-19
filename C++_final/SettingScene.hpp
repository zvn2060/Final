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
    Fragment* fragment{};
    enum Tags{Audio, Language, Display};
    void ConstructUI();
    std::list<Engine::IObject*>* ConsLangTag();
    std::list<Engine::IObject*>* ConsDisplayTag();
    std::list <Engine::IObject*>* ConsAudioTag();
	Slider* BGMSlider, *SFXSlider;
    Engine::OptionSwitch* LangSwitch;
    Engine::OptionSwitch* FullScreenSwitch;
    void SetBGMValue( float value);
    void SetSFXValue(float value);
    void ControllUnits();
public:
    SettingScene() = default;
    void Initialize() override;
    void TagOnclick(int unit);
    void OnclickOption(int unit);
};


#endif //SETTINGSCENE_HPP
