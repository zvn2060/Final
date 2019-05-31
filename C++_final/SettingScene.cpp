#include "SettingScene.hpp"
#include "AudioHelper.hpp"

void SettingScene::Initialize(){
	AddNewObject( new Engine::Image( "title/background.png", 0, 0, 1280, 720 ) );
	AudioHelper::PlayBGM("BGM/title.ogg");
}
