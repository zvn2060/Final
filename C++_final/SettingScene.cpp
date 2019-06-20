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
    AudioHelper::PlayBGM("BGM/setting.ogg");
    ConstructUI();
    fragment = new Fragment();
    fragment->EmbedAt(this);
	fragment->AddNewFragment( "audio", std::bind( &SettingScene::ConsAudioTag, this ) );
	fragment->AddNewFragment( "lang", std::bind( &SettingScene::ConsLangTag, this ) );
	fragment->AddNewFragment( "display", std::bind( &SettingScene::ConsDisplayTag, this ) );
    fragment->ChangeFragment("audio");
	LangSwitch->Disable();
	FullScreenSwitch->Disable();
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
		txtbtn->SetOnClickCallback(std::bind(&SettingScene::TagOnclick, this, i));
		AddNewControlObject(txtbtn);
    }
 	
}

std::list<Engine::IObject*>* SettingScene::ConsAudioTag(){
    
    auto ls = new std::list<Engine::IObject*>;

    
    BGMSlider = new Slider(MultiLang::SettingScene_audio_BGM, "FOT-SkipStd-B.otf", 48,
            Engine::LayoutHelper::HorizontalCenter(-50),
            Engine::LayoutHelper::VerticalCenter(-200),
            400, 10, 0xff, 0xff, 0xff, 0xff);
    BGMSlider->SetOnValueChangedCallback(std::bind(&SettingScene::SetBGMValue, this, std::placeholders::_1));
    BGMSlider->SetValue( AudioHelper::BGMVolume );
    AddNewControlObject(BGMSlider);

    SFXSlider = new Slider(MultiLang::SettingScene_audio_SFX, "FOT-SkipStd-B.otf", 48,
    		Engine::LayoutHelper::HorizontalCenter(-50),
    		Engine::LayoutHelper::VerticalCenter(),
			400, 10, 0xff, 0xff, 0xff, 0xff);
    SFXSlider->SetOnValueChangedCallback(std::bind(&SettingScene::SetSFXValue, this, std::placeholders::_1));
    SFXSlider->SetValue( AudioHelper::SFXVolume );
    AddNewControlObject(SFXSlider);

    ls->emplace_back(BGMSlider);
    ls->emplace_back(SFXSlider);
    return ls;
}

std::list<Engine::IObject*>* SettingScene::ConsLangTag(){
    auto ls = new std::list<Engine::IObject*>;
    LangSwitch = new Engine::OptionSwitch(
			Engine::LayoutHelper::HorizontalCenter(100),
			Engine::LayoutHelper::VerticalCenter(-50),
    		FileHelper::GetFiles("resources/lang/"),
    		Engine::GameEngine::GetInstance().GetLang()
    		);
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

void SettingScene::TagOnclick( int unit) {
    AudioHelper::PlayAudio( "btn_switch.ogg" );
    switch (unit){
        case Audio:
			if(fragment->ChangeFragment("audio")){
				SFXSlider->Enable();
				BGMSlider->Enable();
				LangSwitch->Disable();
				FullScreenSwitch->Disable();
			}
            break;
        case Language:
			if(fragment->ChangeFragment("lang")){
				SFXSlider->Disable();
				BGMSlider->Disable();
				LangSwitch->Enable();
				FullScreenSwitch->Disable();
			}
			break;
        case Display:
			if(fragment->ChangeFragment("display")){
				SFXSlider->Disable();
				BGMSlider->Disable();
				LangSwitch->Disable();
				FullScreenSwitch->Enable();
			}
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

