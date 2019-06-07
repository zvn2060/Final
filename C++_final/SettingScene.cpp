#include "SettingScene.hpp"
#include "AudioHelper.hpp"
#include "TextButton.hpp"
#include "LOG.hpp"
#include "MultiLang.hpp"


void SettingScene::Initialize(){

	AudioHelper::PlayBGM("BGM/title.ogg");
	ConstructUI();
	fragment = new Fragment();
	fragment->EmbedAt(this);
	fragment->AddNewFragemt("audio", std::bind(&SettingScene::ConsAudioTag, this));
	fragment->AddNewFragemt("lang", std::bind(&SettingScene::ConsLangTag, this));
	fragment->AddNewFragemt("display", std::bind(&SettingScene::ConsDisplayTag, this));
	fragment->ChangeFragment("audio");
}

void SettingScene::ConstructUI() {
	
	AddNewObject( new Engine::Image( "background/title.png", 0, 0, 1280, 720 ) );
    Engine::TextButton* btn;
    btn = new Engine::TextButton(MultiLang::SettingScene_audio, "FOT-SkipStd-B.otf", 48, 50 , 60, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Audio));
    AddNewControlObject(btn);
    btn = new Engine::TextButton(MultiLang::SettingScene_language, "FOT-SkipStd-B.otf", 48, 50 , 220, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Language));
    AddNewControlObject(btn);
    btn = new Engine::TextButton(MultiLang::SettingScene_display, "FOT-SkipStd-B.otf", 48, 50 , 380, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Display));
    AddNewControlObject(btn);
    btn = new Engine::TextButton(MultiLang::SettingScene_back, "FOT-SkipStd-B.otf", 48, 50 , 600, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 4));
    AddNewControlObject(btn);

}

std::list<Engine::IObject*>* SettingScene::ConsAudioTag(){
	
	auto ls = new std::list<Engine::IObject*>;
	int halfw = Engine::GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfh = Engine::GameEngine::GetInstance().GetScreenHeight() / 2;

	Slider* BGMSlider, *SFXSlider;
	BGMSlider = new Slider(MultiLang::SettingScene_audio_BGM, "FOT-SkipStd-B.otf", 48,
	        halfw - 50, halfh - 200, 400, 10,
            0xff, 0xff, 0xff, 255);
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
	
	return ls;
}

std::list<Engine::IObject*>* SettingScene::ConsDisplayTag(){
	auto ls = new std::list<Engine::IObject*>;
	return ls;
}

void SettingScene::Onclick(int option) {
	AudioHelper::PlayAudio( "btn_switch.ogg" );
	switch (option){
        case Audio:
        	fragment->ChangeFragment("audio");
            break;
        case Language:
			fragment->ChangeFragment("lang");
			break;
        case Display:
			fragment->ChangeFragment("display");
			break;
        case 4:
        	fragment->Terminate();
            Engine::GameEngine::GetInstance().ChangeScene( "title" );
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
