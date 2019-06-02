#include "SettingScene.hpp"
#include "AudioHelper.hpp"
#include "TextButton.hpp"
#include "LOG.hpp"


void SettingScene::Initialize(){

	AudioHelper::PlayBGM("BGM/title.ogg");
	ConstructUI();
	fragment = new Fragment();
	fragment->EmbedAt(this);
	fragment->AddNewFragemt("audio", std::bind(&SettingScene::ConsAudioTag, this));
	fragment->AddNewFragemt("lang", std::bind(&SettingScene::ConsLangTag, this));
	fragment->AddNewFragemt("display", std::bind(&SettingScene::ConsDisplayTag, this));
	
}

void SettingScene::ConstructUI() {
	AddNewObject( new Engine::Image( "background/title.png", 0, 0, 1280, 720 ) );
    Engine::TextButton* btn;
    btn = new Engine::TextButton("Audio", "FOT-SkipStd-B.otf", 48, 50 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Audio));
    AddNewControlObject(btn);
    btn = new Engine::TextButton("Language", "FOT-SkipStd-B.otf", 48, 250 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Language));
    AddNewControlObject(btn);
    btn = new Engine::TextButton("Display", "FOT-SkipStd-B.otf", 48, 550 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, Display));
    AddNewControlObject(btn);
    btn = new Engine::TextButton("Back", "FOT-SkipStd-B.otf", 48, 60 , 600, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 4));
    AddNewControlObject(btn);
}

std::list<Engine::IObject*>* SettingScene::ConsAudioTag(){
	auto ls = new std::list<Engine::IObject*>;
	Slider* BGMSlider;
	BGMSlider = new Slider(200, 200, 400, 10);
	BGMSlider->SetOnValueChangedCallback(std::bind(&SettingScene::SetBGMValue, this, std::placeholders::_1));
	BGMSlider->SetValue( AudioHelper::BGMVolume );
	AddNewControlObject(BGMSlider);
	ls->emplace_back(BGMSlider);
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
	// THIS WILL cause assertion fail :
	// al_set_sample_instance_gain( bgmInstance, value );
	AudioHelper::BGMVolume = value;
}


