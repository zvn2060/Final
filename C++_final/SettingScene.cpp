#include "SettingScene.hpp"
#include "AudioHelper.hpp"
#include "LayoutHelper.hpp"
#include "TextButton.hpp"
#include "LOG.hpp"
#include "MultiLang.hpp"
#include "OptionSwitch.hpp"
#include "FileHelper.hpp"


void SettingScene::Initialize(){
    SetBackGround("background/title.png");
    AudioHelper::PlayBGM("BGM/title.ogg");
    halfh = Engine::GameEngine::GetInstance().GetScreenHeight() / 2;
    halfw = Engine::GameEngine::GetInstance().GetScreenWidth() / 2;
    ConstructUI();
    fragment = new Fragment();
    fragment->EmbedAt(this);
    fragment->AddNewFragemt("audio", std::bind(&SettingScene::ConsAudioTag, this));
    fragment->AddNewFragemt("lang", std::bind(&SettingScene::ConsLangTag, this));
    fragment->AddNewFragemt("display", std::bind(&SettingScene::ConsDisplayTag, this));
    fragment->ChangeFragment("audio");
}

void SettingScene::ConstructUI() {
    Engine::TextButton* txtbtn;
	std::string text[4]{
		MultiLang::SettingScene_audio,
		MultiLang::SettingScene_language,
		MultiLang::SettingScene_display,
		MultiLang::SettingScene_back
	};
    for(auto i : {0 , 1 , 2 , 3}){
		txtbtn = new Engine::TextButton(text[i], "FOT-SkipStd-B.otf", 48,
				Engine::LayoutHelper::AlignLeft(50),
				Engine::LayoutHelper::AlignTop(60 + 160 * i),
				0xff, 0xff, 0xff, 0, 0);
		txtbtn->SetOnClickCallback(std::bind(&SettingScene::SlideOnclick, this, i));
		AddNewControlObject(txtbtn);
    }
 
}

std::list<Engine::IObject*>* SettingScene::ConsAudioTag(){
    
    auto ls = new std::list<Engine::IObject*>;

    Slider* BGMSlider, *SFXSlider;
    BGMSlider = new Slider(MultiLang::SettingScene_audio_BGM, "FOT-SkipStd-B.otf", 48,
            halfw - 50, halfh - 200, 400, 10,
            0xff, 0xff, 0xff, 0xff);
    BGMSlider->SetOnValueChangedCallback(std::bind(&SettingScene::SetBGMValue, this, std::placeholders::_1));
    BGMSlider->SetValue( AudioHelper::BGMVolume );
    AddNewControlObject(BGMSlider);

    SFXSlider = new Slider(MultiLang::SettingScene_audio_SFX, "FOT-SkipStd-B.otf", 48,
                           halfw - 50, halfh, 400, 10,
                           0xff, 0xff, 0xff, 255);
    SFXSlider->SetOnValueChangedCallback(std::bind(&SettingScene::SetSFXValue, this, std::placeholders::_1));
    SFXSlider->SetValue( AudioHelper::SFXVolume );
    AddNewControlObject(SFXSlider);

    ls->emplace_back(BGMSlider);
    ls->emplace_back(SFXSlider);
    return ls;
}

std::list<Engine::IObject*>* SettingScene::ConsLangTag(){
    auto ls = new std::list<Engine::IObject*>;
    LangSwitch = new Engine::OptionSwitch(halfw + 100, halfh - 50, FileHelper::GetFiles("resources/lang/"), Engine::GameEngine::GetInstance().GetLang());
	LangSwitch->SetOnClickCallback(std::bind(&SettingScene::OnclickOption, this, 0));
    AddNewControlObject(LangSwitch);
    ls->emplace_back(LangSwitch);
    return ls;
}

std::list<Engine::IObject*>* SettingScene::ConsDisplayTag(){
    auto ls = new std::list<Engine::IObject*>;
	FullScreenSwitch = new Engine::OptionSwitch(
			Engine::LayoutHelper::HorizontalCenter(100),
			Engine::LayoutHelper::VerticalCenter(-50),
			std::vector<std::string>{"Windowed","Full Screen"},
			"Windowed");
	FullScreenSwitch->SetOnClickCallback(std::bind(&SettingScene::OnclickOption, this, 1));
	AddNewControlObject(FullScreenSwitch);
	ls->emplace_back(FullScreenSwitch);
    return ls;
}

void SettingScene::SlideOnclick(int unit) {
    AudioHelper::PlayAudio( "btn_switch.ogg" );
    switch (unit){
        case Audio:
            fragment->ChangeFragment("audio");
            break;
        case Language:
            fragment->ChangeFragment("lang");
            break;
        case Display:
            fragment->ChangeFragment("display");
            break;
        case 3:
            fragment->Terminate();
            Engine::GameEngine::GetInstance().ChangeScene( "title" );
            break;
        default:
            ;
    }
}

void SettingScene::OnclickOption(int unit) {
    switch (unit){
        case 0:
            Engine::GameEngine::GetInstance().ChangeLang(LangSwitch->GetCurrentOption());
            break;
        case 1:
			Engine::GameEngine::GetInstance().ToggleFullScreen();
            break;
        default:
            ;
    }
}

void SettingScene::SetBGMValue( float value ){
    AudioHelper::BGMVolume = value;
}

void SettingScene::SetSFXValue(float value){
    AudioHelper::SFXVolume = value;
}
