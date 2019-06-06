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
    btn = new Engine::TextButton(MultiLang::SettingScene_audio, "FOT-SkipStd-B.otf", 48, 50 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Audio));
    AddNewControlObject(btn);
    btn = new Engine::TextButton(MultiLang::SettingScene_language, "FOT-SkipStd-B.otf", 48, 250 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Language));
    AddNewControlObject(btn);
    btn = new Engine::TextButton(MultiLang::SettingScene_display, "FOT-SkipStd-B.otf", 48, 550 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Display));
    AddNewControlObject(btn);
    btn = new Engine::TextButton(MultiLang::SettingScene_back, "FOT-SkipStd-B.otf", 48, 60 , 600, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 4));
    AddNewControlObject(btn);

}

std::list<Engine::IObject*>* SettingScene::ConsAudioTag(){
	
	auto ls = new std::list<Engine::IObject*>;
	int halfw = Engine::GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfh = Engine::GameEngine::GetInstance().GetScreenHeight() / 2;
	
	
	Engine::Label* label;
	label = new Engine::Label("BGM", "FOT-SkipStd-B.otf", 48, halfw - 400, halfh - 75, 0xff, 0xff, 0xff, 255, 0.5, 0.5);
	AddNewObject(label);
	ls->emplace_back(label);
	
	label = new Engine::Label("SFX", "FOT-SkipStd-B.otf", 48, halfw - 400, halfh + 125, 0xff, 0xff, 0xff, 255, 0.5, 0.5);
	AddNewObject(label);
	ls->emplace_back(label);
	
	
	Slider* BGMSlider, *SFXSlider;
	BGMSlider = new Slider(halfw - 200, halfh - 100, 400, 10);
	BGMSlider->SetOnValueChangedCallback(std::bind(&SettingScene::SetBGMValue, this, std::placeholders::_1));
	BGMSlider->SetValue( AudioHelper::BGMVolume );
	AddNewControlObject(BGMSlider);
	
	SFXSlider = new Slider(halfw - 200, halfh + 100, 400, 10);
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
