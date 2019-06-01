#include "SettingScene.hpp"
#include "AudioHelper.hpp"
#include "TextButton.hpp"
#include "LOG.hpp"


void SettingScene::Initialize(){

	AudioHelper::PlayBGM("BGM/title.ogg");
	ConstructUI();
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

void SettingScene::Onclick(int option) {
	AudioHelper::PlayAudio( "btn_switch.ogg" );
	switch (option){
        case Audio:
        	
            break;
        case Language:
			
			break;
        case Display:
			
			break;
        case 4:
            Engine::GameEngine::GetInstance().ChangeScene( "title" );
            break;
    }
}
