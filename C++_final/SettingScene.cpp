#include "SettingScene.hpp"
#include "AudioHelper.hpp"
#include "TextButton.hpp"

void SettingScene::Initialize(){
	AddNewObject( new Engine::Image( "background/title.png", 0, 0, 1280, 720 ) );
	AudioHelper::PlayBGM("BGM/title.ogg");
	ConstructUI();
}

void SettingScene::ConstructUI() {
    Engine::TextButton* btn;
    btn = new Engine::TextButton("Audio", "FOT-SkipStd-B.otf", 48, 50 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::TextButton("Language", "FOT-SkipStd-B.otf", 48, 250 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 2));
    AddNewControlObject(btn);

    btn = new Engine::TextButton("Display", "FOT-SkipStd-B.otf", 48, 550 , 20, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 3));
    AddNewControlObject(btn);

    btn = new Engine::TextButton("Back", "FOT-SkipStd-B.otf", 48, 60 , 600, 0xff, 0xff, 0xff, 0, 0);
    btn->SetOnClickCallback(std::bind(&SettingScene::Onclick, this, 4));
    AddNewControlObject(btn);
}

void SettingScene::Onclick(int option) {
    switch (option){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            Engine::GameEngine::GetInstance().ChangeScene( "title" );
            break;
    }
}

